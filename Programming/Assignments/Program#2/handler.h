//CS202
//Program #2
//Hyunchan Kim
//handler.h

/*
	This is handler.h that handles execution of this program
*/

#include "bst.h"

class handler
{
	public:
		int read_in_menu();
		int read_in_ingredient(list_lll * a_list);
		int test(list_lll * a_list, bst a_tree);

	protected:
		list_lll * list;
		bst a_tree;
};