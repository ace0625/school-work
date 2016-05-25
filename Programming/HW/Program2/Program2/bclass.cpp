//CS202
//Assignment#2
//Hyunchan Kim

//bclass.cpp
//This is the base class that manages class type, class, name, gpa, credit
// and displays information and gpa


#include <iostream>
#include <cstring>
#include "bclass.h"
using namespace std;


// default constructor
bclass::bclass()
{
	course_type = NULL;
	course_code = 0;
	course_name = NULL;
	course_credit = 0;
	grade = NULL;
	gpa = 0.0;
	course_effect = 0;	
}

// copy constructor 
bclass::bclass(bclass* a_bclass):course_code(a_bclass->course_code), course_credit(a_bclass->course_credit), course_effect(a_bclass->course_effect)
{
	if(a_bclass->course_type) {
		course_type = new char[strlen(a_bclass->course_type)+1];
		strcpy(course_type, a_bclass->course_type);
	}
	if(a_bclass->course_name) {
		course_name = new char[strlen(a_bclass->course_name)+1];
		strcpy(course_name, a_bclass->course_name);
	}
}

//copy constructor 
bclass::bclass(char* a_course_type, int a_course_code, char* a_course_name, int a_course_credit, int a_course_effect): course_code(a_course_code), course_credit(a_course_credit), course_effect(a_course_effect)
{
	if(a_course_type) {
		course_type = new char[strlen(a_course_type)+1];
		strcpy(course_type, a_course_type);
	}
	if(a_course_name) {
		course_name = new char[strlen(a_course_name)+1];
		strcpy(course_name, a_course_name);
	}
}

//set the grade
void bclass::set_grade_data(char* a_grade)
{
	if(a_grade) {
		if(grade) delete [] grade;
		grade = new char[strlen(a_grade)+1];
		strcpy(grade, a_grade);
	}
	
}
//get grade data that returns grade
char* bclass::get_grade()
{
	return grade;
}
//get credit that returns credit
int bclass::get_course_credit()
{
	return course_credit;
}
//display class information
void bclass::display_bclass()
{
	cout << "===========CLASS INFORMATION===============" << endl;
	cout << "-> Type of class: " << course_type   << endl;
	cout << "-> Class code: " << course_code   << endl;
	cout << "-> Class name: " << course_name   << endl;
	cout << "-> Credit: " << course_credit << endl;	

	if(course_effect == 1)
		cout << "-->> CORE " << endl << endl;
	else if(course_effect == 2)
		cout <<" -->> Required - NON_CS" << endl << endl;
	else if(course_effect == 3)
		cout <<" -->> NOT REQUIRED CLASS" << endl << endl;
	

}

// all
base_class::base_class()
{
	total_credit = 0;
	total_qpoint = 0.0;
	course_gpa = 0.0;
}

// GPA ==> Quality Points / Total credit
void base_class::calculate(int a_credit, float a_qpoint)
{
	total_credit += a_credit;
	total_qpoint += (a_qpoint * a_credit);
}

void base_class::calc_gpa()
{
	course_gpa = total_qpoint / total_credit;
}

void base_class::display_gpa()
{
	cout << "-> Total_credit: " << total_credit << endl;
	cout << "-> Total GPA: " << course_gpa << endl;
	cout << "==========================================\n\n";
}

// class req_class
req_class::req_class()
{
}

void req_class::display_gpa()
{
	cout << "\n\n==========YOUR GPA ==========================" << endl;
	cout << "-> Required class total_credit: " << total_credit << endl;
	cout << "-> Required class GPA: " << course_gpa << endl << endl;
}

// class core_class
core_class::core_class()
{
}

void core_class::display_gpa()
{
	cout << "-> CORE class total_credit: " << total_credit << endl;;
	cout << "-> CORE class GPA: " << course_gpa << endl << endl;
}

// class ncs_class
ncs_class::ncs_class()
{
}

void ncs_class::display_gpa()
{
	cout << "-> NON-CS(Required) class total_credit: " << total_credit << endl;
	cout << "-> NON-CS(Required) GPA: " << course_gpa << endl << endl;
}

// class req_class
nreq_class::nreq_class()
{
}

void nreq_class::display_gpa()
{
	cout << "-> NOT required class total_credit: " << total_credit << endl;
	cout << "-> NOT required class GPA: " << course_gpa << endl << endl;
}
