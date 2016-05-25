//CS163
//Assignment#5
//Hyunchan Kim

#include <cstring>
#include <cctype>
#include <iostream>

#ifndef _TASK_ENTRY_H
#define _TASK_ENTRY_H
class task_entry
{
	public:
		task_entry(void);
		~task_entry(void);
		int create_entry(char* task_no, char* term, char* step, char* desc);
		int copy_entry(const task_entry & a_new_entry);
		int retrieve(char* matching_name, task_entry & found) const;   
		int retrieve(task_entry & found) const;  
		bool compare (char* match);
		int display(void) const;
		int display_step();
		char* get_task_no() const;
		char* get_term() const;

	private:
		char* task_no;
		char* term;
		char* step;
		char* desc;
};
#endif
