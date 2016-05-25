//CS163
//Assignment #3
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

//const int MAX = 5; 

class app_entry
{
	public:
		app_entry(); //constructor;
		~app_entry(); //destructor;
		int create_entry(char * app_name, char * key_word, char * description, float rating); //create an entry
		int copy_entry(const app_entry & copy_from); //copy an app entry
		int retrieve(char * matching_keyword, app_entry & found); //retrieve by key word
		int display_all(); //display all data
		bool again();
	private:
		char * app_name;
		char * key_word;
		char * description;
		float rating;
};

#endif