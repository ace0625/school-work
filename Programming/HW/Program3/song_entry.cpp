//CS202
//Assignment #3
//Hyunchan Kim

//song_entry.cpp
//This is the song entry.cpp file 
//This does basically create son entry, retrieve, display

#include "song_entry.h"

// Default constructor 
song_entry::song_entry()
{
	song_no = 0;
}

// defualt destructor 
song_entry::~song_entry()
{}

// constructor, creates an entry
song_entry::song_entry(int p_song_no, String p_song_title, String p_song_artitst, String p_song_genre[])
{
	song_no = p_song_no;
	song_title = p_song_title;
	song_artitst = p_song_artitst;
	if(p_song_genre[0])
		song_genre[0]= p_song_genre[0];
	if(p_song_genre[1])
		song_genre[1]= p_song_genre[1];
	if(p_song_genre[2])
		song_genre[2]= p_song_genre[2];
}

// copy constructor
song_entry::song_entry(const song_entry & copy_from)
{
	song_no = copy_from.song_no; 
	song_title   = copy_from.song_title;
	song_artitst = copy_from.song_artitst;
	
	if(copy_from.song_genre[0])
		song_genre[0]= copy_from.song_genre[0];
	if(copy_from.song_genre[1])
		song_genre[1]= copy_from.song_genre[1];
	if(copy_from.song_genre[2])
		song_genre[2]= copy_from.song_genre[2];
}

// Retrieve function by artist name
int song_entry::retrieve(String matching_artist, song_entry & found)
{
	if(matching_artist != song_artitst)
		return 0;

	song_no = found.song_no;
	song_title   = found.song_title;
	song_artitst = found.song_artitst;
	song_genre[0]= found.song_genre[0];
	song_genre[1]= found.song_genre[1];
	song_genre[2]= found.song_genre[2];
	return 1;
}

//Retrieve by song number
int song_entry::retrieve_by_song_no(int matching_no)
{
	if(matching_no != song_no)
		return 0;
	else
		return 1;
}


// Find function that checks if there's matching song entry by artist name
int song_entry::find(String matching_artist)
{
	if(matching_artist == song_artitst)
		return 1;
	else
		return 0;
}

// display entry information
void song_entry::display_all()
{
	cout << "=> <Title> : " << song_title << endl;
	cout << "=> <Artist> : " << song_artitst << endl;
	cout << "=> <Genre> : "; display_song_genre();
	cout << "=> <Song_no> : " << song_no << endl;
}

// Displaying genres
void song_entry::display_song_genre()
{
	cout << song_genre[0];
	if(song_genre[1]) cout << ", " << song_genre[1];
	if(song_genre[2]) cout << ", " << song_genre[2];
	cout << endl;
}

// display name of the song
void song_entry::display_song_title()
{
	cout << song_title;
}

// get Song title
String song_entry::get_song_title()
{
	return song_title;
}
//get artist name
String song_entry::get_song_artitst()
{
	return song_artitst;
}

