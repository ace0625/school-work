// Copyright (c) Mark P Jones, OGI School of Science & Engineering
// Subject to conditions of distribution and use; see LICENSE for details
// April 24 2004 01:01 AM
// 

package compiler;

/** A diagnostic handler that counts diagnostics and then passes them
 *  on to another handler.  A collection of DelegatingHandlers
 *  can be used to track the number of errors that occurred in different
 *  phases, and then passing them to a shared handler that collects or
 *  reports on all diagnostics as a single unit.
 */
public class DelegatingHandler extends Handler {
    private Handler handler;

    /** Construct a delegating handler.
     */
    public DelegatingHandler(Handler handler) {
        this.handler = handler;
    }

    /** Respond to a diagnostic.
     */
    protected void respondTo(Diagnostic d) {
        handler.report(d);
    }
}
