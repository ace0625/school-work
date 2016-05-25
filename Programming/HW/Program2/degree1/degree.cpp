#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "course_lll.h"
#include "degree.h"
#include "bst.h"
using namespace std;

degree::degree()
{}

void degree::add_sdata(int a_course_term, sclass* a_sclass)
{
	bst bbb;

	if(find_course(a_sclass->get_course_type(), a_sclass->get_course_code()) {
		bbb.add(a_course_term, a_sclass);
	}
	else {
		cout << "NO class found~!!!!!!!!!" << endl;
	}
}

void degree::degree_handler()
{
	// add basic data from file to LLL
	course_lll ccc;
	//ccc.display_all();
	
	// add student's data to BST->LLL
	bst bbb;
	//degree_handler ddd;

	char a_course_type [] = "CS";
	int a_course_code = 163;
	int a_course_term = 20151;
	char a_course_grade1 [] = "B+";
	char a_course_grade2 [] = "B";
	char a_course_grade3 [] = "A";
	char a_course_grade4 [] = "C";
	
	sclass* s1 = new sclass(a_course_type, a_course_code, a_course_term, a_course_grade1);
	//bbb.add(a_course_term, s1);
	add_sdata(a_course_term, s1);
	ccc.set_grade(s1);
	

	a_course_term = 20152;
	sclass* s2 = new sclass(a_course_type, 162, a_course_term, a_course_grade2);
	//bbb.add(a_course_term, s2);
	add_sdata(a_course_term, s1);
	ccc.set_grade(s2);
//	ccc.display_all();

	sclass* s3 = new sclass(a_course_type, 202, a_course_term, a_course_grade3);
	//bbb.add(a_course_term, s3);
	add_sdata(a_course_term, s3);

	ccc.set_grade(s3);

	sclass* s4 = new sclass(a_course_type, 121, a_course_term, a_course_grade4);
	//bbb.add(a_course_term, s4);
	add_sdata(a_course_term, s4);
	ccc.set_grade(s4);

//    bbb.display_all();
	ccc.calculate_gpa();
	cout << endl;
	
	
	//show_result();
	

//	cout << "** remove "<< rem << " **************************" << endl;
//	bbb.remove(rem); 
//	bbb.display_all();
//	cout << endl;


}

int main()
{
	degree deg;
	deg.degree_handler();
	return 0;
}
