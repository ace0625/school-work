//CS202
//Program #1
//Hyunchan Kim
//main.cpp

#include "menu_controller.h"
using namespace std;

int main()
{
	menu_controller menu;
	int menu_in = 0;
	
	while(menu_in != 9) {
		cout << "\n####################################################" << endl;
        cout << "##           Household and School program         ##" << endl;
        cout << "####################################################" << endl;
        cout << "#                                                  #" << endl;
        cout << "#  1. Display household information                #" << endl;
        cout << "#  2. Display school information                   #" << endl;
        cout << "#  3. Find the best school                         #" << endl;
        cout << "#  4. Delete All data                              #" << endl;
        cout << "#  0. Exit Program                                 #" << endl;
        cout << "#                                                  #" << endl;
		cout << "####################################################" << endl;
		cout << endl;
		cout << "## Please choose menu: ";
		
		cin >> menu_in;
		cin.ignore();
		cout << endl;
		
		switch(menu_in) 
		{
			// Process for menu
			case 1:
				cout << "****************************************************" << endl;
				menu.show_household_info();
				break;

			case 2:
				cout << "****************************************************" << endl;
				menu.show_school_info();
				break;

			case 3:
				cout << "****************************************************" << endl;
				menu.school_research();
				break;

			case 4:
				cout << "****************************************************" << endl;
				menu.delete_data();
				break;

			// Exit Program
			case 0:
				cout << "Close the program. Bye Bye." << endl;
				return 0;
				
			default:
				cout << "** Please choose number in the menu!" << endl;
				
		}
		cout << "\n\n";
	}	

	return 0;
}
