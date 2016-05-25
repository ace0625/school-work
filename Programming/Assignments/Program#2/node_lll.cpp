//CS202
//Program #2
//Hyunchan Kim
//node_lll.cpp

/*
	This is node_lll.h implementation
*/

#include "node_lll.h"

/*
	node_lll default constructor
*/
node_lll::node_lll() : a_menu(NULL), next(NULL) {}

/*
	node_lll copy constructor with set_menu function
*/
node_lll::node_lll(char * menu_name, int kind)
{
	set_menu(menu_name, kind);
}
/*
	node_lll copy constructor
*/
node_lll::node_lll(const node_lll & copy_from)
{
	a_menu = copy_from.a_menu->copy_pointer();
}

/*
	set_next pointer
*/
void node_lll::set_next(node_lll * head)
{
	next = head;
}

/*
	get next, return next pointer
*/
node_lll * & node_lll::get_next()
{
	return next;
}

/*
	get menu name
*/
char * node_lll::get_menu_name()
{
	return a_menu->get_menu();
}

/*
	display nodes
*/
int node_lll::node_lll_display()
{
	a_menu->display_menu_data();
	return 1;
}

/*
	set the menu name and kind
*/
void node_lll::set_menu(char * a_menu_name, int kind)
{
	if(kind == 0) // make entrees instance
	{
		a_menu = new entrees(a_menu_name);
	}
	if(kind == 1) //make appetizers instance
	{
		a_menu = new appetizers(a_menu_name);	
	}
	if(kind == 2) //make drinks instance
	{
		a_menu = new drinks(a_menu_name);
	}
}