// 21 Compilation
import compiler.*;
import lexer.*;
import parser.*;
import ast.*;
import java.io.FileReader;

public class Compiler {
  public static void main(String[] args) {
    Handler handler = new SimpleHandler();
    try {
      if (args.length!=1) {
        throw new Failure("This program requires exactly one argument");
      }

      // Read program:
      String     input  = args[0] + ".mini";
      FileReader reader = new FileReader(input);
      Source     source = new JavaSource(handler, input, reader);
      MiniLexer  lexer  = new MiniLexer(handler, source);
      MiniParser parser = new MiniParser(handler, lexer);
      Stmt       prog   = parser.parseProgram();
      if (handler.hasFailures()) {
        throw new Failure("Aborting: errors detected during syntax analysis");
      }

      // Analyze program:
      new ScopeAnalysis(handler).analyze(prog);
      new TypeAnalysis(handler).analyze(prog);
      new InitAnalysis(handler).analyze(prog);

      // Optimization:
      prog.simplify();

      // Output compiled program:
      String output = args[0] + ".s";
      new IA32(output).generateAssembly(output, prog);                   // <<<
      System.out.println("Assembly code output: " + output);

      // Invoke assembler to produce executable:
      Runtime.getRuntime()                                               // <<<
             .exec("gcc -m32 -o " + args[0] + " " +                      // <<<
                     args[0] + ".s runtime.c")                           // <<<
             .waitFor();                                                 // <<<
      System.out.println("Executable program: " + args[0]);

    } catch (Failure f) {
      handler.report(f);
    } catch (Exception e) { 
      handler.report(new Failure("Exception: " + e));
    }     
  }     
}
