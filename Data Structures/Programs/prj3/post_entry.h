//CS163
//Assignment #3
//Hyunchan kim

//post_entry.h



#ifndef _POST_ENTRY_H
#define _POST_ENTRY_H

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;

//const int MAX = 5; 

class post_entry
{
	public:
		post_entry(); //constructor;
		~post_entry(); //destructor;
		int create_entry(char * a_name, char * a_date, char * a_content, char * a_like, char * a_key_words); //create an entry
		int copy_entry(const post_entry & copy_from); //copy an entry
		int retrieve(char * matching_keyword, post_entry & found); //retrieve by key word
		int display_all(); //display all data
		bool again();
		
	private:
		char * name;
		char * date;
		char * content;
		char * likes;
		char * key_words;
		
};

#endif