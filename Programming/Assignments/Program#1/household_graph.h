// CS202
// Program #1
// household_graph.h

#ifndef _HOUSEHOLD_GRAPH_H
#define _HOUSEHOLD_GRAPH_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;

/*
	This is household class which contains household information
	from the external census data and base class. 
*/
class household
{
	public:
		household(); //default constructor
		~household(); //destructor
		household(char * a_region, char * a_race, char * a_income, char * a_age_group); //constructor
		household(const household & copy_info); //copy constructor
		int display_household();

	protected:
		char * region; //region
		char * race; //contains races
		char * income; // median house hold income
		char * age_group; // for each age group, the number of people
};

/*
	This is edge_node class that indicates adjacency list node
	and derived class from household class
*/
class edge_node : public household
{
	public:
		edge_node(); //default constructor
		~edge_node(); //destructor
		edge_node(char * a_region, char * a_race, char * a_income, char * a_age_group); //constructor
		edge_node(const household & copy_info); //copy constructor
		int set_destination(int a_destination); //set destination
		int get_destination(); //get destination
		edge_node * & go_next(); //go to next node

	protected:
		int destination;
		edge_node * next;
};

/*
	This is adjacency_list class contains edge information.
	In other words, adjacency_list has 'has a' relationship with 
	edge_node.
*/
class adjacency_list
{
	public:
		adjacency_list(); //default constructor
		~adjacency_list(); //destructor
		void sethead(); //set head to null
		edge_node * & go_to_head(); //return head

	protected:
		edge_node * head;
};

/*
	This is household_graph class composed of graph data structure.
*/
class household_graph
{
	public:
		household_graph(); //default constructor
		~household_graph(); //destructor
		void load_census_data();//read in an external data file
		int create(char * a_region, char * a_race, char * a_income, char * a_age_group, int number); // create a data
		int add_edge_data(char * a_region, char * a_race, char * a_income, char * a_age_group, int start, int end);
		edge_node * a_edge_node(char * a_region, char * a_race, char * a_income, char * a_age_group, int end);
		void remove_all(); //remove all data
		int display(); //display all data

	protected:
		adjacency_list * list;
		int vertex_size;

};


#endif


