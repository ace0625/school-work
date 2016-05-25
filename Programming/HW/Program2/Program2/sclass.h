//CS202
//Assignment#2
//Hyunchan Kim
//sclass.h

//=======================================================================
//This program is about Computer science major curriculum that shows you
//what classes you have to take before getting into CS program and your
//status with your grade and GPA by the classes you have taken so far.
//First, this program reads in the CS curriculum data from a text file
//and analyzes with your classes taken. 
//=======================================================================

//this is the header file that manages student's classes that have been taken
#ifndef _SCLASS_H_
#define _SCLASS_H_

class sclass
{
	public:
		sclass(); //constructor
		sclass(sclass* a_sclass); //copy constructor
		sclass(char* a_course_type, int a_course_code, int a_course_term, char* a_course_grade); //copy constructor
		char* get_course_type(); //get type of class
		int get_course_code(); //get class code number
		char* get_course_grade(); //get class grade
		void display_sclass(); //display the class information
	protected:
		char* course_type;	// type of class such as CS, MTH
		int course_code;	// class code number such as 251, 250
		int course_term;	// term when the class taken 20151 (1-Fall, 2-Winter, 3-Spring, 4-Summer, )
		char* course_grade;	// class grade such as A, A+, B
};

#endif