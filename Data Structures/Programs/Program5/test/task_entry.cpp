//CS163
//Assignment#5
//Hyunchan Kim

#include <iostream>
#include <cstring>
#include "task_entry.h"
using namespace std;

// constructor - initialize data member to NULL
task_entry::task_entry(void)
{
	task_no = NULL;
	term = NULL;
	step = NULL;
	desc = NULL;
}

// destructor - deallocate memory
task_entry::~task_entry(void)
{
	delete [] task_no;
	delete [] term;
	delete [] step;
	delete [] desc;
}

// create entry information
int task_entry::create_entry(char* a_task_no, char* a_term, char* a_step, char* a_desc)
{
	if(!task_no || !term || !step || !desc)
		return 0;

	if(task_no) delete task_no;
	if(term) delete term;
	if(step) delete step;
	if(desc) delete desc;

	task_no = new char[strlen(a_task_no) + 1];
	term = new char[strlen(a_term) + 1];
	step = new char[strlen(a_step) + 1];
	desc = new char[strlen(a_desc) + 1];
	strcpy(task_no, a_task_no);
	strcpy(term, a_term);
	strcpy(step, a_step);
	strcpy(desc, a_desc);
	
	return 1;
}

// copy entry information
int task_entry::copy_entry(const task_entry & copy_from)
{
	if(copy_from.task_no) 
	{
		task_no = new char[strlen(copy_from.task_no) + 1];
		strcpy(task_no, copy_from.task_no);
	}

	if(copy_from.term) 
	{
		term = new char[strlen(copy_from.term) + 1];
		strcpy(term, copy_from.term);
	}

	if(copy_from.step) 
	{
		step = new char[strlen(copy_from.step) + 1];
		strcpy(step, copy_from.step);
	}

	if(copy_from.desc) 
	{
		desc = new char[strlen(copy_from.desc) + 1];
		strcpy(desc, copy_from.desc);
	}

	if(!task_no || !term || !step || !desc) 
		return 0;
	else 
		return 1;
}

// retrieve entry information
int task_entry::retrieve(task_entry & found) const
{
	if(!strcmp(term, found.term)) 
		return 0;
	
	// if(found.p_area) delete [] found.p_area;
	// if(found.p_code) delete [] found.p_code;
	// if(found.p_name) delete [] found.p_name;
	// if(found.p_desc) delete [] found.p_desc;
	// found.p_code = found.p_name = found.p_desc = NULL;
	
	if(task_no) 
	{
		found.task_no = new char[strlen(task_no) + 1];
		strcpy(found.task_no, task_no);
	}

	if(term) 
	{
		found.term = new char[strlen(term) + 1];
		strcpy(found.term, term);
	}

	if(step) 
	{
		found.step = new char[strlen(step) + 1];
		strcpy(found.step, step);
	}

	if(desc) {
		found.desc = new char[strlen(desc) + 1];
		strcpy(found.desc, desc);
	}

	return 1;
}

// compare
bool task_entry::compare (char* match)
{
	if(!match)
		return false;
	if(strcmp(term, match)==0)
		return true;
	else
		return false;
}

// display entry information
int task_entry::display() const
{
	char type = term[2];
	char importance[10];
	
	if(type == 'R') strcpy(importance, "*****");
	else if(type == 'S') strcpy(importance, "***");
	else strcpy(importance, "****");

	cout << "Importance: " << importance << endl;
	cout << "STEP>>  " << step << endl;
	cout << "Description:" << desc << endl << endl;
	return 1;
}

// display entry information
int task_entry::display_step() 
{
	cout << "step: " << step << endl;
	return 1;
}

// display entry information
char* task_entry::get_term() const
{
	if(!term) 
		return NULL;
	return term;
}

// display entry information
char* task_entry::get_task_no() const
{
	if(!task_no) 
		return NULL;
	return task_no;
}
