//CS163
//Program #1
//10/14/2015
//Hyunchan Kim
//candidate.h

// For this assignment which is candidate program that basically manages presidential candidates. It mainly implements 
// creating a candidate information with name, major views, rank, and thoughts, update poll which is a voting system that
// you can poll to a particular candidate you want and the rank would change, update information that you can wriete 
// your personal thoughts to a particular candidate, and display all candidates in the system.
// The main data structure is Linear linked list. 

//this is the main header file that declares the ADT and client program

#ifndef _CANDIDATE_H
#define _CANDIDATE_H

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;


//ADT class
class candidate
{
	public:
		candidate(); //default constructor
		~candidate(); //default destructor
		//create a candidate function
		int create_candidate(char * firstname, char * lastname, char * a_view1, char * a_view2, 
		char * a_view3, char * a_view4, char * a_view5, int a_rank, char * a_thoughts);	
		int copy_candidate(const candidate & copy_from); //copy function
		int retrieve(char * keyword, candidate & found); //find a particular item
		int display(); //display function	
		void add_poll(); //add a poll
		void add_thoughts(char * a_thought); //add your thoughts
		bool again(); //ask user to do again
		
	private:
		char * first_name; //first name
		char * last_name; //last name
		char * view1; //major view 1
		char * view2; //major view 2
		char * view3; //major view 3
		char * view4; //major view 4
		char * view5; //major view 5
		int rank; // poll rank
		char * thoughts; // your thoughts 
};


// This structure is the node performing LLL
struct node
{
	candidate a_candidate; //Array that holds the data
	node * next; //points to the next node
};


//list class for LLL
class list
{
	public:
		list(); //default constructor
		~list(); //default destructor
		int insert(candidate & to_add); //insert function that adds a candidate to LLL
		int update_poll(char * name, candidate & found); //update poll
		int update_information(char * findbylastname, char * a_thought, candidate & found); //update candidate information
		int display_all(void); //display all data in LLL
	
	private:
		node * head; //head pointer
		int number_of_candidate; //number of candidate
};

#endif
