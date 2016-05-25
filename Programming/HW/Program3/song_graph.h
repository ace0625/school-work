//CS202
//Assignment #3
//Hyunchan Kim

//song_graph.h
//this is the graph header file that composes all graph information

#include <iostream>
#include <fstream>
#include <cstring>
#include "song_entry.h"

#ifndef _SONG_GRAPH_H
#define _SONG_GRAPH_H

//gentre node class
class lll_genere_node:public song_entry
{
	public:
		lll_genere_node(); //default constructor
		~lll_genere_node(); //default destructor
		lll_genere_node(const song_entry & a_entry); //constructor
		lll_genere_node*& go_next(); //go next function
		
	protected:
		song_entry* entry; //entry pointer
		lll_genere_node* next; //next pointer
};

class grp_vertex;

//edge node class
class edge_node
{
	public:
		edge_node();  //default constructor
		grp_vertex*& go_adjacent(); //go to adjacent vertex
		edge_node*& go_next(); //go to next
	protected: 
		grp_vertex* adjacent; //adjacent pointer
		edge_node* next; //next pointer
};

//vertex class
class grp_vertex
{
	public:
		grp_vertex(); //default constructor
		String get_song_genere(); //get genre
		void set_song_genere(String song_genere); //set song genre
		int compare_song_genere(String p_song_genere); //comparing genres
		edge_node*& go_eg_head(); //go to edge head
		void set_eg_head(edge_node* p_eg_head); // set edge head
		lll_genere_node*& go_lg_head(); // go to head
		void set_lg_head(lll_genere_node* p_lg_head); //set head
		
	protected:
		String song_genere; //string genre
		lll_genere_node* lg_head;	// head for LLL
		edge_node* eg_head;	// edge list
};

class song_graph_table
{
	public:
		song_graph_table(int size = 50);
		~song_graph_table(void);
		int insert_grp_vertex(const String p_song_genere, const song_entry & to_add);
		int find_location(String key_value);
		int find_genere(const String p_song_genere);
		int insert_edge(String current_grp_vertex, String to_attach);
		int remove_all();
		int get_genere_size();
		int load_song_info_file(char file_title[]);
		int load_song_edge_file(char file_title[]);

		void display_genere_title();
		void display_genere_songs(String key_genere);
		void display_genere_related(String key_genere);
		void display_recur(int &i);

		protected:
		grp_vertex* adjacency_list;
		int genere_size;
		int list_size;
		int* visited;
};
#endif
