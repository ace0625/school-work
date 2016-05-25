/**
 * Kwangwoong Yang
 * amusement song, [Program #5]
 * 
 * "song_graph.cpp" - song Graph Program File
 * This program implements a song graph logic.
 *  
 */
#include "song_graph.h"
using namespace std;


//********************************************
// class : edge_node
edge_node::edge_node()
{
	// constructor
}

grp_vertex* edge_node::go_adjacent()
{
	return adjacent;
}

edge_node* edge_node::go_next()
{
	return next;
}

//********************************************
// class : grp_vertex
grp_vertex::grp_vertex()
{
	// constructor
	ghead = NULL;
	entry = NULL;
}

song_entry* grp_vertex::get_entry()
{
	return entry;
}

edge_node* grp_vertex::get_ghead()
{
	return ghead;
}

//********************************************
// class : song_graph_table
// constructor - initialize data member to NULL
song_graph_table::song_graph_table(int size)
{
	// Allocate the adjacency list and set each ghead pointer to NULL
	list_size = size;
	adjacency_list = new grp_vertex[size];
}

// destructor - deallocate memory
song_graph_table::~song_graph_table()
{
	remove_all();
}

// remove all data
int song_graph_table::remove_all()
{
/*
	for(int i = 0; i < list_size; i++) {
		// delete entry
		if(!adjacency_list[i].get_entry()) break;
		delete adjacency_list[i].get_entry();
		adjacency_list[i].get_entry() = NULL;

		// delete edge_nodes
		edge_node* ghead = adjacency_list[i].get_ghead();
		while(ghead) {
			edge_node* temp = ghead;
			ghead = ghead->go_next();
			delete temp;
			temp = NULL;
		}
	}
	delete [] adjacency_list;
*/
	return 1;
}

//Store the grp_vertex at this location.
int song_graph_table::insert_grp_vertex(const song_entry & to_add)
{
	int i = 0;
	while(adjacency_list[i].get_entry()) {
		i++;
		if(i >= list_size - 1) break;
	}

	// if the array of vertices is full
	if(i >= list_size - 1) return 0;

	song_entry* temp = new song_entry;
	temp->copy_entry(to_add);
	adjacency_list[i].get_entry() = temp;

	return 1;
}

//Attach an edge to a grp_vertex
int song_graph_table::insert_edge(String current_grp_vertex, String to_attach)
{
	int cv = find_location(current_grp_vertex);
	int av = find_location(to_attach);
	if(cv == list_size - 1 || av == list_size - 1)
		return 0;

	edge_node* newNode = new edge_node;
	newNode->go_adjacent() = &adjacency_list[av];

	if(!adjacency_list[cv].get_ghead()) {
		newNode->go_next() = NULL;
	}
	else {
		newNode->go_next() = adjacency_list[cv].get_ghead();
	}
	adjacency_list[cv].get_ghead() = newNode;
	
	return 1;
}

// Wrapper - Display all vertices
int song_graph_table::display_all()
{
	bool* visited = new bool[list_size];
	for(int i = 0; i < list_size; i++)
		visited[i] = false;

	for(int i=0; i<list_size; i++) {
		if(!adjacency_list[i].get_ghead()) continue;
		edge_node* temp = adjacency_list[i].get_ghead();
		display_recur(temp, visited);
	}
	
	delete [] visited;

	return 1;
}

// Wrapper - Display area
int song_graph_table::display_genre(String key_genre)
{
	bool* visited = new bool[list_size];
	for(int i = 0; i < list_size; i++)
		visited[i] = false;

	for(int i = 0; i < list_size; i++) {
		if(!adjacency_list[i].get_ghead()) continue;
		if(strcmp(adjacency_list[i].get_entry()->get_parea(), key_genre) == 0) {
			edge_node* temp = adjacency_list[i].get_ghead();
			display_recur(temp, visited);
		}
	}
	
	delete [] visited;

	return 1;
}


// Display vertices recursively
void song_graph_table::display_recur(edge_node* current, bool visited[])
{
	if(!current) return;
	int vt = find_location(current->go_adjacent()->get_entry()->get_pcode());
	if(!visited[vt]) {
		visited[vt] = true;
		current->go_adjacent()->get_entry()->display_all();
	}
	return display_recur(current->go_next(), visited);
}

//Find a location in the graph
int song_graph_table::find_location(String key_value)
{
	//return the location of this particular key value 
	int m = 0;
	for(m = 0; m < list_size; m++) {
		if(adjacency_list[m].get_entry()->compare(key_value)) {
			break;
		}
	}

	return m;
}

/*
// load information file
int song_graph_table::load_song_info_file(char file_title[])
{
	const int MAX_LINE_LEN = 500;
	const int MAX_TOKEN = 4;
	const String const DELIM = "|";

	// File I/O
	ifstream fin;
	ofstream fout;
	
	// read Park Information File
	fin.open(file_title); 
	if(fin.fail()) {
		return 0;
	}

	String p_genre; // Genre
	String p_artitist;
	String p_title;

	// Load information
	while(!fin.eof()) {
		song_entry entry;

		char buff[MAX_LINE_LEN];
		fin.getline(buff, MAX_LINE_LEN);

		const String token[MAX_TOKEN] = {};

		token[0] = strtok(buff, DELIM);
		if(!token[0]) break;
		
		for(int i = 1; i < MAX_TOKEN; i++) {
			token[i] = strtok(0, DELIM);
		}

		// copy information to entry
		song_artitst = token[0];
		song_genre   = token[1];
		song_title   = token[2];

//cout << "p_artitist :" << p_artitist << endl;
//cout << "p_title:" << p_title << endl;
//cout << "p_desc :" << p_desc << endl;

		// create entry & insert grp_vertex
		entry.create_entry(p_genre, p_artitist, p_title);
		insert_grp_vertex(entry);
	}
	fin.close();
	
	// delete
	if(p_genre) delete p_genre;
	if(p_artitist) delete p_artitist;
	if(p_title) delete p_title;

	return 1;
}
*/

// load edge file
int song_graph_table::load_song_edge_file(char file_title[])
{
/*
	const int MAX_LINE_LEN = 10;
	const int MAX_TOKEN = 2;
	const String const DELIM = "|";

	// File I/O
	ifstream fin;
	ofstream fout;
	
	// read Park Information File
	fin.open(file_title); 
	if(fin.fail()) {
		return 0;
	}

	// Load information
	while(!fin.eof()) {
		song_entry entry;

		char buff[MAX_LINE_LEN];
		fin.getline(buff, MAX_LINE_LEN);

		String token[MAX_TOKEN] = {};

		token[0] = strtok(buff, DELIM); // Genre Code1
		if(!token[0]) break;              
		token[1] = strtok(0, DELIM); // Genre Code2 - target

//cout << "p_artitist1:" << token[0] << endl;
//cout << "p_artitist2:" << token[1] << endl;

		// create entry & insert grp_vertex
		insert_edge(token[0], token[1]);
		insert_edge(token[1], token[0]);
	}
	fin.close();
	
*/
	return 1;
}
/*
int main()
{
	song_graph_table my_park;
	char park_info_file_name [] = "am_park_info.txt";
	char park_edge_file_name [] = "am_park_edge.txt";
	char area[4][4] = {"AA", "BB", "CC", "DD"};
	int menu_in = 0;


	// park infomation file read and insert
	if(!my_park.load_park_info_file(park_info_file_name)) {
		cout << "\n[ERROR] Park Information File loading process fail!" << endl;
		return 0;
	}
	else {
		cout << "\n[SUCCESS] Park Information File is successfully loaded!\n\n";
	}

	// park edge file read and insert
	if(!my_park.load_park_edge_file(park_edge_file_name)) {
		cout << "\n[ERROR] Park Edge File loading process fail!" << endl;
		return 0;
	}
	else {
		cout << "\n[SUCCESS] Park Edge File is successfully loaded!\n\n";
	}

}
*/