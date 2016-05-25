#include <iostream>
#include "sclass.h"
using namespace std;

// class - base class ****************************
// constructor - sclass for classes' basic data
sclass::sclass()
{}

sclass::sclass(sclass* a_sclass):course_type(a_sclass->course_type), course_code(a_sclass->course_code), course_term(a_sclass->course_term), course_grade(a_sclass->course_grade)
{}

sclass::sclass(char* a_course_type, int a_course_code, int a_course_term, char a_course_grade): course_type(a_course_type), course_code(a_course_code), course_term(a_course_term), course_grade(a_course_grade)
{}

void sclass::display_sclass()
{
	cout << "course data *********" << endl;
	cout << "course_type  :" << course_type   << endl;
	cout << "course_code  :" << course_code   << endl;
	cout << "course_term  :" << course_term   << endl;
	cout << "course_grade:" << course_grade << endl << endl;	
}
