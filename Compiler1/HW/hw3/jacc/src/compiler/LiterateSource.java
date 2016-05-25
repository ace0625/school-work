// Copyright (c) Mark P Jones, OGI School of Science & Engineering
// Subject to conditions of distribution and use; see LICENSE for details
// April 24 2004 01:01 AM
// 

package compiler;

/** A wrapper for sources that adds support for Bird-track style literate
 *  programming; the "inverted comment convention".
 */
public class LiterateSource extends Source {
    private Source  source;
    private boolean strict;

    /** Construct a literate source by wrapping an existing source.
     *
     *  @param handler   The error handler for this LiterateSource.
     *  @param strict    A true value indicates that strict checking for
     *                   the rules of literate scripts will be used, and
     *                   that warnings will be generated for incorrect
     *                   usage.  Such errors occur when a comment line
     *                   appears next to a code line with no intervening
     *                   blank line, or when no code lines are found in
     *                   the given input file.
     *  @param source    The source that will be wrapped.
     */
    public LiterateSource(Handler handler, boolean strict, Source source) {
        super(handler);
        this.source = source;
        this.strict = strict;
    }

    /** A specialized constructor that forces the construction of a strict
     *  LiterateSource.
     */
    public LiterateSource(Handler handler, Source source) {
        this(handler, true, source);
    }

    /** Return a description of the source as a String.  This method just
     *  returns the description of the source for this LiterateSource.
     */
    public String describe() {
        return source.describe();
    }

    private static final int BLANK   = 0;
    private static final int COMMENT = 1;
    private static final int CODE    = 2;
    private int  lines = 0;
    private int  last  = BLANK;
    private char tag   = '>';

    /** Read the next line from the input stream.
     *
     *  @return The next line, or null at the end of the input stream.
     */
    public String readLine() {
        String line = source.readLine();
        if (line==null) {
            if (strict && lines==0) {
                // TODO: finish this off!
                // complain "No lines read; perhaps you forgot the '>'s?"
            }
            return null;
        } else if (line.length()>0 && line.charAt(0)==tag) {
            if (strict && last==COMMENT) {
                // TODO: finish this off!
                // complain "Program line follows comment line"
            }
            last = CODE;
            lines++;
            return " " + line.substring(1);
        } else {
            for (int i=line.length(); 0<i--; ) {
                if (!Character.isWhitespace(line.charAt(i))) {
                    if (strict && last==COMMENT) {
                        // TODO: finish this off!
                        // complain "Comment line follows program line"
                    }
                    last = COMMENT;
                    return "";
                }
            }
            last = BLANK;
            return "";
        }
    }

    /** Return the current line number.
     */
    public int getLineNo() {
        return source.getLineNo();
    }

    /** Return the text of a specific line, given its line number.
     */
    public String getLine(int lineNo) {
        return source.getLine(lineNo);
    }

    /** Close the input stream and any associated resources.  This
     *  method just closes the source of this LiterateSource.
     */
    public void close() {
        source.close();
    }
}
