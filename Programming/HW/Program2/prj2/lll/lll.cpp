#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "lll.h"
using namespace std;

// class - node ****************************
// constructor - node for a linear linked list
node::node()
{
	next = NULL;
}


node::~node()
{
	cout << "node::~node()" << endl;
}

node::node(bclass* a_bclass): bclass(a_bclass)
{}

node::node(char* a_course_type, int a_course_code, char* a_course_name, int a_course_credit): bclass(a_course_type, a_course_code, a_course_name, a_course_credit)
{}

// node move to next
node *& node::go_next()
{
	return next;
}

bool node::if_next()
{
	if(next) return true;
	else return false;
}

void node::display()
{
	display_bclass();
}

int node::retrieve(const char* a_course_type, int a_course_code)
{
	if(course_type == a_course_type && course_code == a_course_code)
		return 1;
	else
		return 1;
}

// class - lll ****************************
// constructor for lll class
lll::lll()
{
	head = NULL;

	char course_file_name [] = "course.txt";
	load_courses(course_file_name);
	
}

int lll::load_courses(char course_file_name[])
{
	const int MAX_LINE_LEN = 500;
	const int MAX_TOKEN = 6;
	const char* const DELIM = ";";

	// File I/O
	ifstream fin;
	ofstream fout;
	
	// read course Information File
	fin.open(course_file_name); 
	if(fin.fail()) {
		return 0;
	}

	char* course_type = NULL; // Employer's Name
	char* course_code  = NULL; // course_code (city, state)
	char* course_name = NULL; // course Title
	char* course_credit  = NULL; // course Description

	// get course information
	while(!fin.eof()) {
		char buff[MAX_LINE_LEN];
		fin.getline(buff, MAX_LINE_LEN);

		const char* token[MAX_TOKEN] = {};

		token[0] = strtok(buff, DELIM);
		if(!token[0]) break;
		
		for(int i = 1; i < MAX_TOKEN; i++) {
			token[i] = strtok(0, DELIM);
		}

		// copy information to LLL
		if(course_type) delete [] course_type;
		if(course_code)  delete [] course_code;
		if(course_name) delete [] course_name;
		if(course_credit)  delete [] course_credit;
		
		course_type = new char[strlen(token[0]) + 1];
		strcpy(course_type, token[0]);

		course_code  = new char[strlen(token[1]) + 1];
		strcpy(course_code , token[1]);

		course_name = new char[strlen(token[2]) + 1];
		strcpy(course_name, token[2]);

		course_credit  = new char[strlen(token[3]) + 1];
		strcpy(course_credit , token[3]);

cout << "course_type:" << course_type << endl;
cout << "course_code :" << course_code  << endl;
cout << "course_name:" << course_name << endl;
cout << "course_credit :" << course_credit  << endl;

		add_course(course_type, atoi(course_code), course_name, atoi(course_credit));
	}
	fin.close();

	// delete
	if(course_type) delete [] course_type;
	if(course_code)  delete [] course_code;
	if(course_name) delete [] course_name;
	if(course_credit)  delete [] course_credit;

	return 1;
}

// destructor for lll class
lll::~lll()
{
	remove_all();
	delete head;
}

void lll::add_course(char* a_course_type, int a_course_code, char* a_course_name, int a_course_credit)
{
	bclass* p_bclass = new bclass(a_course_type, a_course_code, a_course_name, a_course_credit);
	add(p_bclass);
}

void lll::add(bclass* a_bclass)
{
	if(!head) {
		head = new node(a_bclass);
		head->go_next() = NULL;
		return;
	}
	
	node* temp = new node(a_bclass);
	temp->go_next() = head;
	head = temp;
}

void lll::remove(const char* course_type, const int course_code)
{
	if(!head) return;
	node* temp = head;
	while(!head->retrieve(course_type, course_code)) {
		temp = head;
		head = head->go_next();
	}
	temp->go_next() = head->go_next();
	delete head;
	head = NULL;	
}

bool lll::find(const char* a_course_type, const int a_course_code)
{
	if(retrieve(a_course_type, a_course_code)) return true;
	else return false;
}

void lll::display_all()
{
	display_all(head);
}

void lll::display_all(node* head)
{
	if(!head) return;
	
	head->display();
	display_all(head->go_next());
}

int lll::remove_all()
{
	int result = remove_all(head);
	cout << "remove_all: " << result << endl;
	return 1;
}

int lll::remove_all(node * & head)
{
	if(!head) return 0;
	int val = remove_all(head->go_next()) + 1;
	delete head;
	head = NULL;
	return val;	
}


int main()
{
	lll b;

	return 0;
}
