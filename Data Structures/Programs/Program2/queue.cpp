//CS163
//Assignment #2
//4/29/2015
//Hyunchan Kim
//queue.cpp
#include "queue.h"

//implements all functions declared in queue class, queue.h

//queue default constructor
queue::queue()
{
	rear = NULL;
	num_customer = 0;
}

//queue default destructor
queue::~queue()
{
	num_customer = 0;

	if (!rear) return;
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

//enqueue function that add a service to the queue
int queue::enqueue(const service & to_add)
{
	if (!rear)
	{
		rear = new queue_node;
		rear->next = rear;
		if (rear->a_service.copy_order(to_add))
		{
			++num_customer;
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
		if (rear->a_service.copy_order(to_add))
		{
			++num_customer;
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

int queue::dequeue(service & paid)
{
	if (!rear)
		return 0;
	if (rear->next == rear)
	{
		num_customer = 0;
		delete rear;
		rear = NULL;
	}
	else
	{
		queue_node * temp = rear->next;
		rear->next = temp->next;
		delete temp;
		temp = NULL;
		--num_customer;
	}
	return 1;
}

//display everything in the queue
int queue::display_all()
{
	if (!rear) //when rear is null
		return 0;

	queue_node * current = rear->next;
	for (int i = 0; i < num_customer; i++)
	{
		current->a_service.display();
		current = current->next;
	}
	return 1;
}
	
