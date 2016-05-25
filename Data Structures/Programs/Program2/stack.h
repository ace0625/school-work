//CS163
//Assignment #2
//4/29/2015
//Hyunchan Kim
//stack.h

#include "service.h"

//This stack.h manages statistics that presents average waiting time, individual waiting time.
//The waiting time is changes when an order comes in or an order is paid.

struct stack_node
{
	service * services;
	stack_node * next;
};

const int MAX = 20;


class stack
{
	public:
		stack(); //constructor
		~stack(); //destructor

		int push(const service & to_add); // add a service to the stack
		int pop(); //remove a service at the top of the stack
		int peek(service & foundAtTop); //retrieve the servie at the top of the stack
		int display_stack(); //display all in the stack
	private:
		stack_node * head; //stack node pointer
		int top_index; // top index
};