//CS202
//Assignment #3
//Hyunchan Kim

//song_table.h

//This is the header file for song table building hash table by artist name
//and also initializing song list.

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <time.h>

#ifndef _SONG_TABLE_H
#define _SONG_TABLE_H
#include "song_entry.h"
#include "string.h"

//artist node class derived from song entry
class lll_artist_node:public song_entry
{
	public:
		lll_artist_node(); //default constructor
		lll_artist_node(const lll_artist_node & copy); //copy constructor
		lll_artist_node(song_entry & a_entry); //constructor
		~lll_artist_node(); //destructor
		lll_artist_node*& go_next(); //go next function
		
	protected:
		String artist_keyword; //keyword by artst name
		song_entry * entry; //song entry pointer
		lll_artist_node * next; //next pointer
};


//hash table class
class song_hash_table:public lll_artist_node
{
	public:
		song_hash_table(); //constructor
		~song_hash_table(); //destructor
		int hash(String key_value) const; // hash function by artist name
		int insert_hash_table(const song_entry * to_add, String artist_keyword); // add to hash table 
		int load_songs(String song_file_name); // load songs from a song file 
		int add_song_hash_table(int p_song_no, String p_song_title, String p_song_artitst, String p_song_genre[]); //add to hash table
		int display_song_artist_keyword(); //display artist name
		int init_playlist(); //initial song list by random order
		int display_by_song_num(int song_no); //display song by song number
		int display_all_table(); //display all table data
		int add_to_cll(int song_no); //add to my favourite list which is CLL
		int add_to_cll(lll_artist_node*&rear, int song_no); //add to my favourite list which is CLL, wrapper
		int remove_to_cll(int song_no); //remove a song from my favourite list by song number
		int remove_to_cll(lll_artist_node*&rear, int song_no);  //remove a song from my favourite list by song number, wrapper
		int display_cll(); //display my favourite song list
		int display_cll(lll_artist_node * rear);//display my favourite song list, wrapper
		int remove_all_cll(); //remove all songs my favourite song list
		int remove_all_cll(lll_artist_node * rear); //remove all songs my favourite song list
		
	protected:
		lll_artist_node ** p_hash_table; //hash table pointer
		int song_hash_table_size; //hash table size
		int song_ran_size; //initial list song size
		lll_artist_node * rear; //rear pointer for CLL
};

#endif
