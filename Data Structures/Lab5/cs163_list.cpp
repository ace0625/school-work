#include "cs163_list.h"

/* These are the functions you will be implementing */
/* USE RECURSION! */
int insert_after(node * & head)
{
	int count = 0;
	if(!head)
		return 0;
	
	if(head->data == 2)
	{
		node * temp = new node;
		temp->data = 10;
		temp->next = head->next;
		temp->previous = head;
		head->next = temp;
		head->next->previous = temp;
	}
		
	return count = insert_after(head->next);
	
}

int insert_before(node * & head)
{
	int count = 0;
	if(!head)
		return 0;
	
	count = insert_before(head->next);
	if(head->data == 2)
	{
		node * temp = new node;
		temp->data = 10;
		temp->next = head;
		temp->previous = head->previous;
		head->previous = temp;
		head = temp;
	}
	
	return 1;
}

int display_last_two(node * head)
{
	int value = 0;
	if(!head||!head->next||!head->next->next)
		cout << head->data << " -> " << head->next->data << endl;
	
	else 
		value = display_last_two(head->next);
	
	return 1;

}
int remove_last_two(node * & head)
{
	int value = 0;
	if(!head||!head->next||!head->next->next)
	{
		head->next = NULL;
		delete head->next;
		delete head;
		head = NULL;
	}
	else 
		value = remove_last_two(head->next);
	
	return 1;
}


//challenge:
bool same_length(node * head1, node * head2)
{
	if(!head1 || !head2)
	{
		if(!head1 && !head2)
			return true;
		else 
			return false;
	}
	return same_length(head1->next, head2->next);
}






















