//CS163
//Program #1
//10/14/2015
//Hyunchan Kim
//main.cpp
//This file is main program that runs the client Program

#include "candidate.h"

int main()
{
	candidate a_candidate; //a candidate instance
	candidate candidate_tofind, candidate_tofind2; 
	list candidate_list; //candidate list LLL
	int select; // selection integer
	char first[10]; //for first name
	char last[10]; //for last name 
	char view1[100], view2[100], view3[100], view4[100], view5[100]; // five major views
	char thoughts[100]; //your thoughts
	char to_poll[10], to_thought[10];
	
	while (true)
	{
		//menu selection starts
	cout << "\n================ MENU ===============" << endl;
	cout << "1. Add a candidate" << endl;  //read in text file from parts.txt
	cout << "2. Update Poll" << endl; //display parts in order
	cout << "3. Update Information" << endl; // display all steps
	cout << "4. Display all candidates" << endl; // display all data
	cout << "0. Exit" << endl << endl; // exit
	cout << "Select => ";
	cin >> select;
	
		switch (select)
		{
		case 1: //create a candidate
			cin.ignore();
			cout << "First name : "; cin.get(first, 10); cin.ignore(10,'\n');
			cout << "Last name : "; cin.get(last, 10); cin.ignore(10,'\n');
			cout << "Major view 1 : "; cin.get(view1, 100); cin.ignore(100,'\n');
			cout << "Major view 2 : "; cin.get(view2, 100); cin.ignore(100,'\n');
			cout << "Major view 3 : "; cin.get(view3, 100); cin.ignore(100,'\n');
			cout << "Major view 4 : "; cin.get(view4, 100); cin.ignore(100,'\n');
			cout << "Major view 5 : "; cin.get(view5, 100); cin.ignore(100,'\n');
			
			a_candidate.create_candidate(first, last, view1, view2, 
			view3, view4, view5, 0, thoughts);
			
			if (candidate_list.insert(a_candidate))
				cout << "A candidate has been added " << endl << endl;
			else
				cout << "Failed !! " << endl << endl;
			break;
			
		case 2: //update poll
			cin.ignore();
			cout << "Enter a candidate's last name you would like to vote: ";
			cin.get(to_poll, 10, '\n'); cin.ignore(10,'\n');
			if(candidate_list.update_poll(to_poll, candidate_tofind))
			{
				cout << "Your poll has been added" << endl;
			}
			else
				cout << "Cannot find the candidate" << endl;
				
			break;
			
		case 3: // update information
			cin.ignore();
			cout << "Enter a candidate's last name you would like to write your thoughts: ";
			cin.get(to_thought, 10, '\n'); cin.ignore(10,'\n');
			cout << "Enter your thoughts : ";
			cin.get(thoughts, 100, '\n'); cin.ignore(100,'\n');
			if(candidate_list.update_information(to_thought, thoughts, candidate_tofind2))
			{
				cout << "Your thoughts has been added" << endl;
			}
			else
				cout << "Cannot find the candidate" << endl;
			break;
			
		case 4: //display all candidate data
			if (!candidate_list.display_all())
				cout << "Can not display all \n\n";
			break;
			
		case 0: //exit
			cout << "<<<<<<<<<<<<< BYE >>>>>>>>>>>>>" << endl;
			return 0;
			break;
		}

	}
	return 0;
}






