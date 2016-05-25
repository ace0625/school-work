//----------------------------------------------------------------------
// A starting version of miniJava (W15) lexer.
//
// (For CS321 Winter 2015)
//----------------------------------------------------------------------
//
//
import java.io.FileReader;
import java.util.HashMap;

public class mjLexer implements mjTokenConstants {

  static class LexError extends Exception {
    public LexError(int line, int column, String msg) { 
      super("at (" + line + "," + column + ") " + msg); 
    }
  }

  // Token object
  //
  static class Token {
    int code; 		// token code
    String lexeme;      // lexeme string
    int line;	   	// line number of token's first char
    int column;    	// column number of token's first char
    
    public Token(int code, String lexeme, int line, int column) {
      this.code=code; this.lexeme=lexeme;
      this.line=line; this.column=column; 
    }
    public String toString() {
      return "(" + line + "," + column + ") " + code + " " + lexeme;
    }
  }

  // The main method
  //
  public static void main(String [] args) {
    try {
      if (args.length == 1) {
        Token tkn;
	int tknCnt = 0;
        reader = new FileReader(args[0]);
        while ((tkn = nextToken()) != null) { 
      	System.out.print("(" + tkn.line + "," + tkn.column + ")\t");
	switch(tkn.code) {
	case ID:     
	  System.out.println("ID(" + tkn.lexeme + ")"); 
	  break;
	case INTLIT: 

	  // ... code needed ...

	case DBLLIT: 

	  // ... code needed ...

	case STRLIT: 

	  // ... code needed ...

	default:     
	  System.out.println(tkn.lexeme);
	} 
	tknCnt++;
	}
        System.out.println("Total: " + tknCnt + " tokens");
        reader.close();
      } else {
        System.err.println("Need a file name as command-line argument.");
      } 
    } catch (LexError e) {
      System.err.println(e);
    } catch (Exception e) {
      System.err.println(e);
    }
  }

  // Return the next token
  //
  public static Token nextToken() throws Exception {

    // ... code needed ...

  }

  // Utility routines
  //
  private static boolean isLetter(int c) {
    return (('A' <= c) && (c <= 'Z')
	    || ('a' <= c) && (c <= 'z'));
  }

  private static boolean isDigit(int c) {
    return ('0' <= c) && (c <= '9');
  }

  private static boolean isOctal(int c) {
    return ('0' <= c) && (c <= '7');
  }

  private static boolean isHex(int c) {
    return ('0' <= c) && (c <= '9')
            || ('A' <= c) && (c <= 'F')
	    || ('a' <= c) && (c <= 'f');
  }

}
