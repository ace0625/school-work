//CS202
//Assignment#2
//Hyunchan Kim
//sclass.cpp

#include <iostream>
#include <cstring>
#include "sclass.h"
using namespace std;

//constructor
sclass::sclass()
{}

//student class copy constructor
sclass::sclass(sclass* a_sclass):course_code(a_sclass->course_code), course_term(a_sclass->course_term)
{
	if(a_sclass->course_type) {
		course_type = new char[strlen(a_sclass->course_type)+1];
		strcpy(course_type, a_sclass->course_type);
	}
	if(a_sclass->course_grade) {
		course_grade = new char[strlen(a_sclass->course_grade)+1];
		strcpy(course_grade, a_sclass->course_grade);
	}
}

//student class copy constructor
sclass::sclass(char* a_course_type, int a_course_code, int a_course_term, char* a_course_grade): course_code(a_course_code), course_term(a_course_term)
{
	if(a_course_type) {
		course_type = new char[strlen(a_course_type)+1];
		strcpy(course_type, a_course_type);
	}
	if(a_course_grade) {
		course_grade = new char[strlen(a_course_grade)+1];
		strcpy(course_grade, a_course_grade);
	}
}

//get class type, return course type
char* sclass::get_course_type()
{
	return course_type;
}

//get class code, return course code
int sclass::get_course_code()
{
	return course_code;
}

//get grade, return course grade
char* sclass::get_course_grade()
{
	return course_grade;
}


void sclass::display_sclass()
{
	cout << "<<<<<<<<<<You have taken this class >>>>>>>>>>>>" << endl;
	cout << "= Class name  :" << course_type   << course_code << " " << endl;
	cout << "= Term :" << course_term   << endl;
	cout << "= Grade:" << course_grade << endl;
	cout << "<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl << endl << endl;
}
