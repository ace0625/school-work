#include "cs163_list.h"
using namespace std;

//Sum  all of the data together in a LLL
int list::sum_total()
{
	//Step 1 - Write your code here
/*	int total = 0;
	node * current = head;
	while(current!=NULL)
	{
	  total += current->data;
	  current = current->next;
	}
	return total;
*/

       //Recursion function call	
	sum_total(head);

}

//Now implement the function recursively!
int list::sum_total(node * head)
{
   	if(head == NULL)
	   return 0 ;
	else
	{
          return  head->data + sum_total(head->next);
	}
}

// *************************************************
//Remove the last node in a LLL. Return false if the
//list is empty and nothing is removed
bool list::remove_last()
{
       //Step 2 - Write your code here

/*	node *temp1, *temp2;
	if(head==NULL)
	   return false;
	else
	{
		temp1 = head;
		while(temp1->next !=NULL)
		{
		   temp2 = temp1;
		   temp1 = temp1->next;
		}
		delete temp1;
		temp2->next = NULL;
		return true;	
	}

*/
	remove_last(head, tail);
}


//Now implement the function recursively!
bool list::remove_last(node * & head, node * & tail)
{
   if(head == NULL)
	return false;
   else if(head == tail)
   {
       delete tail;
       head = NULL;
       tail = NULL;
       return true;
   }
   else 
   {
	remove_last(head->next, tail);
        return true;
   }

}

// ************************************************
//Remove all nodes in a LLL. Remove false if there is
//nothing to remove
bool list::remove_all()
{
       //Step 3 - Remove all nodes in a LLL
 /*	node * temp;
	while(head)
	{
	   temp = head->next;
	   delete head;
           head = temp;
	}
	return true;
*/
	remove_all(head);
}

//Now implement the function recursively!
bool list::remove_all(node * & head)
{
	
   if(head == NULL)
	return false;
   else
   {
	remove_all(head->next);
        delete head;
        head = NULL;
   }
   return true;
	

}


// ************************************************
//Return true if the requested item (sent in as an argument)
//is in the list, otherwise return false
bool list::find_item(int item_to_find)
{
        //Step 4 - Write your code here
   /* while(head != NULL)
    {
	if(head->data == item_to_find)
		return true;
        else
	   head = head->next;
    }

    return false;
*/
    
    find_item(head, item_to_find);
}

//Now implement the function recursively!
bool list::find_item(node * head, int item_to_find)
{
	if(head == NULL)
	   return false;
	else
	{
 	   if(head->data == item_to_find)
		return true;
	   else 
	     find_item(head->next, item_to_find);
	}
}


// ************************************************
//Make a complete copy of a LLL
bool list::copy(list & from)
{
        //Step 5 - Write your code here
/*	node * current;
	node * from_current;

	if(!from.head)
	   return false;
	else
	{
	    from_current = from.head;
	    head = new node;
	    head->data = from.head->data;
	    from_current = from_current->next;
	    current = head;
	    while(from_current)
	    {
		current->next = new node;
		current = current->next;
		current->data = from_current->data;
		from_current = from_current->next;
	    }
	    current->next = NULL;
	    tail = current;
	    return true;
	}	
*/

   	copy(head, tail, from.head);
}

//Now implement the function recursively
bool list::copy(node * & dest_head, node * & dest_tail, node * source)
{
	if(!source)
	{
	      dest_head = dest_tail = NULL;
	      return false;
	}
	else
	{
		dest_head = new node;
		dest_head->data = source->data;
	
		if(!source->next)
 			 dest_tail = dest_head;

		 copy(dest_head->next, dest_tail, source->next);
	}
	return true;
}
















