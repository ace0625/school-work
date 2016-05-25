// Copyright (c) Mark P Jones, OGI School of Science & Engineering
// Subject to conditions of distribution and use; see LICENSE for details
// April 24 2004 01:01 AM
// 

package compiler;

/** A position within an array of tokens.  Used to illustrate alternative
 *  implementations for the Position type.
 */
public class TokenArrayPosition extends Position {
    private int pos;
    public TokenArrayPosition(int pos) {
        this.pos = pos;
    }

    /** Obtain a printable description of the token position.
     */
    public String describe() {
        return "Token #" + pos;
    }

    /** Copy a token position.
     */
    public Position copy() {
        return new TokenArrayPosition(pos);
    }
}
