// CS202
// Program #1
// Hyunchan Kim
// menu_controller.h

#include "school.h"
#include <iostream>
using namespace std;

/*
	This menu_controller class controls 
	all data and menu
*/
class menu_controller : public school
{
	public:
		void show_household_info();
		void show_school_info();
		void school_research();
		void delete_data();
};