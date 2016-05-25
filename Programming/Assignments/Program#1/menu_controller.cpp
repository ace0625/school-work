// CS202
// Program #1
// Hyunchan Kim
// menu_controller.cpp

#include "menu_controller.h"

/*
 	load census data and graph
*/
void menu_controller::show_household_info()
{
	school a_school;
	cout << ">>>>>>> House hold information <<<<<<<<" << endl;
	a_school.load_census_data();
	a_school.display();
	cout << ">>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<< " << endl << endl;
}

/*
	display school information and dll
*/
void menu_controller::show_school_info()
{
	school a_school;
	cout << ">>>>>>> School information <<<<<<<<" << endl;
	a_school.load_school_data();
	a_school.display_all();
	cout << ">>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<< " << endl << endl;
}	

/*
	find the matching best school
*/
void menu_controller::school_research()
{
	school a_school;
	a_school.load_school_data();
	cout << ">>>>>>>>>> Matching best school information <<<<<<<<<" << endl << endl;
	a_school.retrieve_school();
	cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>> <<<<<<<<<<<<<<" << endl << endl;
}


/*
	deleting all data
*/
void menu_controller::delete_data()
{
	school a_school;
	a_school.load_school_data();
	cout << ".......> Remove All data" << endl;
	a_school.remove_all();
	a_school.display_all();

}







