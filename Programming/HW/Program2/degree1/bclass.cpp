#include <iostream>
#include <cstring>
#include "bclass.h"
using namespace std;

// class - base class ****************************
// constructor - bclass for basic data of classes
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

bclass::bclass(bclass* a_bclass):course_code(a_bclass->course_code), course_credit(a_bclass->course_credit), course_effect(a_bclass->course_effect)
{
	if(a_bclass->course_type) {
		course_type = new char[sizeof(a_bclass->course_type)+1];
		strcpy(course_type, a_bclass->course_type);
	}
	if(a_bclass->course_name) {
		course_name = new char[sizeof(a_bclass->course_name)+1];
		strcpy(course_name, a_bclass->course_name);
	}
}

bclass::bclass(char* a_course_type, int a_course_code, char* a_course_name, int a_course_credit, int a_course_effect): course_code(a_course_code), course_credit(a_course_credit), course_effect(a_course_effect)
{
	if(a_course_type) {
		course_type = new char[sizeof(a_course_type)+1];
		strcpy(course_type, a_course_type);
	}
	if(a_course_name) {
		course_name = new char[sizeof(a_course_name)+1];
		strcpy(course_name, a_course_name);
	}
}

void bclass::set_grade_data(char* a_grade)
{
	if(a_grade) {
		if(grade) delete [] grade;
		grade = new char[sizeof(a_grade)+1];
		strcpy(grade, a_grade);
	}
	
}

char* bclass::get_grade()
{
	return grade;
}

int bclass::get_course_credit()
{
	return course_credit;
}

void bclass::display_bclass()
{
	cout << "bclass::course data #######" << endl;
	cout << "bclass::course_type  :" << course_type   << endl;
	cout << "bclass::course_code  :" << course_code   << endl;
	cout << "bclass::course_name  :" << course_name   << endl;
	cout << "bclass::course_credit:" << course_credit << endl;	
	if(grade)
		cout << "bclass::grade:" << grade << endl;
	else
		cout << "bclass::grade: -" << endl;

	cout << "bclass::gpa:" << gpa << endl;	
	cout << "bclass::course_effect:" << course_effect << endl << endl;	
}

// all
base_class::base_class()
{
	total_credit = 0;
	total_qpoint = 0.0;
	avg_gpa = 0.0;
}

// GPA ==> Quality Points / Total credit
void base_class::calculate(int a_credit, float a_qpoint)
{
	cout << "**base_class::calculate" << endl;
	total_credit += a_credit;
	total_qpoint += a_qpoint;
}

void base_class::display_gpa()
{
	cout << "base total_credit:" << total_credit;
	cout << "base total_qpoint:" << total_qpoint;
	cout << "base avg_gpa:" << avg_gpa << endl;
}

// class req_class
req_class::req_class()
{
}

void req_class::calculate(int a_credit, float a_qpoint)
{
	cout << "**req_class::calculate" << endl;
	total_credit += a_credit;
	total_qpoint += a_qpoint;
}

void req_class::display_gpa()
{
	cout << "req total_credit:" << total_credit;
	cout << "req total_qpoint:" << total_qpoint;
	cout << "req avg_gpa:" << avg_gpa << endl;
}

// class core_class
core_class::core_class()
{
}

void core_class::calculate(int a_credit, float a_qpoint)
{
	cout << "**core_class::calculate" << endl;
	total_credit += a_credit;
	total_qpoint += a_qpoint;
}

void core_class::display_gpa()
{
	cout << "core total_credit:" << total_credit;
	cout << "core total_qpoint:" << total_qpoint;
	cout << "core avg_gpa:" << avg_gpa << endl;
}

// class ncs_class
ncs_class::ncs_class()
{
}

void ncs_class::calculate(int a_credit, float a_qpoint)
{
	cout << "**ncs_class::calculate" << endl;
	total_credit += a_credit;
	total_qpoint += a_qpoint;
}

void ncs_class::display_gpa()
{
	cout << "ncs total_credit:" << total_credit;
	cout << "ncs total_qpoint:" << total_qpoint;
	cout << "ncs avg_gpa:" << avg_gpa << endl;
}

// class req_class
nreq_class::nreq_class()
{
}

void nreq_class::calculate(int a_credit, float a_qpoint)
{
	cout << "**nreq_class::calculate" << endl;
	total_credit += a_credit;
	total_qpoint += a_qpoint;
}

void nreq_class::display_gpa()
{
	cout << "nreq total_credit:" << total_credit;
	cout << "nreq total_qpoint:" << total_qpoint;
	cout << "nreq avg_gpa:" << avg_gpa << endl;
}
