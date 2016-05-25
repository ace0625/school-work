//CS163
//Program#2
//Hyunchan Kim
//list.cpp
#include "list.h"

//This class implements the functions from the list class that manages 
//shopping cart you can add, remove, and display orders

//default constructor
list::list()
{
	head = NULL;
}


//default destructor
list::~list()
{
	if (head)
	{
		node * temp;
		while (head)
		{
			temp = head->next;
			delete head;
			head = temp;
		}
	}
}

/*
insert an order to a linear linked list(shopping cart)
*/
int list::add(product & to_add)
{
	//when head is null
   if(!head)
   {
		head = new node;
		head->a_product.copy_product(to_add);
		head->next = NULL;
   }
   //else
   else
   {
	   node * current = head;
	   while(current->next)
	   {
		   current = current->next;
	   }
	   current->next = new node;
	   current = current->next;
	   current->a_product.copy_product(to_add);
	   current->next = NULL;
   }
   
   return 1;
}

/*
Remove an order from the linear linked list(shopping cart)
*/
int list::remove(char * position, product & found)
{ 
	char file[] = "data.txt";
	//if head is null
	if(!head)
		return 0;
    
    node * current = head;
    while(current)
    {
		if(current->a_product.retrieve(position, file))
		{
			delete current;
			current = NULL;
			return 1;
		}
		current = current->next;
    }
    return 0;
}


/*
Display all the items in the shopping cart
*/
int list::display_all(void)
{
	if(!head)
		return 0;

    node * current = head;
    while(current)
    {
		current->a_product.display_all();
		current = current->next;
    }
    return 1;	

}

