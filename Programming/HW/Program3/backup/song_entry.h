#include <iostream>
#include <cstring>

#ifndef _SONG_ENTRY_H
#define _SONG_ENTRY_H
#include "string.h"
using namespace std;

class song_entry: public String
{
	public:
		song_entry();
		~song_entry();
		song_entry(int p_song_no, String p_song_title, String p_song_artitst, String p_song_genre);
		song_entry(const song_entry & copy_from);
		int retrieve(String matching_artist, song_entry & found);
		int retrieve_by_song_no(int matching_no);
		int find(String matching_artist);
		void display_all();
		void display_song_title();
		void display_song_genre();
		String get_song_title();
		
	protected:
		int song_no;
		String song_title;
		String song_artitst;
		String song_genre;
	
};

#endif

