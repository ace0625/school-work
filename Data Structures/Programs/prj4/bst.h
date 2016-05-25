//CS163
//Assignment #4
//Hyunchan kim

//bst.h

#ifndef _BST_H
#define _BST_H

#include <iostream>
#include <cstring>
#include "concept_entry.h"

struct node
{
	concept_entry entry;
	node * left;
	node * right;
};

class bst
{
	public:
		bst(); //constructor
		~bst(); //destructor
		int build();
		int insert(char * key_word, const concept_entry & to_add); //inserting function
		int retrieve(char * keyword_to_find); //retrieve function
		int remove(char * keyword_to_remove); //remove by keyword
 		int remove_all(); //remove all data
		int display(char * key_word); //display the matching data by key word
		int display_all_bst(); //display all tree
		int display_concept(); //display concept names
		
	private:
		int insert(node * & root, char * key_word, const concept_entry & to_add); //inserting function
		int retrieve(node * root, char * keyword_to_find); //retrieve function
		int remove(node * & root, char * keyword_to_remove); //remove by keyword
		int remove_all(node * & root); //remove all data
		int display(node * & root, char * key_word); //display the matching data by key word
		int display_all_bst(node * root); //display all tree
		int display_concept(node * root); //list concept names
		
		node * root; //root node
	
};

#endif

