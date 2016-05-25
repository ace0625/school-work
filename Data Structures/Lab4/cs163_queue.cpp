
#include "cs163_queue.h"


//Implement these functions using a Circular Linked List
//Add at the rear
int queue::enqueue(const journal_entry & to_add)
{
	//Write the function here
    if(!rear)
    {
		rear = new q_node;
		rear->next = rear;
		rear->entry.copy_entry(to_add);
    }	
    else
    {
		q_node * temp = rear->next;
		rear->next = new q_node;
		rear = rear->next;
		rear->next = temp;
		rear->entry.copy_entry(to_add);
    }
    return 1;
}

//Remove the node at the front
int queue::dequeue ()
{

	//Write the function here
	if(!rear)
	   return 0;
	if(rear->next == rear)
	{
	   delete rear;
	   rear = NULL;
	}
	else
	{
	   q_node * temp = rear->next;
	   rear->next = temp->next;
	   delete temp;
	}
}

void queue::removal_entire(q_node *&rear)
{
	if(!rear)
		return;
	if(rear->next == rear)
	{
		delete rear;
		rear = NULL;
	}
	
	q_node * temp = rear;
	rear = rear->next;
	while(rear)
	{
		temp = rear->next;
		delete rear;
		rear = temp;
	}
}	

int queue::count_all(q_node * rear)
{
	if(!rear)
		return 0;
	if(rear->next == rear)
		return 1;
	
	q_note * current = rear;
	int cnt = 0;
	while(current != rear)
	{
		++cnt;
		current = current->next;
	}
	
	return cnt;
}