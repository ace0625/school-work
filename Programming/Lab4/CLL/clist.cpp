#include "clist.h"

void duplicate(node * & new_copy, node *original)
{
	if(!original)
	{
		new_copy = NULL;
		return;
	}
	else
	{
		if(!new_copy)
		{
			new_copy = new node;
			new_copy->data = original->data;
			original = original->next;
			new_copy->next = new_copy;
		}
			node * temp = new node;
			temp->data = original->data;
			new_copy->next = temp;
			new_copy = temp;
			
			return duplicate(new_copy->next, original->next);
	}
}