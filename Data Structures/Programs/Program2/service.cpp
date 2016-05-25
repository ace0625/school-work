//CS163
//Assignment #2
//4/29/2015
//Hyunchan Kim
//service.cpp
#include "service.h"

//implements all functions declared from service header file

//service constructor
service::service()
{
	name = NULL;
	order = NULL;
	arrival_time = NULL;
	length_of_time = 0;
	total_time = 0;
}

//service destructor
service::~service()
{
	name = NULL;
	order = NULL;
	arrival_time = NULL;
	length_of_time = 0;
	total_time = 0;
}
//create a new service 
int service::createOrder(char * a_name, char * an_order, char * an_arrival_time, int time)
{
	name = new char[strlen(a_name) + 1]; //get name
	strcpy(name, a_name);

	order = new char[strlen(an_order) + 1]; //get order name
	strcpy(order, an_order);

	arrival_time = new char[strlen(an_arrival_time) + 1]; //get arrivaal time
	strcpy(arrival_time, an_arrival_time);

	length_of_time = time; //get length of the time

	total_time += length_of_time; //add the length of the time to the total time

	return 1;
}

//copy the order service 
int service::copy_order(const service & copyfrom)
{
	if (copyfrom.name)
	{
		name = new char[strlen(copyfrom.name) + 1];
		strcpy(name, copyfrom.name);
	}
	if (copyfrom.order)
	{
		order = new char[strlen(copyfrom.order) + 1];
		strcpy(order, copyfrom.order);
	}
	if (copyfrom.arrival_time)
	{
		arrival_time = new char[strlen(copyfrom.arrival_time) + 1];
		strcpy(arrival_time, copyfrom.arrival_time);
	}
	length_of_time = copyfrom.length_of_time;
	
	total_time += copyfrom.total_time;

	return 1;
}


//get current time function.
/* char service::getCurrentTime()
{
	time_t t = time(0);
	char * curTime = ctime(&t);
	//cout << curTime << endl;
	return (char)curTime;
} */

//display order information(name, order name, arrival time)
void service::display()
{
	cout << "\n>>>>>>>Your Order information <<<<<<<<<<<" << endl;
	cout << "-> Name: " << name << endl;
	cout << "-> Order: " << order << endl;
	cout << "-> Arrival time: " << arrival_time;
	cout << "-> Approximate time: " << length_of_time << endl;
	cout << "-> Total waiting time: " << total_time << endl << endl;
}


//displyting total remaining time
int service::total_remaining_time()
{
	cout << "The remain waiting time is " << total_time << " minutes." << endl;
	cout << "Please wait. Thank you." << endl;

	return total_time;
}

//set average time
int service::average_time()
{
	return 0;
}

// prompt the user if want to play again
bool again()
{
	char response;
	cout << "Go back to the Menu? (Y/N): ";
	cin >> response;
	cin.ignore(100, '\n');
	if (toupper(response) == 'Y')
		return true;
	else
		return false;
}
