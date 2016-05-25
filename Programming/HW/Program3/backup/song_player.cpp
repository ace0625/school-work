/**
 * Kwangwoong Yang
 * CS163, [Program #3]
 *
 * "song_hash_table.cpp" - Song Hash Table Program File
 * This program implements a hash table.
 *  
 */
#include "song_player.h"
using namespace std;

song_player::song_player()
{}

// load song file to hash table
int song_player::load_songs(String song_file_name)
{
	const int MAX_LINE_LEN = 500;
	const int MAX_TOKEN = 6;
	const int GENRE_MAX_TOKEN = 3;
	const char* DELIM = ";";

	// File I/O
	ifstream fin;
	ofstream fout;
	
	// read Song Information File
	fin.open(song_file_name.getCharP()); 
	if(fin.fail()) {
		return 0;
	}

	String song_artitst; // song_artitst (city, state)
	String song_genre; // Song Genre
	String song_title  ; // 
	int song_no = 1;

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
		song_genre   = token[1];
		song_title   = token[2];
		
		// cout << "song_artitst :" << song_artitst << endl;
		// cout << "song_genre:" << song_genre << endl;
		// cout << "song_title:" << song_title << endl;
		// cout << "song_no:" << song_no << endl;
		
		sht.add_song_hash_table(++song_no, song_title, song_artitst, song_genre);
	}
	fin.close();
	
	return 1;
}
void song_player::display_artist_table()
{
	sht.display_all_table();
}

//Initial list that randomly sorted
void song_player::init_list()
{
	sht.init_playlist();
}

//Add a song to your favorite list which is CLL
int song_player::add_to_my_list(int song_number)
{
	if(sht.add_to_cll(song_number))
		return 1;
	else
		return 0;
}

//Display my favorite list 
int song_player::display_my_list()
{
	sht.display_cll();
}

int song_player::clear_my_favourite_list()
{
	sht.remove_all_cll();
}

bool song_player::again()
{
	char response;
	cout << "Would you like to add more songs? (Y/N): ";
	cin >> response;
	cin.ignore(100, '\n');
	if (toupper(response) == 'Y')
		return true;
	else
		return false;
}

//main 
int main() 
{
	int song_number;
	int menu_select;
	
	song_player splayer;
	String song_file = "song_cont.dat";
	splayer.load_songs(song_file);
	
	while(true)
	{
		cout << "\n\n####################################################" << endl;
        cout << "##                 Song Player                    ##" << endl;
        cout << "####################################################" << endl;
        cout << "#                                                  #" << endl;
        cout << "#  1. List by Artist	                            #" << endl;
        cout << "#  2. Random list to add to your favourite list    #" << endl;
        cout << "#  3. Display your favourite list                  #" << endl;
        cout << "#  4. Clear my favourite list                      #" << endl;
        cout << "#  0. Exit Program                                 #" << endl;
        cout << "#                                                  #" << endl;
		cout << "####################################################" << endl;
		cout << endl;
		cout << "--> Select a menu:  ";
		cin >> menu_select;
		cout << endl;
		
		//MENU
		switch(menu_select)
		{
			case 1:
				cout << "\n\n=============== Artist List ===================\n\n";
				splayer.display_artist_table();
				break;
			case 2:
			cout << "\n\n=============== Random List ===================\n\n";
			splayer.init_list();	
			do{
				cout << "\nEnter the song number you would like to add to you list: ";
				cin >> song_number; 
				if(splayer.add_to_my_list(song_number))
					cout << "added to your list!" << endl;
				else
					cout << "There is no song matching!" << endl;
			}while(splayer.again());
				break;
			case 3:
				cout << "\n\n=============== My favourite List ===================\n\n";
				splayer.display_my_list();
				break;
			case 4:
				cout << "\n\nRemove all songs from my list\n\n";
				splayer.clear_my_favourite_list();
				break;
			case 0:
				cout << "\n\n========= Bye Bye ==========\n\n";
				return 0;
		}
	}
}
