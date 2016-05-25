#include "cs163_list.h"
using namespace std;




//Step 3 - Implement these three functions
//Add to the end of the LLL as efficiently as possible
int list::add(journal_entry & to_add)
{
           //Implement this function using the
           //journal entry functions we just wrote!

   if(!head)
   {
	head = tail = new node;
	tail->next = NULL;
	tail->entry.copy_entry(to_add);
   }
   else
   {
	tail->next = new node;
	tail = tail->next;
	tail->next = NULL;
	tail->entry.copy_entry(to_add);
   }
   
   return 1;
}

//Determine if there is a match with the title passed in
//and if so provide the matching journal entry back to the
//client program through the second argument.
//Return a zero if no match is found
int list::find(char matching_title[], journal_entry & found)
{
	//Your code goes here!           
    if(!head)
	return 0;
    
    node * current = head;
    while(current)
    {
	if(current->entry.retrieve(matching_title, found));
	  return 1;
	
	current = current->next;
    }
    return 1;
}


//Display all journal entries
//Return false if there are no entries
int list::display(void)
{
         //Your code goes here!
    if(!head)
	return 0;

    node * current = head;
    while(current)
    {
	current->entry.display();
	current = current->next;
    }
    return 1;	

}


//Step 4 - Copy the list passed in as an argument
//and add the nodes to the end of the current list
int list::append(list & source)
{

        //Your code goes here!
	if(!source.head)
	   return 0;
 
	node * current = source.head;
	while(current)
	{
	   add(current->entry);
	   current = current->next;
	}
	return 1;
}





























