//CS202
//Assignment#2
//Hyunchan Kim
//course_lll.cpp

//managing course data and build a linear linked list
//=======================================================================
//This program is about Computer science major curriculum that shows you
//what classes you have to take before getting into CS program and your
//status with your grade and GPA by the classes you have taken so far.
//First, this program reads in the CS curriculum data from a text file
//and analyzes with your classes taken. 
//=======================================================================
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "course_lll.h"
using namespace std;

//constructor
node::node()
{
	next = NULL;
}

//destructor
node::~node()
{}

//copy constructor
node::node(bclass* a_bclass): bclass(a_bclass)
{}

//copy constructor
node::node(char* a_course_type, int a_course_code, char* a_course_name, int a_course_credit):bclass(a_course_type, a_course_code, a_course_name, a_course_credit, course_effect)
{}

// linear linked list go to next node
node *& node::go_next()
{
	return next;
}

//verify if there is next node
bool node::if_next()
{
	if(next) 
		return true;
	else 
		return false;
}

//display linear linked list
void node::display_lnode()
{
	display_bclass();
}

//find a data with course type and course code
int node::find(const char* a_course_type, int a_course_code)
{
	//compare course type and course code
	if(strcmp(course_type, a_course_type)==0 && course_code == a_course_code)
		return 1;
	else
		return 0;
}
//get course effect to check if core, not required class
int node::get_course_effect()
{
	return course_effect;
}

//compare each node with course type and course code
int node::compare_node(const node* a_node)
{
	if(strcmp(course_type, a_node->course_type) == 0 && course_code == a_node->course_code) 
		return 1;
	else 
		return 0;
}

int node::retrieve_bclass(const char* a_course_type, int a_course_code)
{
	if(strcmp(course_type, a_course_type) == 0 && course_code == a_course_code) 
	{
		return 1;
	}
	else
		return 0;
}


// constructor for reading from a text file
course_lll::course_lll()
{
	head = NULL;
	char file [] = "program_data.txt";
	load_courses(file);
	
}


//read in the program data from the text file
int course_lll::load_courses(char course_file_name[])
{
	const int MAX_LINE_LEN = 500;
	const int MAX_TOKEN = 6;
	const char* const DELIM = ";";

	ifstream fin; //file input
	ofstream fout; //file output
	
	fin.open(course_file_name);  //open up the file
	if(fin.fail()) 
	{
		return 0;
	}

	char* course_type = NULL; // class type
	char* course_code  = NULL; // class code number
	char* course_name = NULL; // class name
	char* course_credit  = NULL; //  credit
	char* course_effect  = NULL; // class kind(core, non core)	

	//read data line by line
	while(!fin.eof()) 
	{
		char buff[MAX_LINE_LEN];
		fin.getline(buff, MAX_LINE_LEN);

		const char* token[MAX_TOKEN] = {};

		token[0] = strtok(buff, DELIM);
		if(!token[0]) break;
		
		for(int i = 1; i < MAX_TOKEN; i++) 
		{
			token[i] = strtok(0, DELIM);
		}

		
		if(course_type) 
			delete [] course_type;
		if(course_code)  
			delete [] course_code;
		if(course_name) 
			delete [] course_name;
		if(course_credit)  
			delete [] course_credit;
		
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

	//	cout << "--->> " << course_type << course_code << " " << course_name << " " << course_credit << "credits" << endl;

		add_course(course_type, atoi(course_code), course_name, atoi(course_credit), atoi(course_effect));
	}
	fin.close(); //close the file

	// deallocate the data space
	if(course_type) 
		delete [] course_type;
	if(course_code)  
		delete [] course_code;
	if(course_name) 
		delete [] course_name;
	if(course_credit)  
		delete [] course_credit;

	return 1;
}

// destructor for course_lll class
course_lll::~course_lll()
{
	remove_all();
	delete head;
}

//add the file data read from the text file
void course_lll::add_course(char* a_course_type, int a_course_code, char* a_course_name, int a_course_credit, int a_course_effect)
{
	bclass* p_bclass = new bclass(a_course_type, a_course_code, a_course_name, a_course_credit, a_course_effect);
	add(p_bclass);
}

// traversing and adding each clas data to the linear linked list 
void course_lll::add(bclass* a_bclass)
{
	if(!head) 
	{
		head = new node(a_bclass);
		head->go_next() = NULL;
		return;
	}
	node* temp = new node(a_bclass);
	temp->go_next() = head;
	head = temp;
}

//Remove the class data with class type and class code number
void course_lll::remove(const char* course_type, int course_code)
{
	if(!head) return;
	node* temp = head;
	while(!head->find(course_type, course_code)) 
	{
		temp = head;
		head = head->go_next();
	}
	temp->go_next() = head->go_next();
	delete head;
	head = NULL;	
}

//display all data in linear linked list
void course_lll::display_all()
{
	display_all(head);
}
//display all data in linear linked list
void course_lll::display_all(node* head)
{
	if(!head) 
		return;
	head->display_lnode();
	display_all(head->go_next());
}

//This function is to find the class matching to the course type and class code number
int course_lll::find_course(const char* a_course_type, int a_course_code)
{
	if(!head) //when head is null
		return 0;
	node* temp = head;
	while(temp) 
	{
		if(temp->find(a_course_type, a_course_code)) 
		{
			return 1;
		}
		temp = temp->go_next();
	}
	return 0;
}
//remove all wrapper function that removes all data
int course_lll::remove_all()
{
	int result = remove_all(head);
	
	return 1;
}
//remove all wrapper function that removes all data in LLL
int course_lll::remove_all(node * & head)
{
	if(!head) 
		return 0;
	int val = remove_all(head->go_next()) + 1;
	delete head;
	head = NULL;
	return val;	
}

void course_lll::calculate_gpa() 
{
	// GPA is calculated by q_point(total) / total credit
	node* temp = head;
	float q_point = 0.0; //points according to credit and grade
	float total_q_point = 0.0; //total points according to credit and grade to calculate GPA
	int total_credit = 0; //total credit taken
	float gpa = 0.0; //GPA
	
	base_class* arr_bclass[5];
	arr_bclass[0] = new req_class;  // required class(CS & non-cs)
	arr_bclass[1] = new core_class; // CORE class(CS only)
	arr_bclass[2] = new ncs_class;  // required but not CS
	arr_bclass[3] = new nreq_class; // not required class
	arr_bclass[4] = new base_class; // all class

	while(temp) 
	{
		if(!temp->get_grade())  //checking if there is a grade
		{
			temp = temp->go_next();
			continue;
		}
		// GPA is calculated by q_point(total) / total credit
		
		if(strcmp(temp->get_grade(), "A")==0)  //Grade A
			q_point = 4; //point
		else if(strcmp(temp->get_grade(), "A-")==0) //Grade A-
			q_point = 3.67;//point
		else if(strcmp(temp->get_grade(), "B+")==0) //Grade B+
			q_point = 3.33;//point
		else if(strcmp(temp->get_grade(), "B")==0)  //Grade B
			q_point = 3;//point
		else if(strcmp(temp->get_grade(), "B-")==0) //Grade B-
			q_point = 2.67;//point
		else if(strcmp(temp->get_grade(), "C+")==0) //Grade C+
			q_point = 2.33;//point
		else if(strcmp(temp->get_grade(), "C")==0)  //Grade C
			q_point = 2;//point
		else if(strcmp(temp->get_grade(), "C-")==0) //Grade C-
			q_point = 1.67;//point
		else if(strcmp(temp->get_grade(), "D+")==0) //Grade D+
			q_point = 1.33;//point
		else if(strcmp(temp->get_grade(), "D")==0)  //Grade D
			q_point = 1;//point
		else if(strcmp(temp->get_grade(), "D-")==0) //Grade D-
			q_point = 0.67;//point
		else if(strcmp(temp->get_grade(), "F")==0)  //Grade F
			q_point = 0;//point


		//classify the classes as core, non required, required
		arr_bclass[temp->get_course_effect()]->calculate(temp->get_course_credit(), q_point);
		
		if(temp->get_course_effect() == 1 || temp->get_course_effect() == 2) 
		{
			arr_bclass[0]->calculate(temp->get_course_credit(), q_point);
		}
		arr_bclass[4]->calculate(temp->get_course_credit(), q_point);

		temp = temp->go_next();
	}

	//calculating GPA at each section(CORE, not required, required but CS, all)
	arr_bclass[0]->calc_gpa();
	arr_bclass[1]->calc_gpa();
	arr_bclass[2]->calc_gpa();
	arr_bclass[3]->calc_gpa();
	arr_bclass[4]->calc_gpa();
	
	//Displaying GPA at each section(CORE, not required, required but CS, all)
	arr_bclass[0]->display_gpa();
	arr_bclass[1]->display_gpa();
	arr_bclass[2]->display_gpa();
	arr_bclass[3]->display_gpa();
	arr_bclass[4]->display_gpa();	
}
//set grade data 
void course_lll::set_grade(sclass* s1)
{
	node* temp = head;
	while(temp) 
	{
		if(temp->retrieve_bclass(s1->get_course_type(), s1->get_course_code())) 
		{
			temp->set_grade_data(s1->get_course_grade());
			break;
		}
		temp = temp->go_next();
	}
}
