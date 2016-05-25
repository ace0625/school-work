//CS202
//Program #2
//Hyunchan Kim
//bst.h

/*
	This class is for binary search tree
*/

#ifndef _BST_H
#define _BST_H
#include "node_bst.h"

class bst
{
	public:
		bst(); //default constructor
		~bst(); //destructor
		int key(char * a_ingredient); //build a unique key
		int create(char * a_ingredient, int a_distinct, list_lll * a_list); //create a node
		int retrieve(char * a_ingredient); //retrieve a data
		int remove_all(); //remove all data
		int display_all_bst(); //display all nodes

	protected:
		int create(char * a_ingredient, int a_distinct, list_lll * a_list, node_bst * & root); //wrapper function for create
		int retrieve(char * a_ingredient, node_bst * root); //wrapper function for retrieve
		int remove_all(node_bst * & root); //wrapper function for remove all
		int display_all_bst(node_bst * & root); //wrapper function for display all bst
		node_bst * root;
};

#endif