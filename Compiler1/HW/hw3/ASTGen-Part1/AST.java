//CS321
//Homework #3 part1
//Hyunchan Kim

/*
// AST Specification: ------------------

class Class(private boolean isAbstract,
            private String  name,
            private Args    args,
            private Class[] subclasses)

class Args(Args before, Args last)

class Arg(private String visibility,
          private Type   type,
          private String id)

abstract class Type {
  class NameType(private String[] ids)
  class ArrayType(private Type elem)
}

// -------------------------------------
*/

class Class
{
	private boolean isAbstract;
	private String name;
	private Args args;
	private Class[] subclasses;

	Class(boolean isAbstract, String name, Args args, Class[] subclasses)
	{
		this.isAbstract = isAbstract;
		this.name = name;
		this.args = args;
		this.subclasses = subclasses;
	}
}

class Args
{
	Args before;
	Args last;

	Args(Args before, Args last)
	{
		this.before = before;
		this.last = last;
	}
}


class Arg
{
	private String visibility;
	private Type type;
	private String id;

	Arg(String visibility, Type type, String id)
	{
		this.visibility = visibility;
		this.type = type;
		this.id = id;
	}
}


abstract class Type
{
	Type()
	{

	}
}

class NameType extends Type
{
	private String[] ids;

	NameType(String[] ids)
	{
		this.ids = ids;
	}
}

class ArrayType extends Type
{
	private Type elem;

	ArrayType(Type elem)
	{
		this.elem = elem;
	}
}





