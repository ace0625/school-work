//CS202
//Program #2
//Hyunchan Kim
//menu_data.cpp

/*
	This is menu_data.cpp that implements 
	the functions for menu
*/

#include "menu_data.h"

/*
	default constructor
*/
menu_data::menu_data() : menu_name(NULL) {}

/*
	constructor with menu name
*/
menu_data::menu_data(char * a_menu_name)
{
	menu_name = new char[strlen(a_menu_name) + 1];
	strcpy(menu_name, a_menu_name);	
}

/*
	copy constructor
*/
menu_data::menu_data(const menu_data & copy_from)
{
	if(copy_from.menu_name)
	{
		menu_name = new char[strlen(copy_from.menu_name) + 1];
		strcpy(menu_name, copy_from.menu_name);
	}
}

/*
	destructor
*/
menu_data::~menu_data()
{
	menu_name = NULL;
}

/*
	display menu function
*/
void menu_data::display_menu_data()
{
	cout << "MENU : " << menu_name << endl;
}

/*
	get menu
*/
char * menu_data::get_menu()
{
	return menu_name;
}

//========================================================================

/*
	entrees class implementaion
*/
	

/*
	entrees default constructor
*/
entrees::entrees() {}

/*
	entrees constructor with menu name
*/
entrees::entrees(char * a_menu_name)
{
	menu_name = new char[strlen(a_menu_name) + 1];
	strcpy(menu_name, a_menu_name);	
}
/*
	entrees default constructor
*/
entrees::entrees(const entrees & copy_from) 
{
	if(copy_from.menu_name)
	{
		menu_name = new char[strlen(copy_from.menu_name) + 1];
		strcpy(menu_name, copy_from.menu_name);
	}
}

/*
	This is returning the pointer type
*/
menu_data * entrees::copy_pointer()
{
	return new entrees(*this);
}

/*
	Display entree data
*/
void entrees::display_menu_data()
{
	cout << "\n<< Entrees >>" << endl;
	cout << menu_name << endl;
	cout << "============================" << endl;
}

//========================================================================


/*
	appetizers class implementation 
*/


/*
	appetizers default constructor
*/
appetizers::appetizers() {}

/*
	appetizers constructor with menu name
*/
appetizers::appetizers(char * a_menu_name)
{
	menu_name = new char[strlen(a_menu_name) + 1];
	strcpy(menu_name, a_menu_name);	
}

/*
	appetizers default constructor
*/
appetizers::appetizers(const appetizers & copy_from) 
{
	if(copy_from.menu_name)
	{
		menu_name = new char[strlen(copy_from.menu_name) + 1];
		strcpy(menu_name, copy_from.menu_name);
	}
}

/*
	This is returning the pointer type
*/
menu_data * appetizers::copy_pointer()
{
	return new appetizers(*this);
}

/*
	Display appetizers data
*/
void appetizers::display_menu_data()
{
	cout << "\n<< Appetizers >>" << endl;
	cout << menu_name << endl;
	cout << "============================" << endl;
}


//========================================================================


/*
	drinks class implementation
*/


/*
	drinks default constructor
*/
drinks::drinks() {}

/*
	drinks constructor with menu name
*/
drinks::drinks(char * a_menu_name)
{
	menu_name = new char[strlen(a_menu_name) + 1];
	strcpy(menu_name, a_menu_name);	
}

/*
	drinks default constructor
*/
drinks::drinks(const drinks & copy_from) 
{
	if(copy_from.menu_name)
	{
		menu_name = new char[strlen(copy_from.menu_name) + 1];
		strcpy(menu_name, copy_from.menu_name);
	}
}

/*
	This is returning the pointer type
*/
menu_data * drinks::copy_pointer()
{
	return new drinks(*this);
}

/*
	Display drinks data
*/
void drinks::display_menu_data()
{
	cout << "\n<< Drinks >>" << endl;
	cout << menu_name << endl;
	cout << "============================" << endl;
}


