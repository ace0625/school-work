#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "course_lll.h"
using namespace std;

// class - node ****************************
// constructor - node for a linear linked list
node::node()
{
	next = NULL;
}

node::~node()
{
	cout << "node::~node()" << endl;
}

node::node(bclass* a_bclass): bclass(a_bclass)
{}

node::node(char* a_course_type, int a_course_code, char* a_course_name, int a_course_credit):
	bclass(a_course_type, a_course_code, a_course_name, a_course_credit, course_effect)
{}

// node move to next
node *& node::go_next()
{
	return next;
}

bool node::if_next()
{
	if(next) return true;
	else return false;
}

void node::display_lnode()
{
	display_bclass();
}

int node::find(const char* a_course_type, int a_course_code)
{
	if(course_type == a_course_type && course_code == a_course_code)
		return 1;
	else
		return 1;
}

int node::get_course_effect()
{
	return course_effect;
}

int node::compare_node(const node* a_node)
{
	if(strcmp(course_type, a_node->course_type) == 0 
		&& course_code == a_node->course_code) return 1;
	else return 0;
}

//int node::retrieve_bclass(const char* a_course_type, int a_course_code, node& a_node)
int node::retrieve_bclass(const char* a_course_type, int a_course_code)
//int node::retrieve(const sclass a_sclass, node& a_node)
{
	//if(compare_node(*node(a_sclass))) {
	//cout << "node::retrieve >>>>> course_type:" << course_type << " course_code:" << course_code << endl;
	if(strcmp(course_type, a_course_type) == 0 && course_code == a_course_code) {
	//cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
//		a_node.course_type = new char[strlen(course_type) + 1];
//		strcpy(a_node.course_type, course_type);
//		a_node.course_code = course_code;
//		a_node.course_name = new char[strlen(course_name) + 1];
//		strcpy(a_node.course_name, course_name);
//		a_node.course_credit = course_credit;
//		a_node.grade = grade;
//		a_node.course_effect = course_effect;
		return 1;
	}
	else
		return 0;
}

// class - course_lll ****************************
// constructor for course_lll class
course_lll::course_lll()
{
	head = NULL;

	char course_file_name [] = "course.txt";
	load_courses(course_file_name);
	
}

int course_lll::load_courses(char course_file_name[])
{
	const int MAX_LINE_LEN = 500;
	const int MAX_TOKEN = 6;
	const char* const DELIM = ";";

	// File I/O
	ifstream fin;
	ofstream fout;
	
	// read course Information File
	fin.open(course_file_name); 
	if(fin.fail()) {
		return 0;
	}

	char* course_type = NULL; // course type - CS
	char* course_code  = NULL; // course code - 163
	char* course_name = NULL; // course name
	char* course_credit  = NULL; // course credit
	char* course_effect  = NULL; // course effect	

	// get course information
	while(!fin.eof()) {
		char buff[MAX_LINE_LEN];
		fin.getline(buff, MAX_LINE_LEN);

		const char* token[MAX_TOKEN] = {};

		token[0] = strtok(buff, DELIM);
		if(!token[0]) break;
		
		for(int i = 1; i < MAX_TOKEN; i++) {
			token[i] = strtok(0, DELIM);
		}

		// copy information to LLL
		if(course_type) delete [] course_type;
		if(course_code)  delete [] course_code;
		if(course_name) delete [] course_name;
		if(course_credit)  delete [] course_credit;
		
		course_type = new char[strlen(token[0]) + 1];
		strcpy(course_type, token[0]);

		course_code  = new char[strlen(token[1]) + 1];
		strcpy(course_code , token[1]);

		course_name = new char[strlen(token[2]) + 1];
		strcpy(course_name, token[2]);

		course_credit  = new char[strlen(token[3]) + 1];
		strcpy(course_credit , token[3]);

		course_effect  = new char[strlen(token[4]) + 1];
		strcpy(course_effect , token[4]);

//cout << "load_courses> course_type:" << course_type << endl;
//cout << "load_courses> course_code :" << course_code  << endl;
//cout << "load_courses> course_name:" << course_name << endl;
//cout << "load_courses> course_credit :" << course_credit  << endl;

		add_course(course_type, atoi(course_code), course_name, atoi(course_credit), atoi(course_effect));
	}
	fin.close();

	// delete
	if(course_type) delete [] course_type;
	if(course_code)  delete [] course_code;
	if(course_name) delete [] course_name;
	if(course_credit)  delete [] course_credit;

	return 1;
}

// destructor for course_lll class
course_lll::~course_lll()
{
	remove_all();
	delete head;
}

void course_lll::add_course(char* a_course_type, int a_course_code, char* a_course_name, int a_course_credit, int a_course_effect)
{
	bclass* p_bclass = new bclass(a_course_type, a_course_code, a_course_name, a_course_credit, a_course_effect);
	add(p_bclass);
}

void course_lll::add(bclass* a_bclass)
{
	if(!head) {
		head = new node(a_bclass);
		head->go_next() = NULL;
		return;
	}
	
	node* temp = new node(a_bclass);
	temp->go_next() = head;
	head = temp;
}

void course_lll::remove(const char* course_type, int course_code)
{
	if(!head) return;
	node* temp = head;
	while(!head->find(course_type, course_code)) {
		temp = head;
		head = head->go_next();
	}
	temp->go_next() = head->go_next();
	delete head;
	head = NULL;	
}

void course_lll::display_all()
{
	display_all(head);
}

void course_lll::display_all(node* head)
{
	if(!head) return;
	
	head->display_lnode();
	display_all(head->go_next());
}

int course_lll::find_course(const char* a_course_type, int a_course_code)
{
	if(!head) return 0;
	node* temp = head;
	while(temp) {
		if(find(a_course_type, a_course_code)) {
			return 1;
		}
		temp = temp->go_next();
	}
	return 0;
}

int course_lll::remove_all()
{
	int result = remove_all(head);
	cout << "remove_all: " << result << endl;
	return 1;
}

int course_lll::remove_all(node * & head)
{
	if(!head) return 0;
	int val = remove_all(head->go_next()) + 1;
	delete head;
	head = NULL;
	return val;	
}

void course_lll::calculate_gpa() {
	//****************************
	// need to do for gpa calculate
	// gpa = a_gpa;

	// Quality Points
	// A,  A-,  B+ , B, B-  , C+  , C, C-  , D+  , D, D-  , F
	//{4, 3.67, 3.33, 3, 2.67, 2.33, 2, 1.67, 1.33, 1, 0.67, 0}
	// GPA ==> Quality Points / Total credit
	
	node* temp = head;
	float q_point = 0.0;
	float total_q_point = 0.0;
	int total_credit = 0;
	float gpa = 0.0;
	
	base_class* arr_bclass[5];
	arr_bclass[0] = new req_class;  // required - all
	arr_bclass[1] = new core_class; // required - core
	arr_bclass[2] = new ncs_class;  // required - non-cs
	arr_bclass[3] = new nreq_class; // non-required
	arr_bclass[4] = new base_class; // non-required

	while(temp) {
//		cout << "temp->course_type:" << temp->get_course_type();
//		cout << "temp->course_code:" << temp->get_course_code() << endl;
		
/*
		// CS only
		if(class_req == 1) {
			if(temp->get_course_effect() != 1) {
				temp = temp->go_next();
				continue;
			}
		}

*/
		// pass for not taking class
		if(!temp->get_grade()) {
			temp = temp->go_next();
			continue;
		}

		if(strcmp(temp->get_grade(), "A")==0)  q_point = 4;
		else if(strcmp(temp->get_grade(), "A-")==0) q_point = 3.67;
		else if(strcmp(temp->get_grade(), "B+")==0) q_point = 3.33;
		else if(strcmp(temp->get_grade(), "B")==0)  q_point = 3;
		else if(strcmp(temp->get_grade(), "B-")==0) q_point = 2.67;
		else if(strcmp(temp->get_grade(), "C+")==0) q_point = 2.33;
		else if(strcmp(temp->get_grade(), "C")==0)  q_point = 2;
		else if(strcmp(temp->get_grade(), "C-")==0) q_point = 1.67;
		else if(strcmp(temp->get_grade(), "D+")==0) q_point = 1.33;
		else if(strcmp(temp->get_grade(), "D")==0)  q_point = 1;
		else if(strcmp(temp->get_grade(), "D-")==0) q_point = 0.67;
		else if(strcmp(temp->get_grade(), "F")==0)  q_point = 0;

// GPA ==> Quality Points / Total credit
		//arr_bclass[0].calculate();
		arr_bclass[temp->get_course_effect()]->calculate(temp->get_course_credit(), q_point);
		if(temp->get_course_effect() == 1 || temp->get_course_effect() == 2) {
			arr_bclass[0]->calculate(temp->get_course_credit(), q_point);
		}
		arr_bclass[4]->calculate(temp->get_course_credit(), q_point);

		//total_credit += get_course_credit();
		//total_q_point += course_credit * q_point;

		temp = temp->go_next();
	}
	
	arr_bclass[0]->display_gpa();
	arr_bclass[1]->display_gpa();
	arr_bclass[2]->display_gpa();
	arr_bclass[3]->display_gpa();
	arr_bclass[4]->display_gpa();
	
	//gpa = total_q_point / total_credit;
	//cout << "&& GPA &&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
	//cout << " total_q_point:" << total_q_point;
	//cout << " total_credit:" << total_credit;
	//cout << " gpa:" << gpa << endl;
}

void course_lll::set_grade(sclass* s1)
{

// Quality Points
// A,  A-,  B+ , B, B-  , C+  , C, C-  , D+  , D, D-  , F
//{4, 3.67, 3.33, 3, 2.67, 2.33, 2, 1.67, 1.33, 1, 0.67, 0}
// GPA ==> Quality Points / Total credit

	// 1. course == required & core
	// 2. course == required & non-cs
	// 3. course == non-required

//	course_grade = s1.course_grade;


	node* temp = head;
	while(temp) {
		if(temp->retrieve_bclass(s1->get_course_type(), s1->get_course_code())) {
			temp->set_grade_data(s1->get_course_grade());
			break;
		}

		temp = temp->go_next();
	}
	cout << "course_lll::set_grade temp->get_grade():" << temp->get_grade();

}


/*
int main()
{
	course_lll b;

	return 0;
}
*/