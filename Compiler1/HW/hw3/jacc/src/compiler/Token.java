// Copyright (c) Mark P Jones, OGI School of Science & Engineering
// Subject to conditions of distribution and use; see LICENSE for details
// April 24 2004 01:01 AM
// 

package compiler;

/** Provides a representation for the Tokens that are used in a
 *  TokenArrayLexer.
 */
public class Token {
    private int    code;
    private String text;

    public Token(int code, String text) {
        this.code = code;
        this.text = text;
    }

    public Token(int code) {
        this(code,null);
    }

    public int getCode() {
        return code;
    }

    public String getText() {
        return text;
    }
}
