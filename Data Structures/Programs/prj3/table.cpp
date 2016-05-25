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

//This is the insert function that adds the post data to the table with
//an unique hash key created by key word
int table::insert(char * key_value, const post_entry & to_add)
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
int table::retrieve_table(char * keyword_to_find, post_entry & found)
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
		{
			//cout << "empty" << endl;  
		}	
		
		//cout << endl << "--##Chain: " << i << endl;
		node * current = hash_table[i]; 
		while(current)  //While the data is still valid,
		{
			current->entry.display_all();  //Output
			current = current->next;  //Traverse until the data is not valid
		}
	}
	return 1;
}

//This function reads all the external file and insert into a hash table.
int table::build()
{
	const int MAX_LINE_LEN = 500;
	const int MAX_TOKEN = 6;
	const char* const DELIM = ";";

	ifstream fin; //file input
	ofstream fout; //file output
	
	fin.open("data.txt");  //open up the file
	if(fin.fail()) 
		return 0;

	char * name, *date, *content, *likes, *key_words;
	//read data line by line
	while(!fin.eof()) 
	{
		char buff[MAX_LINE_LEN];
		fin.getline(buff, MAX_LINE_LEN);

		const char* token[MAX_TOKEN] = {};

		token[0] = strtok(buff, DELIM);
		if(!token[0]) break;
		
		for(int i = 1; i < MAX_TOKEN; i++) 
		{
			token[i] = strtok(0, DELIM);
		}
			
		name = new char[strlen(token[0]) + 1];
		strcpy(name, token[0]);
		
		date = new char[strlen(token[1]) + 1];
		strcpy(date, token[1]);

		content  = new char[strlen(token[2]) + 1];
		strcpy(content, token[2]);

		likes = new char[strlen(token[3]) + 1];
		strcpy(likes, token[3]);

		key_words = new char[strlen(token[4]) + 1];
		strcpy(key_words, token[4]);
	
	
		
		// cout << "\n>>>>>>> POST <<<<<<<<<<<" << endl;
		// cout << "-> NAME: " << name << endl;
		// cout << "-> DATE: " << date << endl;
		// cout << "-> CONTENT: " << content << endl;
		// cout << "-> LIKES: " << likes << endl;
		// cout << "-> KEY_WORDS: " << key_words << endl << endl;
		
		// get hash value
		int index = hash(key_words);
		//Insert a post to the hash table
		node * temp = new node;
		if(!temp->entry.create_entry(name, date, content, likes, key_words)) //if copy entry returns 0
		{
			delete temp; //deallocate temp pointer
			return 0;
		}
		temp->next = hash_table[index];
		hash_table[index] = temp; 
		// cout << "insert" << endl;
		
	}
	fin.close(); //close the file

	return 1;
}