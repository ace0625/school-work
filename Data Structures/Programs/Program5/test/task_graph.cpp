//CS163
//Assignment#5
//Hyunchan Kim

#include <iostream>
#include <fstream>
#include <cstring>
#include "task_graph.h"
using namespace std;

// constructor - initialize data member to NULL
table::table(int size)
{
	list_size = size;
	adjacency_list = new vertex[size];
	for(int i = 0; i < size; i++) 
	{
		adjacency_list[i].head = NULL;
		adjacency_list[i].entry = NULL;
	}
}

table::~table()
{
	remove_all();
}

// remove all data
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

//Store the vertex at this location.
int table::insert_vertex(const task_entry & to_add)
{
	int i = 0;
	while(adjacency_list[i].entry)
	{
		i++;
		if(i >= list_size - 1) 
			break;
	}

	// if the array of vertices is full
	if(i >= list_size - 1) 
		return 0;

	task_entry * temp = new task_entry;
	temp->copy_entry(to_add);
	adjacency_list[i].entry = temp;

	return 1;
}

//Attach an edge to a vertex
int table::insert_edge(char* current_vertex, char* to_attach)
{
	int cv = find_location(current_vertex);
	int av = find_location(to_attach);
	if(cv == list_size - 1 || av == list_size - 1)
		return 0;

	node* newNode = new node;
	newNode->adjacent = &adjacency_list[av];

	if(!adjacency_list[cv].head) 
	{
		newNode->next = NULL;
	}
	else 
	{
		newNode->next = adjacency_list[cv].head;
	}
	adjacency_list[cv].head = newNode;
	
	return 1;
}

// Wrapper - Display all vertices
int table::display_all()
{
	bool* visited = new bool[list_size];
	for(int i = 0; i < list_size; i++)
		visited[i] = false;

	for(int i=0; i<list_size; i++) 
	{
		if(!adjacency_list[i].head) 
			continue;
		node * temp = adjacency_list[i].head;
		display_recur(temp, visited);
	}
	
	delete [] visited;

	return 1;
}

// Wrapper - Display area
int table::display_taskno(char* key)
{
	bool* visited = new bool[list_size];
	for(int i = 0; i < list_size; i++)
		visited[i] = false;

	for(int i = 0; i < list_size; i++) 
	{
		if(!adjacency_list[i].head) 
			continue;
		if(strcmp(adjacency_list[i].entry->get_task_no(), key) == 0) 
		{
			node* temp = adjacency_list[i].head;
			display_recur(temp, visited);
		}
	}
	delete [] visited;
	return 1;
}


// Display vertices recursively
void table::display_recur(node* current, bool visited[])
{
	if(!current) 
		return;
	int vt = find_location(current->adjacent->entry->get_term());
	if(!visited[vt]) 
	{
		visited[vt] = true;
		current->adjacent->entry->display();
	}
	return display_recur(current->next, visited);
}

//Find a location in the graph
int table::find_location(char* key_value)
{
	//return the location of this particular key value 
	int m = 0;
	for(m = 0; m < list_size; m++) 
	{
		if(adjacency_list[m].entry->compare(key_value)) 
			break;
	}
	return m;
}

// load information file
int table::load_task_info_file(char file_name[])
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

	char* p_taskno = NULL; // task no
	char* p_term = NULL; // term
	char* p_step = NULL; // step
	char* p_desc = NULL; // Description

	// Load information
	while(!fin.eof()) 
	{
		task_entry entry;
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
		if(p_taskno) delete p_taskno;
		if(p_term) delete p_term;
		if(p_step) delete p_step;
		if(p_desc) delete p_desc;
		
		p_taskno = new char[strlen(token[0]) + 1];
		strcpy(p_taskno, token[0]);

		p_term = new char[strlen(token[1]) + 1];
		strcpy(p_term, token[1]);

		p_step = new char[strlen(token[2]) + 1];
		strcpy(p_step, token[2]);

		p_desc = new char[strlen(token[3]) + 1];
		strcpy(p_desc, token[3]);

		// create entry & insert vertex
		entry.create_entry(p_taskno, p_term, p_step, p_desc);
		insert_vertex(entry);
	}
	fin.close();
	
	// delete
	if(p_taskno) delete p_taskno;
	if(p_term) delete p_term;
	if(p_step) delete p_step;
	if(p_desc) delete p_desc;

	return 1;
}

// load edge file
int table::load_task_edge_file(char file_name[])
{
	const int MAX_LINE_LEN = 10;
	const int MAX_TOKEN = 2;
	const char* const DELIM = "|";

	// File I/O
	ifstream fin;
	ofstream fout;
	
	// read task Information File
	fin.open(file_name); 
	if(fin.fail()) {
		return 0;
	}

	// Load information
	while(!fin.eof()) 
	{
		//task_entry entry;

		char buff[MAX_LINE_LEN];
		fin.getline(buff, MAX_LINE_LEN);

		char* token[MAX_TOKEN] = {};

		token[0] = strtok(buff, DELIM); 
		if(!token[0]) 
			break;              
		token[1] = strtok(0, DELIM); 
		
		// create entry & insert vertex
		insert_edge(token[0], token[1]);
		insert_edge(token[1], token[0]);
	}
	fin.close();
	
	return 1;
}

