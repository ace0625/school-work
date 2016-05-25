//CS202
//Program #2
//Hyunchan Kim
//list_lll.cpp

/*
	This is list_lll.h implementation
*/

#include "list_lll.h"

/*
	defualt constructor implementation
*/
list_lll::list_lll() : head(NULL) {}

/*
	destructor implementation
*/
list_lll::~list_lll()
{
	remove_all();
}

/*
	craete a data with ingredient and kind
*/
int list_lll::create(char * ingredient, int kind)
{
	node_lll * current = new node_lll(ingredient, kind);
	if(!head)
	{
		head = current;
		head->set_next(NULL);
		return 1;
	}
	else
	{
		current->set_next(head);
		head = current;
		return 1;
	}
}

/*
	remove a matching data
*/
int list_lll::remove(char * ingredient)
{
	if(!head)
		return 0;

	node_lll * current = head;
	while(current)
	{
		if((current->get_next()) && (strcmp(current->get_next()->get_menu_name(), ingredient) == 0))
		{
			node_lll * temp = current;
			node_lll * temp2 = temp->get_next();
			node_lll * temp3 = temp2->get_next();
			temp->get_next() = temp3;
			temp2->get_next() = NULL;
			delete temp2;
			return 1;
		}
		if(!current->get_next()->get_next() && strcmp(current->get_next()->get_menu_name(), ingredient) == 0)
		{
			cout << current->get_next()->get_menu_name() << endl;
			return 1;
		}
		current = current->get_next();
	}
	return 1;
}

/*
	retrieve a data
*/
int list_lll::retrieve(char * ingredient)
{
	node_lll * current = head;
	while(current)
	{
		if(strcmp(current->get_menu_name(), ingredient) == 0)
		{
			cout << "The matching data has been found!! " << endl;
			cout << ">>>>  " << current->get_menu_name() << endl;
		}
		current = current->get_next();
	}
	return 1;
}

/*
	remove all data
*/
int list_lll::remove_all()
{
    if(!head)
        return 0;
    node_lll * current = head;
    while(current)
    {
        head = head->get_next();
        delete current;
        current = head;
    }
    head = NULL;

    return 1;
}


/*
	display all data in LLL
*/
int list_lll::display_all()
{
	if(!head)
	{
		cout << "Empty data" << endl;
		return 0;
	}
	node_lll * current = head;
	while(current)
	{	
		cout << "===================== " << endl;
		current->node_lll_display();
		current = current->get_next();
	}
	return 1;
}





