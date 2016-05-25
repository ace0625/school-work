//CS202
//Program #2
//Hyunchan Kim
//node_bst.h

/*
	This is node_bst.h, This will construct the node for bst with ingredient information
*/
#ifndef _NODE_BST_H
#define _NODE_BST_H

#include "node_lll.h"
#include "list_lll.h"
/*
	This is ingredient class that handles ingredient data
*/
class ingredient
{
	public:
		ingredient(); //default constructor
		~ingredient(); //destructor
		ingredient(char * a_ingredient, int distinguisher); //constructor with ingredient and distinguisher
		ingredient(const ingredient & copy_from); //copy constructor
		int ingredient_display(); //display intredient
		char * get_ingred(); //get ingredient
		bool ingredient_compare(int kind); //compare ingredients

	protected:
		char * ingredient_name;
		int distinct;
};

/*
	this is node class for bst 
	and ingredient class is derived.
*/
class node_bst : public ingredient
{
	public:
		node_bst(); // default constructor
		node_bst(list_lll * a_list, char * a_ingredient, int a_distinct); // constructor with ingredient and distinguisher
		node_bst(const node_bst & copy_from); // copy constructor
		node_bst * & go_left(); // get left pointer
		node_bst * & go_right(); // get right poiter
		int display_list();
		//int display_node_data();

	protected:
		node_bst * left;
		node_bst * right;
		list_lll * list;
};

#endif

