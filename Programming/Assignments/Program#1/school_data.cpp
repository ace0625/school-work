// CS202
// Program #1
// school_data.cpp

#include "school_data.h"

/*
	school data default constructor implementation
*/
school_data::school_data() : name_of_school(NULL), age(NULL), class_num(NULL), best_class_size(NULL), ave_class_size(NULL) {}


/*
	copy constructor with school data object
*/
school_data::school_data(const school_data & copy_from)
{
	if(copy_from.name_of_school)
	{
		name_of_school = new char[strlen(copy_from.name_of_school) + 1];
		strcpy(name_of_school, copy_from.name_of_school);
	}
	if(copy_from.age)
	{
		age = new char[strlen(copy_from.age) + 1];
		strcpy(age, copy_from.age);
	}
	if(copy_from.class_num)
	{
		class_num = new char[strlen(copy_from.class_num) + 1];
		strcpy(class_num, copy_from.class_num);
	}
	if(copy_from.best_class_size)
	{
		best_class_size = new char[strlen(copy_from.best_class_size) + 1];
		strcpy(best_class_size, copy_from.best_class_size);
	}
	if(copy_from.ave_class_size)
	{
		ave_class_size = new char[strlen(copy_from.ave_class_size) + 1];
		strcpy(ave_class_size, copy_from.ave_class_size);
	}
}

/*
	constructor implementation with dynamic memeory inputs
*/
school_data::school_data(char * name, char * an_age, char * num, char * best_size, char * ave_size)
{
	name_of_school = new char[strlen(name) + 1];
	strcpy(name_of_school, name);
	
	age = new char[strlen(an_age) + 1];
	strcpy(age, an_age);
	
	class_num = new char[strlen(num) + 1];
	strcpy(class_num, num);
	
	best_class_size = new char[strlen(best_size) + 1];
	strcpy(best_class_size, best_size);
	
	ave_class_size = new char[strlen(ave_size) + 1];
	strcpy(ave_class_size, ave_size);
}

/*
	school data destructor
*/
school_data::~school_data()
{
	delete [] name_of_school;
	delete [] age;
    delete [] class_num; 
	delete [] best_class_size;
	delete [] ave_class_size;

}

/*
	display school information
*/
int school_data::display_school()
{
	cout << endl;
	cout << name_of_school << endl;
	cout << age << endl;
    cout << class_num << endl; 
	cout << best_class_size << endl;
	cout << ave_class_size << endl;

	return 1;
}

//=========================================================================================================

/*
	dll_node default constructor
*/
dll_node::dll_node()
{
	next = NULL;
	prev = NULL;
}

/*
	dll_node destructor	
*/
dll_node::~dll_node() {}

/*
	dll_node copy constructor with school data object
*/
dll_node::dll_node(const school_data & a_copy) : school_data(a_copy) {}

/*
	copy constructor
*/
dll_node::dll_node(const dll_node & a_node) : school_data(a_node) {}

/*
	copy functoin with using derivation list 
*/
dll_node::dll_node(char * name, char * a_age, char * num, char * best_size, char * ave_size) : school_data(name, a_age, num, best_size, ave_size) {}

/*
	go to next 
*/
dll_node * & dll_node::go_next()
{
	return next;
}

/*
	go to previous
*/
dll_node * & dll_node::go_prev()
{
	return prev;
}






