//CS163
//Assignment #3
//Hyunchan kim

//table.h

//this class is the header file for table structure
//prototype insert, retrieve_table, display all table
#include "app_entry.h"

struct node
{
	app_entry entry;
	node * next;
};

class table
{
public:
	table(int size=5); //constructor	
	~table(); //destructor
	int hash(char key_value[]); //hash function
	int insert(char * key_value, const app_entry & to_add); //inserting function
	int retrieve_table(char * keyword_to_find, app_entry & found); //retrieve function
	//int display(char * match, char * key_value);
	int display_all_table(); //display all data
	
private:
	node ** hash_table;  //a dynamically allocated array of head pointers
	int hash_table_size;

};
