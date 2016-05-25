// Copyright (c) Mark P Jones, OGI School of Science & Engineering
// Subject to conditions of distribution and use; see LICENSE for details
// April 24 2004 01:01 AM
// 

package compiler;

/** A lexical analyser that uses an array of Token objects to provide its
 *  input.  Used to illustrate alternative implementations of Lexer.
 */
public class TokenArrayLexer extends Lexer {
    private Token[] tokens;
    private int     count = 0;

    /** Construct a lexical analysis phase with a specified diagnostic
     *  handler.
     */
    public TokenArrayLexer(Handler handler, Token[] tokens) {
        super(handler);
        this.tokens = tokens;
    }

    /** Return the next token from the array.
     */
    public int nextToken() {
        if (tokens==null || count>=tokens.length) {
            lexemeText = null;
            return token = 0;
        } else {
            token      = tokens[count].getCode();
            lexemeText = tokens[count].getText();
            count++;
            return token;
        }
    }

    /** Return the position of the current token in the array.
     */
    public Position getPos() {
        return new TokenArrayPosition(count);
    }

    /** Close the token input stream by nulling out the token array.
     */
    public void close() {
        tokens = null;
    }
}
