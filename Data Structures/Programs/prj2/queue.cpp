//CS163
//Program#2
//Hyunchan Kim
//queue.cpp

#include "queue.h"
//implements all functions declared in queue class, queue.h

/*
queue default constructor
*/
queue::queue()
{
	rear = NULL;
}

/*
queue default destructor
*/
queue::~queue()
{
	if (!rear) 
		return;
	else
	{
		queue_node * current = rear->next;
		queue_node * head = current;
		rear->next = NULL;
		rear = NULL;
		while (current)
		{
			current = current->next;
			delete head;
			head = current;
		}
	}
}

/*
This is enqueue function that add an order to the queue
*/
int queue::enqueue(const product & to_add)
{
	if (!rear)
	{
		rear = new queue_node;
		rear->next = rear;
		if (rear->a_product.copy_product(to_add))
		{
			return 1;
		}
		else
		{
			delete rear;
			rear->next = NULL;
			return 0;
		}
	}
	else
	{
		queue_node * temp = rear->next;
		rear->next = new queue_node;
		rear = rear->next;
		rear->next = temp;
		if (rear->a_product.copy_product(to_add))
		{
			return 1;
		}
		else
		{
			delete temp;
			delete rear;
			rear->next = NULL;
			return 0;
		}
	}
}

/*
This is dequeue function that removes an item at the front 
*/
int queue::dequeue()
{
	if (!rear)
		return 0;
	if (rear->next == rear)
	{
		delete rear;
		rear = NULL;
	}
	else
	{
		queue_node * temp = rear->next;
		rear->next = temp->next;
		delete temp;
		temp = NULL;
	}
	return 1;
}

/*
This function is display_all that displays everything in the queue
*/
int queue::display_all()
{
	if (!rear) //when rear is null
		return 0;

	queue_node * current = rear;
	while(current != rear)
	{	
		current->a_product.display_all();
		current = current->next;
	}
	return 1;
}
	
