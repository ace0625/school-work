// CS202
// Program #1
// school_data.h

#ifndef _SCHOOL_DLL_H
#define _SCHOOL_DLL_H

#include <iostream>
#include <cstring>
using namespace std;

/*
	This is school_data class contains school informatoin
	from an external school file
*/
class school_data
{
    public:
        school_data(); //default constructor
        school_data(const school_data & copy_from); //copy constructor
        school_data(char * name, char * an_age, char * num, char * best_size, char * ave_size); //copy constructor
        ~school_data(); //destructor
        int display_school(); //display school data function

	 protected:
        char * name_of_school;
        char * age;
        char * class_num;
        char * best_class_size;
        char * ave_class_size;
};

/*
	node class for doulbly linked list 
*/
class dll_node : public school_data
{
	public:
		dll_node(); //default constructor
		~dll_node(); //destructor
		dll_node(const school_data & a_copy); //copy constructor
		dll_node(const dll_node & a_node); //copy constructor
		dll_node(char * name, char * a_age, char * num, char * best_size, char * ave_size); //copy constructor
		dll_node * & go_next(); // go next 
		dll_node * & go_prev(); // go previous

	protected:
		dll_node * next;
		dll_node * prev;
};

#endif