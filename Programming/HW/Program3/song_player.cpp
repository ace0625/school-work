//CS202
//Assignment #3
//Hyunchan Kim

//song_plpayer.h

//This is the song player header file that has main operations including main

#include "song_player.h"
using namespace std;

song_player::song_player()
{}

// load song file to hash table
int song_player::load_songs(String file_name)
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
	fin.open(file_name.getCharP()); 
	if(fin.fail()) {
		return 0;
	}

	String song_artitst; // song_artitst (city, state)
	String song_genre[3]; // Song Genre
	String song_title  ; // 
	int song_no = 0;

	// get song information
	while(!fin.eof()) 
	{
		char buff[MAX_LINE_LEN];
		fin.getline(buff, MAX_LINE_LEN);

		const char* token[MAX_TOKEN] = {};
		const char* token2[MAX_TOKEN] = {}; // for Genre

		token[0] = strtok(buff, DELIM);
		if(!token[0]) break;
		
		for(int i = 1; i < MAX_TOKEN; i++) 
		{
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

		for(int i = 1; i < GENRE_MAX_TOKEN; i++) 
		{
			token2[i] = strtok(0, DELIM2);
			if(!token2[i]) break;
		}
		for(int i = 0; i < GENRE_MAX_TOKEN; i++)
			if(token2[i]) song_genre[i] = token2[i];
	
		song_no++;
		song_entry entry = song_entry(song_no, song_title, song_artitst, song_genre);
		// hash-table add
		sht.add_song_hash_table(song_no, song_title, song_artitst, song_genre);
		// graph add
		for(int i = 0; i < GENRE_MAX_TOKEN; i++) 
		{
			if(song_genre[i]) 
			{
				sgt.insert_grp_vertex(song_genre[i], entry);
			}
		}	
	}
	fin.close();
	
	return 1;
}

// This function is for loading an external file for edge list
int song_player::load_song_edge_file(String file_name)
{
	const int MAX_LINE_LEN = 100;
	const int MAX_TOKEN = 2;
	const char* DELIM = ";";

	// File I/O
	ifstream fin;
	ofstream fout;
	
	// read Park Information File
	fin.open(file_name.getCharP()); 
	if(fin.fail()) 
	{
		return 0;
	}
	// Load information
	while(!fin.eof()) 
	{
		char buff[MAX_LINE_LEN];
		fin.getline(buff, MAX_LINE_LEN);

		String token[MAX_TOKEN] = {};

		token[0] = strtok(buff, DELIM); // Genre Code1
		if(!token[0]) break;              
		token[1] = strtok(0, DELIM); // Genre Code2 - target

//cout << "Genre1:" << token[0] << endl;
//cout << "Genre2:" << token[1] << endl;

		// create entry & insert grp_vertex
		sgt.insert_edge(token[0], token[1]);
		sgt.insert_edge(token[1], token[0]);
	}
	fin.close();
	
	return 1;
}

// load edge file
void song_player::display_genere_title()
{
	cout << "Genere **************" << endl;
	sgt.display_genere_title();
	cout << endl;
}

void song_player::display_genere_songs(String p_song_genere)
{
	cout << "Genere [" << p_song_genere << "] Song List **************" << endl;
	sgt.display_genere_songs(p_song_genere);
	cout << endl;
}

//again function asking whether adding more song or not
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

//again function asking whether removing more song or not
bool song_player::again2()
{
	char response;
	cout << "Would you like to remove more song? (Y/N): ";
	cin >> response;
	cin.ignore(100, '\n');
	if (toupper(response) == 'Y')
		return true;
	else
		return false;
}

//start function with menu and start this program
void song_player::start()
{
	int menu_select;
	int song_no_to_add = 0;
	int song_no_to_remove = 0;
	
	String song_file = "song_cont.dat";
	String song_grp_edge_file = "song_graph_edge.dat";
	load_songs(song_file);
	load_song_edge_file(song_grp_edge_file);
	
	while(true)	
	{
		cout << "\n\n#########################################################" << endl;
        cout << "##                 Song Player                         ##" << endl;
        cout << "#########################################################" << endl;
        cout << "#                                                  	#" << endl;
        cout << "#  1. List by Artist	                            	#" << endl;
        cout << "#  2. Random list to add to your favourite list    	#" << endl;
        cout << "#  3. Display your favourite list                  	#" << endl;
        cout << "#  4. Remove a song from my favourite list         	#" << endl;
		cout << "#  5. Display selected genre songs with related genre   #" << endl;
        cout << "#  0. Exit Program                                 	#" << endl;
        cout << "#                                                  	#" << endl;
		cout << "########################################################" << endl;
		cout << endl;
		cout << "--> Select a menu:  ";
		cin >> menu_select;
		cout << endl;
		
		//MENU
		switch(menu_select)
		{
			case 1:
				cout << "\n\n=============== Artist List ===================\n\n";
				sht.display_all_table();
				break;
				
			case 2:
			cout << "\n\n=============== Random List ===================\n\n";
				sht.init_playlist();
				
				do{
					cout << "\nEnter a song number to add to your favourite list: ";
					cin >> song_no_to_add;
					cin.ignore();
					sht.add_to_cll(song_no_to_add);
				}while(again());
				break;
				
			case 3:
				cout << "\n\n=============== My favourite List ===================\n\n";
				sht.display_cll();
				break;
				
			case 4:
				cout << "\n\n=============== Remove a song ===================\n\n";
				sht.display_cll();
				do{
					cout << "Enter a song number to remove: ";
					cin >> song_no_to_remove;
					cin.ignore();
					sht.remove_to_cll(song_no_to_remove);
				}while(again());
				break;
				
			case 5:
				cout << "\n\n=============== List by Genre ===================\n\n";
				cout << "1.Pop" << endl;
				cout << "2.Country" << endl;
				cout << "3.Rock" << endl;
				cout << "4.Indie" << endl;
				cout << "5.Dance" << endl;
				cout << "6.House" << endl;
				cout << "7.Blues" << endl;
				cout << "8.Ethnic/Folk" << endl;
				cout << "9.Hip-Hop" << endl;
				cout << "10.Rap" << endl;
				int choose;
				cin >> choose;
				switch(choose)
				{
					case 1:
						display_genere_songs("Pop");
						sgt.display_genere_related("Pop");
						break;
					case 2:
						display_genere_songs("Country");
						sgt.display_genere_related("Country");
						break;
					case 3:
						display_genere_songs("Rock");
						sgt.display_genere_related("Rock");
						break;
					case 4:
						display_genere_songs("Indie");
						sgt.display_genere_related("Indie");
						break;
					case 5:
						display_genere_songs("Dance");
						sgt.display_genere_related("Dance");
						break;
					case 6:
						display_genere_songs("House");
						sgt.display_genere_related("House");
						break;
					case 7:
						display_genere_songs("Blues");
						sgt.display_genere_related("Blues");
						break;
					case 8:
						display_genere_songs("Ethnic/Folk");
						sgt.display_genere_related("Ethnic/Folk");
						break;
					case 9:
						display_genere_songs("Hip-Hop");
						sgt.display_genere_related("Hip-Hop");
						break;
					case 10:
						display_genere_songs("Rap");
						sgt.display_genere_related("Rap");
						break;
				}
				break;
			case 0:
				cout << "\n\n========= Bye Bye ==========\n\n";
				return;
		}
	}
	
}

//this is the main start this program
int main() 
{
	song_player splayer;
	splayer.start();
	
}

