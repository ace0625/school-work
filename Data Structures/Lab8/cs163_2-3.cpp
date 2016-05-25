#include "cs163_2-3.h"

using namespace std;

//These are the functions that you will be writing for Lab #8

// **** STEP 1
//First write the wrapper functions:
//Display all nodes with no children in 2-3 tree
int table::display_23()      
{
    //call the recursive function here
	return display_23(root23);
}

//Now implement the recursive function to display all leaves
int table::display_23(node23 * root)
{
	if(!root)
		return 0;
	if(!root->child[0])
	{
		if(root->data[0])
			cout << root->data[0] << " ";
		if(root->data[1])
			cout << root->data[1] << " ";
	}
	display_23(root->child[0]);
	display_23(root->child[1]);
	display_23(root->child[2]);
	
	return 1;
 }

// **** STEP 2
// Implement the recursive function to deallocate all items.
// The destructor already calls this function
int table::deallocate_23(node23 * & root)
{
	if(!root)
		return 0;
	int cnt = 0;
	cnt += deallocate_23(root->child[0]);
	cnt += deallocate_23(root->child[1]);
	cnt += deallocate_23(root->child[2]);
	delete root;
	root = NULL;
	
	return cnt;
} 

// **** STEP 3
//First write the wrapper functions:
//Return true if the root's largest value appears more than once
bool table::find_largest()   
{

    //place your code here
	if(!root23) return false;
	if(root23->data[1])
		return find_largest(root23, root23->data[1]);
	else
		return find_largest(root23, root23->data[0]);

}

//Return true if the root's largest value appears more than once
//Write this function recursively
bool table::find_largest(node23 * root, int match)
{
	if(!root)
		return false;
	bool state = false;
	if(root->data[0] == match)
		state = true;
	if(root->data[1] == match)
		state = true;
	else
	{
		state = false;
		find_largest(root->child[0], match);
		find_largest(root->child[1], match);
		find_largest(root->child[2], match);
	}
	return state;
}


// **** STEP 4
//First write the wrapper functions:
//Copies the argument's tree into the current object's tree
int table::copy(const table & source) 
{
   
    //call the recursive function here
	//return (root23, source.root23);
}


//Now implement the recursive function to copy the tree
int table::copy(node23 * & dest_root, node23 * source_root)
{
	
}      
