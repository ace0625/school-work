//CS163
//Assignment #4
//Hyunchan kim

//concept_entry.h

//This is the header file for managing concept entry
//prototype create, copy, retrieve, display

#ifndef _CONCEPT_ENTRY_H
#define _CONCEPT_ENTRY_H

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;

class concept_entry
{
	public:
		concept_entry(); //constructor;
		~concept_entry(); //destructor;
		int create_entry(char * a_number, char * a_concept_name, char * a_data_structure, char * an_advantage, char * a_disadvantage); //create an entry
		int copy_entry(const concept_entry & copy_from); //copy a concept entry
		int retrieve(char * matching_keyword, concept_entry & found); //retrieve by key word
		int display_all(); //display all data
		int display_concept(); //display concept name
		int str_compare(const char* s2); //compare with input
		bool again(); //again function
		
	private:
		char * number; //concept number
		char * concept; //concept name
		char * data_structure; //data_structure
		char * advantage; //advantage
		char * disadvantage;  //disadvantage
};

#endif