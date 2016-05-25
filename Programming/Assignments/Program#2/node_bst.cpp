//CS202
//Program #2
//Hyunchan Kim
//node_bst.cpp

/*
	This is for implementation for node_bst
*/

#include "node_bst.h"
using namespace std;

//ingredient class implementation

/*
	ingredient default constructor
*/
ingredient::ingredient() : ingredient_name(NULL), distinct(0){}

/*
	destructor implementation
*/
ingredient::~ingredient()
{
	delete [] ingredient_name;
	distinct = 0;
}
/*
	ingredient constructor with ingredient and type
*/
ingredient::ingredient(char * a_ingredient, int distinguisher)
{
	ingredient_name = new char[strlen(a_ingredient) + 1];
	strcpy(ingredient_name, a_ingredient);
	distinct = distinguisher;
}

/*
	ingredient copy constructor
*/
ingredient::ingredient(const ingredient & copy_from)
{
	if(copy_from.ingredient_name)
	{
		ingredient_name = new char[strlen(copy_from.ingredient_name) + 1];
		strcpy(ingredient_name, copy_from.ingredient_name);
	}
	if(copy_from.distinct)
	{
		distinct = copy_from.distinct;
	}
}

/*
	display ingredient function
*/
int ingredient::ingredient_display()
{
	cout << "Ingredient : " << ingredient_name << endl;
	return 1;
}

/*
	get ingredient pointer
*/
char * ingredient::get_ingred()
{
	return ingredient_name;
}

/*
	comparing ingredients if they are the same
*/
bool ingredient::ingredient_compare(int kind)
{
	if(kind <= distinct)
		return true;
	else
		return false;
}


//=========================================================

//node_bst implementation

/*
	node bst default constructor
*/
node_bst::node_bst() : left(NULL), right(NULL), list(NULL) {}

/*
	node bst constructor
*/
node_bst::node_bst(list_lll * a_list, char * a_ingredient, int a_distinct) : ingredient(a_ingredient, a_distinct)
{
	list = a_list;
}

/*
	node bst copy constructor
*/
node_bst::node_bst(const node_bst & copy_from) : ingredient(copy_from)
{
	list = copy_from.list;
}

/*
	go to left pointer
*/
node_bst * & node_bst::go_left()
{
	return left;
}

/*
	go to right pointer
*/
node_bst * & node_bst::go_right()
{
	return right;
}

/*
	display list
*/
int node_bst::display_list()
{
	if(!list)
		return 0;
	else
	{
		list->display_all();
		return 1;
	}
}

// /*
// */
// int node_bst::display_node_data()
// {
	
// }












