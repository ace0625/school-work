#ifndef _BCLASS_H_
#define _BCLASS_H_

class bclass
{
	public:
		bclass();
		bclass(bclass* a_bclass);
		bclass(char* a_course_type, int a_course_code, char* a_course_name, int a_course_credit, int a_course_effect);
		void set_grade_data(char* grade);
		char* get_grade();
		int get_course_credit();
		void display_bclass();
		//virtual void calculate();
	protected:
		char* course_type;	// CS, COMM
		int course_code;	// 163, 202
		char* course_name;	// Data Structure
		int course_credit;	// 4
		char* grade;		// A, A-, B+, B, B-, C+, C, C-, D+, D, D-, F
		float gpa;		// 3.0
		int course_effect;	// 1 - CS, 0 - NON CS
};

class base_class
{
	public:
		base_class(); // req_class constructor
		virtual void calculate(int a_credit, float a_qpoint); // for all classes
		virtual void display_gpa();
	
	protected:
		int total_credit;
		float total_qpoint;
		float avg_gpa;
};

class req_class: public base_class
{
	public:
		req_class(); // req_class constructor
		void calculate(int a_credit, float a_qpoint);
		void display_gpa();
	
	protected:
};

class core_class: public req_class
{
	public:
		core_class(); // core_class constructor
		void calculate(int a_credit, float a_qpoint);
		void display_gpa();
	
	protected:
};

class ncs_class: public req_class
{
	public:
		ncs_class(); // ncs_class constructor
		void calculate(int a_credit, float a_qpoint);
		void display_gpa();
	
	protected:
};

class nreq_class: public base_class
{
	public:
		nreq_class(); // nreq_class constructor
		void calculate(int a_credit, float a_qpoint);
		void display_gpa();
	
	protected:
};

#endif