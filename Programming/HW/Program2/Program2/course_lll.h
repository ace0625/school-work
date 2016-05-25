//CS202
//Assignment#2
//Hyunchan Kim
//course_lll.h

//This header file composes of LLL class and node 

#include "bclass.h"
#include "sclass.h"

#ifndef _COURSE_LLL_H_
#define _COURSE_LLL_H_

//=======================================================================
//This program is about Computer science major curriculum that shows you
//what classes you have to take before getting into CS program and your
//status with your grade and GPA by the classes you have taken so far.
//First, this program reads in the CS curriculum data from a text file
//and analyzes with your classes taken. 
//=======================================================================

//node class derived from base class
class node: public bclass
{
	public:
		node(); // default constructor
		node(bclass* a_bclass); //copy constructor
		node(char* a_course_type, int a_course_code, char* a_course_name, int a_course_credit); //copy constructor
		~node(); // destructor
		node *& go_next(); // go to the next node
		bool if_next(); //check if there's the next node
		void display_lnode(); //display LLL nodes
		int compare_node(const node* a_node); //comparing nodes
		int retrieve_bclass(const char* course_type, int course_code); //retrieve function with class type and class code
		int find(const char* a_course_type, int a_course_code); //find a node with class type and class code
		int get_course_effect(); //receive the class type such as core, required, non-cs
	
	protected:
		node* next; //next pointer
};

//linear linked list class
class course_lll: public node
{
	public:
		course_lll(); // default constructor
		~course_lll(); // default destructor
		int load_courses(char course_file_name[]); //read in a text file, data
		void add(bclass* a_bclass); // add a data to the linear linked list
		void add_course(char* a_course_type, int a_course_code, char* a_course_name, int a_course_credit, int a_course_effect); //adding a data with type, code, name, credit information
		void remove(const char* course_type, const int course_code); // remove index of data ( in deal datas)
		void display_all(); // displaying data
		void display_all(node* head); // wrapper function of display
		int find_course(const char* a_course_type, int a_course_code); //finding class data
		int remove_all(); //removing all class data
		int remove_all(node * & head); //wrapper function of remove all
		void set_grade(sclass* s1); //setting grade data
		void calculate_gpa(); //calculating GPA

	protected:
		node* head; //head pointer
};

#endif