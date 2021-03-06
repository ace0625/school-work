// This is supporting software for CS321/CS322 Compilers and Language Design.
// Copyright (c) Portland State University
//---------------------------------------------------------------------------
// For CS322 W'16 (J. Li).
// 

// AST0 Definition.
//
//
package ast;
import java.util.*;

public class Ast0 {
  static int tab=0;	// indentation for printing AST.

  public abstract static class Node {
    String tab() {
      String str = "";
      for (int i = 0; i < Ast0.tab; i++)
	str += " ";
      return str;
    }
  }

  // Program Node -------------------------------------------------------

  // Program -> {Stmt}
  //
  public static class Program extends Node {
    public final Stmt[] stmts;

    public Program(Stmt[] sa) { stmts=sa; }
    public Program(List<Stmt> sl) { 
      this(sl.toArray(new Stmt[0]));
    }
    public String toString() { 
      String str = "# AST0 Program\n";
      for (Stmt s: stmts) 
	str += s;
      return str;
    }
  }   

  // Statements ---------------------------------------------------------

  public static abstract class Stmt extends Node {}

  // Stmt -> "{" {Stmt} "}"
  //
  public static class Block extends Stmt {
    public final Stmt[] stmts;

    public Block(Stmt[] sa) { stmts=sa; }
    public Block(List<Stmt> sl) { 
      this(sl.toArray(new Stmt[0])); 
    }
    public String toString() { 
      String s = "";
      if (stmts!=null) {
	s = tab() + "{\n";
	Ast0.tab++; 
	for (Stmt st: stmts) 
	  s += st;
	Ast0.tab--;
	s += tab() + "}\n"; 
      }
      return s;
    }
  }

  // Stmt -> "Assign" <Id> Exp
  //
  public static class Assign extends Stmt {
    public final Id lhs;
    public final Exp rhs;

    public Assign(Id id, Exp e) { lhs=id; rhs=e; }

    public String toString() { 
      return tab() + "Assign " + lhs + " " + rhs + "\n"; 
    }
  }

  // Stmt -> "If" Exp Stmt ["Else" Stmt]  
  //
  public static class If extends Stmt {
    public final Exp cond;
    public final Stmt s1;   // then-clause
    public final Stmt s2;   // else-clause (could be null)

    public If(Exp e, Stmt as1, Stmt as2) { cond=e; s1=as1; s2=as2; }

    public String toString() { 
      String str = tab() + "If " + cond + "\n"; 
      Ast0.tab++; 
      str += tab() + s1; 
      Ast0.tab--;
      if (s2 != null) {
	str += tab() + "Else\n";
	Ast0.tab++; 
	str += tab() + s2; 
	Ast0.tab--;
      }
      return str;
    }
  }

  // Stmt -> "While" Exp Stmt 
  //
  public static class While extends Stmt {
    public final Exp cond;
    public final Stmt s;

    public While(Exp e, Stmt as) { cond=e; s=as; }

    public String toString() { 
      String str = tab() + "While " + cond + "\n";
      Ast0.tab++; 
      str += tab() + s; 
      Ast0.tab--;
      return str;
    }
  }   

  // Stmt -> "Print" Exp
  //
  public static class Print extends Stmt {
    public final Exp arg;  // (could be null)

    public Print(Exp e) { arg=e; }

    public String toString() { 
      return tab() + "Print " + (arg==null ? "()" : arg) + "\n"; 
    }
  }

  // Expressions --------------------------------------------------------

  public static abstract class Exp extends Node {}

  public static enum BOP {
    ADD("+"), SUB("-"), MUL("*"), DIV("/"), AND("&&"), OR("||"),
    EQ("=="), NE("!="), LT("<"), LE("<="), GT(">"), GE(">=");
    private String name;

    BOP(String n) { name = n; }
    public String toString() { return name; }
  }

  public static enum UOP {
    NEG("-"), NOT("!");
    private String name;

    UOP(String n) { name = n; }
    public String toString() { return name; }
  }

  // Exp -> "(" "Binop" BOP Exp Exp ")"
  //
  public static class Binop extends Exp {
    public final BOP op;
    public final Exp e1;
    public final Exp e2;

    public Binop(BOP o, Exp ae1, Exp ae2) { op=o; e1=ae1; e2=ae2; }

    public String toString() { 
      return "(Binop " + op + " " + e1 + " " + e2 + ")";
    }
  }

  // Exp -> "(" "Unop" UOP Exp ")"
  //
  public static class Unop extends Exp {
    public final UOP op;
    public final Exp e;

    public Unop(UOP o, Exp ae) { op=o; e=ae; }

    public String toString() { 
      return "(Unop " + op + " " + e + ")";
    }
  }

  // Exp -> <Id>
  //
  public static class Id extends Exp {
    public final String nm;

    public Id(String s) { nm=s; }
    public String toString() { return nm; }
  }

  // Exp -> <IntLit>
  //
  public static class IntLit extends Exp {
    public final int i;	

    public IntLit(int ai) { i=ai; }
    public String toString() { return i + ""; }
  }

  // Exp -> <BoolLit>
  //
  public static class BoolLit extends Exp {
    public final boolean b;	

    public BoolLit(boolean ab) { b=ab; }
    public String toString() { return b + ""; }
  }

  // Exp -> <StrLit>
  //
  public static class StrLit extends Exp {
    public final String s;	

    public StrLit(String as) { s=as; }
    public String toString() { return "\"" + s + "\""; }
  }

}
