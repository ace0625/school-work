//CS163
//Assignment #3
//Hyunchan kim

//main.cpp
#include "app_entry.h"
#include "table.h"

//This is the main.cpp that starts program and prompt the user 
//to implement this program.

int main()
{
	int menu_select; //for selecting the menu
	char app_name[100]; //temporary for name
	char key_word[100]; //temporary for key word
	char description[100]; //temporary for description
	float rating; //temporary for rating
	
	char key_word_to_find[100]; //temporary for finding by key word
	char app_name_to_find[100]; //temporary for finding by app name

	table app_table, app_table_by_name;
	app_entry entry_toadd, entry_tofind;

		
	while(true)
	{
		cout << "####################################################" << endl;
        cout << "##               Phone Application                ##" << endl;
        cout << "####################################################" << endl;
        cout << "#                                                  #" << endl;
        cout << "#  1. Add an application                           #" << endl;
        cout << "#  2. Find by Keyword                              #" << endl;
        cout << "#  3. Find by application name                     #" << endl;
        cout << "#  4. Display all                                  #" << endl;
        cout << "#  0. Exit Program                                 #" << endl;
        cout << "#                                                  #" << endl;
		cout << "####################################################" << endl;
		cout << endl;
		cout << "--> Select a menu:  ";
		cin >> menu_select;
		cout << endl;
		
		//MENU
		switch(menu_select)
		{
			//Add a application data to the table
			case 1:
				cin.ignore();
				cout << "--> Application name: "; cin.get(app_name, 100); cin.ignore(100,'\n');
				cout << "--> key_word: ";  cin.get(key_word, 100); cin.ignore(100,'\n');
				cout << "--> description: ";  cin.get(description, 100); cin.ignore(100,'\n');
				do{
					cout << "-> rating(0.0~5.0): "; cin >> rating;
				}while(rating<0.0 || rating>5.0);
				entry_toadd.create_entry(app_name, key_word, description, rating);
				app_table.insert(key_word, entry_toadd);
				app_table_by_name.insert(app_name, entry_toadd);
				entry_toadd.display_all();
				break;
			//Search data by keyword
			case 2:
				cout << "->> Prompt a keyword to find applications: ";
				cin >> key_word_to_find;
				if(app_table.retrieve_table(key_word_to_find, entry_tofind))
				{
					cout << "\n\n########<<This is what was found>> ##########" << endl;
					entry_tofind.display_all();
				}
				else
				{
					cout << "\n\n We are not able to find the application" << endl;
				}
				break;
				
			//Search data by application name
			case 3:
				cout << "--> Prompt an application name you would like to find: ";
				cin >> app_name_to_find;
				if(app_table_by_name.retrieve_table(app_name_to_find, entry_tofind))
				{
					cout << "\n\n########<<We found the application here>> ##########" << endl;
					entry_tofind.display_all();
				}
				else
				{
					cout << "\n\n We are not able to find the application" << endl;
				}
				break;
			//Display all table data
			case 4:
				cout << "================ Display all ===============" << endl << endl;
				app_table.display_all_table(); //call display all table 
				break;
			//close the program
			case 0:
				cout << "\n\n========= Bye Bye ==========\n\n";
				return 0;
		}
		
	}
	
	
	//return 0;
}