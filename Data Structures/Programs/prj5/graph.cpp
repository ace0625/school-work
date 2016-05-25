//CS163
//Assignment#5
//Hyunchan Kim

#include "graph.h"
using namespace std;
//graph.cpp


/*
	Constructor
*/
table::table(int size)
{
	adjacency_list = new vertex[size];
	for(int i = 0; i < size; ++i)
	{
		adjacency_list[i].head = NULL;
		adjacency_list[i].entry = NULL;
	}
	list_size = size;
}

/*
	Destructor
*/
table::~table()
{
   remove_all();
}

/*
	Remove all data
*/
int table::remove_all()
{
	for(int i = 0; i < list_size; i++) 
   {
		// delete entry
		if(!adjacency_list[i].entry) break;
		delete adjacency_list[i].entry;
		adjacency_list[i].entry = NULL;

		// delete nodes
		node* head = adjacency_list[i].head;
		while(head) 
		{
			node* temp = head;
			head = head->next;
			delete temp;
			temp = NULL;
		}
	}
	delete [] adjacency_list;
	return 1;
}

/*
	Load data file
*/
int table::load_data_file(char file_name[])
{
	const int MAX_LINE_LEN = 500;
	const int MAX_TOKEN = 4;
	const char* const DELIM = "|";

	// File I/O
	ifstream fin;
	ofstream fout;
	
	// read Information File
	fin.open(file_name); 
	if(fin.fail()) 
	{
		return 0;
	}

	char * t_event = NULL; // event
	char * t_ID = NULL; // ID
	char * t_name = NULL; // name

	// Load information
	while(!fin.eof()) 
	{
		friend_entry entry;
		
		char buff[MAX_LINE_LEN];
		fin.getline(buff, MAX_LINE_LEN);

		const char* token[MAX_TOKEN] = {};

		token[0] = strtok(buff, DELIM);
		if(!token[0]) break;
		
		for(int i = 1; i < MAX_TOKEN; i++) 
		{
			token[i] = strtok(0, DELIM);
		}

		// copy information to entry
		if(t_event) delete t_event;
		if(t_ID) delete t_ID;
		if(t_name) delete t_name;
		
		t_event = new char[strlen(token[0]) + 1];
		strcpy(t_event, token[0]);

		t_ID = new char[strlen(token[1]) + 1];
		strcpy(t_ID, token[1]);

		t_name = new char[strlen(token[2]) + 1];
		strcpy(t_name, token[2]);

		// create entry & insert vertex
		entry.create_entry(t_event, t_ID, t_name);
		insert_vertex(entry);
	}
	fin.close();
	
	// delete
		if(t_event) delete t_event;
		if(t_ID) delete t_ID;
		if(t_name) delete t_name;

	return 1;
}


/*
	Load edge file
*/
int table::load_edge_file(char file_name[])
{
	const int MAX_LINE_LEN = 10;
	const int MAX_TOKEN = 3;
	const char* const DELIM = "|";

	// File I/O
	ifstream fin;
	ofstream fout;
	
	char * edge1 = NULL;
	char * edge2 = NULL;
	// read task Information File
	fin.open(file_name); 
	if(fin.fail()) 
	{
		return 0;
	}
	// Load information
	while(!fin.eof()) 
	{
		char buff[MAX_LINE_LEN];
		fin.getline(buff, MAX_LINE_LEN);

		char* token[MAX_TOKEN] = {};

		token[0] = strtok(buff, DELIM); 
		if(!token[0]) 
			break;              
		token[1] = strtok(0, DELIM); 
		
		edge1 = new char[strlen(token[0]) + 1];
		strcpy(edge1, token[0]);
		edge2 = new char[strlen(token[1]) + 1];
		strcpy(edge2, token[1]);
		
		insert_edge(edge1, edge2);
		insert_edge(edge2, edge1);
		// create entry & insert vertex
		// insert_edge(token[0], token[1]);
		// insert_edge(token[1], token[0]);
	}
	fin.close();
	
	return 1;
}

/*
	Insert vertex
*/
int table::insert_vertex(const friend_entry & to_add)
{
	for(int i = 0; i < list_size; ++i)
	{
		if(!adjacency_list[i].entry)
		{
			adjacency_list[i].entry = new friend_entry;
			adjacency_list[i].entry->copy_entry(to_add);
			return 1;
		}
		else if(i == list_size-1)
			return 0;
	}

}

/*
	Find a location in the graph
*/
int table::find_location(char * key_value)
{
	if(!adjacency_list)
		return 0;
	
	bool match = false;
	for(int i = 0; i < list_size; ++i)
	{
		match = adjacency_list[i].entry->compare(key_value);
		if(match)
			return i;
	}
	return 0;
}

/*
	Attach an edge to a vertex
*/
int table::insert_edge(char * current_vertex, char * to_attach)
{
    int current_v = find_location(current_vertex);
    int attach_v = find_location(to_attach);

    if(current_v == list_size-1 || attach_v == list_size-1)
        return 0;

    node * temp = new node;
    temp->adjacent = &adjacency_list[attach_v];

    if(!adjacency_list[current_v].head)
        temp->next = NULL;
    else
        temp->next = adjacency_list[current_v].head;

    adjacency_list[current_v].head = temp;

    return 1;
}

/*
	Display all vertices adjacent to the one specified
*/
int table::display_adjacent(char * key_value)
{
    int vt = find_location(key_value);

    node* temp = adjacency_list[vt].head;

    while(temp) 
	{
        temp->adjacent->entry->display();
        temp = temp->next;
    }
    return 1;
}


/*
	Display event list
*/
int table::display_event(char * key)
{
	bool* visited = new bool[list_size];
	for(int i = 0; i < list_size; i++)
		visited[i] = false;

	for(int i = 0; i < list_size; i++) 
	{
		if(!adjacency_list[i].head) 
			continue;
		if(strcmp(adjacency_list[i].entry->get_event(), key) == 0) 
		{
			node* temp = adjacency_list[i].head;
			display_recur(temp, visited);
		}
	}
	delete [] visited;
	return 1;
}

/*
	Display all
*/
int table::display_all()
{
	for(int i = 0; i < list_size; i++) 
    {
		if (!adjacency_list[i].entry && i == 0)//If the list is empty
            return 0;
        adjacency_list[i].entry->display();
	}

	return 1;
}


/*
	Display in recursive order
*/
void table::display_recur(node* current, bool visited[])
{
	if(!current) 
		return;
	int vt = find_location(current->adjacent->entry->get_ID());
	if(!visited[vt]) 
	{
		visited[vt] = true;
		current->adjacent->entry->display();
	}
	return display_recur(current->next, visited);
}
