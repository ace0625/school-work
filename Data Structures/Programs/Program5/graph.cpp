#include "graph.h"

//graph.cpp

table::table(int size)
{
      //Allocate the adjacency list and set each
      //head pointer to NULL
	adjacency_list = new vertex[size];
	for(int i = 0; i < size; ++i)
	{
		adjacency_list[i].head = NULL;
		adjacency_list[i].entry = NULL;
	}
	list_size = size;
}

table::~table()
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
int table::insert_vertex(const journal_entry & to_add)
{
        //Place your code here
	int i = 0;
	while(adjacency_list[i].entry)
	{
		i++;
		if(i >= list_size - 1)
			break;
	}
	// array of vertices is full
	if(i >= list_size) 
		return 0;
	
	journal_entry * temp = new journal_entry;
	temp->copy_entry(to_add);
	adjacency_list[i].entry = temp;
	return 1;

}

//Find a location in the graph
//Consider this a helper function for all of the other member functions!
int table::find_location(char * key_value)
{
	int m = 0;
    for(m = 0; m < list_size; m++) 
	{
        if(adjacency_list[m].entry->compare(key_value)) 
			return m;
    }
}

//Attach an edge to a vertex
int table::insert_edge(char * current_vertex, char * to_attach)
{
       //Attach this vertices edge to the specified vertex
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

//Display all vertices adjacent to the one specified
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

int table:display_all()
{
	return 1;
}
