//CS202
//Assignment #3
//Hyunchan Kim

//This is the song entry.h file 
//This does basically create son entry, retrieve, display

#include <iostream>
#include <cstring>

#ifndef _SONG_ENTRY_H
#define _SONG_ENTRY_H
#include "string.h"
using namespace std;

class song_entry: public String
{
	public:
		song_entry(); //default constructor
		~song_entry(); //destructor
		song_entry(int p_song_no, String p_song_title, String p_song_artitst, String p_song_genre[]); //constructor
		song_entry(const song_entry & copy_from); //copy constructor
		int retrieve(String matching_artist, song_entry & found); //retrieve function by artist name
		int retrieve_by_song_no(int matching_no); //retrieve function by song number
		int find(String matching_artist); //find function by artist name
		void display_all(); //display song entry
		void display_song_title(); //display song title
		void display_song_genre(); //display song gentre
		String get_song_title(); //get song title
		String get_song_artitst(); //get song artist
		
	protected:
		int song_no; //song number
		String song_title; //Title
		String song_artitst; //Artist name
		String song_genre[3]; //Genres
	
};

#endif

