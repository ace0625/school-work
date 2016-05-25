//CS202
//Assignment #3
//Hyunchan Kim

//song_play.h

//This is song play header file that has prototypes of all functions
//to start and implement actual program

#ifndef _SONG_PLAYER_H
#define _SONG_PLAYER_H

#include <iostream>
#include <fstream>
#include <cstring>

#include "song_table.h"
#include "song_graph.h"

class song_player
{
	public:
		song_player(); //constructor
		int load_songs(String song_file_name); //load song data from an external file
		int load_song_edge_file(String file_title); //load edge information from an external file
		void display_genere_title(); //display titles
		void display_genere_songs(String p_song_genere); //display genres
		void start(); //start program
		bool again(); //prompt to add more songs
		bool again2(); //prompt to remove more songs
	protected:
		song_hash_table sht; //hash table
		song_graph_table sgt; //graph
};

#endif
