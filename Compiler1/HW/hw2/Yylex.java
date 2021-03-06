/* The following code was generated by JFlex 1.4.3 on 2/2/16 8:46 PM */

//CS321
//Homework#2
//2/2/2016
//Hyunchan Kim


/**
 * This class is a scanner generated by 
 * <a href="http://www.jflex.de/">JFlex</a> 1.4.3
 * on 2/2/16 8:46 PM from the specification file
 * <tt>HighlightDates.jflex</tt>
 */
class Yylex {

  /** This character denotes the end of file */
  public static final int YYEOF = -1;

  /** initial size of the lookahead buffer */
  private static final int ZZ_BUFFERSIZE = 16384;

  /** lexical states */
  public static final int YYINITIAL = 0;

  /**
   * ZZ_LEXSTATE[l] is the state in the DFA for the lexical state l
   * ZZ_LEXSTATE[l+1] is the state in the DFA for the lexical state l
   *                  at the beginning of a line
   * l is of the form l = 2*k, k a non negative integer
   */
  private static final int ZZ_LEXSTATE[] = { 
     0, 0
  };

  /** 
   * Translates characters to character classes
   */
  private static final String ZZ_CMAP_PACKED = 
    "\11\0\1\0\1\2\1\0\1\0\1\1\22\0\1\46\13\0\1\47"+
    "\2\0\1\50\1\12\1\11\1\16\1\23\1\30\1\31\1\32\1\33"+
    "\1\33\1\32\7\0\1\24\2\0\1\44\1\0\1\13\3\0\1\3"+
    "\2\0\1\17\1\42\1\40\3\0\1\37\13\0\1\51\1\0\1\4"+
    "\1\15\1\20\1\45\1\14\1\13\1\34\1\21\1\26\1\3\1\0"+
    "\1\27\1\22\1\5\1\41\1\25\1\0\1\7\1\35\1\36\1\6"+
    "\1\43\2\0\1\10\3\0\1\52\uff82\0";

  /** 
   * Translates characters to character classes
   */
  private static final char [] ZZ_CMAP = zzUnpackCMap(ZZ_CMAP_PACKED);

  /** 
   * Translates DFA states to action switch labels.
   */
  private static final int [] ZZ_ACTION = zzUnpackAction();

  private static final String ZZ_ACTION_PACKED_0 =
    "\1\0\20\1\47\0\1\2\1\0\2\2\1\0\1\2"+
    "\1\0\1\2\4\0\1\2\42\0\1\2\1\0\2\2"+
    "\1\0\1\2\2\0\12\2\3\0\1\2\20\0\2\2"+
    "\27\0";

  private static int [] zzUnpackAction() {
    int [] result = new int[166];
    int offset = 0;
    offset = zzUnpackAction(ZZ_ACTION_PACKED_0, offset, result);
    return result;
  }

  private static int zzUnpackAction(String packed, int offset, int [] result) {
    int i = 0;       /* index in packed string  */
    int j = offset;  /* index in unpacked array */
    int l = packed.length();
    while (i < l) {
      int count = packed.charAt(i++);
      int value = packed.charAt(i++);
      do result[j++] = value; while (--count > 0);
    }
    return j;
  }


  /** 
   * Translates a state to a row index in the transition table
   */
  private static final int [] ZZ_ROWMAP = zzUnpackRowMap();

  private static final String ZZ_ROWMAP_PACKED_0 =
    "\0\0\0\53\0\126\0\201\0\254\0\327\0\u0102\0\u012d"+
    "\0\u0158\0\u0183\0\u01ae\0\u01d9\0\u0204\0\u022f\0\u025a\0\u0285"+
    "\0\u02b0\0\u02db\0\u0306\0\u0331\0\u035c\0\u0387\0\u03b2\0\u03dd"+
    "\0\u01d9\0\u0408\0\u0204\0\u0433\0\u045e\0\u0489\0\u04b4\0\u04df"+
    "\0\u050a\0\u0535\0\u0560\0\u058b\0\u05b6\0\u05e1\0\u060c\0\u0637"+
    "\0\u0662\0\u068d\0\u06b8\0\u06e3\0\u070e\0\u0739\0\u0764\0\u078f"+
    "\0\u07ba\0\u07e5\0\u0810\0\u083b\0\u0866\0\u0891\0\u08bc\0\u08e7"+
    "\0\u0912\0\u093d\0\u0968\0\u0993\0\u09be\0\u09e9\0\u09e9\0\53"+
    "\0\u0a14\0\u0a3f\0\u0a6a\0\u0a95\0\u0ac0\0\u0aeb\0\u0b16\0\u0b41"+
    "\0\u0b6c\0\u0b97\0\u0bc2\0\u0bed\0\u0c18\0\u0c43\0\u0c6e\0\u0c99"+
    "\0\u0cc4\0\u0cef\0\u0d1a\0\u0d45\0\u0d70\0\u0d9b\0\u0dc6\0\u0df1"+
    "\0\u0e1c\0\u0e47\0\u0e72\0\u0e9d\0\u0ec8\0\u0ef3\0\u0f1e\0\u0f49"+
    "\0\u0f74\0\u0f9f\0\u0fca\0\u0ff5\0\u1020\0\u104b\0\u1076\0\u10a1"+
    "\0\u10cc\0\u10f7\0\u1122\0\u114d\0\u1178\0\u11a3\0\u11ce\0\u11f9"+
    "\0\u1224\0\u124f\0\u127a\0\u12a5\0\u12d0\0\u12fb\0\u1326\0\u1351"+
    "\0\u137c\0\u13a7\0\u13d2\0\u13fd\0\u1428\0\u1453\0\u147e\0\u14a9"+
    "\0\u14d4\0\u14ff\0\u152a\0\u1555\0\u1580\0\u15ab\0\u15d6\0\u1601"+
    "\0\u162c\0\u1657\0\u1682\0\u16ad\0\u16d8\0\u1703\0\u172e\0\u1759"+
    "\0\u1784\0\u17af\0\u17da\0\u1805\0\u1830\0\u185b\0\u1886\0\u18b1"+
    "\0\u18dc\0\u1907\0\u1932\0\u195d\0\u1988\0\u1703\0\u172e\0\u19b3"+
    "\0\u19de\0\u1a09\0\u1a34\0\u1a5f\0\u1a8a\0\u1ab5";

  private static int [] zzUnpackRowMap() {
    int [] result = new int[166];
    int offset = 0;
    offset = zzUnpackRowMap(ZZ_ROWMAP_PACKED_0, offset, result);
    return result;
  }

  private static int zzUnpackRowMap(String packed, int offset, int [] result) {
    int i = 0;  /* index in packed string  */
    int j = offset;  /* index in unpacked array */
    int l = packed.length();
    while (i < l) {
      int high = packed.charAt(i++) << 16;
      result[j++] = high | packed.charAt(i++);
    }
    return j;
  }

  /** 
   * The transition table of the DFA
   */
  private static final int [] ZZ_TRANS = zzUnpackTrans();

  private static final String ZZ_TRANS_PACKED_0 =
    "\3\2\1\3\1\4\1\5\3\2\1\6\1\7\1\10"+
    "\2\2\1\11\1\12\2\2\1\12\1\13\1\4\3\2"+
    "\1\14\1\15\1\14\1\15\1\2\1\16\1\2\1\16"+
    "\2\17\1\5\1\2\1\20\1\21\5\2\57\0\1\22"+
    "\1\0\1\23\52\0\1\24\16\0\1\25\66\0\1\26"+
    "\12\0\1\27\1\30\6\0\1\31\1\32\3\0\1\33"+
    "\4\0\1\34\4\0\4\34\12\0\1\30\1\0\1\35"+
    "\13\0\1\33\4\0\1\36\4\0\1\33\4\0\1\31"+
    "\1\33\1\31\1\33\33\0\1\37\37\0\1\27\1\30"+
    "\6\0\1\34\1\40\3\0\1\34\4\0\1\34\4\0"+
    "\4\34\12\0\1\30\1\0\1\41\6\0\1\42\47\0"+
    "\1\27\1\30\6\0\1\43\1\40\33\0\1\30\1\0"+
    "\1\35\3\0\1\27\1\30\43\0\1\30\1\0\1\44"+
    "\3\0\1\27\1\30\43\0\1\30\1\0\1\35\16\0"+
    "\1\45\56\0\1\46\36\0\1\47\7\0\1\50\52\0"+
    "\1\50\43\0\1\51\52\0\1\52\21\0\1\53\57\0"+
    "\1\54\25\0\1\55\106\0\1\56\11\0\1\30\1\57"+
    "\1\60\1\61\5\0\1\62\3\0\1\63\2\0\1\63"+
    "\1\0\1\60\10\0\1\64\1\0\1\64\2\65\1\61"+
    "\1\0\2\66\10\0\1\57\1\60\1\61\5\0\1\62"+
    "\3\0\1\63\2\0\1\63\1\0\1\60\10\0\1\64"+
    "\1\0\1\64\2\65\1\61\1\0\2\66\6\0\1\67"+
    "\1\70\43\0\1\70\1\0\1\35\3\0\1\27\1\30"+
    "\43\0\1\30\15\0\1\71\1\72\3\0\1\71\4\0"+
    "\1\73\4\0\4\74\20\0\1\27\1\30\43\0\1\30"+
    "\1\0\1\41\17\0\1\75\36\0\1\67\1\70\43\0"+
    "\1\70\15\0\1\76\1\77\3\0\1\76\4\0\1\100"+
    "\4\0\4\100\26\0\1\101\1\102\43\0\1\103\1\104"+
    "\43\0\1\104\15\0\1\71\1\72\3\0\1\71\4\0"+
    "\1\105\4\0\4\74\44\0\1\106\63\0\1\107\52\0"+
    "\1\110\34\0\1\111\33\0\1\112\1\113\3\0\1\114"+
    "\37\0\1\113\5\0\1\115\1\116\11\0\1\117\31\0"+
    "\1\116\5\0\1\112\1\113\5\0\1\102\35\0\1\113"+
    "\5\0\1\112\1\113\3\0\1\120\37\0\1\113\5\0"+
    "\1\115\1\116\23\0\1\121\17\0\1\116\5\0\1\115"+
    "\1\116\11\0\1\122\31\0\1\116\10\0\1\123\1\0"+
    "\1\124\52\0\1\125\16\0\1\126\66\0\1\127\25\0"+
    "\1\130\42\0\1\131\62\0\1\132\56\0\1\133\46\0"+
    "\1\134\40\0\1\70\1\57\1\60\1\61\11\0\1\63"+
    "\2\0\1\63\1\0\1\60\10\0\1\64\1\0\1\64"+
    "\2\65\1\61\1\0\2\66\10\0\1\57\1\60\1\61"+
    "\11\0\1\63\2\0\1\63\1\0\1\60\10\0\1\64"+
    "\1\0\1\64\2\65\1\61\1\0\2\66\16\0\2\74"+
    "\3\0\1\74\4\0\1\74\4\0\4\74\14\0\1\135"+
    "\13\0\1\74\4\0\1\74\4\0\1\74\4\0\4\74"+
    "\30\0\2\74\35\0\1\135\52\0\1\135\3\0\1\136"+
    "\1\137\4\0\1\140\36\0\1\137\15\0\1\100\4\0"+
    "\1\100\4\0\1\100\4\0\4\100\20\0\1\112\1\113"+
    "\15\0\1\141\25\0\1\113\5\0\1\112\1\113\43\0"+
    "\1\113\6\0\1\104\1\142\1\143\12\0\1\63\2\0"+
    "\1\63\1\0\1\143\13\0\2\65\2\0\2\66\10\0"+
    "\1\142\1\143\12\0\1\63\2\0\1\63\1\0\1\143"+
    "\13\0\2\65\2\0\2\66\17\0\1\74\35\0\1\135"+
    "\3\0\1\115\1\116\33\0\1\144\7\0\1\116\5\0"+
    "\1\112\1\113\36\0\1\145\4\0\1\113\20\0\1\146"+
    "\37\0\1\112\1\113\11\0\1\147\31\0\1\113\6\0"+
    "\1\113\6\0\1\150\1\151\3\0\1\150\4\0\1\152"+
    "\4\0\4\153\30\0\1\150\1\151\3\0\1\150\4\0"+
    "\1\152\4\0\4\153\23\0\1\154\50\0\1\116\6\0"+
    "\1\150\1\151\3\0\1\150\4\0\1\155\4\0\4\153"+
    "\30\0\1\150\1\151\3\0\1\150\4\0\1\155\4\0"+
    "\4\153\20\0\1\115\1\116\43\0\1\116\41\0\1\156"+
    "\44\0\1\117\45\0\1\157\35\0\1\160\52\0\1\161"+
    "\21\0\1\162\57\0\1\163\25\0\1\164\106\0\1\165"+
    "\24\0\1\166\44\0\1\167\1\153\67\0\1\170\63\0"+
    "\1\171\34\0\1\165\43\0\1\172\1\173\3\0\1\174"+
    "\4\0\1\173\4\0\4\173\21\0\1\137\6\0\1\175"+
    "\1\151\3\0\1\175\4\0\1\153\4\0\4\153\30\0"+
    "\1\175\1\151\3\0\1\175\4\0\1\153\4\0\4\153"+
    "\25\0\1\176\65\0\1\102\35\0\1\123\1\0\1\177"+
    "\52\0\1\125\60\0\1\122\53\0\1\200\52\0\1\201"+
    "\57\0\1\145\31\0\1\202\1\203\6\0\2\153\3\0"+
    "\1\153\4\0\1\153\4\0\4\153\12\0\2\203\14\0"+
    "\1\153\4\0\1\153\4\0\1\153\4\0\4\153\20\0"+
    "\1\202\1\203\6\0\2\153\33\0\2\203\4\0\1\202"+
    "\1\203\43\0\2\203\12\0\1\204\44\0\1\202\1\203"+
    "\7\0\1\153\33\0\2\203\41\0\1\102\31\0\1\205"+
    "\36\0\1\202\1\203\3\0\1\206\37\0\2\203\4\0"+
    "\1\202\1\203\11\0\1\153\31\0\2\203\4\0\1\202"+
    "\1\203\5\0\1\153\35\0\2\203\4\0\1\202\1\203"+
    "\3\0\1\207\37\0\2\203\4\0\1\202\1\203\23\0"+
    "\1\210\17\0\2\203\4\0\1\202\1\203\11\0\1\211"+
    "\31\0\2\203\4\0\1\202\1\203\4\0\1\212\36\0"+
    "\2\203\4\0\1\202\1\203\15\0\1\213\25\0\2\203"+
    "\4\0\1\202\1\203\33\0\1\214\7\0\2\203\4\0"+
    "\1\202\1\203\36\0\1\215\4\0\2\203\14\0\2\100"+
    "\3\0\1\100\4\0\1\100\4\0\1\100\3\216\30\0"+
    "\2\100\3\0\1\100\4\0\1\100\4\0\4\100\30\0"+
    "\2\216\3\0\1\216\4\0\1\216\4\0\1\216\1\217"+
    "\2\100\20\0\1\202\1\203\6\0\1\153\4\0\1\153"+
    "\4\0\1\153\4\0\4\153\12\0\2\203\7\0\1\220"+
    "\75\0\1\162\37\0\1\221\46\0\1\222\43\0\1\223"+
    "\1\203\6\0\1\224\4\0\1\225\27\0\2\226\4\0"+
    "\1\223\1\226\6\0\1\224\4\0\1\225\27\0\2\226"+
    "\13\0\1\102\56\0\1\227\42\0\1\230\103\0\1\231"+
    "\44\0\1\153\45\0\1\215\36\0\1\206\65\0\1\153"+
    "\45\0\1\211\53\0\1\232\46\0\2\173\3\0\1\173"+
    "\4\0\1\173\4\0\4\173\31\0\1\233\47\0\1\234"+
    "\52\0\1\102\105\0\1\235\12\0\1\226\6\0\1\224"+
    "\4\0\1\225\65\0\3\236\30\0\2\236\3\0\1\236"+
    "\4\0\1\236\4\0\1\236\1\237\32\0\1\224\4\0"+
    "\1\225\43\0\1\117\52\0\1\240\101\0\1\153\30\0"+
    "\1\241\50\0\1\100\50\0\1\242\50\0\1\243\54\0"+
    "\1\153\51\0\1\153\44\0\1\136\1\137\43\0\1\137"+
    "\26\0\1\244\101\0\1\245\24\0\1\246\101\0\1\100";

  private static int [] zzUnpackTrans() {
    int [] result = new int[6880];
    int offset = 0;
    offset = zzUnpackTrans(ZZ_TRANS_PACKED_0, offset, result);
    return result;
  }

  private static int zzUnpackTrans(String packed, int offset, int [] result) {
    int i = 0;       /* index in packed string  */
    int j = offset;  /* index in unpacked array */
    int l = packed.length();
    while (i < l) {
      int count = packed.charAt(i++);
      int value = packed.charAt(i++);
      value--;
      do result[j++] = value; while (--count > 0);
    }
    return j;
  }


  /* error codes */
  private static final int ZZ_UNKNOWN_ERROR = 0;
  private static final int ZZ_NO_MATCH = 1;
  private static final int ZZ_PUSHBACK_2BIG = 2;

  /* error messages for the codes above */
  private static final String ZZ_ERROR_MSG[] = {
    "Unkown internal scanner error",
    "Error: could not match input",
    "Error: pushback value was too large"
  };

  /**
   * ZZ_ATTRIBUTE[aState] contains the attributes of state <code>aState</code>
   */
  private static final int [] ZZ_ATTRIBUTE = zzUnpackAttribute();

  private static final String ZZ_ATTRIBUTE_PACKED_0 =
    "\1\0\1\11\17\1\47\0\1\1\1\0\2\1\1\0"+
    "\1\1\1\0\1\11\4\0\1\1\42\0\1\1\1\0"+
    "\2\1\1\0\1\1\2\0\12\1\3\0\1\1\20\0"+
    "\2\1\27\0";

  private static int [] zzUnpackAttribute() {
    int [] result = new int[166];
    int offset = 0;
    offset = zzUnpackAttribute(ZZ_ATTRIBUTE_PACKED_0, offset, result);
    return result;
  }

  private static int zzUnpackAttribute(String packed, int offset, int [] result) {
    int i = 0;       /* index in packed string  */
    int j = offset;  /* index in unpacked array */
    int l = packed.length();
    while (i < l) {
      int count = packed.charAt(i++);
      int value = packed.charAt(i++);
      do result[j++] = value; while (--count > 0);
    }
    return j;
  }

  /** the input device */
  private java.io.Reader zzReader;

  /** the current state of the DFA */
  private int zzState;

  /** the current lexical state */
  private int zzLexicalState = YYINITIAL;

  /** this buffer contains the current text to be matched and is
      the source of the yytext() string */
  private char zzBuffer[] = new char[ZZ_BUFFERSIZE];

  /** the textposition at the last accepting state */
  private int zzMarkedPos;

  /** the current text position in the buffer */
  private int zzCurrentPos;

  /** startRead marks the beginning of the yytext() string in the buffer */
  private int zzStartRead;

  /** endRead marks the last character in the buffer, that has been read
      from input */
  private int zzEndRead;

  /** number of newlines encountered up to the start of the matched text */
  private int yyline;

  /** the number of characters up to the start of the matched text */
  private int yychar;

  /**
   * the number of characters from the last newline up to the start of the 
   * matched text
   */
  private int yycolumn;

  /** 
   * zzAtBOL == true <=> the scanner is currently at the beginning of a line
   */
  private boolean zzAtBOL = true;

  /** zzAtEOF == true <=> the scanner is at the EOF */
  private boolean zzAtEOF;

  /** denotes if the user-EOF-code has already been executed */
  private boolean zzEOFDone;

  /* user code: */
  void echo() {
    int len = yylength();       // Find length of current lexeme
    for (int i=0; i<len; i++) { // Run through each character in turn
      char c = yycharat(i);   
      switch (c) {              // and translate as appropriate ...
        case '<' : System.out.print("&lt;");  break;
        case '>' : System.out.print("&gt;");  break;
        case '&' : System.out.print("&amp;"); break;
        default  : System.out.print(c);       break;
      }
    }
  }
  void tag(String cl) {
    System.out.print("<span class=\"" + cl + "\">");
    echo();
    System.out.print("</span>");
  }
  void date() { tag("date"); }


  /**
   * Creates a new scanner
   * There is also a java.io.InputStream version of this constructor.
   *
   * @param   in  the java.io.Reader to read input from.
   */
  Yylex(java.io.Reader in) {
    System.out.println("<html>");
  System.out.println("<head>");
  System.out.println("<title>My Syntax Colored Web Page</title>");
  System.out.println("<style type=\"text/css\">");
  System.out.println("  body     {white-space:pre;");
  System.out.println("            background-color:#ffffcc;");
  System.out.println("            color:black;");
  System.out.println("            font-family:\"Lucida Console\",\"Courier New\",Monotype}");
  //for Dates
  System.out.println("  .date {background-color:white; color:green}");
  System.out.println("</style>");
  System.out.println("</head>");
  System.out.println("<body>");
    this.zzReader = in;
  }

  /**
   * Creates a new scanner.
   * There is also java.io.Reader version of this constructor.
   *
   * @param   in  the java.io.Inputstream to read input from.
   */
  Yylex(java.io.InputStream in) {
    this(new java.io.InputStreamReader(in));
  }

  /** 
   * Unpacks the compressed character translation table.
   *
   * @param packed   the packed character translation table
   * @return         the unpacked character translation table
   */
  private static char [] zzUnpackCMap(String packed) {
    char [] map = new char[0x10000];
    int i = 0;  /* index in packed string  */
    int j = 0;  /* index in unpacked array */
    while (i < 132) {
      int  count = packed.charAt(i++);
      char value = packed.charAt(i++);
      do map[j++] = value; while (--count > 0);
    }
    return map;
  }


  /**
   * Refills the input buffer.
   *
   * @return      <code>false</code>, iff there was new input.
   * 
   * @exception   java.io.IOException  if any I/O-Error occurs
   */
  private boolean zzRefill() throws java.io.IOException {

    /* first: make room (if you can) */
    if (zzStartRead > 0) {
      System.arraycopy(zzBuffer, zzStartRead,
                       zzBuffer, 0,
                       zzEndRead-zzStartRead);

      /* translate stored positions */
      zzEndRead-= zzStartRead;
      zzCurrentPos-= zzStartRead;
      zzMarkedPos-= zzStartRead;
      zzStartRead = 0;
    }

    /* is the buffer big enough? */
    if (zzCurrentPos >= zzBuffer.length) {
      /* if not: blow it up */
      char newBuffer[] = new char[zzCurrentPos*2];
      System.arraycopy(zzBuffer, 0, newBuffer, 0, zzBuffer.length);
      zzBuffer = newBuffer;
    }

    /* finally: fill the buffer with new input */
    int numRead = zzReader.read(zzBuffer, zzEndRead,
                                            zzBuffer.length-zzEndRead);

    if (numRead > 0) {
      zzEndRead+= numRead;
      return false;
    }
    // unlikely but not impossible: read 0 characters, but not at end of stream    
    if (numRead == 0) {
      int c = zzReader.read();
      if (c == -1) {
        return true;
      } else {
        zzBuffer[zzEndRead++] = (char) c;
        return false;
      }     
    }

	// numRead < 0
    return true;
  }

    
  /**
   * Closes the input stream.
   */
  public final void yyclose() throws java.io.IOException {
    zzAtEOF = true;            /* indicate end of file */
    zzEndRead = zzStartRead;  /* invalidate buffer    */

    if (zzReader != null)
      zzReader.close();
  }


  /**
   * Resets the scanner to read from a new input stream.
   * Does not close the old reader.
   *
   * All internal variables are reset, the old input stream 
   * <b>cannot</b> be reused (internal buffer is discarded and lost).
   * Lexical state is set to <tt>ZZ_INITIAL</tt>.
   *
   * @param reader   the new input stream 
   */
  public final void yyreset(java.io.Reader reader) {
    zzReader = reader;
    zzAtBOL  = true;
    zzAtEOF  = false;
    zzEOFDone = false;
    zzEndRead = zzStartRead = 0;
    zzCurrentPos = zzMarkedPos = 0;
    yyline = yychar = yycolumn = 0;
    zzLexicalState = YYINITIAL;
  }


  /**
   * Returns the current lexical state.
   */
  public final int yystate() {
    return zzLexicalState;
  }


  /**
   * Enters a new lexical state
   *
   * @param newState the new lexical state
   */
  public final void yybegin(int newState) {
    zzLexicalState = newState;
  }


  /**
   * Returns the text matched by the current regular expression.
   */
  public final String yytext() {
    return new String( zzBuffer, zzStartRead, zzMarkedPos-zzStartRead );
  }


  /**
   * Returns the character at position <tt>pos</tt> from the 
   * matched text. 
   * 
   * It is equivalent to yytext().charAt(pos), but faster
   *
   * @param pos the position of the character to fetch. 
   *            A value from 0 to yylength()-1.
   *
   * @return the character at position pos
   */
  public final char yycharat(int pos) {
    return zzBuffer[zzStartRead+pos];
  }


  /**
   * Returns the length of the matched text region.
   */
  public final int yylength() {
    return zzMarkedPos-zzStartRead;
  }


  /**
   * Reports an error that occured while scanning.
   *
   * In a wellformed scanner (no or only correct usage of 
   * yypushback(int) and a match-all fallback rule) this method 
   * will only be called with things that "Can't Possibly Happen".
   * If this method is called, something is seriously wrong
   * (e.g. a JFlex bug producing a faulty scanner etc.).
   *
   * Usual syntax/scanner level error handling should be done
   * in error fallback rules.
   *
   * @param   errorCode  the code of the errormessage to display
   */
  private void zzScanError(int errorCode) {
    String message;
    try {
      message = ZZ_ERROR_MSG[errorCode];
    }
    catch (ArrayIndexOutOfBoundsException e) {
      message = ZZ_ERROR_MSG[ZZ_UNKNOWN_ERROR];
    }

    throw new Error(message);
  } 


  /**
   * Pushes the specified amount of characters back into the input stream.
   *
   * They will be read again by then next call of the scanning method
   *
   * @param number  the number of characters to be read again.
   *                This number must not be greater than yylength()!
   */
  public void yypushback(int number)  {
    if ( number > yylength() )
      zzScanError(ZZ_PUSHBACK_2BIG);

    zzMarkedPos -= number;
  }


  /**
   * Contains user EOF-code, which will be executed exactly once,
   * when the end of file is reached
   */
  private void zzDoEOF() {
    if (!zzEOFDone) {
      zzEOFDone = true;
      System.out.println("</body>");
  System.out.println("</html>");

    }
  }


  /**
   * Resumes scanning until the next regular expression is matched,
   * the end of input is encountered or an I/O-Error occurs.
   *
   * @return      the next token
   * @exception   java.io.IOException  if any I/O-Error occurs
   */
  public int yylex() throws java.io.IOException {
    int zzInput;
    int zzAction;

    // cached fields:
    int zzCurrentPosL;
    int zzMarkedPosL;
    int zzEndReadL = zzEndRead;
    char [] zzBufferL = zzBuffer;
    char [] zzCMapL = ZZ_CMAP;

    int [] zzTransL = ZZ_TRANS;
    int [] zzRowMapL = ZZ_ROWMAP;
    int [] zzAttrL = ZZ_ATTRIBUTE;

    while (true) {
      zzMarkedPosL = zzMarkedPos;

      zzAction = -1;

      zzCurrentPosL = zzCurrentPos = zzStartRead = zzMarkedPosL;
  
      zzState = ZZ_LEXSTATE[zzLexicalState];


      zzForAction: {
        while (true) {
    
          if (zzCurrentPosL < zzEndReadL)
            zzInput = zzBufferL[zzCurrentPosL++];
          else if (zzAtEOF) {
            zzInput = YYEOF;
            break zzForAction;
          }
          else {
            // store back cached positions
            zzCurrentPos  = zzCurrentPosL;
            zzMarkedPos   = zzMarkedPosL;
            boolean eof = zzRefill();
            // get translated positions and possibly new buffer
            zzCurrentPosL  = zzCurrentPos;
            zzMarkedPosL   = zzMarkedPos;
            zzBufferL      = zzBuffer;
            zzEndReadL     = zzEndRead;
            if (eof) {
              zzInput = YYEOF;
              break zzForAction;
            }
            else {
              zzInput = zzBufferL[zzCurrentPosL++];
            }
          }
          int zzNext = zzTransL[ zzRowMapL[zzState] + zzCMapL[zzInput] ];
          if (zzNext == -1) break zzForAction;
          zzState = zzNext;

          int zzAttributes = zzAttrL[zzState];
          if ( (zzAttributes & 1) == 1 ) {
            zzAction = zzState;
            zzMarkedPosL = zzCurrentPosL;
            if ( (zzAttributes & 8) == 8 ) break zzForAction;
          }

        }
      }

      // store back cached position
      zzMarkedPos = zzMarkedPosL;

      switch (zzAction < 0 ? zzAction : ZZ_ACTION[zzAction]) {
        case 2: 
          { date();
          }
        case 3: break;
        case 1: 
          { System.out.print(yytext());
          }
        case 4: break;
        default: 
          if (zzInput == YYEOF && zzStartRead == zzCurrentPos) {
            zzAtEOF = true;
            zzDoEOF();
            return YYEOF;
          } 
          else {
            zzScanError(ZZ_NO_MATCH);
          }
      }
    }
  }

  /**
   * Runs the scanner on input files.
   *
   * This is a standalone scanner, it will print any unmatched
   * text to System.out unchanged.
   *
   * @param argv   the command line, contains the filenames to run
   *               the scanner on.
   */
  public static void main(String argv[]) {
    if (argv.length == 0) {
      System.out.println("Usage : java Yylex <inputfile>");
    }
    else {
      for (int i = 0; i < argv.length; i++) {
        Yylex scanner = null;
        try {
          scanner = new Yylex( new java.io.FileReader(argv[i]) );
          while ( !scanner.zzAtEOF ) scanner.yylex();
        }
        catch (java.io.FileNotFoundException e) {
          System.out.println("File not found : \""+argv[i]+"\"");
        }
        catch (java.io.IOException e) {
          System.out.println("IO error scanning file \""+argv[i]+"\"");
          System.out.println(e);
        }
        catch (Exception e) {
          System.out.println("Unexpected exception:");
          e.printStackTrace();
        }
      }
    }
  }


}
