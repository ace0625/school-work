//CS163
//Assignment #4
//Hyunchan Kim
//bst.cpp


//This is bst.cpp that implements binary search tree 
#include "bst.h"


//default constructor
bst::bst()
{
	root = NULL;
}

//default destructor
bst::~bst()
{
	remove_all();
}

//insert to BST wrapper
int bst::insert(char * key_word, const app_entry & to_add)
{
	return insert(root, key_word, to_add);
}

//insert to BST 
int bst::insert(node * & root, char * key_word, const app_entry & to_add)
{
	if(!root) 
	{
		root = new node;
		root->entry = new app_entry;
		root->entry->copy_entry(to_add);
		root->left = root->right = NULL;
	}
	else if(root->entry->str_compare(key_word) > 0)
		insert(root->left, key_word, to_add);
	else
		insert(root->right, key_word, to_add);
}

//display function by key word wrapper
int bst::display(char * key_word)
{
	return display(root, key_word);
}
//display function  by key word
int bst::display(node * & root, char * key_word)
{
	if(!root)
		return 0;
	
	if(root->entry->str_compare(key_word) == 0)
	{
		cout << "\n>>>>>>>>> We found the data <<<<<<<<<" << endl;
		root->entry->display_all();
		return 1;
	}
	else if(root->entry->str_compare(key_word) > 0)
		return display(root->left, key_word);
	else
		return display(root->right, key_word);
	
}

//display all BST wrapper
int bst::display_all_bst()
{
	return display_all_bst(root);
}
//display all BST 
int bst::display_all_bst(node * root)
{
	if(!root)
		return 0;
	
	display_all_bst(root->left);
	root->entry->display_all();
	display_all_bst(root->right);
	
	return 1;
}

//Remove all data in BST wrapper 
int bst::remove_all()
{
	return remove_all(root);
}
//Remove all data in BST 
int bst::remove_all(node * & root)
{
	if(!root) 
		return 0;

	int val = remove_all(root->left) + remove_all(root->right) + 1;
	delete root->entry;
	delete root;
	root = NULL;
	return val;
}