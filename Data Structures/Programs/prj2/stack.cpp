//CS163
//Assignment #2
//Hyunchan Kim
//stack.cpp
#include "stack.h"

//implements all functions declared in stack class, stack.h

//Stack constructor
stack::stack()
{
	head = NULL;
	top_index = 0;
}
//stack destructor
stack::~stack()
{
	if (!head)
		return;
	stack_node * current = head;
	while (current)
	{
		current = current->next;
		delete head;
		head = current;
	}
}

//push a servic to the top of the stack
int stack::push(const product & to_add)
{
	if (!head)
	{
		head = new stack_node;
		head->next = NULL;
		head->products = new product[MAX];
		top_index = 0;
		head->products[top_index++].copy_product(to_add);
	}
	else if (top_index == MAX)
	{
		stack_node * temp = new stack_node;
		temp->next = head;
		head = temp;
		temp->products = new product[MAX];
		top_index = 0;
		temp->products[top_index++].copy_product(to_add);
	}
	else
		head->products[top_index++].copy_product(to_add);

	return 1;
}

//pop(remove) the service at the top of the stack
int stack::pop()
{
	if (!head)
		return 0;

	stack_node * temp;
	if (top_index == 0)
	{
		temp = head->next;
		delete[] head->products;
		delete head;
		head = temp;
		top_index = MAX - 1;
	}
	else
		--top_index;

	return 1;

}

//peek the service at the top of the stack
int stack::peek(product & foundAtTop)
{
	if (!head) //if there is no item, head is null
		return 0;

	if (top_index == 0)
		return 0;

	foundAtTop.copy_product(head->products[top_index - 1]);
	foundAtTop.display_all();

	return 1;
}
