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
#include <cstdlib>
#include <time.h>

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
		song_entry * entry;
		lll_artist_node * next;
};


class song_hash_table:public lll_artist_node
{
	public:
		song_hash_table(); // hash table's size - prime number
		~song_hash_table();
		int hash(String key_value) const; // generate hash value
		int insert_hash_table(const song_entry * to_add, String artist_keyword); // insert data to hash table with chaining
		int load_songs(String song_file_name); // load songs from a song file
		int add_song_hash_table(int p_song_no, String p_song_title, String p_song_artitst, String p_song_genre);
	
		int display_song_artist_keyword();
		int length_of_chain();
		
		
		int init_playlist();
		int display_by_song_num(int song_no);
		int display_all_table();
		int add_to_cll(int song_no);
		int add_to_cll(lll_artist_node*&rear, int song_no);
		
		int display_cll();
		int display_cll(lll_artist_node * rear);
		int remove_all_cll();
		int remove_all_cll(lll_artist_node * rear);
		
	protected:
		lll_artist_node ** p_hash_table;
		int song_hash_table_size;
		
		lll_artist_node * rear;
};

#endif
