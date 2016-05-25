//CS163
//Assignment #2
//4/29/2015
//Hyunchan Kim

//service.h
//This class is the base class implements creating an order, copying order, getting current time, 
//displaying service, total remaining time, and average time. The data go to the queue and stacks
//classes to manage different data structures.
#ifndef _SERVICE_H
#define _SERVICE_H

#include <iostream>
#include <cctype>
#include <cstring>
#include <ctime>

using namespace std;
//service class
class service
{
	public:
		service(); //constructor
		~service(); //destructor
		int createOrder(char * name, char * order, char * arrival_time, int length_of_time); //create an order
		int copy_order(const service & copyfrom); //copy order
		char getCurrentTime(); // get currentTime
		void display(); //display a service
		int total_remaining_time();
		int average_time();
	private:
		char * name; //customer's name
		char * order; //order name
		char * arrival_time; //arrival time
		int length_of_time; // the length of time
		int total_time; // total time

};

//ask user whether to start again
bool again();

#endif
