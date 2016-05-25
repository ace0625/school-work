//CS202
//Assignment#2
//Hyunchan Kim
//bst.h
//=======================================================================
//This program is about Computer science major curriculum that shows you
//what classes you have to take before getting into CS program and your
//status with your grade and GPA by the classes you have taken so far.
//First, this program reads in the CS curriculum data from a text file
//and analyzes with your classes taken. 
//=======================================================================

#include "course_lll.h"
#include "sclass.h"
#ifndef _BST_H_
#define _BST_H_
//this header file composes of base of binaray search tree

class snode: public sclass
{
	public:
		snode(); //default constructor
		~snode(); //destructor
		snode(sclass* a_sclass); //copy constructor
		snode(char* a_course_type, int a_course_code, int a_course_term, char* a_course_grade); //copy constructor
		snode *& go_next(); //go to next node
		bool if_next(); //check if there's next node
		void display_snode(); //displaying node
		int retrieve(const char* a_course_type, int a_course_code); //retrieve a class by class type and class code

	protected:
		snode* next; //next pointer
};

//BST node class derived from snode(student node)
class bst_node: public snode
{
	public:
		bst_node();//default constructor
		~bst_node();//destructor
		bst_node(const int a_term); //copy constructor
		bst_node *& go_left(); //go to left
		bst_node *& go_right(); //go to right
		bool if_left(); //check if there's left node
		bool if_right(); //check if there's right node
		void display_bst(); //display BST
		int get_term(); //get the term data
		int compare(int a_term); //compare the term
		void set_term(int a_term); //set the term data
		bool match_term(const int a_term); //check if they are the same term
		void add_snode(int a_term, sclass* a_sclass); //adding a data to LLL

	protected:
		bst_node* left; //left pointer
		bst_node* right; //right pointer
		int term; //term
		snode* head; //head pointer
};

// Binary search tree class
class bst: public bst_node
{
	public:
		bst(); //default constructor
		~bst(); //destructor
		void add(int a_term, sclass* a_sclass); //add a data at the specific term tree
		int find_add(bst_node* root, int a_term, sclass* a_sclass); //check if there's the same tree and add the data
		void add_bst_node(bst_node*& root, const int a_term, sclass* a_sclass); //adding a node to BST
		int compare(const int a_term, const int b_term); //compare the term data
		void remove(const int a_term); //remove by term
		void remove(bst_node* &root, const int a_term); //remove the data in BST
		void display_all(); //display all
		void display_all(bst_node* root); //wrapper function of display all
		int remove_all(); //remove all 
		int remove_all(bst_node * & root); //wrapper function of remove all

	protected:
		bst_node* root; //root pointer
};

#endif