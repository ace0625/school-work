// SC0 interpreter. (For CS322 Lab2)
//
// (Starter version)
//
import java.util.*;
import java.io.*;

class SC0Interp {

  //-----------------------------------------------------------------
  // Memory models
  //-----------------------------------------------------------------
  //

  // Local variable array
  // - use vars.get(idx) and vars.put(idx,val) to access
  //
  static HashMap<Integer,Integer> vars = new HashMap<Integer,Integer>();

  // Heap memory for array objects
  // - use heapAlloc(size) to allocate, heap.get(loc) and 
  //   heap.set(loc,val) to access
  //
  static List<Integer> heap = new ArrayList<Integer>();

  static int heapAlloc(int size) {
    int loc = heap.size();
    for (int i=0; i<size; i++)
      heap.add(0);	// init array elements to 0
    return loc;
  }

  // Operand stack
  // - use stack.push(val) and stack.pop() to access
  //
  static Stack<Integer> stack = new Stack<Integer>();


  //-----------------------------------------------------------------
  // The main method
  //-----------------------------------------------------------------
  //
  // 1. the frontend
  // 2. the "fetch-and-execute" loop
  //
  public static void main(String [] args) throws Exception {
    if (args.length == 1) {
      // The frontend
      // - reading program from file, convert it to an array of insts
      //
      FileInputStream stream = new FileInputStream(args[0]);
      BufferedReader reader = new BufferedReader(new InputStreamReader(stream));
      List<String> instList = new ArrayList<String>();
      String line;
      while ((line = reader.readLine()) != null) {
	if (!(line.isEmpty() || line.trim().equals("")
	      || line.startsWith("#")))
	  instList.add(line);
      }
      reader.close();
      String[] insts = instList.toArray(new String[0]); 

      // The "fetch-and-execute" loop
      //
      Scanner sc;
      int n, idx=0;
      String lnum, name;
      while (idx < insts.length) {
	sc = new Scanner(insts[idx]);
	lnum = sc.next(); 			// line number (ignored)
	name = sc.next(); 			// inst name          
	n = sc.hasNextInt() ? sc.nextInt() : 0; // inst operand
	int next = execute(name, n);
	idx += next;
      }
    } else {
      System.out.println("Need a file name as command-line argument.");
    }
  }

  //-----------------------------------------------------------------
  // Execute an individual instruction
  //-----------------------------------------------------------------
  //
  // Inst -> "CONST" n
  // 	  |  ("LOAD" | "STORE") n
  // 	  |  "ALOAD" | "ASTORE" |  "NEWARRAY" | "PRINT"  
  // 	  |  "NEG" | "ADD" | "SUB" | "MUL" | "DIV" | "AND" | "OR" 
  // 	  |  ("GOTO"|"IFZ"|"IFEQ"|"IFNE"|"IFLT"|"IFLE"|"IFGT"|"IFGE") n
  //
  static int execute(String instName, int n) 
  {
    int val, val1, val2;
    int count, aref, idx, res;
    int incr = 1;

    switch (instName) {
    case "CONST": 
      stack.push(n); 
      break;
    case "LOAD":  
      stack.push(vars.get(n));
      break;
    case "STORE": 
      vars.put(n, stack.pop());
      break; 
    case "ALOAD":
      idx = stack.pop();
      aref = stack.pop();
      val = heap.get(aref+idx);
      stack.push(val);
      break; 
    case "ASTORE": 
      val = stack.pop();
      idx = stack.pop();
      aref = stack.pop();
      heap.set(idx+aref, val);
      break; 
    case "NEWARRAY": 
      int size = stack.pop();
      aref = heapAlloc(size);
      stack.push(aref);
      break; 
    case "PRINT": 
      System.out.println(stack.pop());
      break; 
    case "NEG":   
      res = - (stack.pop());
      stack.push(res);
      break;
    case "ADD": case "SUB":   
    case "MUL": case "DIV":
      val2 = stack.pop();
      val1 = stack.pop();   
      res = binop(instName,val1,val2);
      stack.push(res);
      break; 
    case "GOTO":  
      incr = n; 
      break;
    case "IFZ":   
      val = stack.pop();
      if (val == 0)
        incr = n;
      break;
    case "IFEQ": case "IFNE":  
    case "IFLT": case "IFLE":  
    case "IFGT": case "IFGE":  
      val2 = stack.pop();
      val1 = stack.pop();
      if (cond(instName,val1,val2))
        incr = n;
      break;
    }
    return incr;
  }

  static int binop(String op, int v1, int v2) 
  {
    switch (op) {
    case "ADD": return v1 + v2;
    case "SUB": return v1 - v2;
    case "MUL": return v1 * v2;
    case "DIV": return v1 / v2;
    case "AND": return v1 & v2;
    case "OR":  return v1 | v2;
    }
    return 0;
  }

  static boolean cond(String op, int v1, int v2) 
  {
    switch (op) {
    case "IFEQ": return v1 == v2;
    case "IFNE": return v1 != v2;
    case "IFLT": return v1 < v2;
    case "IFLE": return v1 <= v2;
    case "IFGT": return v1 > v2;
    case "IFGE": return v1 >= v2;
    }
    return false;
  }
}

