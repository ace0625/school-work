//CS163
//Assignment #4
//Hyunchan kim

//bst.h

#ifndef _BST_H
#define _BST_H

#include <iostream>
#include <cstring>
#include "app_entry.h"

struct node
{
	app_entry * entry;
	node * left;
	node * right;
};

class bst
{
	public:
		bst(); //constructor
		~bst(); //destructor
		int insert(char * key_word, const app_entry & to_add); //inserting function
		int retrieve(char * keyword_to_find, const app_entry & to_find); //retrieve function
		int remove(char * keyword_to_remove); //remove by keyword
 		int remove_all(); //remove all data
		int display(char * key_word); //display the matching data by key word
		int display_all_bst(); //display all tree
		
	private:
		int insert(node * & root, char * key_word, const app_entry & to_add); //inserting function
		int retrieve(node * root, char * keyword_to_find, const app_entry & to_find); //retrieve function
		int remove(node * & root, char * keyword_to_remove); //remove by keyword
		int remove_all(node * & root); //remove all data
		int display(node * & root, char * key_word); //display the matching data by key word
		int display_all_bst(node * root); //display all tree
		
		node * root; //root node
	
};

#endif

