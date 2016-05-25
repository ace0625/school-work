//CS163
//Program #1
//4/15/2015
//Hyunchan Kim
//DIY.cpp
//This file Implements the Abstract Data Type

#include "DIY.h"

/*
Default constructor
*/
DIY::DIY()
{
	part_head = NULL;
	step_head = NULL;
	num_of_parts = 0;
}
/*
Default desctructor
*/
DIY::~DIY()
{
	num_of_parts = 0; //count number of parts
	if (part_head) 
	{
		node * temp;
		while (part_head)
		{
			temp = part_head->next;
			delete part_head;
			part_head = temp;
		}
	}
	if (step_head)
	{
		node * temp;
		while (step_head)
		{
			temp = step_head->next;
			delete step_head;
			step_head = temp;
		}
	}
}
/*
readfile function reads in all the data from parts.txt file
and sets a LLL
*/
int DIY::readfile(const char *filename)
{
	ifstream read;
	read.open("parts.txt");
	if (read.is_open()) // if txt file is open
	{
		while (!read.eof())  // read all file data
		{
			if (!part_head)  //if head is null
			{
				part_head = new node;
				part_head->data.part_number = new char[20];
				part_head->data.description = new char[20];
				part_head->data.quantity = new char[20];
				part_head->data.step_number = new char[20];
				part_head->data.steps = new char[20];
				read.getline(part_head->data.part_number, 20, ':'); //read data until first colon has been read for the part number
				read.getline(part_head->data.description, 20, ':'); //read data until second colon has been read for the part description
				read.getline(part_head->data.quantity, 20, ':'); //read data until third colon has been read for quantity
				read.getline(part_head->data.step_number, 20, ':'); //read data until fourth colon has been read for the step number
				read.getline(part_head->data.steps, 20, '\n'); //read data until newline has been read for steps
				++num_of_parts; //number of parts +1
				part_head->next = NULL;
			}
			else
			{
				node * current = part_head;
				while (current->next) // get to the last node(loop until the last node is null)
				{
					current = current->next;
				}
					current->next = new node;
					current = current->next;
					current->data.part_number = new char[20];
					current->data.description = new char[20];
					current->data.quantity = new char[20];
					current->data.step_number = new char[20];
					current->data.steps = new char[20];
					read.getline(current->data.part_number, 20, ':'); //read data until first colon has been read for the part number
					read.getline(current->data.description, 20, ':'); //read data until second colon has been read for the part description
					read.getline(current->data.quantity, 20, ':'); //read data until third colon has been read for quantity
					read.getline(current->data.step_number, 20, ':');  //read data until fourth colon has been read for the step number
					read.getline(current->data.steps, 20, '\n');		//read data until newline has been read for steps
					++num_of_parts; //number of parts +1
					current->next = NULL;
			}	
		}
	}
	else
	{
		//if file is not open
		return 0;
	}
	read.close();  //close reading file
	return 1;
}
/*
THis function implements displaying the part numbers in order
*/
int DIY::display_parts()
{
	if (!part_head) //if head is null
		return 0;

	node * current = part_head;
	char * temp = new char[20]; //temporary data for sorting
	//sorting part number data
	for (int i = 0; i < num_of_parts; ++i)
	{
		while (current->next)
		{
			if (atoi(current->data.part_number)	 > atoi(current->next->data.part_number)) //atoi function converts char to int
			{
				temp = current->data.part_number;
				current->data.part_number = current->next->data.part_number;
				current->next->data.part_number = temp;
				current = current->next;
			}
			else
				current = current->next;
		}
		current = part_head;
	}

	//Print part numbers in sorted order
	if (!part_head)
	return 0;
	node * curr = part_head;
	while (curr)
	{
		cout << "-->> " << curr->data.part_number << ":";
		cout << curr->data.description << ":";
		cout << curr->data.quantity << ":";
		cout << curr->data.step_number << ":";
		cout << curr->data.steps << endl << endl;
		curr = curr->next;
	}
	cout << "----------------- Total " << num_of_parts << " parts." << endl << endl; //number of parts
	return 1;
}

/*
This functions implements displaying steps
*/
int DIY::display_steps()
{
	if (!part_head) // if head is null
		return 0;
	node * current = part_head;
	while (current) // loop all nodes and display steps
	{
		cout << "For step --> " << current->data.steps << endl;
		cout << "We need the part <" << current->data.part_number << ">" << endl << endl;
		current = current->next;
	}
	return 1;
}
/*
This function implements displaying all data in a small box
*/
int DIY::display_all()
{
	if (!part_head) //Return 0 if head is null
		return 0;
	node * current = part_head;
	while (current) //go through all nodes
	{
		cout << "\n===============================\n";
		cout << "= Part Number: " << current->data.part_number << endl;
		cout << "= Description: " << current->data.description << endl;
		cout << "= Quantity: " << current->data.quantity << endl;
		cout << "= Number of steps : " << current->data.step_number << endl;
		cout << "= Steps : " << current->data.steps << endl;
		cout << "=================================\n";
		current = current->next;
	}
	return 1;
}