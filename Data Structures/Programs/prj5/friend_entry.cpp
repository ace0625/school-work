//CS163
//Program#5
//Hyunchan Kim


#include "friend_entry.h"
using namespace std;

// constructor - initialize data member to NULL
friend_entry::friend_entry(void)
{
	event = NULL;
	ID = NULL;
	name = NULL;
}

// destructor - deallocate memory
friend_entry::~friend_entry(void)
{
	delete [] event;
	delete [] ID;
	delete [] name;
}

// create entry information
int friend_entry::create_entry(char * a_event, char * a_ID, char * a_name)
{
	event = new char[strlen(a_event) + 1];
	ID = new char[strlen(a_ID) + 1];
	name = new char[strlen(a_name) + 1];
	strcpy(event, a_event);
	strcpy(ID, a_ID);
	strcpy(name, a_name);
	
	return 1;
}

// copy entry information
int friend_entry::copy_entry(const friend_entry & copy_from)
{
	if(copy_from.event) 
	{
		event = new char[strlen(copy_from.event) + 1];
		strcpy(event, copy_from.event);
	}

	if(copy_from.ID) 
	{
		ID = new char[strlen(copy_from.ID) + 1];
		strcpy(ID, copy_from.ID);
	}

	if(copy_from.name) 
	{
		name = new char[strlen(copy_from.name) + 1];
		strcpy(name, copy_from.name);
	}
	
	return 1;
}

// retrieve entry information
int friend_entry::retrieve(friend_entry & found)
{
	if(!strcmp(event, found.event)) 
		return 0;
	
	if(event) 
	{
		found.event = new char[strlen(event) + 1];
		strcpy(found.event, event);
	}
	if(ID) 
	{
		found.ID = new char[strlen(ID) + 1];
		strcpy(found.ID, ID);
	}
	if(name) 
	{
		found.name = new char[strlen(name) + 1];
		strcpy(found.name, name);
	}

	return 1;
}

// compare
bool friend_entry::compare(char * match)
{
	if(!match)
		return false;
	if(strcmp(ID, match)==0)
		return true;
	else
		return false;
}

// display entry information
int friend_entry::display()
{
	cout << "EVENT NAME : " << event << endl;
	cout << "ID : " << ID << endl;
	cout << "NAME :" << name << endl << endl;
	
	return 1;
}


//get event information
char * friend_entry::get_event() 
{
	if(!event) 
		return NULL;
	return event;
}

//get ID information
char * friend_entry::get_ID() 
{
	if(!ID) 
		return NULL;
	return ID;
}
