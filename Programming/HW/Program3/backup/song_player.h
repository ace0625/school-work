#ifndef _SONG_PLAYER_H
#define _SONG_PLAYER_H

#include <iostream>
#include <fstream>
#include <cstring>

#include "song_table.h"
//#include "liked_playlist.h"

class song_player
{
	public:
		song_player();
		int load_songs(String song_file_name);
		void display_artist_table();
		void init_list();
		int add_to_my_list(int song_number);
		int display_my_list();
		int clear_my_favourite_list();
		bool again();
		
	protected:
		song_hash_table sht;
};

#endif
