#include "bclass.h"

class node: public bclass
{
	public:
		node(); // node constructor
		node(bclass* a_bclass);
		node(char* a_course_type, int a_course_code, char* a_course_name, int a_course_credit);
		~node(); // node destructor
		node *& go_next(); // LLL node move to left
		bool if_next();
		void display();
		int retrieve(const char* course_type, int course_code);
	
	protected:
		node* next;
};

// LLL objects
class lll: public node
{
	public:
		lll(); // LLL constructor
		~lll(); // LLL destructor
		int load_courses(char course_file_name[]);
		void add(bclass* a_bclass); // add data at front of LLL
		void add_course(char* a_course_type, int a_course_code, char* a_course_name, int a_course_credit);
		void remove(const char* course_type, const int course_code); // remove index of data ( in deal datas)
		void display_all(); // display data of LLL
		void display_all(node* head); // display data of LLL
		int remove_all();
		int remove_all(node * & head);
		bool find(const char* a_course_type, const int a_course_code);

	protected:
		node* head;
};


