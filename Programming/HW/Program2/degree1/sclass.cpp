#include <iostream>
#include <cstring>
#include "sclass.h"
using namespace std;

// class - base class ****************************
// constructor - sclass for student data of classes
sclass::sclass()
{}

sclass::sclass(sclass* a_sclass):course_code(a_sclass->course_code), course_term(a_sclass->course_term)
{
	if(a_sclass->course_type) {
		course_type = new char[sizeof(a_sclass->course_type)+1];
		strcpy(course_type, a_sclass->course_type);
	}
	if(a_sclass->course_grade) {
		course_grade = new char[sizeof(a_sclass->course_grade)+1];
		strcpy(course_grade, a_sclass->course_grade);
	}
}

sclass::sclass(char* a_course_type, int a_course_code, int a_course_term, char* a_course_grade): course_code(a_course_code), course_term(a_course_term)
{
	if(a_course_type) {
		course_type = new char[sizeof(a_course_type)+1];
		strcpy(course_type, a_course_type);
	}
	if(a_course_grade) {
		course_grade = new char[sizeof(a_course_grade)+1];
		strcpy(course_grade, a_course_grade);
	}
}

char* sclass::get_course_type()
{
	return course_type;
}

int sclass::get_course_code()
{
	return course_code;
}

char* sclass::get_course_grade()
{
	return course_grade;
}


void sclass::display_sclass()
{
	cout << "sclass::course data ********" << endl;
	cout << "sclass::course_type  :" << course_type   << endl;
	cout << "sclass::course_code  :" << course_code   << endl;
	cout << "sclass::course_term  :" << course_term   << endl;
	cout << "sclass::course_grade:" << course_grade << endl << endl;	
}
