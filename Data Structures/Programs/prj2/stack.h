//CS163
//Program#2
//Hyunchan Kim
//stack.h

#include "product.h"

//This is stack header file that basically designs stack functions
//for managing pending orders or delayed orders
struct stack_node
{
	product * products;
	stack_node * next;
};

const int MAX = 20;

class stack
{
	public:
		stack(); //constructor
		~stack(); //destructor
		int push(const product & to_add); // add a service to the stack
		int pop(); //remove a service at the top of the stack
		int peek(product & foundAtTop); //retrieve the servie at the top of the stack
	private:
		stack_node * head; //stack node pointer
		int top_index; // top index
};