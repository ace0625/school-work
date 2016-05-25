//CS163
//Program #1
//4/15/2015
//Hyunchan Kim
//main.cpp
//This file is main program that runs the client Program

#include "DIY.h"

int main()
{
	DIY diy; // DIY class
	int select; // selection integer
	while (true)
	{
		//menu selection starts
	cout << "\n================ MENU ===============" << endl;
	cout << "1. Read File" << endl;  //read in text file from parts.txt
	cout << "2. Display Parts" << endl; //display parts in order
	cout << "3. Display Steps" << endl; // display all steps
	cout << "4. Display all" << endl; // display all data
	cout << "0. Exit" << endl; // exit
	cin >> select;
		switch (select)
		{
		case 1: //read file
			if (diy.readfile("parts.txt"))
				cout << "Read in Complete!! " << endl << endl;
			else
				cout << "Read in Failed !! " << endl << endl;
			break;
		case 2: //display parts in order
			if (diy.display_parts())
				cout << "========All parts in order of part number==============\n\n";
			else
				cout << "Can not find the parts\n\n";
			break;
		case 3: // display all steps
			if (diy.display_steps())
				cout << "========== All the display steps ================\n\n";
			else
				cout << "Can not display steps...\n\n";
			break;
		case 4: //display all data
			if (!diy.display_all())
				cout << "Can not display all \n\n";
			break;
		case 0: //exit
			cout << "<<<<<<<<<<<<<BYE>>>>>>>>>>>>>" << endl;
			return 0;
			break;
		}

	}
	return 0;
}






