//CS202
//Assignment#2
//Hyunchan Kim

//degree.cpp
//=======================================================================
//This program is about Computer science major curriculum that shows you
//what classes you have to take before getting into CS program and your
//status with your grade and GPA by the classes you have taken so far.
//First, this program reads in the CS curriculum data from a text file
//and analyzes with your classes taken. 
//=======================================================================

//this is the degree.cpp that has main that starts this program reading a file
//and calculate GPA to show the result

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "course_lll.h"
#include "degree.h"
#include "bst.h"
using namespace std;

//degree constructor
degree::degree()
{}

//first find the class from the data file if adding or not
void degree::add_sdata(int a_course_term, sclass* a_sclass)
{
	bst bbb;
	if(find_course(a_sclass->get_course_type(), a_sclass->get_course_code())) 
	{
		bbb.add(a_course_term, a_sclass);
	}
	else 
	{
		//cout << "There is no class data matching" << endl;
	}
}

void degree::degree_handler()
{
	course_lll ccc; //read the course program file (program_data.txt)
	ccc.display_all(); //display all data from the file
	
	bst bbb; // add student's data in the binary search tree
	
	//===========================================================
	//below, adding classes I have taken so far

	char a_course_type [] = "CS";
	char a_course_type2 [] = "COMM";
	char a_course_type3 [] = "PH";
	char a_course_type4 [] = "MTH";
	int a_course_code = 163;
	int a_course_term = 20142;
	char a_course_grade1 [] = "B+";
	char a_course_grade2 [] = "B";
	char a_course_grade3 [] = "A";
	char a_course_grade4 [] = "C";
	
	//class 1
	sclass* s1 = new sclass(a_course_type, a_course_code, a_course_term, a_course_grade1);
	if(find_course(s1->get_course_type(), s1->get_course_code())) 
	{
		bbb.add(a_course_term, s1);
		ccc.set_grade(s1);
	}
	//class 2
	a_course_term = 20152;
	sclass* s2 = new sclass(a_course_type, 162, a_course_term, a_course_grade2);
	if(find_course(s2->get_course_type(), s2->get_course_code())) 
	{
		bbb.add(a_course_term, s2);
		ccc.set_grade(s2);
	}
	else 
	{
		//cout << "There is no matching class" << endl;
	}
	//class 3
	sclass* s3 = new sclass(a_course_type, 202, a_course_term, a_course_grade3);
	if(find_course(s3->get_course_type(), s3->get_course_code())) 
	{
		bbb.add(a_course_term, s3);
		ccc.set_grade(s3);
	}
	else 
	{
	//	cout << "There is no matching class" << endl;
	}
	//class 4
	sclass* s4 = new sclass(a_course_type, 121, a_course_term, a_course_grade4);
	if(find_course(s4->get_course_type(), s4->get_course_code())) 
	{
		bbb.add(a_course_term, s4);
		ccc.set_grade(s4);
	}
	else 
	{
		//cout << "There is no matching class" << endl;
	}
	//class 5
	sclass* s5 = new sclass(a_course_type2, 220, a_course_term, a_course_grade4);
	if(find_course(s5->get_course_type(), s5->get_course_code())) 
	{
		bbb.add(a_course_term, s5);
		ccc.set_grade(s5);
	}
	else 
	{
	//	cout << "There is no matching class" << endl;
	}
	//class 6
	sclass* s6 = new sclass(a_course_type3, 251, a_course_term, a_course_grade3);
	if(find_course(s6->get_course_type(), s6->get_course_code())) 
	{
		bbb.add(a_course_term, s6);
		ccc.set_grade(s6);
	}
	else 
	{
		//cout << "There is no matching class" << endl;
	}
	cout << endl;
    bbb.display_all();
	ccc.calculate_gpa();
	cout << endl;
}

//main class 
int main()
{
	degree deg;
	deg.degree_handler();
	return 0;
}
