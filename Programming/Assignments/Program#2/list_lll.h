//CS202
//Program #2
//Hyunchan Kim
//list_lll.h

/*
	This is list_lll.h that composes the lll list with menu data
*/
#ifndef _LIST_LLL_H
#define _LIST_LLL_H

#include "node_lll.h"

class list_lll
{
    public:
        list_lll(); //list default constructor
        ~list_lll(); //list destructor
        int create(char * ingredient, int kind); //create 
        int remove(char * ingredient); //remove a data found
        int retrieve(char * ingredient); //retrieve a data
        int remove_all(); //remove all data
        int display_all(); //display all data

  	protected:
        node_lll * head; //head pointer

};

#endif