//CS202
//Program #2
//Hyunchan Kim
//menu_data.h
/*
	This is menu data class that will be base class for
	entrees, appetizer, drinks
*/
#ifndef _MENU_DATA_H
#define _MENU_DATA_H

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class menu_data
{
	public:
		menu_data(); //default constructor
		menu_data(char * a_menu_name); //constructor with menu name
		menu_data(const menu_data & copy_from); //copy constructor
		virtual ~menu_data(); //virtual destructor
		virtual menu_data * copy_pointer() = 0;
		virtual void display_menu_data(); //virtual display function
		char * get_menu(); //get menu

	protected:
		char * menu_name; //name of menu 
};

/*
	This is entrees class derived from base class, menu_data
*/
class entrees : public menu_data
{
	public:
		entrees(); //default constructor
		entrees(char * a_menu_name); //constructor with menu name
		entrees(const entrees & copy_from); //copy constructor
		menu_data * copy_pointer();
		void display_menu_data(); //virtual function
};

/*
	This is appetizers class derived from base class, menu_data
*/
class appetizers : public menu_data
{
	public:
		appetizers(); //default constructor
		appetizers(char * a_menu_name); //constructor with menu name
		appetizers(const appetizers & copy_from); //copy constructor
		menu_data * copy_pointer();
		void display_menu_data(); //virtual display function
};

/*
	This is drinks class derived from base class, menu_data
*/
class drinks : public menu_data
{
	public:
		drinks(); //default constructor
		drinks(char * a_menu_name); //constructor with menu name
		drinks(const drinks & copy_from); //copy constructor
		menu_data * copy_pointer();
		void display_menu_data(); //virtual display function
};

#endif