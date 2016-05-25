/**
 * Kwangwoong Yang
 * CS163, [Program #3]
 * 
 * "song_hash_table.h" - Job Hash Table Header File
 * This program implements a hash table.
 *  
 */
#include <iostream>
#include <fstream>
#include <cstring>

#ifndef _SONG_TABLE_H
#define _SONG_TABLE_H
#include "song_entry.h"
#include "string.h"

class lll_artist_node:public song_entry
{
	public:
		lll_artist_node();
		lll_artist_node(song_entry & a_entry);
		~lll_artist_node();
		lll_artist_node*& go_next();
		
	protected:
		String artist_keyword;
		song_entry* entry;
		lll_artist_node* next;
		
		
};

class song_hash_table:public lll_artist_node
{
	public:
		song_hash_table(int size = 11); // hash table's size - prime number
		~song_hash_table();

		int hash(String key_value) const; // generate hash value
		int insert_hash_table(const song_entry * to_add, String artist_keyword); // insert data to hash table with chaining
		//int retrieve(String artist_to_find);
		int load_songs(String song_file_name); // load songs from a song file
		int add_song_hash_table(int p_song_no, String p_song_title, String p_song_artitst, String p_song_genre[]);
		int display_song_artist_keyword();
		int display_song_genre();
		int display_song_title();
		int length_of_chain();

	protected:
		lll_artist_node ** p_hash_table;
		int song_hash_table_size;
};

#endif
