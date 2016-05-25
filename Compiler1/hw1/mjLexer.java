
// CS321 Assignment1 revised version
// January 28, 2015
// Hyunchan Kim


import java.io.FileReader;
import java.io.PushbackReader;


public class mjLexer implements mjTokenConstants {
  //Bookkeeping numbers
  static int currLine, currColumn, beginLine, beginColumn;

  static FileReader reader = null;
  static PushbackReader pbReader = null;

  // Lexer Error
  static class LexError extends Exception {
    public LexError(int line, int column, String msg) { 
      super("at (" + line + "," + column + ") " + msg); 
    }
  }

  // Token object
  //
  static class Token {
    int code; 		      // token code
    String lexeme;      // lexeme string
    int line;	   	      // line number of token's first char
    int column;    	    // column number of token's first char
    
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
        currLine = 1;
        currColumn = 0;
        reader = new FileReader(args[0]);
        pbReader = new PushbackReader(reader);
        
        while ((tkn = nextToken()) != null) { 
      	  System.out.print("(" + tkn.line + "," + tkn.column + ")\t");
	      switch(tkn.code) {
        	case ID:     
	          System.out.println("ID(" + tkn.lexeme + ")"); 
	          break;
	        case INTLIT:
	          int val = Integer.parseInt(tkn.lexeme);
	          System.out.println("INTLIT(" + val + ")");
		      break; 
			case DBLLIT: 
	           double dbl = Double.parseDouble(tkn.lexeme);
       		   System.out.println("DBLLIT(" + dbl + ")");
	           break; 
			case STRLIT: 
		       String lexeme = tkn.lexeme.substring(1, tkn.lexeme.length()-1);
		       System.out.println("STRLIT(\"" + lexeme + "\")");
		       break; 
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

  // Returns the next character from the input stream
  //
  static int nextChar() throws Exception {
    	int c = pbReader.read();
        if (c =='\n') {
            currLine++;
            currColumn = 0;
          } else {
            currColumn++;
          }
          return c;
  }


  // Peeks at the next character from the input stream. 
  //
  static int peek() throws Exception {
    int c = pbReader.read();
    pbReader.unread(c);
    return c;
  }
  
  // Moves the character forward if until the end delimiter of a multi-line is seen
  //
  static int skipmlcomments() throws Exception  {
		int c = nextChar();
		int next = peek();
		while(true) { 
			c = nextChar();
			next = peek();
      		if(c == -1 || next == -1) {
    			throw new LexError(beginLine, beginColumn, "Unterminated Multi-line Comment");
    		}
			if (c == '*' && next == '/') {
				c = nextChar();
				return peek();
			}
		}
  }

  
 
  // Return the next token
  //
  public static Token nextToken() throws Exception {
    StringBuilder buffer = new StringBuilder();
    int c = nextChar();
    int key = -1;   

    for(;;) {
      beginLine = currLine;
      beginColumn = currColumn;   
      
      switch(c) {
        case -1:
          return null;

        // Skip whitespace
        case ' ':
        case '\t':
        case '\n':
        case '\r':
          c = nextChar();
          continue;
        
        // Skip single=line comments
        case '/':     
        	if(peek() == '/') {
        		c = nextChar();
        		c = nextChar();
        		while(c != '\n') {
        			c = nextChar();
        		}
        		continue;
        	}
        	else if(peek() == '*') {
        		c = skipmlcomments();
        		continue;
        	} 
        	else {
    	    	buffer.append((char)c);
    	    	return new Token(c, buffer.toString(), beginLine, beginColumn);
            } 
        	
        	
        // Grab strings if delimiter is found
        case '"':
        	buffer.append((char)c);
        	do {
        		c = nextChar();
        		if(c == -1) {
        			throw new LexError(beginLine, beginColumn, "Unterminated String: " + buffer.toString());
        		}
        		buffer.append((char) c);
        	} while(c != '"');
        	return new Token(4, buffer.toString(), beginLine, beginColumn);
        
        // Check if floating point
        case '.':
        	char t = (char)peek();
    	    if(!isDigit(peek())){
    	      buffer.append((char)c);
    	      return new Token(c, buffer.toString(), beginLine, beginColumn);
    	    }
    	    
        default:          
             //Check if INTLIT
             if(isDigit(c) || c == '.')  {
	        	   int c2 = peek();
	         	   buffer.append((char) c);	         	  
	         	   
	         	   // An Octal
	         	   if(c == '0' && (c2 != 'x' && c2 != 'X' && c2 != '.')) {
	         		   
	         		   while(isDigit(peek())) {
	         			  c = nextChar();
		      	          buffer.append((char) c);   
	         		   }
	         		   
	         		   String strDec = new String(octToDec(buffer.toString()));
	         		   checkIntOverflow(buffer.toString(), currColumn);
	         		   return new Token(2, strDec, beginLine, beginColumn);
	         	   }
             	         	   
	               // Hex
	         	   else if(c == '0' && (peek() == 'x' || peek() == 'X')) {
	         		   c = nextChar(); 
	         		   buffer.append((char) c); // append the x flag
	         		   
	         		   while(isHex(peek())) {
	         		     c = nextChar();
	      	             buffer.append((char) c); 
	         		   }
	         		   
	         		   String strDec = new String(hexToDec(buffer.toString()));
	         		   checkIntOverflow(strDec, currColumn);
	         		   return new Token(2, strDec, beginLine, beginColumn);
	         	   }
	         	   
	               // decimal
	         	   else {
	    	          while(isDigit(peek()) || peek() == '.') {
	    	           c = nextChar();
	    	           buffer.append((char) c); 
	    	         }   
	    	         // check if float
	    	         checkIntOverflow(buffer.toString(), currColumn);
	    	         if(buffer.toString().contains(".")) {
	    	           return new Token(3, buffer.toString(), beginLine, beginColumn); 
	    	         } else {    
	    	           return new Token(2, buffer.toString(), beginLine, beginColumn);
	    	         }
	               }
	           }
            }           
           
           // Check if operators or delimiters
       	   if(isOperator(c)) {
             key = isTwoCharOp(c, peek());
             if(key != -1) {
               buffer.append((char) c);
               c = nextChar();
               buffer.append((char) c);
               return new Token(key, buffer.toString(), beginLine, beginColumn);
             }
             buffer.append((char) c);
             return new Token(c, buffer.toString(), beginLine, beginColumn);
          }
                   
          if(isLetter(c)) {
           buffer.append((char) c);
           while ( (isLetter(peek()) || isDigit(peek())) ){
           	c = nextChar();
           	buffer.append((char) c); 
           }
           
           // Check if reserved word
           key = isReservedWord(buffer.toString());
           if(key != -1) {
             return new Token(key, buffer.toString(), beginLine, beginColumn);
           } else { //An ID
           	return new Token(1, buffer.toString(), beginLine, beginColumn);
           }
          } 
      throw new LexError(currLine, currColumn, "Illegal char: " + (char)c);
    }
  }
  
  
  // Utility routines
  //
  
  // Checks the integer string found by lexer for overflow
  // Throws an int overflow exception if integer literal value
  // is less than zero or bigger than 2^31 - 1
  //
  static boolean checkIntOverflow(String intLiteral, int currColumn) throws LexError {
	  try {
		  if(intLiteral.contains("."))  {
			  double dbl = Double.parseDouble(intLiteral); 
		  }
		  else {
			  int decimal = Integer.parseInt(intLiteral);
		  }
		  return true;
	  }
	  catch(NumberFormatException e) {
		  throw new LexError(currLine, currColumn, "Integer Overflow: " + intLiteral);
	  }
  }
  
  // Converts a string representing a hex number (with 0x prefix) to a decimal int
  // Returns the string representing a decimal number
  //
  static String hexToDec(String strHex) throws LexError {
	  String hex = new String(strHex.substring(2).toUpperCase());
      try {
		  int decimal = Integer.parseInt(hex, 16);
		  return Integer.toString(decimal);
      } catch (NumberFormatException e) {
    	  throw new LexError(beginLine, beginColumn, "Invalid Hex:" + strHex);
      }
  }
  
  
  // Converts a string representing an octal number to a decimal int
  // Returns the string representing a decimal number
  //
  static String octToDec(String strOct) throws LexError {
	try {
	  int decimal = Integer.parseInt(strOct, 8);
	  return Integer.toString(decimal);
    } catch (NumberFormatException e) {
	  throw new LexError(beginLine, beginColumn, "Invalid Octal:" + strOct);
    }
  }
 
  // Check if the buffer StringBuilder is a reserved word
  // Returns the int key of reserved word if found
  // Returns -1 if buffer is not a recognized reserved word
  //
  static int isReservedWord(String buffer) {
    switch(buffer) {
      case "true":
        return 5;
      case "false":
        return 6;
      case "class":
        return 7;
      case "extends":
        return 8;
      case "static":
        return 9;
      case "public":
        return 10;
      case "void":
        return 11;
      case "main":
        return 12;
      case "int":
        return 13;
      case "double":
        return 14;
      case "String":
        return 15;
      case "boolean":
        return 16;
      case "new":
        return 17;
      case "this":
        return 18;
      case "if":
        return 19;
      case "else":
        return 20;
      case "System":
        return 21;
      case "out":
        return 22;
      case "println":
        return 23;
      case "while":
        return 24;
      case "return":
        return 25;
      default:
        return -1;
    }
  }


  // Check if c+c2 is a two-character operator 
  // Returns the int key of operator if found
  // Returns -1 if c+c2 is not a recognizable operator
  //
  static int isTwoCharOp(int c, int c2) {
    String op = "" + (char)c + (char)c2;

    switch(op) {
      case "==": 
        return 26;
      case "!=":
        return 27;
      case "<=":
        return 28;
      case ">=":
        return 29;
      case "&&": 
        return 30;
      case "||":
        return 31;
      default:
        return -1;
    }
  } 


  private static boolean isOperator(int c) throws Exception {
    switch(c) {
      case '+':
      case '-':
      case '*':
      case '/':
      case '|':
      case '!':
      case '=':
      case '>':
      case '<':
      case ';':
      case ',':
      case '.':
      case '(':
      case ')':
      case '{':
      case '}':
      case '[':
      case ']':
      case '&':
        return true;
      default:
        return false;
    }
  }
 
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