/**
 * Kwangwoong Yang
 * CS163, [Program #3]
 *
 * "song_hash_table.cpp" - Song Hash Table Program File
 * This program implements a hash table.
 *  
 */
#include "song_table.h"
using namespace std;


lll_artist_node::lll_artist_node()
{}

lll_artist_node::~lll_artist_node()
{}

lll_artist_node::lll_artist_node(song_entry & a_entry): song_entry(a_entry)
{}

lll_artist_node*& lll_artist_node::go_next()
{
	return next;
}

// constructor - initialize data member to NULL
song_hash_table::song_hash_table(int size)
{
	// Allocate the hash table and initialize each
	// element and data member.
	p_hash_table = new lll_artist_node * [size];
	song_hash_table_size = size;
	
	// initialize each element to NULL
	for(int i = 0; i < song_hash_table_size; i++) {
		p_hash_table[i] = NULL;
	}

}

// destructor - deallocate memory
song_hash_table::~song_hash_table()
{
	// deallocate each element of hash table
	for(int i = 0; i < song_hash_table_size; i++) {
		if(p_hash_table[i]) {
			lll_artist_node* temp = p_hash_table[i];
			lll_artist_node* temp2 = p_hash_table[i];
			while(temp->go_next()) {
				temp2 = temp->go_next();
				delete temp;
				temp = temp2;
			}
			temp = NULL;
		}
	}
	delete [] p_hash_table;
}

// get hash number
int song_hash_table::hash(String key_value) const
{
	int keyLen = key_value.getStrlen();
	int temp = 0;
	int sum = 0;

	for (int i = 0; i < keyLen; i++) {
		temp = key_value.getCharP()[i];
		sum += temp;
	}
	return sum % song_hash_table_size;
}

// load song file to hash table
int song_hash_table::load_songs(String song_file_name)
{
	const int MAX_LINE_LEN = 500;
	const int MAX_TOKEN = 6;
	const int GENRE_MAX_TOKEN = 3;
	const char* DELIM = ";";
	const char* DELIM2 = "|";

	// File I/O
	ifstream fin;
	ofstream fout;
	
	// read Song Information File
	fin.open(song_file_name.getCharP()); 
	if(fin.fail()) {
		return 0;
	}

	String song_artitst; // song_artitst (city, state)
	String song_genre[3]; // Song Genre
	String song_title  ; // 
	int song_no = 0;

	// get song information
	while(!fin.eof()) {
		song_entry entry;

		char buff[MAX_LINE_LEN];
		fin.getline(buff, MAX_LINE_LEN);

		const char* token[MAX_TOKEN] = {};
		const char* token2[MAX_TOKEN] = {}; // for Genre

		token[0] = strtok(buff, DELIM);
		if(!token[0]) break;
		
		for(int i = 1; i < MAX_TOKEN; i++) {
			token[i] = strtok(0, DELIM);
		}

		// copy information to entry
		song_artitst = token[0];
		//song_genre   = token[1];
		song_title   = token[2];
		char* song_genre_arr = new char[sizeof(token[1])+1];
		strcpy(song_genre_arr, token[1]);
		
		// genre spilit
		token2[0] = strtok(song_genre_arr, DELIM2);
		if(!token2[0]) break;

		for(int i = 1; i < GENRE_MAX_TOKEN; i++) {
			token2[i] = strtok(0, DELIM2);
			if(!token2[i]) break;
		}
		
		for(int i = 0; i < GENRE_MAX_TOKEN; i++)
			if(token2[i]) song_genre[i] = token2[i];

		cout << "song_artitst :" << song_artitst << endl;
		cout << "song_genre[0]:" << song_genre[0] << endl;
		if(song_genre[1])
			cout << "song_genre[1]:" << song_genre[1] << endl;
		if(song_genre[2])
			cout << "song_genre[2]:" << song_genre[2] << endl;
			
		cout << "song_title:" << song_title << endl;
		cout << "song_no:" << song_no << endl;

		if(!add_song_hash_table(++song_no, song_title, song_artitst, song_genre)) {
			return 0;
		}
	}
	fin.close();
	
	return 1;
}

// Add Song to hash table - create entry, copy entry, insert_hash_table hash table
int song_hash_table::add_song_hash_table(int p_song_no, String p_song_title, String p_song_artitst, String p_song_genre[])
{
	song_entry entry = song_entry(p_song_no, p_song_title, p_song_artitst, p_song_genre);

	// insert_hash_table entry to the table
	// get hash value
	int hash_val = hash(p_song_artitst);

	// create new node
	lll_artist_node* temp = new lll_artist_node(entry);

	//temp->go_next() = p_hash_table[hash_val];
	temp->go_next() = p_hash_table[hash_val];
	p_hash_table[hash_val] = temp;
	
	return 1;
}


// display song title keyword
int song_hash_table::display_song_artist_keyword()
{
/*
	int i = 0;
	for(int j = 0; j < song_hash_table_size; j++) {
		lll_artist_node* htable = p_hash_table[j];
		if(!htable) break;
		while(htable->go_next()) {
			if(i > 0) cout << ", ";
			cout << htable->artist_keyword;
			htable = htable->go_next();
			i++;
		}
	}
*/
	return 1;
}

// display length of chain
int song_hash_table::length_of_chain() {
	cout << "current Hash Table Size: " << song_hash_table_size << endl;
	for(int i = 0; i < song_hash_table_size; i++) {
		lll_artist_node* htable = p_hash_table[i];
		if(!htable) {
			cout << "size of chain in p_hash_table[" << i << "]: 0" << endl;
			continue;
		}
		int j = 0;
		while(htable->go_next()) {
			htable = htable->go_next();
			j++;
		}
		cout << "size of chain in p_hash_table[" << i << "]: " << j << endl;
	}

	return 1;
}


int main() 
{
	song_hash_table sht;
	String song_file = "song_cont.dat";
	sht.load_songs(song_file);
	//sht.display_all();
}