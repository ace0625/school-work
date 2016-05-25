#include "cs163_tree.h"
using namespace std;



//These are the functions that you will be writing for the BST


void table::display_largest()
{
	return display_largest(root);
}      	//STEP 1
void table::display_largest(node * root) 
{
	if(!root)
		return;
	if(!root->right)
		cout << "\nSTEP 1 : largest data in BST is " << root->data << endl;
	else
		return display_largest(root->right);
}

int table::count_root() 
{
	return count_root(root, root->data);
}		//STEP 2
int table::count_root(node * root, int match) 
{
	int cnt = 0;
	if(!root)
		return 0;
	if(root->data == match)
		++cnt;
	if(match < root->data)
		cnt += count_root(root->left, match);
	else
		cnt += count_root(root->right, match);
	
	return cnt;
}

void table::copy(table & source) 
{
	return copy(root, source.root);
}  	//STEP 3
void table::copy(node * & destination, node * source) 
{
	if(!source)
	{
		destination = NULL;
		return;
	}
	else
	{
		destination = new node;
		destination->data = source->data;
		destination->left = destination->right = NULL;
		
		copy(destination->left, source->left);
		copy(destination->right, source->right);
	}
}



//Now for the 2-3-4 Tree		//STEP 4
int table::count_3_data()   //sample wrapper function that return the count
{
      return count_3_data(root234);
}	     
     
int table::count_3_data(node234 * root)
{
	int cnt = 0;
	if(!root)
		return 0;
	if(root->data[2])
		++cnt;
	for(int i = 0; i < 4; i++)
		cnt += count_3_data(root->child[i]);
	
	return cnt;
}	            
        


//STEP 5
int table::height()
{
	return height(root234);
}                    //Return the height
int table::height(node234 * root)
{
	//int height = 0;
	if(!root)
		return 0;
		
	int l_height = height(root->child[0]) + 1;
	// int r_height = height(root->child[1]) + 1;
	
	// return max(l_height, r_height);
		return l_height;
	// return height;
}                    

//STEP 6
//Copy from the argument into the data members...
int table::copy_234(table & copy_from) 
{
	return copy(root234, copy_from.root234);
}
int table::copy(node234 * & destination, node234 * source)
{
	if(!source)
		return 0;
	else
	{
		destination = new node234;
		destination->data[0] = source->data[0];
		destination->data[1] = source->data[1];
		destination->data[2] = source->data[2];
		copy(destination->child[0], source->child[0]);
		copy(destination->child[1], source->child[1]);
		copy(destination->child[2], source->child[2]);
		copy(destination->child[3], source->child[3]);
	}
	return 1;
}      









