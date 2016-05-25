//CS202
//Assignment #3
//Hyunchan Kim

//song_graph.h
//this is the graph header file that composes all graph information

#include "song_graph.h"
using namespace std;


// class : edge_node
lll_genere_node::lll_genere_node() //constructor 
{}

lll_genere_node::~lll_genere_node() //destructor
{}

lll_genere_node::lll_genere_node(const song_entry& a_entry): song_entry(a_entry) //copy constructor
{}

lll_genere_node*& lll_genere_node::go_next() //go next 
{
	return next;
}


// edge node class
edge_node::edge_node() {}

grp_vertex *&  edge_node::go_adjacent() //go adjacent
{
	return adjacent;
}

//go next
edge_node*& edge_node::go_next()
{
	return next;
}

grp_vertex::grp_vertex() //graph class constructor
{
	lg_head = NULL;
	eg_head = NULL;
}

String grp_vertex::get_song_genere() //get song genre
{
	return song_genere;
}

//set song genre 
void grp_vertex::set_song_genere(String p_song_genere)
{
	song_genere = p_song_genere;
}

//compare song genre
int grp_vertex::compare_song_genere(String p_song_genere)
{
	if(song_genere == p_song_genere) return 1;
	else return 0;
}

//go edge head
edge_node*& grp_vertex::go_eg_head()
{
	return eg_head;
}

//set edge head
void grp_vertex::set_eg_head(edge_node* p_eg_head)
{
	eg_head = p_eg_head;
}

//go to edge head
lll_genere_node*& grp_vertex::go_lg_head()
{
	return lg_head;
}

//set edge head
void grp_vertex::set_lg_head(lll_genere_node* p_lg_head)
{
	lg_head = p_lg_head;
}

//graph table constructor
song_graph_table::song_graph_table(int size)
{
	genere_size = 0;
	list_size = size;
	adjacency_list = new grp_vertex[size];
	visited = new int[size];
}

// destructor 
song_graph_table::~song_graph_table()
{
	remove_all();
}

// Remove all 
int song_graph_table::remove_all()
{
	for(int i = 0; i < genere_size; i++) 
	{
		edge_node* eg_head = adjacency_list[i].go_eg_head();
		while(eg_head) 
		{
			edge_node* temp = eg_head;
			eg_head = eg_head->go_next();
			delete temp;
			temp = NULL;
		}
		lll_genere_node* lg_head = adjacency_list[i].go_lg_head();
		while(lg_head) 
		{
			lll_genere_node* temp = lg_head;
			lg_head = lg_head->go_next();
			delete temp;
			temp = NULL;
		}
	}
	delete [] adjacency_list;
	return 1;
}

//Find a location with genre
int song_graph_table::find_location(const String p_song_genere)
{
	if(genere_size == 0) return -1;
	for(int i = 0; i < list_size; i++) 
	{
		if(adjacency_list[i].compare_song_genere(p_song_genere)) 
		{	
			return i;
		}
	}
	return -1;
}

//get genre size
int song_graph_table::get_genere_size()
{
	return genere_size;
}

//Store the grp_vertex at this location.
int song_graph_table::insert_grp_vertex(const String p_song_genere, const song_entry & to_add)
{
	int idx_song_genere = 0;
	int gr_size = 0;
	
	idx_song_genere = find_location(p_song_genere);
	lll_genere_node* temp = new lll_genere_node(to_add);

	if(idx_song_genere >= 0) 
	{
		temp->go_next() = adjacency_list[idx_song_genere].go_lg_head();
		adjacency_list[idx_song_genere].set_lg_head(temp);
		adjacency_list[idx_song_genere].set_song_genere(p_song_genere);
		return 1;
	}
	else 
	{
		gr_size = get_genere_size();
		adjacency_list[gr_size].set_lg_head(temp);
		adjacency_list[gr_size].set_song_genere(p_song_genere);
		genere_size++;
	}

	return 1;
}

//Attach an edge to a grp_vertex
int song_graph_table::insert_edge(String current_grp_vertex, String to_attach)
{
	int cv = find_location(current_grp_vertex);
	int av = find_location(to_attach);
	
	// if error to find
	if(cv == -1 || av == -1)
		return 0;

	edge_node* newNode = new edge_node;
	newNode->go_adjacent() = &adjacency_list[av];

	if(!adjacency_list[cv].go_eg_head()) 
	{
		newNode->go_next() = NULL;
	}
	else 
	{
		newNode->go_next() = adjacency_list[cv].go_eg_head();
	}
	adjacency_list[cv].go_eg_head() = newNode;
	return 1;
}

// Wrapper - Display genre
void song_graph_table::display_genere_songs(String key_genere)
{
	int i = 0, j = 0;
	i = find_location(key_genere);
	lll_genere_node* temp = adjacency_list[i].go_lg_head();

	while(temp) 
	{
		cout << ++j << ". " << temp->get_song_title() << " / " << temp->get_song_artitst() << endl;
		temp = temp->go_next();
	}

	return;
}

// display related genere - recursively
void song_graph_table::display_genere_related(String key_genere)
{
	for(int i = 0; i < list_size; i++)
		visited[i] = 0;

	int temp = find_location(key_genere);
	display_recur(temp);
}

// Display genres vertices recursively
void song_graph_table::display_recur(int &i)
{
	int j, t;
	cout << "CURRENT GENRE : " << adjacency_list[i].get_song_genere() << endl;
	visited[i] = 1;
	String temp;
	while(adjacency_list[i].go_eg_head()) 
	{
		temp = adjacency_list[i].go_eg_head()->go_adjacent()->get_song_genere();
		t = find_location(temp);
		cout << "Related genre : " << temp << endl;
		visited[t] = 1;
		if(!visited[t]) 
		{
			if(adjacency_list[i].go_eg_head()->go_next()) 
			{
				temp = adjacency_list[i].go_eg_head()->go_next()->go_adjacent()->get_song_genere();
				t = find_location(temp);
				display_recur(t);
			}
			else
				adjacency_list[i].go_eg_head() =  adjacency_list[i].go_eg_head()->go_next();
		}
		else
			adjacency_list[i].go_eg_head() =  adjacency_list[i].go_eg_head()->go_next();
	}
}

//display title
void song_graph_table::display_genere_title()
{
	if(genere_size == 0) return;
	for(int i = 0; i < genere_size; i++) 
	{
		cout << "[" << i << "] " << adjacency_list[i].get_song_genere() << endl;
	}
}
