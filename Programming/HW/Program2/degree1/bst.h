#include "course_lll.h"
#include "sclass.h"
#ifndef _BST_H_
#define _BST_H_

class snode: public sclass
{
	public:
		snode();
		~snode();
		snode(sclass* a_sclass);
		snode(char* a_course_type, int a_course_code, int a_course_term, char* a_course_grade);
		snode *& go_next();
		bool if_next();
		void display_snode();
		int retrieve(const char* a_course_type, int a_course_code);

	protected:
		snode* next;
};

class bst_node: public snode
{
	public:
		bst_node();
		~bst_node();
		bst_node(const int a_term);
		// bst_node move to left
		bst_node *& go_left();
		// bst_node move to right
		bst_node *& go_right();
		bool if_left();
		bool if_right();
		void display_bst();
		int get_term();
		int compare(int a_term);

		void set_term(int a_term);
		// check match term 
		bool match_term(const int a_term);

		// add lll node
		void add_snode(int a_term, sclass* a_sclass);

	protected:
		bst_node* left;
		bst_node* right;
		int term;
		snode* head;
};

// BST objects
class bst: public bst_node
{
	public:
		bst();
		// destructor for bst class
		~bst();
		void add(int a_term, sclass* a_sclass);

		int find_add(bst_node* root, int a_term, sclass* a_sclass);

		// add bst node
		void add_bst_node(bst_node*& root, const int a_term, sclass* a_sclass);
		int compare(const int a_term, const int b_term);

		void remove(const int a_term);
		void remove(bst_node* &root, const int a_term);
		void display_all();
		void display_all(bst_node* root);
		int remove_all();
		int remove_all(bst_node * & root);

	protected:
		bst_node* root;
};

#endif