// CS202
// Program #1
// Hyunchan Kim
// school.h

#ifndef _SCHOOL_H
#define _SCHOOL_H

#include <iostream>
#include <cstring>
#include <fstream>
#include "school_data.h"
#include "household_graph.h"
using namespace std;

/*
	This is school class that represents coordianation of school
	and derived from household_graph
*/
class school : public household_graph
{
	public:
		school(); // default constructor
		~school(); // destructor
		int load_school_data(); // read in external file
		int add_school(char * a_name, char * a_age, char * a_class_num, char * best_size, char * ave_size); //create a school
		void remove_all(); //remove all data
		//int remove_all(dll_node * head); //remove all data by node
		//int remove(int pos); //remove an item by postion
		int get_length(); //get length
		int retrieve_school(); // find a school
		int display_all(); //display all data

	private:
		dll_node * head;
};


#endif