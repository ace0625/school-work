//CS202
//Program #2
//Hyunchan Kim
//handler.cpp

/*
	This is handler.cpp that implements bst and LLL with external files
*/

#include "handler.h"

/*
	read in exnternal menu file
*/
int handler::read_in_menu()
{
	char name[30], kind[30];

	list = new list_lll;

	ifstream file;
	file.open("menu.txt");
	if(file)
	{
		while(!file.eof())
		{
			file.getline(kind, 30, '\n');
			file.getline(name, 30, '\n');
			file.ignore(100, '\n');
		
			if(*kind == 'e') //entrees
			{
				list->create(name, 0);
			}
			if(*kind == 'a') //appetizers
			{
				list->create(name, 1);	
			}
			if(*kind == 'd') //drinks
			{
				list->create(name, 2);
			}
		}
		read_in_ingredient(list);
		//test(list);
	}
	

	file.close();
	return 1;
}
/*
	read in ingredient external file
*/
int handler::read_in_ingredient(list_lll * a_list)
{
	char a_ingred[100];
	int a_key = 0;
	ifstream file;
	file.open("ingredient.txt");
	if(file)
	{
		while(!file.eof())
		{
			file.getline(a_ingred, 100, '\n');
			file.ignore(100, '\n');
			a_key = a_tree.key(a_ingred);
			a_tree.create(a_ingred, a_key, a_list);
		}

		test(a_list, a_tree);
	}
	file.close();
	return 1;
}

/*
 This is test function basically starts this program
*/
int handler::test(list_lll * a_list, bst a_tree)
{
	int menu_in = 0;
	
	while(menu_in != 9) {
		cout << "\n####################################################" << endl;
        cout << "##               Restaurant manager                ##" << endl;
        cout << "####################################################" << endl;
        cout << "#                                                  #" << endl;
        cout << "#  1. Display all menu                             #" << endl;
        cout << "#  2. Retrieve a menu test                         #" << endl;
        cout << "#  3. Remove a menu test                           #" << endl;
        cout << "#  4. Delete All menu                              #" << endl;
        cout << "#  5. Display bst                                  #" << endl;
        cout << "#  6. Retrieve in bst                              #" << endl;
        cout << "#  7. Remove all bst                               #" << endl;
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
			{
				cout << "****************************************************" << endl;
				a_list->display_all();
				break;
			}
			case 2:
			{
				cout << "****************************************************" << endl;
				char find[10] = "coke";
				a_list->retrieve(find);
				break;
			}
			case 3:
			{
				cout << "****************************************************" << endl;
				char find2[10] = "coke";
				a_list->remove(find2);
				cout << "\n>>>>>>>>>>>>> remove done <<<<<<<<<" << endl;
				a_list->display_all();
				break;
			}

			case 4:
			{
				cout << "****************************************************" << endl;
				a_list->remove_all();
				cout << "Remove all success!! " << endl;
				break;
			}

			case 5:
			cout << "****************************************************" << endl;
				a_tree.display_all_bst();
				break;

			case 6:
			{
				cout << "****************************************************" << endl;
				char find3[10] = "pepper";
				a_tree.retrieve(find3);
				break;
			}

			case 7:
				cout << "****************************************************" << endl;
				a_tree.remove_all();
				cout << "Remove all bst success" << endl;
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
	return 1;

}