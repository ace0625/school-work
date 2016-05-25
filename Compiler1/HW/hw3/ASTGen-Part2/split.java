class C {
  // declare the fields for this class
  protected int x;

  // declare default constructor for this class
  C(int x) {
    this.x = x;
  }

  // add additional methods and fields here ... 
}

class D1 extends C {
  // declare the fields for this class
  private int y;

  // declare default constructor for this class
  D1(int x, int y) {
    super(x);
    this.y = y;
  }

  // add additional methods and fields here ... 
}

class D2 extends C {
  // declare the fields for this class
  int z;

  // declare default constructor for this class
  D2(int x, int z) {
    super(x);
    this.z = z;
  }

  // add additional methods and fields here ... 
}

