// Copyright (c) Mark P Jones, OGI School of Science & Engineering
// Subject to conditions of distribution and use; see LICENSE for details
// April 24 2004 01:01 AM
// 

package compiler;

/** A wrapper for sources that adds support for a history of recent input.
 */
public class HistorySource extends Source {
    /** The underlying source from which this HistorySource
     *  obtains its input.
     */
    private Source source;

    /** A cyclic buffer that is used to record recently entered lines.
     */
    private String[] history;

    /** Construct a history source by wrapping an existing source.
     *
     *  @param handler   The error handler for this LiterateSource.
     *  @param histSize  Specifies the number of most recently returned
     *                   lines that are to be buffered.  We assume that
     *                   histSize > 0.
     *  @param source    The source that will be wrapped.
     */
    public HistorySource(Handler handler, int histSize, Source source) {
        super(handler);
        this.source  = source;
        this.history = (histSize>0) ? new String[histSize] : null;
    }

    /** Return a description of the source as a String.  This method just
     *  returns the description of the source for this LiterateSource.
     */
    public String describe() {
        return source.describe();
    }

    /** Read the next line from the input stream.
     *
     *  @return The next line, or null at the end of the input stream.
     */
    public String readLine() {
        String line = source.readLine();
        if (history!=null) {
            int histNo      = source.getLineNo() % history.length;
            history[histNo] = line;
        }
        return line;
    }

    /** Return the current line number.
     */
    public int getLineNo() {
        return source.getLineNo();
    }

    /** Return the text of a specific line, given its line number.
     *  This implementation uses a cyclic history buffer to record
     *  recently entered lines.  Earlier input is discarded.
     */
    public String getLine(int lineNo) {
        if (history!=null && lineNo>0) {
            int lineNumber = source.getLineNo();
            if (lineNo>lineNumber-history.length && lineNo<=lineNumber) {
                return history[lineNo % history.length];
            }
        }
        return source.getLine(lineNo);
    }

    /** Close the input stream and any associated resources.  This
     *  method just closes the source of this HistorySource and
     *  nulls out the history buffer.
     */
    public void close() {
        source.close();
        this.history = null;
    }
}
