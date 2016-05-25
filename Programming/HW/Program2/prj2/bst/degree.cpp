#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "degree.h"
using namespace std;

// class - snode ****************************
// constructor - snode for a linear linked list
snode::snode()
{
	next = NULL;
}


snode::~snode()
{
	cout << "snode::~snode()" << endl;
}

snode::snode(bclass* a_bclass): bclass(a_bclass)
{}

snode::snode(char* a_course_type, int a_course_code, int a_course_term, char a_course_grade): bclass(a_course_type, a_course_code, a_course_term, a_course_grade)
{}

// snode move to next
snode *& snode::go_next()
{
	return next;
}

bool snode::if_next()
{
	if(next) return true;
	else return false;
}

void snode::display()
{
	display_bclass();
}

int snode::retrieve(const char* a_course_type, int a_course_code)
{
	if(course_type == a_course_type && course_code == a_course_code)
		return 1;
	else
		return 1;
}

// class - degree ****************************
// constructor for degree class
degree::degree()
{
	head = NULL;
}

// destructor for degree class
degree::~degree()
{
	remove_all();
	delete head;
}

void degree::add_course(char* a_course_type, int a_course_code, int a_course_term, char a_course_grade)
{
	bclass* p_bclass = new bclass(a_course_type, a_course_code, a_course_term, a_course_grade);
	add(p_bclass);
}

void degree::add(bclass* a_bclass)
{
	if(!head) {
		head = new snode(a_bclass);
		head->go_next() = NULL;
		return;
	}
	
	snode* temp = new snode(a_bclass);
	temp->go_next() = head;
	head = temp;
}

void degree::remove(const char* course_type, const int course_code)
{
	if(!head) return;
	snode* temp = head;
	while(!head->retrieve(course_type, course_code)) {
		temp = head;
		head = head->go_next();
	}
	temp->go_next() = head->go_next();
	delete head;
	head = NULL;	
}

bool degree::find(const char* a_course_type, const int a_course_code)
{
	if(retrieve(a_course_type, a_course_code)) return true;
	else return false;
}

void degree::display_all()
{
	display_all(head);
}

void degree::display_all(snode* head)
{
	if(!head) return;
	
	head->display();
	display_all(head->go_next());
}

int degree::remove_all()
{
	int result = remove_all(head);
	cout << "remove_all: " << result << endl;
	return 1;
}

int degree::remove_all(snode * & head)
{
	if(!head) return 0;
	int val = remove_all(head->go_next()) + 1;
	delete head;
	head = NULL;
	return val;	
}


int main()
{
	degree b;

	return 0;
}
