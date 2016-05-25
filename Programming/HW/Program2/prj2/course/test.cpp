#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int load_courses(char course_file_name[]);

int main()
{
	char course_file_name [] = "course.txt";
	load_courses(course_file_name);
	
	return 0;
}



// load course file to hash table
int load_courses(char course_file_name[])
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

	char* course_type = NULL; // Employer's Name
	char* course_code  = NULL; // course_code (city, state)
	char* course_name = NULL; // course Title
	char* course_credit  = NULL; // course Description

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
		if(course_type) delete course_type;
		if(course_code)  delete course_code;
		if(course_name) delete course_name;
		if(course_credit)  delete course_credit;
		
		course_type = new char[strlen(token[0]) + 1];
		strcpy(course_type, token[0]);

		course_code  = new char[strlen(token[1]) + 1];
		strcpy(course_code , token[1]);

		course_name = new char[strlen(token[2]) + 1];
		strcpy(course_name, token[2]);

		course_credit  = new char[strlen(token[3]) + 1];
		strcpy(course_credit , token[3]);

cout << "course_type:" << course_type << endl;
cout << "course_code :" << course_code  << endl;
cout << "course_name:" << course_name << endl;
cout << "course_credit :" << course_credit  << endl;

//		if(!add_course(course_type, course_code, course_name, course_credit)) {
//			return 0;
//		}
	}
	fin.close();

	// delete
	if(course_type) delete course_type;
	if(course_code)  delete course_code;
	if(course_name) delete course_name;
	if(course_credit)  delete course_credit;

	return 1;
}


int add_course(char* course_type, int course_code, char* course_name, int course_credit)
{
	return 0;
}
