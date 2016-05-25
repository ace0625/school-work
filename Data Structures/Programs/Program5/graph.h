#ifndef _GRAPH_H
#define _GRAPH_H

#include "task_entry.h"
//graph.h

struct vertex
{
       task_entry * entry;        //NULL, if the vertex isn't set
       struct node * head;           //edge list
};

struct node
{
       vertex * adjacent;	  //Additional data would be needed for a weighted graph
       node * next;
};

class table
{
      public:
             table(int size=5); //constructor with fixed size
             ~table();    // destructor 
			 int insert_vertex(const task_entry & to_add); //insert vertex
             int find_location(char * key_value); //find vertex data with key value
             int insert_edge(char * current_vertex, char * to_attach); //build an edge
             int display_adjacent(char * key_value);    //display adjacent vertex data
             int display_all(); //display all data

	 private:
		  vertex * adjacency_list; //adjacent list pointer
	      int list_size; //list size

};







#endif