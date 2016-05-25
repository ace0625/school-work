// Sami Sahli
// The template for this file was taken from Lab 2, altered to work for IR1.
// This is supporting software for CS321/CS322 Compilers and Language Design.
// Copyright (c) Portland State University
//---------------------------------------------------------------------------
// For CS322 W'16 (J. Li).
//

// IR1 code generator.
//
//
import java.util.*;
import java.io.*;
import ast.*;
import ir.*;

class IR1Gen {

  static class GenException extends Exception {
    public GenException(String msg) { super(msg); }
  }

  // For returning <src,code> pair from gen routines
  //
  static class CodePack {
    IR1.Src src;
    List<IR1.Inst> code;
    CodePack(IR1.Src src, List<IR1.Inst> code) {
      this.src=src; this.code=code;
    }
  }

  // The main routine
  //
  public static void main(String [] args) throws Exception {
    if (args.length == 1) {
      FileInputStream stream = new FileInputStream(args[0]);
      Ast1.Program p = new Ast1Parser(stream).Program();
      stream.close();
      IR1.Program ir = IR1Gen.gen(p);
      System.out.print(ir.toString());
    } else {
      System.out.println("You must provide an input file name.");
    }
  }

  // Ast1.Program ---
  // Ast1.Func[] funcs;
  //
  // Program -> {Func}
  //
  public static IR1.Program gen(Ast1.Program n) throws Exception {
    List<IR1.Func> code = new ArrayList<IR1.Func>();

    for (Ast1.Func f: n.funcs)
      code.add(gen(f));

    return new IR1.Program(code);
  }

  // Ast1.Func ---
  // Ast1.Type t;
  // String nm;
  // Ast1.Param[] params;
  // Ast1.VarDecl[] vars;
  // Ast1.Stmt[] stmts;
  //
  // Func -> <Global> VarList [VarList]   // Name, Params, Locals
  //         "{" {Inst} "}" <EOL>         // Body
  //
  public static IR1.Func gen(Ast1.Func n) throws Exception {
    IR1.Global global = new IR1.Global("_" + n.nm);
    List<IR1.Id> params = new ArrayList<IR1.Id>();
    List<IR1.Id> locals = new ArrayList<IR1.Id>();
    List<IR1.Inst> code = new ArrayList<IR1.Inst>();

    for (Ast1.Param p: n.params)
      params.add(new IR1.Id(p.nm));

    for (Ast1.VarDecl v: n.vars) {
      locals.add(new IR1.Id(v.nm));

      if (v.init != null)
        code.addAll(gen(v));
    }

    for (Ast1.Stmt s: n.stmts)
      code.addAll(gen(s));

    if (n.t == null)
      code.add(new IR1.Return());

    return new IR1.Func(global, params, locals, code);
  }

  // Ast1.VarDecl ---
  //
  public static List<IR1.Inst> gen(Ast1.VarDecl n) throws Exception {
    List<IR1.Inst> code = new ArrayList<IR1.Inst>();
    IR1.Id id = new IR1.Id(n.nm);
    CodePack e = gen(n.init);
    IR1.Move move = new IR1.Move(id, e.src);

    code.addAll(e.code);
    code.add(move);

    return code;
  }

  // STATEMENTS

  static List<IR1.Inst> gen(Ast1.Stmt n) throws Exception {
    if (n instanceof Ast1.Block)    return gen((Ast1.Block) n);
    if (n instanceof Ast1.Assign)   return gen((Ast1.Assign) n);
    if (n instanceof Ast1.CallStmt) return gen((Ast1.CallStmt) n);
    if (n instanceof Ast1.If)       return gen((Ast1.If) n);
    if (n instanceof Ast1.While)    return gen((Ast1.While) n);
    if (n instanceof Ast1.Print)    return gen((Ast1.Print) n);
    if (n instanceof Ast1.Return)   return gen((Ast1.Return) n);
    throw new GenException("Unknown Stmt: " + n);
  }

  // Ast1.Block ---
  // Ast1.Stmt[] stmts;
  //
  // AG:
  //   code: {stmt.c}
  //
  static List<IR1.Inst> gen(Ast1.Block n) throws Exception {
    List<IR1.Inst> code = new ArrayList<IR1.Inst>();

    for (Ast1.Stmt s: n.stmts)
        code.addAll(gen(s));

    return code;
  }

  // Ast1.Assign ---
  // Ast1.Id lhs;
  // Ast1.Exp rhs;
  //
  // AG:
  //   code: rhs.c + lhs.c + "lhs.s = rhs.v"
  //
  static List<IR1.Inst> gen(Ast1.Assign n) throws Exception {
    List<IR1.Inst> code = new ArrayList<IR1.Inst>();
    CodePack rhs = gen(n.rhs);
    CodePack lhs;

    code.addAll(rhs.code);

    if (n.lhs instanceof Ast1.Id) {
      lhs = gen((Ast1.Id) n.lhs);
      code.add(new IR1.Move((IR1.Dest) lhs.src, rhs.src));
    }
    else if (n.lhs instanceof Ast1.ArrayElm) {
      lhs = genAddr((Ast1.ArrayElm) n.lhs);
      code.addAll(lhs.code);
      code.add(new IR1.Store(new IR1.Addr(lhs.src), rhs.src));
    }

    return code;
  }

  // Ast1.CallStmt ---
  //
  static List<IR1.Inst> gen(Ast1.CallStmt n) throws Exception {
    List<IR1.Inst> code = new ArrayList<IR1.Inst>();
    List<IR1.Src> sources = new ArrayList<IR1.Src>();
    IR1.Global global = new IR1.Global("_" + n.nm);

    for (Ast1.Exp e: n.args) {
      CodePack p = gen(e);
      code.addAll(p.code);
      sources.add(p.src);
    }

    IR1.Call c = new IR1.Call(global, sources);
    code.add(c);

    return code;
  }

  // Ast1.If ---
  // Ast1.Exp cond;
  // Ast1.Stmt s1, s2;
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
  static List<IR1.Inst> gen(Ast1.If n) throws Exception {
    List<IR1.Inst> code = new ArrayList<IR1.Inst>();
    CodePack cond = gen(n.cond);
    IR1.Label L1 = new IR1.Label("L1");

    code.addAll(cond.code);
    code.add(new IR1.CJump(IR1.ROP.EQ, cond.src, IR1.FALSE, L1));
    code.addAll(gen(n.s1));
    if (n.s2 == null)
      code.add(new IR1.LabelDec(L1));
    else {
      IR1.Label L2 = new IR1.Label("L2");
      code.add(new IR1.Jump(L2));
      code.add(new IR1.LabelDec(L1));
      code.addAll(gen(n.s2));
      code.add(new IR1.LabelDec(L2));
    }

    return code;
  }

  // Ast1.While ---
  // Ast1.Exp cond;
  // Ast1.Stmt s;
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
  static List<IR1.Inst> gen(Ast1.While n) throws Exception {
    List<IR1.Inst> code = new ArrayList<IR1.Inst>();
    CodePack cond = gen(n.cond);
    IR1.Label L1 = new IR1.Label("L1");
    IR1.Label L2 = new IR1.Label("L2");

    code.add(new IR1.LabelDec(L1));
    code.addAll(cond.code);
    code.add(new IR1.CJump(IR1.ROP.EQ, cond.src, IR1.FALSE, L2));
    code.addAll(gen(n.s));
    code.add(new IR1.Jump(L1));
    code.add(new IR1.LabelDec(L2));

    return code;
  }

  // Ast1.Print ---
  // Ast1.Exp arg;
  //
  // AG:
  //   code: arg.c + "call print (arg.v)"
  //
  static List<IR1.Inst> gen(Ast1.Print n) throws Exception {
    List<IR1.Inst> code = new ArrayList<IR1.Inst>();
    List<IR1.Src> src = new ArrayList<IR1.Src>();

    CodePack e = gen(n.arg);
    src.add(e.src);
    code.addAll(e.code);

    if (n.arg instanceof Ast1.StrLit)
      code.add(new IR1.Call(new IR1.Global("_printStr"), src, null));
    else if (n.arg == null)
      code.add(new IR1.Call(new IR1.Global("_printStr"), src, null));
    else if (n.arg instanceof Ast1.IntLit || n.arg instanceof Ast1.BoolLit)
      code.add(new IR1.Call(new IR1.Global("_printInt"), src, null));

    return code;
  }

  // Ast1.Return ---
  // Ast1.Exp val;
  //
  // AG:
  //   code: val.c + "return [src]"
  //
  static List<IR1.Inst> gen(Ast1.Return n) throws Exception {
    List<IR1.Inst> code = new ArrayList<IR1.Inst>();

    if (n.val == null)
      code.add(new IR1.Return());
    else {
      CodePack val = gen(n.val);
      code.addAll(val.code);
      code.add(new IR1.Return(val.src));
    }

    return code;
  }

  // EXPRESSIONS

  static CodePack gen(Ast1.Exp n) throws Exception {
    if (n instanceof Ast1.Binop)    return gen((Ast1.Binop) n);
    if (n instanceof Ast1.Unop)     return gen((Ast1.Unop) n);
    if (n instanceof Ast1.Id)       return gen((Ast1.Id) n);
    if (n instanceof Ast1.Call)     return gen((Ast1.Call) n);
    if (n instanceof Ast1.NewArray) return gen((Ast1.NewArray) n);
    if (n instanceof Ast1.ArrayElm) return gen((Ast1.ArrayElm) n);
    if (n instanceof Ast1.IntLit)   return gen((Ast1.IntLit) n);
    if (n instanceof Ast1.BoolLit)  return gen((Ast1.BoolLit) n);
    if (n instanceof Ast1.StrLit)   return gen((Ast1.StrLit) n);
    throw new GenException("Unknown Exp node: " + n);
  }

  // Ast1.Binop ---
  // Ast1.BOP op;
  // Ast1.Exp e1,e2;
  //
  // AG:
  //   newTemp: t
  //   code: e1.c + e2.c
  //         + "t = e1.v op e2.v"
  //
  static CodePack gen(Ast1.Binop n) throws Exception {
      List<IR1.Inst> code = new ArrayList<IR1.Inst>();
      CodePack e1 = gen(n.e1);
      CodePack e2 = gen(n.e2);
      IR1.Temp t = new IR1.Temp();

      code.addAll(e1.code);
      code.addAll(e2.code);
      code.add(new IR1.Binop(gen(n.op), t, e1.src, e2.src));

      return new CodePack(t, code);
  }

  // Ast1.Unop ---
  // Ast1.UOP op;
  // Ast1.Exp e;
  //
  // AG:
  //   newTemp: t
  //   code: e.c + "t = op e.v"
  //
  static CodePack gen(Ast1.Unop n) throws Exception {
    List<IR1.Inst> code = new ArrayList<IR1.Inst>();
    CodePack e = gen(n.e);
    IR1.Temp t = new IR1.Temp();

    code.addAll(e.code);
    code.add(new IR1.Unop(gen(n.op), t, e.src));

    return new CodePack(t, code);
  }

  // Ast1.Id ---
  // String nm;
  //
  static CodePack gen(Ast1.Id n) throws Exception {
    return new CodePack(new IR1.Id(n.nm), null);
  }

  // Ast1.Call ---
  // String nm;
  // Ast1.Exp[] args;
  //
  static CodePack gen(Ast1.Call n) throws Exception {
    IR1.Global global = new IR1.Global("_" + n.nm);
    List<IR1.Inst> code = new ArrayList<IR1.Inst>();
    List<IR1.Src> src = new ArrayList<IR1.Src>();

    for (Ast1.Exp e: n.args) {
      CodePack cp = gen(e);
      code.addAll(cp.code);
      src.add(cp.src);
    }

    IR1.Call c = new IR1.Call(global, src, new IR1.Temp());
    code.add(c);

    return new CodePack((IR1.Src)c.rdst, code);
  }

  // Ast1.NewArray ---
  //
  static CodePack gen(Ast1.NewArray n) throws Exception {
    List<IR1.Inst> code = new ArrayList<IR1.Inst>();
    List<IR1.Src> src = new ArrayList<IR1.Src>();
    IR1.IntLit i = new IR1.IntLit(n.len * 4);
    IR1.Temp t = new IR1.Temp();
    IR1.Global global = new IR1.Global("_malloc");

    src.add(i);
    code.add(new IR1.Call(global, src, t));

    return new CodePack(t, code);
  }

  // Ast1.ArrayElm ---
  // Ast1.Exp ar, idx;
  //
  // AG:
  //   code:
  static CodePack gen(Ast1.ArrayElm n) throws Exception {
    CodePack e = genAddr(n);

    IR1.Temp t = new IR1.Temp();
    e.code.add(new IR1.Load(t, (IR1.Addr)e.src));

    return new CodePack(t, e.code);
  }

  // genAddr ---
  // Ast1.ArrayElm;
  //
  static CodePack genAddr(Ast1.ArrayElm n) throws Exception {
    List<IR1.Inst> code = new ArrayList<IR1.Inst>();
    CodePack ar = gen(n.ar);
    CodePack idx = gen(n.idx);
    IR1.Temp t1 = new IR1.Temp();
    IR1.Temp t2 = new IR1.Temp();
    IR1.IntLit i = new IR1.IntLit(4);

    code.addAll(ar.code);
    code.addAll(idx.code);
    code.add(new IR1.Binop(IR1.AOP.MUL, t1, idx.src, i));
    code.add(new IR1.Binop(IR1.AOP.ADD, t2, ar.src, t1));

    return new CodePack(t2, code);
  }

  // Ast1.IntLit ---
  // int i;
  //
  static CodePack gen(Ast1.IntLit n) throws Exception {
    return new CodePack(new IR1.IntLit(n.i), null);
  }

  // Ast1.BoolLit ---
  // boolean b;
  //
  static CodePack gen(Ast1.BoolLit n) throws Exception {
    return new CodePack(new IR1.BoolLit(n.b), null);
  }

  // Ast1.StrLit ---
  // String s;
  //
  static CodePack gen(Ast1.StrLit n) throws Exception {
    return new CodePack(new IR1.StrLit(n.s), null);
  }

  // OPERATORS

  static IR1.BOP gen(Ast1.BOP op) {
    IR1.BOP irOp = null;
    switch (op) {
    case ADD: irOp = IR1.AOP.ADD; break;
    case SUB: irOp = IR1.AOP.SUB; break;
    case MUL: irOp = IR1.AOP.MUL; break;
    case DIV: irOp = IR1.AOP.DIV; break;
    case AND: irOp = IR1.AOP.AND; break;
    case OR:  irOp = IR1.AOP.OR;  break;
    case EQ:  irOp = IR1.ROP.EQ;  break;
    case NE:  irOp = IR1.ROP.NE;  break;
    case LT:  irOp = IR1.ROP.LT;  break;
    case LE:  irOp = IR1.ROP.LE;  break;
    case GT:  irOp = IR1.ROP.GT;  break;
    case GE:  irOp = IR1.ROP.GE;  break;
    }
    return irOp;
  }

  static IR1.UOP gen(Ast1.UOP op) {
    IR1.UOP irOp = null;
    switch (op) {
    case NEG: irOp = IR1.UOP.NEG; break;
    case NOT: irOp = IR1.UOP.NOT; break;
    }
    return irOp;
  }
}