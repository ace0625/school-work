#include <iostream>
#include "bclass.h"
using namespace std;

// class - base class ****************************
// constructor - bclass for classes' basic data
bclass::bclass()
{}

bclass::bclass(bclass* a_bclass):course_type(a_bclass->course_type), course_code(a_bclass->course_code), course_name(a_bclass->course_name), course_credit(a_bclass->course_credit)
{}

bclass::bclass(char* a_course_type, int a_course_code, char* a_course_name, int a_course_credit): course_type(a_course_type), course_code(a_course_code), course_name(a_course_name), course_credit(a_course_credit)
{}

void bclass::display_bclass()
{
	cout << "course data *********" << endl;
	cout << "course_type  :" << course_type   << endl;
	cout << "course_code  :" << course_code   << endl;
	cout << "course_name  :" << course_name   << endl;
	cout << "course_credit:" << course_credit << endl << endl;	
}
