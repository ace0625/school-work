#include "bclass.h"
#include "sclass.h"

#ifndef _COURSE_LLL_H_
#define _COURSE_LLL_H_

class node: public bclass
{
	public:
		node(); // node constructor
		node(bclass* a_bclass);
		node(char* a_course_type, int a_course_code, char* a_course_name, int a_course_credit);
		~node(); // node destructor
		node *& go_next(); // LLL node move to left
		bool if_next();
		void display_lnode();
		int compare_node(const node* a_node);
		//int retrieve_bclass(const char* course_type, int course_code, node& a_node);
		int retrieve_bclass(const char* course_type, int course_code);
		//int retrieve(const sclass a_sclass, node& a_node);
		int find(const char* a_course_type, int a_course_code);
		//void set_gpa_data(char* grade, float gpa);
		int get_course_effect();
	
	protected:
		node* next;
};

// LLL objects
class course_lll: public node
{
	public:
		course_lll(); // LLL constructor
		~course_lll(); // LLL destructor
		int load_courses(char course_file_name[]);
		void add(bclass* a_bclass); // add data at front of LLL
		void add_course(char* a_course_type, int a_course_code, char* a_course_name, int a_course_credit, int a_course_effect);
		void remove(const char* course_type, const int course_code); // remove index of data ( in deal datas)
		void display_all(); // display data of LLL
		void display_all(node* head); // display data of LLL
		int find_course(const char* a_course_type, int a_course_code);
		int remove_all();
		int remove_all(node * & head);
		void set_grade(sclass* s1);
		void calculate_gpa();

	protected:
		node* head;
};

#endif