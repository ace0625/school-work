// This is supporting software for CS321/CS322 Compilers and Language Design.
// Copyright (c) Portland State University
//---------------------------------------------------------------------------
// For CS322 W'16 (J. Li).
//

// IR0 code generator.
//
//
import java.util.*;
import java.io.*;
import ast.*;
import ir.*;

class IR0GenOpt {

  static class GenException extends Exception {
    public GenException(String msg) { super(msg); }
  }

  // For returning <src,code> pair from gen routines
  //
  static class CodePack {
    IR0.Src src;
    List<IR0.Inst> code;
    CodePack(IR0.Src src, List<IR0.Inst> code) { 
      this.src=src; this.code=code; 
    }
  } 

  // The main routine
  //
  public static void main(String [] args) throws Exception {
    if (args.length == 1) {
      FileInputStream stream = new FileInputStream(args[0]);
      Ast0.Program p = new Ast0Parser(stream).Program();
      stream.close();
      IR0.Program ir = IR0GenOpt.gen(p);
      System.out.print(ir.toString());
    } else {
      System.out.println("You must provide an input file name.");
    }
  }

  // Ast0.Program ---
  // Ast0.Stmt[] stmts;
  //
  // AG:
  //   code: stmts.c  -- append all individual stmt.c
  //
  public static IR0.Program gen(Ast0.Program n) throws Exception {
    List<IR0.Inst> code = new ArrayList<IR0.Inst>();
    for (Ast0.Stmt s: n.stmts)
      code.addAll(gen(s));
    return new IR0.Program(code);
  }

  // STATEMENTS

  static List<IR0.Inst> gen(Ast0.Stmt n) throws Exception {
    if (n instanceof Ast0.Block)  return gen((Ast0.Block) n);
    if (n instanceof Ast0.Assign) return gen((Ast0.Assign) n);
    if (n instanceof Ast0.If)     return gen((Ast0.If) n);
    if (n instanceof Ast0.While)  return gen((Ast0.While) n);
    if (n instanceof Ast0.Print)  return gen((Ast0.Print) n);
    throw new GenException("Unknown Stmt: " + n);
  }

  // Ast0.Block ---
  // Ast0.Stmt[] stmts;
  //
  // AG:
  //   code: {stmt.c}
  //
  static List<IR0.Inst> gen(Ast0.Block n) throws Exception {
    List<IR0.Inst> code = new ArrayList<IR0.Inst>();

    // ... need code ...

    return code;
  }

  // Ast0.Assign ---
  // Ast0.Id lhs;
  // Ast0.Exp rhs;
  //
  // AG:
  //   code: rhs.c + "lhs.s = rhs.v"
  //
  static List<IR0.Inst> gen(Ast0.Assign n) throws Exception {
    List<IR0.Inst> code = new ArrayList<IR0.Inst>();
    CodePack rhs = gen(n.rhs);
    code.addAll(rhs.code);
    if (n.lhs instanceof Ast0.Id) {
      IR0.Dest lhs = new IR0.Id(((Ast0.Id) n.lhs).nm);
      code.add(new IR0.Move(lhs, rhs.src));
    } 
    // else if (n.lhs instanceof Ast0.ArrayElm) {
    //   AddrPack p = genAddr((Ast0.ArrayElm) n.lhs);
    //   code.addAll(p.code);
    //   code.add(new IR0.Store(p.addr, rhs.src));
    // } 
    else {
      throw new GenException("Wrong Ast0 lhs Exp: " + n.lhs);
    }
    // ... need code ...

    return code;
  }

  // Ast0.If ---
  // Ast0.Exp cond;
  // Ast0.Stmt s1, s2;
  //
  // AG:
  //   newLabel: L1[,L2]
  //   code: cond.c 
  //         + "if cond.v == false goto L1" 
  //         + s1.c 
  //         [+ "goto L2"] 
  //         + "L1:" 
  //         [+ s2.c]
  //         [+ "L2:"]
  //
  static List<IR0.Inst> gen(Ast0.If n) throws Exception {
    List<IR0.Inst> code = new ArrayList<IR0.Inst>();
     CodePack p = gen(n.cond);
    if(p.src instanceof IR0.BoolLit){
      if (n.s2 == null){
        return ( ((IR0.BoolLit)p.src).b ) ? gen(n.s1) : new ArrayList<IR0.Inst>();
      }
      else{
        return ( ((IR0.BoolLit)p.src).b ) ? gen(n.s1) : gen(n.s2);
      }
    }
    else{
      IR0.Label L1 = new IR0.Label();
      if (n.cond instanceof Ast0.Binop && isROP(((Ast0.Binop) n.cond).op)){
        CodePack lhs = gen(((Ast0.Binop) n.cond).e1);
        CodePack rhs = gen(((Ast0.Binop) n.cond).e2);
        code.addAll(lhs.code);
        code.addAll(rhs.code);
        code.add(new IR0.CJump(genCounterOp(((Ast0.Binop) n.cond).op),
			       lhs.src, rhs.src, L1));
      }
      else{
        code.addAll(p.code);
        code.add(new IR0.CJump(IR0.ROP.EQ, p.src, IR0.FALSE, L1));
      }
      code.addAll(gen(n.s1));
      if (n.s2 == null) {
        code.add(new IR0.LabelDec(L1));
      } else {	
        IR0.Label L2 = new IR0.Label();
        code.add(new IR0.Jump(L2));
        code.add(new IR0.LabelDec(L1));
        code.addAll(gen(n.s2));
        code.add(new IR0.LabelDec(L2));
      }
      return code;
    }
  }

  // Ast0.While ---
  // Ast0.Exp cond;
  // Ast0.Stmt s;
  //
  // AG:
  //   newLabel: L1,L2
  //   code: "L1:" 
  //         + cond.c 
  //         + "if cond.v == false goto L2" 
  //         + s.c 
  //         + "goto L1" 
  //         + "L2:"
  //
  static List<IR0.Inst> gen(Ast0.While n) throws Exception {
    List<IR0.Inst> code = new ArrayList<IR0.Inst>();
	CodePack cond = gen(n.cond);
    List<IR0.Inst> s = gen(n.s);
    if (cond.src instanceof IR0.BoolLit && !((IR0.BoolLit) cond.src).b){
      return new ArrayList<IR0.Inst>();
    }
    else{
      IR0.Label L1 = new IR0.Label();
      IR0.Label L2 = new IR0.Label();
      code.add(new IR0.LabelDec(L1));
      if (n.cond instanceof Ast0.Binop && isROP(((Ast0.Binop) n.cond).op)){
        CodePack lhs = gen(((Ast0.Binop) n.cond).e1);
        CodePack rhs = gen(((Ast0.Binop) n.cond).e2);
        code.addAll(lhs.code);
        code.addAll(rhs.code);
        code.add(new IR0.CJump(genCounterOp(((Ast0.Binop) n.cond).op),
                               lhs.src, rhs.src, L1));
      } else{
        code.addAll(cond.code);
        code.add(new IR0.CJump(IR0.ROP.EQ, cond.src, IR0.FALSE, L2));
      }
      code.addAll(s);
      code.add(new IR0.Jump(L1));
      code.add(new IR0.LabelDec(L2));
      return code;
    }
  }
  
  // Ast0.Print ---
  // Ast0.Exp arg;
  //
  // AG:
  //   code: arg.c + "print (arg.v)"
  //
  static List<IR0.Inst> gen(Ast0.Print n) throws Exception {
    List<IR0.Inst> code = new ArrayList<IR0.Inst>();
    if (n.arg == null) {
      code.add(new IR0.Print());
    } else {
      CodePack p = gen((Ast0.Exp) n.arg);
      code.addAll(p.code);
      code.add(new IR0.Print(p.src));
    }
    // ... need code ...

    return code;
  }

  // EXPRESSIONS

  static CodePack gen(Ast0.Exp n) throws Exception {
    if (n instanceof Ast0.Binop)    return gen((Ast0.Binop) n);
    if (n instanceof Ast0.Unop)     return gen((Ast0.Unop) n);
    if (n instanceof Ast0.Id)       return gen((Ast0.Id) n);
    if (n instanceof Ast0.IntLit)   return gen((Ast0.IntLit) n);
    if (n instanceof Ast0.BoolLit)  return gen((Ast0.BoolLit) n);
    throw new GenException("Unknown Exp node: " + n);
  }

  // Ast0.Binop ---
  // Ast0.BOP op;
  // Ast0.Exp e1,e2;
  //
  // AG:
  //   newTemp: t
  //   code: e1.c + e2.c
  //         + "t = e1.v op e2.v"
  //
  static CodePack gen(Ast0.Binop n) throws Exception {
    List<IR0.Inst> code = new ArrayList<IR0.Inst>();
    CodePack l = gen(n.e1);
    CodePack r = gen(n.e2);
    IR0.BOP aop = gen(n.op);
    IR0.Src res;
    if (l.src instanceof IR0.IntLit && r.src instanceof IR0.IntLit)
    {
        if(aop == IR0.AOP.ADD)
          res = new IR0.IntLit(((IR0.IntLit) l.src).i + ((IR0.IntLit)r.src).i);
        else if(aop == IR0.AOP.SUB)
          res = new IR0.IntLit(((IR0.IntLit) l.src).i - ((IR0.IntLit)r.src).i);
        else if(aop == IR0.AOP.MUL)
          res = new IR0.IntLit(((IR0.IntLit) l.src).i * ((IR0.IntLit)r.src).i);
        else if(aop == IR0.AOP.DIV)
          res = new IR0.IntLit(((IR0.IntLit) l.src).i / ((IR0.IntLit)r.src).i);
        else
        {
          res = new IR0.IntLit(-1); 
	  	System.out.println("AOP not found");
        }
     return new CodePack(res);
    }
    else
    {
      IR0.Temp t = new IR0.Temp();
      code.addAll(l.code);
      code.addAll(r.code);
      code.add(new IR0.Binop(gen(n.op), t, l.src, r.src));
      return new CodePack(t, code);
    }
    // ... need code ..
  }

  // Ast0.Unop ---
  // Ast0.UOP op;
  // Ast0.Exp e;
  //
  // AG:
  //   newTemp: t
  //   code: e.c + "t = op e.v"
  //
  static CodePack gen(Ast0.Unop n) throws Exception {
    List<IR0.Inst> code = new ArrayList<IR0.Inst>();
   CodePack p = gen(n.e);
    IR0.Src src;
    IR0.UOP uop;
    if(n.op == Ast0.UOP.NEG)
      uop = IR0.UOP.NEG;
    else if (n.op == Ast0.UOP.NOT)
      uop = IR0.UOP.NOT;
    else{
      uop = null;
      System.out.println("not defined OP");
    }
    if (p.src instanceof IR0.IntLit && uop == IR0.UOP.NEG){
        src = new IR0.IntLit(- ((IR0.IntLit)p.src).i);
        return new CodePack(src);
    }
    else if (p.src instanceof IR0.BoolLit && uop == IR0.UOP.NOT){
        src = new IR0.BoolLit(! ((IR0.BoolLit)p.src).b);
        return new CodePack(src);
    }
    else{
      code.addAll(p.code);
      IR0.UOP op = (n.op == Ast0.UOP.NEG) ? IR0.UOP.NEG : IR0.UOP.NOT;
      IR0.Temp t = new IR0.Temp();
      code.add(new IR0.Unop(op, t, p.src));
      return new CodePack(t, code);
    }
    // ... need code ...

  }
  
  // Ast0.Id ---
  // String nm;
  //
  static CodePack gen(Ast0.Id n) throws Exception {
  	return new CodePack(new IR0.Id(n.nm));
    // ... need code ...

  }

  // Ast0.IntLit ---
  // int i;
  //
  static CodePack gen(Ast0.IntLit n) throws Exception {
  	return  new CodePack(new IR0.IntLit(n.i));
    // ... need code ...

  }

  // Ast0.BoolLit ---
  // boolean b;
  //
  static CodePack gen(Ast0.BoolLit n) throws Exception {
  	 return  new CodePack(n.b ? IR0.TRUE : IR0.FALSE);
    // ... need code ...

  }

  // OPERATORS

  static IR0.BOP gen(Ast0.BOP op) {
    IR0.BOP irOp = null;
    switch (op) {
    case ADD: irOp = IR0.AOP.ADD; break;
    case SUB: irOp = IR0.AOP.SUB; break;
    case MUL: irOp = IR0.AOP.MUL; break;
    case DIV: irOp = IR0.AOP.DIV; break;
    case AND: irOp = IR0.AOP.AND; break;
    case OR:  irOp = IR0.AOP.OR;  break;
    case EQ:  irOp = IR0.ROP.EQ;  break;
    case NE:  irOp = IR0.ROP.NE;  break;
    case LT:  irOp = IR0.ROP.LT;  break;
    case LE:  irOp = IR0.ROP.LE;  break;
    case GT:  irOp = IR0.ROP.GT;  break;
    case GE:  irOp = IR0.ROP.GE;  break;
    }
    return irOp;
  }

  static boolean isAOP(Ast0.BOP op) {
    switch (op) {
    case ADD:  return true; 
    case SUB:  return true; 
    case MUL:  return true; 
    case DIV:  return true; 
    }
    return false;
  }
   
  static boolean isROP(Ast0.BOP op) {
    switch (op) {
    case EQ:  return true; 
    case NE:  return true; 
    case LT:  return true; 
    case LE:  return true; 
    case GT:  return true; 
    case GE:  return true; 
    }
    return false;
  }

  static boolean isROP(IR0.BOP op) {
    if (op instanceof IR0.ROP)
      return true;
    else
      return false;
  }
  
  static IR0.ROP genCounterOp(Ast0.BOP op){
     IR0.ROP counterOp = null;
       if(op == Ast0.BOP.EQ){ counterOp = IR0.ROP.NE; }
       else if(op == Ast0.BOP.NE){ counterOp = IR0.ROP.EQ; }
       else if(op == Ast0.BOP.LT){ counterOp = IR0.ROP.GE; }
       else if(op == Ast0.BOP.LE){ counterOp = IR0.ROP.GT; }
       else if(op == Ast0.BOP.GT){ counterOp = IR0.ROP.LE; }
       else counterOp = IR0.ROP.LE;
     
     return counterOp;
  }


}
