//CS163
//Program #5
//Hyunchan Kim

#ifndef _FRIEND_ENTRY_H
#define _FRIEND_ENTRY_H

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

class friend_entry
{
	public:
		friend_entry(void); //constructor
		~friend_entry(void); //destructor
		int create_entry(char * a_event, char * a_ID, char * a_name); //create an entry
		int copy_entry(const friend_entry & copy); //copy constructor
		//int retrieve(char* matching_name, friend_entry & found) const;   
		int retrieve(friend_entry & found);  //retrieve
		bool compare (char * match); //compare
		int display(); //display
		char * get_event(); //get event info
		char * get_ID(); //get ID info
	private:
		char * event;
		char * ID;
		char * name;
};
#endif
