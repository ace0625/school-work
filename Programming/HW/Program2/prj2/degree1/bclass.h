//CS202
//Assignment#2
//Hyunchan Kim

//=======================================================================
//This program is about Computer science major curriculum that shows you
//what classes you have to take before getting into CS program and your
//status with your grade and GPA by the classes you have taken so far.
//First, this program reads in the CS curriculum data from a text file
//and analyzes with your classes taken. 
//=======================================================================

//bclass.h

//This class is base class header 

#ifndef _BCLASS_H_
#define _BCLASS_H_

//BST class
class bclass
{
	public:
		bclass(); //default constructor
		bclass(bclass* a_bclass); //copy constructor
		bclass(char* a_course_type, int a_course_code, char* a_course_name, int a_course_credit, int a_course_effect); //copy constructor
		void set_grade_data(char* grade); //setting grade information
		char* get_grade(); //get grade information
		int get_course_credit(); //get credits
		void display_bclass(); //display all information
		
	protected:
		char* course_type;	// course type(COMM, CS, ECE)
		int course_code;	// course code(202, 300)
		char* course_name;	// course name(programming systems)
		int course_credit;	// course credit(4, 3)
		char* grade;		// course grade(A, A-, B+, B)
		float gpa;		// GPA
		int course_effect;	// course effect that distinguishes if core, non-cs, not-required 
};

//Base class for gpa calculation
class base_class
{
	public:
		base_class(); //  constructor
		void calculate(int a_credit, float a_qpoint); // calculate all classes
		void calc_gpa(); //calculate gpa
		virtual void display_gpa(); //display gpa

	protected:
		int total_credit; //total credit
		float total_qpoint; //total points
		float course_gpa; //total gpa
};

//required class derived from base class
class req_class: public base_class
{
	public:
		req_class(); // constructor
		void display_gpa(); //display GPA
	protected:
};

//core class derived from required class
class core_class: public req_class
{
	public:
		core_class(); //  constructor
		void display_gpa(); //display core class GPA
	protected:
};

//not cs class derived from required class
class ncs_class: public req_class
{
	public:
		ncs_class(); // constructor
		void display_gpa();//display non cs but required class
	protected:
};

//not required class derived from base class
class nreq_class: public base_class
{
	public:
		nreq_class(); // constructor
		void display_gpa(); //display not required class
	protected:
};

#endif