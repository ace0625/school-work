
#include "song_entry.h"

// constructor - initialize data member to NULL
song_entry::song_entry()
{
	song_no = 0;
}

// destructor - deallocate memory
song_entry::~song_entry()
{}

// constructor - create entry information
//song_entry::song_entry(int p_song_no, char* p_song_title, char* p_song_artitst, char* p_song_genre)
song_entry::song_entry(int p_song_no, String p_song_title, String p_song_artitst, String p_song_genre)
{
	song_no = p_song_no;
	song_title = p_song_title;
	song_artitst = p_song_artitst;
	song_genre= p_song_genre;
}

// copy constructor
song_entry::song_entry(const song_entry & copy_from)
{
	song_no = copy_from.song_no; 
	song_title   = copy_from.song_title;
	song_artitst = copy_from.song_artitst;
	song_genre = copy_from.song_genre;
}

// retrieve entry information
int song_entry::retrieve(String matching_artist, song_entry & found)
{
	if(matching_artist != song_artitst)
		return 0;

	song_no = found.song_no;
	song_title   = found.song_title;
	song_artitst = found.song_artitst;
	song_genre   = found.song_genre;
	return 1;
}

int song_entry::retrieve_by_song_no(int matching_no)
{
	if(matching_no != song_no)
		return 0;
	else
		return 1;
	// song_no = found.song_no;
	// song_title   = found.song_title;
	// song_artitst = found.song_artitst;
	// song_genre   = found.song_genre;
}


// retrieve entry information
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
	cout << "= Artist : " << song_artitst << endl;
	cout << "= Title: " << song_title << endl;
	cout << "= Genre: " << song_genre << endl;
	cout << "= No." << song_no << endl;
}

// display song genre
void song_entry::display_song_genre()
{
	cout << song_genre;
}

// display song name
void song_entry::display_song_title()
{
	cout << song_title;
}

// get song's title
String song_entry::get_song_title()
{
	return song_title;
}