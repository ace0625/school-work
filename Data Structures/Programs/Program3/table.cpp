//CS163
//Assignment #3
//Hyunchan kim

//table.cpp

#include "table.h"


//this class is implementing the table structure
//adding with key value(key word), displaying, and removing

//Table default constructor
table::table(int size)
{
	//cout << "table()" << endl;
	hash_table = new node * [size];
    for(int i = 0; i < size; i++) 
	{
        hash_table[i] = NULL; //initialize hash table
    }
	  hash_table_size = size; //set the table size

}

//Table default destructor
table::~table()
{
	//cout << "~table()" << endl;
	for(int i = 0; i < hash_table_size; i++)
	{
		if(hash_table[i]) 
		{
			node* temp = hash_table[i];
			node * temp2;
			while(temp->next) 
			{
				temp2 = temp->next;
				delete temp; //deallocate hash table
				temp = temp2;
		}
		temp = NULL; //set to NULL
		temp2 = NULL; //set to NULL
		}
	}
	delete [] hash_table; //delete the table
}

//This is the hash function that creates an unique hash key by key value
int table::hash(char key_value[])
{
	int keyLen = strlen(key_value);
	int temp = 0;
	int sum = 0;
	int index;
	for (int i = 0; i < keyLen; i++) 
	{
		temp = key_value[i];
		sum += temp;
	}
	index = sum % hash_table_size;
	//cout << "key chain: " << index << endl;
	return index;
}

//This is the insert function that adds the application data to the table with
//an unique hash key created by key word
int table::insert(char * key_value, const app_entry & to_add)
{
	// get hash value
    int index = hash(key_value);

	node * temp = new node;
	if(!temp->entry.copy_entry(to_add)) //if copy entry returns 0
	{
		delete temp; //deallocate temp pointer
		return 0;
	}
	temp->next = hash_table[index];
	hash_table[index] = temp; 
	cout << "insert" << endl;
    return 1;
}

//Using a hash function determine which chain to search
//then return 0 if no match is found
int table::retrieve_table(char * keyword_to_find, app_entry & found)
{
	//cout << "retrieve table" << endl;
	int index = hash(keyword_to_find); //get a hash key
	
	bool success = false; //result value
	node * current = hash_table[index];
	while(current && !success)
	{
		success = current->entry.retrieve(keyword_to_find, found);
		current = current->next;
	}
	return success; 
}

//This function displays all application data in the table
int table::display_all_table()
{
	//cout << "display all table" << endl;
	for(int i = 0; i < hash_table_size; ++i)
	{
	  if(!hash_table[i])  //If empty list, display nothing
	  //	cout << "empty" << endl;
		
		cout << endl << "--##Chain: " << i << endl;
		node * current = hash_table[i]; 
  
		while(current)  //While the data is still valid,
		{
			current->entry.display_all();  //Output
			current = current->next;  //Traverse until the data is not valid
		}
	}
	return 1;
}
