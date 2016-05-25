//CS202
//Program #2
//Hyunchan Kim
//node_lll.h

/*
	This is node_lll.h, header file for 
	linear linked list node
*/
#ifndef _NODE_LLL_H
#define _NODE_LLL_H    

#include "menu_data.h"

class node_lll
{
    public:
        node_lll(); //node constructor
        node_lll(char * menu_name, int kind);
        node_lll(const node_lll & copy_from);
        void set_next(node_lll * head); //set next pointer
        node_lll * & get_next(); //get next pointer
        char * get_menu_name(); //get menu name 
        int node_lll_display();  //display node
        void set_menu(char * a_menu_name, int kind);

    protected:
        menu_data * a_menu;
        node_lll * next; //next poiter

};

#endif