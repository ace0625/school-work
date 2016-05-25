#ifndef _SCLASS_H_
#define _SCLASS_H_

class sclass
{
	public:
		sclass();
		sclass(sclass* a_sclass);
		sclass(char* a_course_type, int a_course_code, int a_course_term, char* a_course_grade);
		char* get_course_type();
		int get_course_code();
		char* get_course_grade();
		void display_sclass();
	protected:
		char* course_type;	// CS, WR
		int course_code;	// 163
		int course_term;	// 20151 (1-Fall, 2-Winter, 3-Spring, 4-Summer, )
		char* course_grade;	// A, B, C, D, F
};

#endif