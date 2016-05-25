#include "cs163_table.h"
using namespace std;

/* Implement these three functions for this lab */
table::table(int size)
{
      //Allocate the hash table and initialize each
      //element and data member.
	  hash_table = new node*[size];
	  for(int i=0; i < size; ++i)
		  hash_table[i] = NULL;
	  
	  hash_table_size = size;

}

//Using a hash function, insert a new value into the 
//head of the chain
int table::insert(char * key_value, const journal_entry & to_add)
{
       //Place your code here
	   int index;
	   int hash = 0;
	   for(int i = 0; i < strlen(key_value); i++)
	   {
		   hash += (int)key_value[i];
	   }
	   index = hash % hash_table_size;
	   
 	   node * temp = new node;
	   if(!temp->entry.copy_entry(to_add))
	   {
		   delete temp;
		   return 0;
	   }
	   temp->next = hash_table[index];
	   hash_table[index] = temp; 
	
	   return 1;

}

//Using a hash function determine which chain to search
//then return 0 if no match is found
int table::retrieve(char * title_to_find, journal_entry & found) const
{

	int index;
    int hash = 0;
	for(int i = 0; i < strlen(title_to_find); i++)
	{
		hash += (int)title_to_find[i];
	}
	index = hash % hash_table_size;
        
	bool success = false;
	node * current = hash_table[index];
	while(current && !success)
	{
		success = current->entry.retrieve(title_to_find, found);
		current = current->next;
	}
	return success; 

}















