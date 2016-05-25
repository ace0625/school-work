#include "cs163_bst.h"
using namespace std;


// ***These are sample wrapper functions
table::~table()
{
     remove_all(root); //call the recursive removal_all private function
}

// ************ STEP 1
// This is a wrapper function that will call the recursive count function
int table::count()
{
    //Notice how the returned value from the recursive function is used
    return count(root);
}

// Now it is your turn to write the count function recursively
int table::count (node * root)
{
	if(!root)
		return 0;
	
	if((!root->left) && (!root->right))
		return 1+ count(root->left) + count(root->right);
	else
		return count(root->left) + count(root->right);
}      

// ************ STEP 2
// Start with the wrapper function that calls the recursive function
int table::sum()
{
    //Call the recursive function here:
	return sum(root);

}

// Now it is your turn to write the sum function recursively
int table::sum (node * root)
{
	if(!root)
		return 0;
	
	return sum(root->left) + sum(root->right) + root->data;
}         



// ************ STEP 3
int table::height()   //simply call the private version of the functions
{
    //Call the recursive function here:
	return height(root);

}

//Now write this function recursively
int table::height (node * root)
{
	if(!root)
		return 0;
	int l_height = height(root->left) + 1;
	int r_height = height(root->right) + 1;
	
	return max(l_height, r_height);
	
}       



// ************ STEP 4
int table::remove_all()
{
    //Call the recursive function here:
	return remove_all(root);

}

// Now it is your turn to write the remove_all function recursively
int table::remove_all(node * & root)
{
	if(!root)
		return 0;
	int val = remove_all(root->left) + remove_all(root->right) + 1;
	delete root;
	root = NULL;
	return val;
}  


// ************ STEP 5
int table::copy(const table & to_copy)
{
    //Call the recursive function here:
	return copy(root, to_copy.root);

}

// Now it is your turn to write the copy function recursively
int table::copy(node * & dest_root, node * source_root)
{
	if(!source_root)
	{
		dest_root = NULL;
		return 0;
	}
	else
	{
		dest_root = new node;
		dest_root->data = source_root->data;
		dest_root->left = dest_root->right = NULL;
		
		copy(dest_root->left, source_root->left);
		copy(dest_root->right, source_root->right);
	}
	return 1;
}  

