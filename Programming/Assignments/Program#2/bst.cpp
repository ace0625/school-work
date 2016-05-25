//CS202
//Program #2
//Hyunchan Kim
//bst.cpp

/*
	This is for implementation of bst.h
*/

#include "bst.h"

/*
 	bst default constructor implementation
*/
bst::bst() : root(NULL) {}

/*
	bst destructor using remove all function
*/
bst::~bst()
{	
	remove_all();
}

/*
	make a unique value using ingredient name
*/
int bst::key(char * a_ingredient)
{
	int key = 0;
	for(int i = 0; (unsigned)i < strlen(a_ingredient); i++)
	{
		key = (key + (int)a_ingredient[i] * 17);
	}
	key = key % 3;

	return key;
}

/*
	create function using wrapper 
*/
int bst::create(char * a_ingredient, int a_distinct, list_lll * a_list)
{
	return create(a_ingredient, a_distinct, a_list, root);

}

/*
	create function using wrapper 
*/
int bst::create(char * a_ingredient, int a_distinct, list_lll * a_list, node_bst * & root)
{
	if(!root)
	{
		root = new node_bst(a_list, a_ingredient, a_distinct);
		root->go_left() = root->go_right() = NULL;
		return 1;
	}
	else if(root->ingredient_compare(a_distinct))
		return create(a_ingredient, a_distinct, a_list, root->go_left());
	else
		return create(a_ingredient, a_distinct, a_list, root->go_right());

	return 1;

}

/*
	retrieve a data with wrapper function
*/
int bst::retrieve(char * a_ingredient)
{
	return retrieve(a_ingredient, root);
}

/*
	retrieve a data with wrapper function
*/
int bst::retrieve(char * a_ingredient, node_bst * root)
{
	if(!root) return 0;
	retrieve(a_ingredient, root->go_left());
	retrieve(a_ingredient, root->go_right());
	if(strcmp(root->get_ingred(), a_ingredient) == 0)
	{
		root->ingredient_display();
		root->display_list();
		return 1;
	}
	return 1;
}

/*
	remove all data with wrapper function
*/
int bst::remove_all()
{
	return remove_all(root);
}

/*
	remove all data with wrapper function
*/
int bst::remove_all(node_bst * & root)
{
	if(!root) return 0;
	if(root->go_left())
		remove_all(root->go_left());
	if(root->go_right())
		remove_all(root->go_right());

	delete root;
	return 1;
}

/*
	display bst with wrapper function
*/
int bst::display_all_bst()
{
	return display_all_bst(root);
}

/*
	display bst with wrapper function
*/
int bst::display_all_bst(node_bst * & root)
{
	if(!root) return 0;
	root->ingredient_display();
	root->display_list();
	display_all_bst(root->go_left());
	display_all_bst(root->go_right());

	return 1;
}





