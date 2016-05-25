//CS163
//Assignment #4
//Hyunchan kim

//app_entry.h

//This is the header file for managing application entry
//prototype create, copy, retrieve, display

#ifndef _APP_ENTRY_H
#define _APP_ENTRY_H

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

class app_entry
{
	public:
		app_entry(); //constructor;
		~app_entry(); //destructor;
		int create_entry(char * app_name, char * key_word, char * description, float rating); //create an entry
		int copy_entry(const app_entry & copy_from); //copy an app entry
		int retrieve(char * matching_keyword, app_entry & found); //retrieve by key word
		int display_all(); //display all data
		int str_compare(const char* s2); //compare with input
		bool again(); //again function
		
	private:
	
		char * application_name; //app name
		char * key_word; //key word
		char * description; //description
		float rating; //rating
};

#endif