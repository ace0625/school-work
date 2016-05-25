#include "table.h"
using namespace std;

//These are the functions that you will be writing for Lab #10


//STEP 1
int table::count()	//SAMPLE wrapper function
{
	return count(root);
}

int table::count(node * root)
{
	if(!root) return 0;
	
	return 1 + count(root->left) + count (root->right);
}


//STEP 2
int table::count_leaf()
{
	return count_leaf(root);
}
int table::count_leaf(node * root)
{
	if(!root)
		return 0;
	if((!root->left) && (!root->right))
		return 1+ count_leaf(root->left) + count_leaf(root->right);
	else
		return count_leaf(root->left) + count_leaf(root->right);
}


//STEP 3
int table::remove_largest()
{
	return remove_largest(root);
}
int table::remove_largest(node * & root)
{
	if(!root)
		return 0;
	if(!root->right)
	{
		delete root;
		root = NULL;
	}
	else
		remove_largest(root->right);
	
	return 1;
}


//STEP 4
int table::sum()
{
	return sum(root);
}
int table::sum(node * root)
{
	if(!root) 
		return 0;
	return sum(root->left) + sum(root->right) + root->data;
}

//STEP 5
int table::copy(table & to_copy)
{
	return copy(root, to_copy.root);
}
int table::copy(node * & destination, node * source)
{
	if(!source)
	{
		destination = NULL;
		return 0;
	}
	else
	{
		destination = new node;
		destination->data = source->data;
		destination->left = destination->right = NULL;
		
		copy(destination->left, source->left);
		copy(destination->right, source->right);
	}
	return 1;
}


//STEP 6a Challenge
int table::create_full(){}
int table::create_full(node * & new_tree){}


//STEP 6b
bool table::is_full(){}
bool table::is_full(node * root){}


//STEP 6c
int table::display_largest(){}
int table::display_largest(node * root){}


//STEP 6d
int table::display_largest2(){}
int table::display_largest2(node * root){}



