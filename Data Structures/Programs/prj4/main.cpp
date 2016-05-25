//CS163
//Assignment #4
//Hyunchan kim

//main.cpp
#include "concept_entry.h"
#include "bst.h"

//This is the main.cpp that starts program and prompt the user 
//to implement this program.

int main()
{
	concept_entry entry;
	bst bst_tree;
	bst_tree.build(); //read in all data from an external file

	char number[2], concept[20], datastructure[30],
		advantage[200], disadvantage[200];
	char num[2];
	int menu_select; //for selecting the menu
	while(true)
	{
		cout << "####################################################" << endl;
        cout << "##          Concept Binary Search Tree            ##" << endl;
        cout << "####################################################" << endl;
        cout << "#                                                  #" << endl;
        cout << "#  1. Add a concept information                    #" << endl;
        cout << "#  2. Find a concept information by keyword        #" << endl;
        cout << "#  3. Display by key word                          #" << endl;
        cout << "#  4. Display all Concepts                         #" << endl;
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
			case 1:	
				cin.ignore();
				cout << "============== new concept ==================" << endl;
				cout << "Number : "; cin.get(number, 2); cin.ignore(2,'\n');
				cout << "Concept : "; cin.get(concept, 20); cin.ignore(20,'\n');
				cout << "Data Structure : "; cin.get(datastructure, 30); cin.ignore(30,'\n');
				cout << "Advantage : "; cin.get(advantage, 200); cin.ignore(200,'\n');
				cout << "Disadvantage : "; cin.get(disadvantage, 200); cin.ignore(200,'\n');
				
				entry.create_entry(number, concept, datastructure, advantage, disadvantage);
				if(bst_tree.insert(number, entry))
					cout << "Your new concept has been added" << endl;
				else 
					cout << "Cannot add your concept" << endl;
				break;
				
			case 2: //retrieve by concept name
				cin.ignore();
				bst_tree.display_concept();
				cout << "=> Enter the concept number you want to retrieve: ";
				cin.get(num, 2); cin.ignore(2,'\n');
				if(!bst_tree.retrieve(num))
					cout << "There's no matching concept data" << endl;
				break;
				
			case 3: //display by keyword
				cin.ignore();
				bst_tree.display_concept();
				cout << "=> Enter a number you want to display the concept information: ";
				cin.get(num, 2); cin.ignore(2,'\n');
				if(!bst_tree.display(num))
					cout << "Cannot find the matching data" << endl;		
				break;
				
			case 4: //display all data in the binary search tree
				bst_tree.display_all_bst();
				break;
				
			case 5: //remove all data in the binary search tree
				if(bst_tree.remove_all())
					cout << "!!!REMOVE ALL COMPLETE!!!" << endl;
				else
					cout << "!!!REMOVE ALL FAILED!!!" << endl;
				break;
				
			//close the program
			case 0:
				cout << "\n\n========= Bye Bye ==========\n\n";
				return 0;
		}
		
	}
	
}