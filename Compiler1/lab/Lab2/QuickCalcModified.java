/** QuickCalc, the quick calculator program.
 *
 *  For CS 321, Languages and Compiler Design I, Week 2 Lab
 *
 *  Compile with: javac QuickCalc.java
 *  Run with:     java  QuickCalc
 *
 * -------------------------------------------------------------------------
 */
public class QuickCalc {

    // Lexical analysis ----------------------------------------------------

    static final char integer = 'N';
    static int token;
    static int tokval;
    static int c;

    static void initInput() {
        c = getChar();
        getToken();
    }

    static int getChar() {
        int c = 0;
        try {
            c = System.in.read();
        } catch (Exception e) {
            calcError("Error in input stream");
        }
        return c;
    }

    static void getToken() {
        while (Character.isWhitespace((char)c)) { // Skip whitespace
            c = getChar();
        }

        if (c<0) {                                // End of file?
            token = 0;
            return;
        }

        switch (c) {                              // Special tokens
            case '+' :
            case '-' :
            case '*' :
            case '/' :
            case '|' :
            case ';' :
            case '(' :
            case ')' : token = c;
                       c     = getChar();
                       return;

            case 'a' : c = getChar();
                       if (c=='b') {
                           c = getChar();
                           if (c=='s') {
                               c = getChar();
                               token = 'A';
                               return;
                           }
                       }
                       calcError("Error in abs token");

            default  : if (Character.isDigit((char)c)) {
                           int n = 0;
                           do {
                               n = 10*n + (c - '0');
                               c = getChar();
                           } while (Character.isDigit((char)c));
                           tokval = n;
                           token  = integer;
                           return;
                       }
        }
        calcError("Illegal character "+(char)c);
    }

    // Parser --------------------------------------------------------------

    static Expr expr() {                    // Expr = Term
        Expr e = term();                    //      | Expr '+' Term
                                            //      | Expr '-' Term
        for (;;) {
            if (token=='+') {
                getToken();
                e = new BinExpr('+',e,term());
            } else if (token=='-') {
                getToken();
                e = new BinExpr('-',e,term());
            } else {
                return e;
            }
        }
    }

    static Expr term() {                    // Term = Atom
        Expr t = atom();                    //      | Term '*' Atom
                                            //      | Term '/' Atom
        for (;;) {
            if (token=='*') {
                getToken();
                t = new BinExpr('*',t,atom());
            } else if (token=='/') {
                getToken();
                t = new BinExpr('/',t,atom());
            } else {
                return t;
            }
        }
    }

    static Expr atom() {                    // Atom = integer
        if (token==integer) {               //      | '(' Expr ')'
            int f = tokval;                 //      | '-' Atom
            getToken();                     //      | '|' Expr '|'
            return new IntExpr(f);          //      | abs '(' Expr ')'
        } else if (token=='(') {
            getToken();
            Expr e = expr();
            if (token==')') {
                getToken();
            } else {
                calcError("missing close paren");
            }
            return e;
        } else if (token=='A') {
            getToken();
            if (token=='(') {
                getToken();
                Expr e = expr();
                if (token==')') {
                    getToken();
                    return new Abs(e);
                }
            }
            calcError("syntax error in abs expression");
        } else if (token=='|') {
            getToken();
            Expr e = expr();
            if (token=='|') {
                getToken();
            } else {
                calcError("missing vertical bar");
            }
            return new Abs(e);
        } else if (token=='-') {
            getToken();
            return new Uminus(atom());
        } else {
            calcError("syntax error");
        }
        return null; /* not used */
    }

    // Error handling ------------------------------------------------------

    static void calcError(String msg) {
        System.err.println("ERROR: " + msg);
        System.exit(1);
    }

    // Driver --------------------------------------------------------------

    public static void main(String[] args) {
        System.out.println("Welcome to the quick calculator program!");
        initInput();
        for (;;) {
            Expr e = expr();
            System.out.println("Result = " + e.eval());

            if (token==';') {
                getToken();
            } else if (token!=0) {
                calcError("syntax error");
            } else {
                return;
            }
        }
    }
}

// Representation of expressions (Abstract Syntax Trees) ---------------

abstract class Expr {
    abstract int eval();
}

class IntExpr extends Expr {
    private int value;
    IntExpr(int value) {
        this.value = value;
    }

    int eval() {
        return value;
    }
}

class Uminus extends Expr {
    private Expr e;
    Uminus(Expr e) {
        this.e = e;
    }

    int eval() {
        return -e.eval();
    }
}

class Abs extends Expr {
    private Expr e;
    Abs(Expr e) {
        this.e = e;
    }

    int eval() {
        int val = e.eval();
        return (val>=0) ? val : (-val);
    }
}

class BinExpr extends Expr {
    private char op;
    private Expr left;
    private Expr right;

    BinExpr(char op, Expr left, Expr right) {
        this.op    = op;
        this.left  = left;
        this.right = right;
    }

    int eval() {
        int l = left.eval();
        int r = right.eval();
        switch (op) {
            case '+' : return l + r;
            case '-' : return l - r;
            case '*' : return l * r;
            case '/' : return l / r;
        }
        return 0; /* not used */
    }
}

// ---------------------------------------------------------------------
