package ast;
import compiler.Position;

/** Abstract syntax for logical not expressions (!).
 */
public class LNot extends UnExpr {

    /** Default constructor.
     */
    public LNot(Position pos, Expr exp) {
        super(pos, exp);
    }

    /** Return a string that provides a simple description of this
     *  particular type of operator node.
     */
    String label() { return "LNot"; }

    /** Generate a pretty-printed description of this expression
     *  using the concrete syntax of the mini programming language.
     */
    public void print(TextOutput out) { unary(out, "!"); }
}
