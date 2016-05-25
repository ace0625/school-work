//CS163
//Assignment#5
//Hyunchan Kim

//graph.h

#ifndef _GRAPH_H
#define _GRAPH_H

#include "friend_entry.h"

struct vertex
{
		friend_entry * entry;        //NULL, if the vertex isn't set
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
             table(int size = 50); //constructor with fixed size
             ~table();    // destructor 
			 int load_data_file(char file_name[]);
			 int load_edge_file(char file_name[]);
			 int insert_vertex(const friend_entry & to_add); //insert vertex
             int find_location(char * key_value); //find vertex data with key value
			 int remove_all(); //remove all data
             int insert_edge(char * current_vertex, char * to_attach); //build an edge
             int display_adjacent(char * key_value);    //display adjacent vertex data
			 int display_event(char * key);
             int display_all(); //display all data
			 void display_recur(node* current, bool visited[]); //display recursive

	 private:
		  vertex * adjacency_list; //adjacent list pointer
	      int list_size; //list size
		

};

#endif