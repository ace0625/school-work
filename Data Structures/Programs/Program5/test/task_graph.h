//CS163
//Assignment#5
//Hyunchan Kim

#include "task_entry.h"

#ifndef _TASK_GRAPH_H
#define _TASK_GRAPH_H

struct vertex
{
	task_entry *  entry;	// entry
	struct node *  head;	// edge(adjacency) list
};

struct node
{
	vertex * adjacent;
	node * next;
};

class table
{
	public:
		table(int size = 50);
		~table(void);
		int insert_vertex(const task_entry & to_add);
		int find_location(char* key_value);
		int insert_edge(char* current_vertex, char* to_attach);
		int remove_all();
		int load_task_info_file(char file_name[]);
		int load_task_edge_file(char file_name[]);
		int display_all();
		int display_taskno(char* key);
		
	private:
		vertex * adjacency_list;
		int list_size;
		void display_recur(node* current, bool visited[]);
};
#endif
