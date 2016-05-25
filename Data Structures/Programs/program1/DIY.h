//CS163
//Program #1
//4/15/2015
//Hyunchan Kim
//DIY.h

//This program is called DIY(Do it yourself) that manages parts and data from an external
//text file to build a green house. This program makes easy to follow to build step by step
//and find what you want. Starting from reading a text file to sorting and displaying each 
//section, you will be able to easily deal with all the part data.

//this is the main header file that declares the ADT and client program

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;

//This structure holds all of the data
struct part
{
	char * part_number; //part number
	char * description; //part description and size
	char * quantity; // part quantity
	char * step_number; // number of steps
	char * steps; //steps
};


// This structure is the node performing LLL
struct node
{
	part data; //Array that holds the data
	node * next; //points to the next node
};

//ADT class
class DIY
{
	public:
		DIY(); //default constructor
		~DIY(); //default destructor
		int readfile(const char *filename); //read in all data from the text file
		int display_parts(); //display all parts, in order of part number
		int display_steps(); //display all steps and parts needed for each step
		int display_all(); //display all data in the file

	private:
		node * part_head; //head pointer for part
		node * step_head; //head pointer for step
		int num_of_parts; //number of parts
};

