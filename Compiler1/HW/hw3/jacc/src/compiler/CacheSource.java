// Copyright (c) Mark P Jones, OGI School of Science & Engineering
// Subject to conditions of distribution and use; see LICENSE for details
// April 24 2004 01:01 AM
// 

package compiler;

/** A Source that caches the text of all lines that it reads.
 */
public class CacheSource extends Source {
    /** The original source for this Source object.
     */
    private Source source;

    /** A cache of the lines held in this source.
     */
    private String[] cache;

    /** Records the number of lines in the cache.
     */
    private int used;

    /** Construct a new caching source.
     */
    public CacheSource(Handler handler, Source source) {
        super(handler);
        this.source = source;
        this.cache  = null;
        this.used   = 0;
    }

    /** Return a printable description of this source.
     */
    public String describe() {
        return source.describe();
    }

    /** Read the next line from the input stream.
     */
    public String readLine() {
        String line = source.readLine();
        if (line!=null) {                      // Store text in the cache
            if (cache==null) {                 // ... which could be empty
                cache = new String[10];
            } else if (used>=cache.length) {   // ... or might be too small
                String newCache[] = new String[2*cache.length];
                for (int i=0; i<used; i++) {
                    newCache[i] = cache[i];
                }
                cache = newCache;
            }
            cache[used++] = line;              // Now we can save the line!
        }
        return line;
    }

    /** Return the current line number.
     */
    public int getLineNo() {
        return source.getLineNo();
    }

    /** Return the text of a specific line, if it is available.  If
     *  the requested source line has not been read yet, then a null
     *  is returned.
     */
    public String getLine(int lineNo) {
        return (cache==null || lineNo<=0 || lineNo>used)
                 ? null : cache[lineNo-1];
    }

    /** Close the input stream and any associated resources.
     */
    public void close() {
        source.close();
        this.cache = null;
    }
}
