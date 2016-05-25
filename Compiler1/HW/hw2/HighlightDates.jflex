//CS321
//Homework#2
//2/2/2016
//Hyunchan Kim

%%

// We use the %standalone declaration, which tells jflex that we want to
// build a self-contained program.  This will result in the definition of a
// main function that reads a file name on the command line and then passes
// all of the text from that file through the generated scanner/lexer.  We
// will produce the corresponding syntax colored output simply by printing
// it on to the standard output device; this makes it easy to inspect the
// output while debugging, but we can also use a redirect operator to
// save the contents in an HTML file instead that is suitable for viewing
// in a browser.

%standalone

// Next, we use the %class declaration, selecting HighlightDates as the name
// for the Java class that will be generated:

// %class HighlightDates

// Assuming that the JFlex source shown here is stored in HighlightDates.jflex,
// we will now be able to generate and compile our program using the
// following commands:
// 
//   jflex HighlightDates.jflex 
//   javac Yylex.java
//
// The resulting program can then be run as follows:
//   
//   java Yylex lexer-sample.txt  > lexer-sample.html

// Every HTML file that we generate should begin with set of lines to set
// basic details such as the title and the style options.  The %init
// feature of jflex provides An easy way to handle this, allowing us to
// specify some code that should be executed as part of the constructor for
// the HighlightDates constructor; in this case, we just need to print the
// initial set of lines for the start of the HTML output.  (This would also
// be a good place to initialize an output file if we wanted to write the
// output from the program directly to a file instead of just printing it
// on the standard output.)

%init{
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
%init}

// There is a similar %eof feature that allows us to specify code that
// will be executed when the program reaches the end of the input file.
// This provides a convenient place for us to put the code that produces
// the HTML lines that are required at the end of every output file:

%eof{
  System.out.println("</body>");
  System.out.println("</html>");
%eof}

// In general, our syntax coloring program will work by matching
// patterns in the input file and then outputing the original lexeme,
// sometimes wrapped between HTML tags to specify how the lexeme
// should be colored.  One small technical challenge in this is that
// we need to make sure that the three characters <, >, and &, which
// have special uses in HTML, are replaced by the appropriate escape
// sequences &lt;, &gt:, and &amp;, respectively in the output.
// In principle, it would be possible to handle this completely within
// the main set of jflex matching rules.  However, in this particular
// case, it seems easier (at least to this author) just to handle
// this with a little bit of Java code as shown in the following
// echo() function.  This function works by reading characters one
// at a time from the internal buffer that JFlex uses, checking for
// the three special cases, and performing the necessary output
// action each time.

%{
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
%}

// As a small technical aside, note that we have used a combination
// of the yylength() and yycharat() functions to access the text of
// the current lexeme.  We could achieve a similar effect using the
// yytext() function, but the approach used here is faster (at least
// in principle) because it avoids the overheads of constructing a
// new string object for each input element.

// The echo() method described above is good for printing the text
// of a lexeme directly, without any special syntax coloring.  For
// lexemes where we want to add some color, however, we can use the
// following tag() method, which adds an appropriate span tag before
// and after the lexeme text.

%{
  void tag(String cl) {
    System.out.print("<span class=\"" + cl + "\">");
    echo();
    System.out.print("</span>");
  }
%}

// The parameter cl is used to specify a particular token class/style;
// given the opening lines of HTML shown above, this should be one of
// "keyword", "comment", "literal", or "invalid".  We can define some
// quick helper methods for each of these four cases as follows:

%{
  void date() { tag("date"); }
%}

// Now we are ready to give regular expressions for each of the input
// elements that can appear in a valid mini program.  We will use the
// following rules to specify the syntax of dates:

//Identifier         = [:jletter:] [:jletterdigit:]*

LineTerminator     = \r|\n|\r\n
WhiteSpace         = {LineTerminator} | [ \t\f] 
//InputCharacter     = [^\r\n]

//Comment            = {TraditionalComment} | {EndOfLineComment}
//TraditionalComment = "/*" [^*] ~"*/" | "/*" "*"+ "/"
//EndOfLineComment   = "//" {InputCharacter}* {LineTerminator}

// ====================================================================
// This is the rules for dates for this assignment

January          = "January"|"january"| "Jan"|"jan"
JanuarybyNum     = "1"|"01"
February         = "February"|"february"|"Feb"|"feb"
FebruarybyNum    = "2"|"02"
March            = "March"|"march"|"Mar"|"mar"
MarchbyNum       = "3"|"03"
April            = "April"|"april"|"Apr"|"apr"
AprilbyNum       = "4"|"04"
May              = "May"|"may"                      
MaybyNum         = "5" | "05"
June             = "June"|"june"|"Jun"|"jun"
JunebyNum        = "6"|"06"
July             = "July"|"july"|"Jul"|"jul"
JulybyNum        = "7"|"07"
August           = "August"|"august"|"Aug"|"aug"
AugustbyNum      = "8"|"08"
September        = "September"|"september"|"Sep"|"sep"
SeptemberbyNum   = "9"|"09"
October          = "October"|"october"|"Oct"|"oct"
OctoberbyNum     = "10"
November         = "November"|"november"|"Nov"|"nov"
NovemberbyNum    = "11"
December         = "December"|"december"|"Dec"|"dec"
DecemberbyNum    = "12"


//Day kinds ther will be 29, 30, 31 (no leap year)
Day_29          = [1-9]|[0-2][1-9]
Day_30          = [1-9]|[0-2][1-9]|[1-3][0] 
Day_31          = [1-9]|[0-2][1-9]|[1-3][0]|[3][1]

//Classify the months by number of days
Month_29        = { February }
Month_30        = { April } | { June } | { September } | { November }
Month_31        = { January } | { March } | { May } | { July } | { August } | { October } | { December }

//Year section
Year        = { Year_L } | { Year_S }
Year_L      = [1][5-9][0-9][0-9] | [2][0-4][0-9][0-9] | [2][5][0][0]
Year_S      = [0-9][0-9]

MonthbyNum_29         = { FebruarybyNum }
MonthbyNum_30         = { AprilbyNum } | { JunebyNum } | { SeptemberbyNum } | { NovemberbyNum }
MonthbyNum_31         = {JanuarybyNum} | {MarchbyNum} | {MaybyNum} | {JulybyNum} | {AugustbyNum} | {OctoberbyNum} | {DecemberbyNum}


Space_Separator    = { LineTerminator } | [ ]
Comma_Separator    = { LineTerminator } | ","
SpaceComma_Separator        = {Space_Separator} | {Comma_Separator}
SpaceComma_Separator2       = {SpaceComma_Separator} | {SpaceComma_Separator} {SpaceComma_Separator}

//Date representation with entire name
Date_L1          = {Month_31} {Space_Separator} {Day_31} {SpaceComma_Separator2} {Year_L}
Date_L2          = {Month_30} {Space_Separator} {Day_30} {SpaceComma_Separator2} {Year_L}
Date_L3          = {Month_29} {Space_Separator} {Day_29} {SpaceComma_Separator2} {Year_L}
Date_L4          = {Day_31} {Space_Separator} {Month_31} {SpaceComma_Separator2} {Year_L}
Date_L5          = {Day_30} {Space_Separator} {Month_30} {SpaceComma_Separator2} {Year_L}
Date_L6          = {Day_29} {Space_Separator} {Month_29} {SpaceComma_Separator2} {Year_L}

DatebyNum_1       = {MonthbyNum_31} "/" {Day_31} "/" {Year}
DatebyNum_2       = {MonthbyNum_30} "/" {Day_30} "/" {Year}
DatebyNum_3       = {MonthbyNum_29} "/" {Day_29} "/" {Year} 
DateShort1         = {Month_31} {Space_Separator} {Day_31} | {Day_31} {Space_Separator} {Month_31}
DateShort2         = {Month_30} {Space_Separator} {Day_30} | {Day_30} {Space_Separator} {Month_30}
DateShort3         = {Month_29} {Space_Separator} {Day_29} | {Day_29} {Space_Separator} {Month_29}
DateShortNum       = {MonthbyNum_31} "/" {Day_31} | {MonthbyNum_30} "/" {Day_30} | {MonthbyNum_29} "/" {Day_29} 

Date_L           = {Date_L1} | {Date_L2} | {Date_L3} | {Date_L4} | {Date_L5} | {Date_L6}
DatebyNum_L        = {DatebyNum_1} | {DatebyNum_2} | DatebyNum_3}
DateShort          = {DateShort1} | {DateShort2} | {DateShort3} | {DateShortNum}

DateHighlight         = { Date_L } | { DatebyNum_L } | {DateShort}

Separator          = "/" | " " | ","



// =======================================================================================
%%


//Hightlighting the mathcing dates
{ DateHighlight }          { date(); }

// This completes the list of all valid tokens that can appear in a mini
// program, but we will end our list of lexer rules with a catch all that
// matches any input not already matched and aborts the program with an
// "Invalid input" error.

//.|\n            { System.err.println("Invalid input");
//                  System.exit(1);
//                }

// ---------------------------------------------------------------------
