//CS163
//Program #3
//Hyunchan Kim
//main.cpp

//This is main file that starts this program

#include "post_entry.h"
#include "table.h"

int main()
{
 	post_entry entry, retrieve_entry;
	table a_table;
	char name[10], date[20], content[100], likes[10], key_words[20];
	char key[20];
	int menu; //menu choice
	a_table.build(); //Read in the external file and insert into the hash table.
	
	cout << "======================================================================" << endl;
	cout << "                  <Welcome to Kim's FACEBOOK>                           " << endl;
	cout << "======================================================================" << endl << endl;
   
	do
	{
		cout << "\n================ MENU ===============" << endl;
		cout << "1. Add a post" << endl;
		cout << "2. Show all posts(Display all table)" << endl;
		cout << "3. Find a post by key word" << endl;
		cout << "0. Exit" << endl;
		cin >> menu;
		
		switch (menu)
		{
			case 1: //Add a post
				cin.ignore();
				cout << "============== new post==================" << endl;
				cout << "name : "; cin.get(name, 10); cin.ignore(10,'\n');
				cout << "date(ex) 11-09-15) : "; cin.get(date, 20); cin.ignore(20,'\n');
				cout << "content : "; cin.get(content, 100); cin.ignore(100,'\n');
				cout << "likes : "; cin.get(likes, 10); cin.ignore(10,'\n');
				cout << "key_words : "; cin.get(key_words, 20); cin.ignore(20,'\n');
				
				entry.create_entry(name, date, content, likes, key_words);
				if(a_table.insert(key_words, entry))
					cout << "Your post has been added" << endl;
				else 
					cout << "Cannot add your post" << endl;
				break;
				
			case 2: //show all post
				a_table.display_all_table();
				break;
				
			case 3: //Retrieve a post by key word
				cin.ignore();
				cout << "Enter a key word to find the matching post: "; 
				cin.get(key, 20); cin.ignore(20,'\n');	
				if(a_table.retrieve_table(key, retrieve_entry))
				{
					cout << "Here's what we found" << endl;
					retrieve_entry.display_all();
				}
				break;
				
			case 0: //exit. see you next time
				cout << ">>>>>>>>SEE YOU NEXT TIME!" << endl;
				return 0;
				break;
		}

	} while (true);
	
	return 0;
}
