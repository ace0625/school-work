/* Generated By:JavaCC: Do not edit this line. mjLLGrammar.java */
import java.io.*;

public class mjLLGrammar implements mjLLGrammarConstants {
  public static void main(String [] args) {
    try {
      if (args.length == 1) {
        FileInputStream stream = new FileInputStream(args[0]);
        new mjLLGrammar(stream).Program();
        stream.close();
        System.out.println("Program's syntax is valid.");
      } else {
        System.out.println("Need a file name as command-line argument.");
      }
    } catch (TokenMgrError e) {
      System.err.println(e);
    } catch (Exception e) {
      System.err.println(e);
    }
  }

//
// PARSER SECTION ---------------------------------------------------------------
//

// Program -> {ClassDecl}
//
  static final public void Program() throws ParseException {
    label_1:
    while (true) {
      switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
      case 7:
        ;
        break;
      default:
        jj_la1[0] = jj_gen;
        break label_1;
      }
      ClassDecl();
    }
    jj_consume_token(0);
  }

// ClassDecl -> "class" <ID> ["extends" <ID>] "{" {VarDecl} {MethodDecl} "}"
//
  static final public void ClassDecl() throws ParseException {
    jj_consume_token(7);
    jj_consume_token(ID);
    switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
    case 8:
      jj_consume_token(8);
      jj_consume_token(ID);
      break;
    default:
      jj_la1[1] = jj_gen;
      ;
    }
    jj_consume_token(53);
    label_2:
    while (true) {
      switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
      case 12:
      case 13:
      case ID:
      case 55:
        ;
        break;
      default:
        jj_la1[2] = jj_gen;
        break label_2;
      }
      VarDecl();
    }
    label_3:
    while (true) {
      switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
      case 10:
        ;
        break;
      default:
        jj_la1[3] = jj_gen;
        break label_3;
      }
      MethodDecl();
    }
    jj_consume_token(54);
  }

// MethodDecl -> "public" ExtType <ID> "(" [Param {"," Param}] ")"
//                 "{" {VarDecl} {Stmt} "}"
//            |  "public" "static" "void" "main" "(" "String" "[" "]" <ID> ")"
//                 "{" {VarDecl} {Stmt} "}"
//
  static final public void MethodDecl() throws ParseException {
    jj_consume_token(10);
    m1();
  }

  static final public void m1() throws ParseException {
    switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
    case 11:
    case 12:
    case 13:
    case ID:
    case 55:
      ExtType();
      jj_consume_token(ID);
      jj_consume_token(49);
      switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
      case 12:
      case 13:
      case ID:
      case 55:
        Param();
        label_4:
        while (true) {
          switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
          case 47:
            ;
            break;
          default:
            jj_la1[4] = jj_gen;
            break label_4;
          }
          jj_consume_token(47);
          Param();
        }
        break;
      default:
        jj_la1[5] = jj_gen;
        ;
      }
      jj_consume_token(50);
      jj_consume_token(53);
      m2();
      break;
    case 9:
      jj_consume_token(9);
      jj_consume_token(11);
      jj_consume_token(20);
      jj_consume_token(49);
      jj_consume_token(21);
      jj_consume_token(51);
      jj_consume_token(52);
      jj_consume_token(ID);
      jj_consume_token(50);
      jj_consume_token(53);
      m2();
      break;
    default:
      jj_la1[6] = jj_gen;
      jj_consume_token(-1);
      throw new ParseException();
    }
  }

  static final public void m2() throws ParseException {
    label_5:
    while (true) {
      if (jj_2_1(2)) {
        ;
      } else {
        break label_5;
      }
      VarDecl();
    }
    label_6:
    while (true) {
      if (jj_2_2(2)) {
        ;
      } else {
        break label_6;
      }
      Stmt();
    }
    jj_consume_token(54);
  }

// Param -> Type <ID>
//
  static final public void Param() throws ParseException {
    Type();
    jj_consume_token(ID);
  }

// VarDecl -> Type <ID> ["=" InitExpr] ";"
//
  static final public void VarDecl() throws ParseException {
    Type();
    jj_consume_token(ID);
    switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
    case 45:
      jj_consume_token(45);
      InitExpr();
      break;
    default:
      jj_la1[7] = jj_gen;
      ;
    }
    jj_consume_token(46);
  }

// ExtType -> Type | "void"
//
  static final public void ExtType() throws ParseException {
    switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
    case 12:
    case 13:
    case ID:
    case 55:
      Type();
      break;
    case 11:
      jj_consume_token(11);
      break;
    default:
      jj_la1[8] = jj_gen;
      jj_consume_token(-1);
      throw new ParseException();
    }
  }

// Type -> BasicType
//      |  BasicType "[" "]"
//      |  <ID>
//
  static final public void Type() throws ParseException {
    switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
    case 12:
    case 13:
    case 55:
      BasicType();
      switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
      case 51:
        jj_consume_token(51);
        jj_consume_token(52);
        break;
      default:
        jj_la1[9] = jj_gen;
        ;
      }
      break;
    case ID:
      jj_consume_token(ID);
      break;
    default:
      jj_la1[10] = jj_gen;
      jj_consume_token(-1);
      throw new ParseException();
    }
  }

// BasicType -> "int" | "boolean"
//
  static final public void BasicType() throws ParseException {
    switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
    case 12:
      jj_consume_token(12);
      break;
    case 55:
      jj_consume_token(55);
      break;
    case 13:
      jj_consume_token(13);
      break;
    default:
      jj_la1[11] = jj_gen;
      jj_consume_token(-1);
      throw new ParseException();
    }
  }

// Stmt -> "{" {Stmt} "}"
//      |  ExtId "(" [Args] ")" ";"
//      |  Lvalue "=" InitExpr ";"
//      |  "if" "(" Expr ")" Stmt ["else" Stmt]
//      |  "while" "(" Expr ")" Stmt
//      |  "System" "." "out" "." "println" "(" [PrintArg] ")" ";"
//      |  "return" [Expr] ";"
//
  static final public void Stmt() throws ParseException {
    switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
    case 53:
      jj_consume_token(53);
      label_7:
      while (true) {
        switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
        case 15:
        case 16:
        case 18:
        case 19:
        case 24:
        case ID:
        case 53:
          ;
          break;
        default:
          jj_la1[12] = jj_gen;
          break label_7;
        }
        Stmt();
      }
      jj_consume_token(54);
      break;
    case 15:
    case ID:
      ExtId();
      s1();
      break;
    case 16:
      jj_consume_token(16);
      jj_consume_token(49);
      Expr();
      jj_consume_token(50);
      Stmt();
      switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
      case 17:
        jj_consume_token(17);
        Stmt();
        break;
      default:
        jj_la1[13] = jj_gen;
        ;
      }
      break;
    case 18:
      jj_consume_token(18);
      jj_consume_token(49);
      Expr();
      jj_consume_token(50);
      Stmt();
      break;
    case 24:
      jj_consume_token(24);
      jj_consume_token(48);
      jj_consume_token(25);
      jj_consume_token(48);
      jj_consume_token(26);
      jj_consume_token(49);
      switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
      case 15:
      case 22:
      case 23:
      case INTLIT:
      case STRLIT:
      case ID:
      case 33:
      case 38:
      case 49:
        PrintArg();
        break;
      default:
        jj_la1[14] = jj_gen;
        ;
      }
      jj_consume_token(50);
      jj_consume_token(46);
      break;
    case 19:
      jj_consume_token(19);
      switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
      case 15:
      case 22:
      case 23:
      case INTLIT:
      case ID:
      case 33:
      case 38:
      case 49:
        Expr();
        break;
      default:
        jj_la1[15] = jj_gen;
        ;
      }
      jj_consume_token(46);
      break;
    default:
      jj_la1[16] = jj_gen;
      jj_consume_token(-1);
      throw new ParseException();
    }
  }

  static final public void s1() throws ParseException {
    switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
    case 49:
      jj_consume_token(49);
      switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
      case 15:
      case 22:
      case 23:
      case INTLIT:
      case ID:
      case 33:
      case 38:
      case 49:
        Args();
        break;
      default:
        jj_la1[17] = jj_gen;
        ;
      }
      jj_consume_token(50);
      jj_consume_token(46);
      break;
    case 45:
    case 51:
      switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
      case 51:
        jj_consume_token(51);
        Expr();
        jj_consume_token(52);
        break;
      default:
        jj_la1[18] = jj_gen;
        ;
      }
      jj_consume_token(45);
      InitExpr();
      jj_consume_token(46);
      break;
    default:
      jj_la1[19] = jj_gen;
      jj_consume_token(-1);
      throw new ParseException();
    }
  }

// Args -> Expr {"," Expr}
//
  static final public void Args() throws ParseException {
    Expr();
    label_8:
    while (true) {
      switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
      case 47:
        ;
        break;
      default:
        jj_la1[20] = jj_gen;
        break label_8;
      }
      jj_consume_token(47);
      Expr();
    }
  }

// PrintArg -> Expr | <STRLIT>
//
  static final public void PrintArg() throws ParseException {
    switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
    case 15:
    case 22:
    case 23:
    case INTLIT:
    case ID:
    case 33:
    case 38:
    case 49:
      Expr();
      break;
    case STRLIT:
      jj_consume_token(STRLIT);
      break;
    default:
      jj_la1[21] = jj_gen;
      jj_consume_token(-1);
      throw new ParseException();
    }
  }

// InitExpr -> "new" BasicType "[" <INTLIT> "]"
//          |  "new" <ID> "(" ")"
//          |  Expr
//
  static final public void InitExpr() throws ParseException {
    switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
    case 14:
      jj_consume_token(14);
      i();
      break;
    case 15:
    case 22:
    case 23:
    case INTLIT:
    case ID:
    case 33:
    case 38:
    case 49:
      Expr();
      break;
    default:
      jj_la1[22] = jj_gen;
      jj_consume_token(-1);
      throw new ParseException();
    }
  }

  static final public void i() throws ParseException {
    switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
    case 12:
    case 13:
    case 55:
      BasicType();
      jj_consume_token(51);
      jj_consume_token(INTLIT);
      jj_consume_token(52);
      break;
    case ID:
      jj_consume_token(ID);
      jj_consume_token(49);
      jj_consume_token(50);
      break;
    default:
      jj_la1[23] = jj_gen;
      jj_consume_token(-1);
      throw new ParseException();
    }
  }

// Expr -> Expr BinOp Expr
//      |  UnOp Expr
//      |  "(" Expr ")"
//      |  ExtId "(" [Args] ")"
//      |  Lvalue
//      |  Literal
//
  static final public void Expr() throws ParseException {
    switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
    case 33:
    case 38:
      UnOp();
      Expr();
      b1();
      break;
    case 49:
      jj_consume_token(49);
      Expr();
      jj_consume_token(50);
      b1();
      break;
    case 15:
    case ID:
      ExtId();
      e2();
      break;
    case 22:
    case 23:
    case INTLIT:
      Literal();
      b1();
      break;
    default:
      jj_la1[24] = jj_gen;
      jj_consume_token(-1);
      throw new ParseException();
    }
  }

  static final public void e2() throws ParseException {
    switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
    case 49:
      jj_consume_token(49);
      switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
      case 15:
      case 22:
      case 23:
      case INTLIT:
      case ID:
      case 33:
      case 38:
      case 49:
        Args();
        break;
      default:
        jj_la1[25] = jj_gen;
        ;
      }
      jj_consume_token(50);
      b1();
      break;
    default:
      jj_la1[27] = jj_gen;
      switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
      case 51:
        jj_consume_token(51);
        Expr();
        jj_consume_token(52);
        break;
      default:
        jj_la1[26] = jj_gen;
        ;
      }
      b1();
    }
  }

  static final public void b1() throws ParseException {
    switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
      BinOp();
      Expr();
      break;
    default:
      jj_la1[28] = jj_gen;

    }
  }

// Lvalue -> ExtId "[" Expr "]"
//        |  ExtId
  static final public void Lvalue() throws ParseException {
    ExtId();
    switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
    case 51:
      jj_consume_token(51);
      Expr();
      jj_consume_token(52);
      break;
    default:
      jj_la1[29] = jj_gen;
      ;
    }
  }

// ExtId -> ["this" "."] <ID> {"." <ID>}
//
  static final public void ExtId() throws ParseException {
    switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
    case 15:
      jj_consume_token(15);
      jj_consume_token(48);
      break;
    default:
      jj_la1[30] = jj_gen;
      ;
    }
    jj_consume_token(ID);
    label_9:
    while (true) {
      switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
      case 48:
        ;
        break;
      default:
        jj_la1[31] = jj_gen;
        break label_9;
      }
      jj_consume_token(48);
      jj_consume_token(ID);
    }
  }

// Literal -> <INTLIT> | "true" | "false"
//
  static final public void Literal() throws ParseException {
    switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
    case INTLIT:
      jj_consume_token(INTLIT);
      break;
    case 22:
      jj_consume_token(22);
      break;
    case 23:
      jj_consume_token(23);
      break;
    default:
      jj_la1[32] = jj_gen;
      jj_consume_token(-1);
      throw new ParseException();
    }
  }

// BinOp -> "+" | "-" | "*" | "/" | "&&" | "||"
//       |  "==" | "!=" | "<" | "<=" | ">" | ">="
//
  static final public void BinOp() throws ParseException {
    switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
    case 32:
      jj_consume_token(32);
      break;
    case 33:
      jj_consume_token(33);
      break;
    case 34:
      jj_consume_token(34);
      break;
    case 35:
      jj_consume_token(35);
      break;
    case 36:
      jj_consume_token(36);
      break;
    case 37:
      jj_consume_token(37);
      break;
    case 39:
      jj_consume_token(39);
      break;
    case 40:
      jj_consume_token(40);
      break;
    case 41:
      jj_consume_token(41);
      break;
    case 42:
      jj_consume_token(42);
      break;
    case 43:
      jj_consume_token(43);
      break;
    case 44:
      jj_consume_token(44);
      break;
    default:
      jj_la1[33] = jj_gen;
      jj_consume_token(-1);
      throw new ParseException();
    }
  }

// UnOp -> "-" | "!"
//
  static final public void UnOp() throws ParseException {
    switch ((jj_ntk==-1)?jj_ntk():jj_ntk) {
    case 33:
      jj_consume_token(33);
      break;
    case 38:
      jj_consume_token(38);
      break;
    default:
      jj_la1[34] = jj_gen;
      jj_consume_token(-1);
      throw new ParseException();
    }
  }

  static private boolean jj_2_1(int xla) {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    try { return !jj_3_1(); }
    catch(LookaheadSuccess ls) { return true; }
    finally { jj_save(0, xla); }
  }

  static private boolean jj_2_2(int xla) {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    try { return !jj_3_2(); }
    catch(LookaheadSuccess ls) { return true; }
    finally { jj_save(1, xla); }
  }

  static private boolean jj_3R_36() {
    Token xsp;
    xsp = jj_scanpos;
    if (jj_scan_token(33)) {
    jj_scanpos = xsp;
    if (jj_scan_token(38)) return true;
    }
    return false;
  }

  static private boolean jj_3R_29() {
    Token xsp;
    xsp = jj_scanpos;
    if (jj_3R_31()) jj_scanpos = xsp;
    if (jj_scan_token(45)) return true;
    return false;
  }

  static private boolean jj_3R_23() {
    if (jj_3R_30()) return true;
    return false;
  }

  static private boolean jj_3R_28() {
    if (jj_scan_token(49)) return true;
    return false;
  }

  static private boolean jj_3R_22() {
    Token xsp;
    xsp = jj_scanpos;
    if (jj_3R_28()) {
    jj_scanpos = xsp;
    if (jj_3R_29()) return true;
    }
    return false;
  }

  static private boolean jj_3R_35() {
    if (jj_3R_37()) return true;
    return false;
  }

  static private boolean jj_3R_34() {
    if (jj_3R_21()) return true;
    return false;
  }

  static private boolean jj_3R_27() {
    if (jj_scan_token(48)) return true;
    return false;
  }

  static private boolean jj_3R_10() {
    if (jj_3R_12()) return true;
    if (jj_scan_token(ID)) return true;
    return false;
  }

  static private boolean jj_3R_33() {
    if (jj_scan_token(49)) return true;
    return false;
  }

  static private boolean jj_3R_32() {
    if (jj_3R_36()) return true;
    return false;
  }

  static private boolean jj_3R_30() {
    Token xsp;
    xsp = jj_scanpos;
    if (jj_3R_32()) {
    jj_scanpos = xsp;
    if (jj_3R_33()) {
    jj_scanpos = xsp;
    if (jj_3R_34()) {
    jj_scanpos = xsp;
    if (jj_3R_35()) return true;
    }
    }
    }
    return false;
  }

  static private boolean jj_3R_18() {
    if (jj_scan_token(19)) return true;
    Token xsp;
    xsp = jj_scanpos;
    if (jj_3R_23()) jj_scanpos = xsp;
    if (jj_scan_token(46)) return true;
    return false;
  }

  static private boolean jj_3R_20() {
    if (jj_3R_11()) return true;
    return false;
  }

  static private boolean jj_3R_17() {
    if (jj_scan_token(24)) return true;
    if (jj_scan_token(48)) return true;
    return false;
  }

  static private boolean jj_3R_16() {
    if (jj_scan_token(18)) return true;
    if (jj_scan_token(49)) return true;
    return false;
  }

  static private boolean jj_3R_15() {
    if (jj_scan_token(16)) return true;
    if (jj_scan_token(49)) return true;
    return false;
  }

  static private boolean jj_3R_14() {
    if (jj_3R_21()) return true;
    if (jj_3R_22()) return true;
    return false;
  }

  static private boolean jj_3R_13() {
    if (jj_scan_token(53)) return true;
    Token xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_20()) { jj_scanpos = xsp; break; }
    }
    if (jj_scan_token(54)) return true;
    return false;
  }

  static private boolean jj_3R_11() {
    Token xsp;
    xsp = jj_scanpos;
    if (jj_3R_13()) {
    jj_scanpos = xsp;
    if (jj_3R_14()) {
    jj_scanpos = xsp;
    if (jj_3R_15()) {
    jj_scanpos = xsp;
    if (jj_3R_16()) {
    jj_scanpos = xsp;
    if (jj_3R_17()) {
    jj_scanpos = xsp;
    if (jj_3R_18()) return true;
    }
    }
    }
    }
    }
    return false;
  }

  static private boolean jj_3_1() {
    if (jj_3R_10()) return true;
    return false;
  }

  static private boolean jj_3R_37() {
    Token xsp;
    xsp = jj_scanpos;
    if (jj_scan_token(29)) {
    jj_scanpos = xsp;
    if (jj_scan_token(22)) {
    jj_scanpos = xsp;
    if (jj_scan_token(23)) return true;
    }
    }
    return false;
  }

  static private boolean jj_3R_26() {
    if (jj_scan_token(15)) return true;
    if (jj_scan_token(48)) return true;
    return false;
  }

  static private boolean jj_3R_25() {
    if (jj_scan_token(51)) return true;
    return false;
  }

  static private boolean jj_3R_21() {
    Token xsp;
    xsp = jj_scanpos;
    if (jj_3R_26()) jj_scanpos = xsp;
    if (jj_scan_token(ID)) return true;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_27()) { jj_scanpos = xsp; break; }
    }
    return false;
  }

  static private boolean jj_3R_24() {
    Token xsp;
    xsp = jj_scanpos;
    if (jj_scan_token(12)) {
    jj_scanpos = xsp;
    if (jj_scan_token(55)) {
    jj_scanpos = xsp;
    if (jj_scan_token(13)) return true;
    }
    }
    return false;
  }

  static private boolean jj_3R_12() {
    Token xsp;
    xsp = jj_scanpos;
    if (jj_3R_19()) {
    jj_scanpos = xsp;
    if (jj_scan_token(31)) return true;
    }
    return false;
  }

  static private boolean jj_3R_19() {
    if (jj_3R_24()) return true;
    Token xsp;
    xsp = jj_scanpos;
    if (jj_3R_25()) jj_scanpos = xsp;
    return false;
  }

  static private boolean jj_3_2() {
    if (jj_3R_11()) return true;
    return false;
  }

  static private boolean jj_3R_31() {
    if (jj_scan_token(51)) return true;
    return false;
  }

  static private boolean jj_initialized_once = false;
  /** Generated Token Manager. */
  static public mjLLGrammarTokenManager token_source;
  static SimpleCharStream jj_input_stream;
  /** Current token. */
  static public Token token;
  /** Next token. */
  static public Token jj_nt;
  static private int jj_ntk;
  static private Token jj_scanpos, jj_lastpos;
  static private int jj_la;
  static private int jj_gen;
  static final private int[] jj_la1 = new int[35];
  static private int[] jj_la1_0;
  static private int[] jj_la1_1;
  static {
      jj_la1_init_0();
      jj_la1_init_1();
   }
   private static void jj_la1_init_0() {
      jj_la1_0 = new int[] {0x80,0x100,0x80003000,0x400,0x0,0x80003000,0x80003a00,0x0,0x80003800,0x0,0x80003000,0x3000,0x810d8000,0x20000,0xe0c08000,0xa0c08000,0x810d8000,0xa0c08000,0x0,0x0,0x0,0xe0c08000,0xa0c0c000,0x80003000,0xa0c08000,0xa0c08000,0x0,0x0,0x0,0x0,0x8000,0x0,0x20c00000,0x0,0x0,};
   }
   private static void jj_la1_init_1() {
      jj_la1_1 = new int[] {0x0,0x0,0x800000,0x0,0x8000,0x800000,0x800000,0x2000,0x800000,0x80000,0x800000,0x800000,0x200000,0x0,0x20042,0x20042,0x200000,0x20042,0x80000,0xa2000,0x8000,0x20042,0x20042,0x800000,0x20042,0x20042,0x80000,0x20000,0x1fbf,0x80000,0x0,0x10000,0x0,0x1fbf,0x42,};
   }
  static final private JJCalls[] jj_2_rtns = new JJCalls[2];
  static private boolean jj_rescan = false;
  static private int jj_gc = 0;

  /** Constructor with InputStream. */
  public mjLLGrammar(java.io.InputStream stream) {
     this(stream, null);
  }
  /** Constructor with InputStream and supplied encoding */
  public mjLLGrammar(java.io.InputStream stream, String encoding) {
    if (jj_initialized_once) {
      System.out.println("ERROR: Second call to constructor of static parser.  ");
      System.out.println("       You must either use ReInit() or set the JavaCC option STATIC to false");
      System.out.println("       during parser generation.");
      throw new Error();
    }
    jj_initialized_once = true;
    try { jj_input_stream = new SimpleCharStream(stream, encoding, 1, 1); } catch(java.io.UnsupportedEncodingException e) { throw new RuntimeException(e); }
    token_source = new mjLLGrammarTokenManager(jj_input_stream);
    token = new Token();
    jj_ntk = -1;
    jj_gen = 0;
    for (int i = 0; i < 35; i++) jj_la1[i] = -1;
    for (int i = 0; i < jj_2_rtns.length; i++) jj_2_rtns[i] = new JJCalls();
  }

  /** Reinitialise. */
  static public void ReInit(java.io.InputStream stream) {
     ReInit(stream, null);
  }
  /** Reinitialise. */
  static public void ReInit(java.io.InputStream stream, String encoding) {
    try { jj_input_stream.ReInit(stream, encoding, 1, 1); } catch(java.io.UnsupportedEncodingException e) { throw new RuntimeException(e); }
    token_source.ReInit(jj_input_stream);
    token = new Token();
    jj_ntk = -1;
    jj_gen = 0;
    for (int i = 0; i < 35; i++) jj_la1[i] = -1;
    for (int i = 0; i < jj_2_rtns.length; i++) jj_2_rtns[i] = new JJCalls();
  }

  /** Constructor. */
  public mjLLGrammar(java.io.Reader stream) {
    if (jj_initialized_once) {
      System.out.println("ERROR: Second call to constructor of static parser. ");
      System.out.println("       You must either use ReInit() or set the JavaCC option STATIC to false");
      System.out.println("       during parser generation.");
      throw new Error();
    }
    jj_initialized_once = true;
    jj_input_stream = new SimpleCharStream(stream, 1, 1);
    token_source = new mjLLGrammarTokenManager(jj_input_stream);
    token = new Token();
    jj_ntk = -1;
    jj_gen = 0;
    for (int i = 0; i < 35; i++) jj_la1[i] = -1;
    for (int i = 0; i < jj_2_rtns.length; i++) jj_2_rtns[i] = new JJCalls();
  }

  /** Reinitialise. */
  static public void ReInit(java.io.Reader stream) {
    jj_input_stream.ReInit(stream, 1, 1);
    token_source.ReInit(jj_input_stream);
    token = new Token();
    jj_ntk = -1;
    jj_gen = 0;
    for (int i = 0; i < 35; i++) jj_la1[i] = -1;
    for (int i = 0; i < jj_2_rtns.length; i++) jj_2_rtns[i] = new JJCalls();
  }

  /** Constructor with generated Token Manager. */
  public mjLLGrammar(mjLLGrammarTokenManager tm) {
    if (jj_initialized_once) {
      System.out.println("ERROR: Second call to constructor of static parser. ");
      System.out.println("       You must either use ReInit() or set the JavaCC option STATIC to false");
      System.out.println("       during parser generation.");
      throw new Error();
    }
    jj_initialized_once = true;
    token_source = tm;
    token = new Token();
    jj_ntk = -1;
    jj_gen = 0;
    for (int i = 0; i < 35; i++) jj_la1[i] = -1;
    for (int i = 0; i < jj_2_rtns.length; i++) jj_2_rtns[i] = new JJCalls();
  }

  /** Reinitialise. */
  public void ReInit(mjLLGrammarTokenManager tm) {
    token_source = tm;
    token = new Token();
    jj_ntk = -1;
    jj_gen = 0;
    for (int i = 0; i < 35; i++) jj_la1[i] = -1;
    for (int i = 0; i < jj_2_rtns.length; i++) jj_2_rtns[i] = new JJCalls();
  }

  static private Token jj_consume_token(int kind) throws ParseException {
    Token oldToken;
    if ((oldToken = token).next != null) token = token.next;
    else token = token.next = token_source.getNextToken();
    jj_ntk = -1;
    if (token.kind == kind) {
      jj_gen++;
      if (++jj_gc > 100) {
        jj_gc = 0;
        for (int i = 0; i < jj_2_rtns.length; i++) {
          JJCalls c = jj_2_rtns[i];
          while (c != null) {
            if (c.gen < jj_gen) c.first = null;
            c = c.next;
          }
        }
      }
      return token;
    }
    token = oldToken;
    jj_kind = kind;
    throw generateParseException();
  }

  static private final class LookaheadSuccess extends java.lang.Error { }
  static final private LookaheadSuccess jj_ls = new LookaheadSuccess();
  static private boolean jj_scan_token(int kind) {
    if (jj_scanpos == jj_lastpos) {
      jj_la--;
      if (jj_scanpos.next == null) {
        jj_lastpos = jj_scanpos = jj_scanpos.next = token_source.getNextToken();
      } else {
        jj_lastpos = jj_scanpos = jj_scanpos.next;
      }
    } else {
      jj_scanpos = jj_scanpos.next;
    }
    if (jj_rescan) {
      int i = 0; Token tok = token;
      while (tok != null && tok != jj_scanpos) { i++; tok = tok.next; }
      if (tok != null) jj_add_error_token(kind, i);
    }
    if (jj_scanpos.kind != kind) return true;
    if (jj_la == 0 && jj_scanpos == jj_lastpos) throw jj_ls;
    return false;
  }


/** Get the next Token. */
  static final public Token getNextToken() {
    if (token.next != null) token = token.next;
    else token = token.next = token_source.getNextToken();
    jj_ntk = -1;
    jj_gen++;
    return token;
  }

/** Get the specific Token. */
  static final public Token getToken(int index) {
    Token t = token;
    for (int i = 0; i < index; i++) {
      if (t.next != null) t = t.next;
      else t = t.next = token_source.getNextToken();
    }
    return t;
  }

  static private int jj_ntk() {
    if ((jj_nt=token.next) == null)
      return (jj_ntk = (token.next=token_source.getNextToken()).kind);
    else
      return (jj_ntk = jj_nt.kind);
  }

  static private java.util.List<int[]> jj_expentries = new java.util.ArrayList<int[]>();
  static private int[] jj_expentry;
  static private int jj_kind = -1;
  static private int[] jj_lasttokens = new int[100];
  static private int jj_endpos;

  static private void jj_add_error_token(int kind, int pos) {
    if (pos >= 100) return;
    if (pos == jj_endpos + 1) {
      jj_lasttokens[jj_endpos++] = kind;
    } else if (jj_endpos != 0) {
      jj_expentry = new int[jj_endpos];
      for (int i = 0; i < jj_endpos; i++) {
        jj_expentry[i] = jj_lasttokens[i];
      }
      boolean exists = false;
      for (java.util.Iterator<?> it = jj_expentries.iterator(); it.hasNext();) {
        exists = true;
        int[] oldentry = (int[])(it.next());
        if (oldentry.length == jj_expentry.length) {
          for (int i = 0; i < jj_expentry.length; i++) {
            if (oldentry[i] != jj_expentry[i]) {
              exists = false;
              break;
            }
          }
          if (exists) break;
        }
      }
      if (!exists) jj_expentries.add(jj_expentry);
      if (pos != 0) jj_lasttokens[(jj_endpos = pos) - 1] = kind;
    }
  }

  /** Generate ParseException. */
  static public ParseException generateParseException() {
    jj_expentries.clear();
    boolean[] la1tokens = new boolean[56];
    if (jj_kind >= 0) {
      la1tokens[jj_kind] = true;
      jj_kind = -1;
    }
    for (int i = 0; i < 35; i++) {
      if (jj_la1[i] == jj_gen) {
        for (int j = 0; j < 32; j++) {
          if ((jj_la1_0[i] & (1<<j)) != 0) {
            la1tokens[j] = true;
          }
          if ((jj_la1_1[i] & (1<<j)) != 0) {
            la1tokens[32+j] = true;
          }
        }
      }
    }
    for (int i = 0; i < 56; i++) {
      if (la1tokens[i]) {
        jj_expentry = new int[1];
        jj_expentry[0] = i;
        jj_expentries.add(jj_expentry);
      }
    }
    jj_endpos = 0;
    jj_rescan_token();
    jj_add_error_token(0, 0);
    int[][] exptokseq = new int[jj_expentries.size()][];
    for (int i = 0; i < jj_expentries.size(); i++) {
      exptokseq[i] = jj_expentries.get(i);
    }
    return new ParseException(token, exptokseq, tokenImage);
  }

  /** Enable tracing. */
  static final public void enable_tracing() {
  }

  /** Disable tracing. */
  static final public void disable_tracing() {
  }

  static private void jj_rescan_token() {
    jj_rescan = true;
    for (int i = 0; i < 2; i++) {
    try {
      JJCalls p = jj_2_rtns[i];
      do {
        if (p.gen > jj_gen) {
          jj_la = p.arg; jj_lastpos = jj_scanpos = p.first;
          switch (i) {
            case 0: jj_3_1(); break;
            case 1: jj_3_2(); break;
          }
        }
        p = p.next;
      } while (p != null);
      } catch(LookaheadSuccess ls) { }
    }
    jj_rescan = false;
  }

  static private void jj_save(int index, int xla) {
    JJCalls p = jj_2_rtns[index];
    while (p.gen > jj_gen) {
      if (p.next == null) { p = p.next = new JJCalls(); break; }
      p = p.next;
    }
    p.gen = jj_gen + xla - jj_la; p.first = token; p.arg = xla;
  }

  static final class JJCalls {
    int gen;
    Token first;
    int arg;
    JJCalls next;
  }

}
