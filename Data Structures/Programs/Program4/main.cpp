//CS163
//Assignment #4
//Hyunchan kim

//main.cpp
#include "app_entry.h"
#include "bst.h"

//This is the main.cpp that starts program and prompt the user 
//to implement this program.

int main()
{
	int menu_select; //for selecting the menu
	char app_name[100], app_name_to_find[100]; //temporary for name
	char key_word[100], key_word_to_find[100]; //temporary for key word
	char description[100]; //temporary for description
	float rating; //temporary for rating
	app_entry entry;
	bst table, table2;
	

		
	while(true)
	{
		cout << "####################################################" << endl;
        cout << "##               Phone Application                 ##" << endl;
        cout << "####################################################" << endl;
        cout << "#                                                  #" << endl;
        cout << "#  1. Add an application                           #" << endl;
        cout << "#  2. Find by Keyword                              #" << endl;
        cout << "#  3. Find by application name                     #" << endl;
        cout << "#  4. Display all                                  #" << endl;
		cout << "#  5. Remove all tree data                         #" << endl;
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
				entry.create_entry(app_name, key_word, description, rating);
				if(entry.display_all())
					cout << "Your application has been added!" << endl;
				table.insert(key_word, entry);
				table2.insert(app_name, entry);
				break;
				
			//Search data by keyword
			case 2:
				cin.ignore();
				cout << "->> Prompt a keyword to find applications: ";
				cin.get(key_word_to_find, 100); cin.ignore(100,'\n');
				if(!table.display(key_word_to_find))
					cout << "There is no matching key word!" << endl;
				break;
				
			//Search data by application name
			case 3:
				cin.ignore();
				cout << "->> Prompt an application name to find: ";
				cin.get(app_name_to_find, 100); cin.ignore(100,'\n');
				if(!table2.display(app_name_to_find))
					cout << "There is no matching application!" << endl;
				break;
				
			//Display all table data
			case 4:
				cout << "================ Display all ===============" << endl << endl;
				if(!table.display_all_bst())
					cout << "Empty data " << endl << endl;
				break;
				
			case 5:
				cout << "================ Remove all ===============" << endl << endl;
				cout << ">>> " << table.remove_all() << " applications removed" << endl;
				break;
				
			//close the program
			case 0:
				cout << "\n\n========= Bye Bye ==========\n\n";
				return 0;
		}
		
	}
	
}