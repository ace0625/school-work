#ifndef _TASK_ENTRY_H
#define _TASK_ENTRY_H

#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;

class task_entry
{
	public:
		task_entry();
		~task_entry();
		int create_entry(char* p_p_area, char* p_p_code, char* p_p_name, char* p_p_desc);
		int copy_entry(const task_entry & copy_from);
		int retrieve(char * matching_name, task_entry & found);   
		int retrieve(task_entry & found);  

		bool compare (char* match);
		int display();
		int display_pname();
		char* get_parea();
		char* get_pcode();

	private:
		char* p_area;
		char* p_code;
		char* p_name;
		char* p_desc;
};
#endif
