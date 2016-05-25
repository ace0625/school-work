/**
 * Kwangwoong Yang
 * song, [Program #3]
 * 
 * "song_graph.h" - song Graph Header File
 * This program implements a song graph.
 *  
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include "song_entry.h"

#ifndef _SONG_GRAPH_H
#define _SONG_GRAPH_H

class grp_vertex;

class edge_node
{
	public:
		edge_node();
		grp_vertex* go_adjacent();
		edge_node* go_next();
	protected:
		grp_vertex* adjacent;
		edge_node* next;
};

class grp_vertex
{
	public:
		grp_vertex();
		song_entry* get_entry();
		edge_node* get_ghead();
	protected:
		song_entry* entry;	// entry
		edge_node* ghead;	// edge(adjacency) list
};

class song_graph_table
{
	public:
		song_graph_table(int size = 50);
		~song_graph_table(void);
		int insert_grp_vertex(const song_entry & to_add);
		int find_location(String key_value);
		int insert_edge(String current_grp_vertex, String to_attach);
		int remove_all();
		int load_song_info_file(char file_title[]);
		int load_song_edge_file(char file_title[]);

		int display_all();
		int display_genre(String key_genre);
	private:
		grp_vertex* adjacency_list;
		int list_size;
		void display_recur(edge_node* current, bool visited[]);
};
#endif
