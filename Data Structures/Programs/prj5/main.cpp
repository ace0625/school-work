//CS163
//Assignment#5
//Hyunchan Kim

#include "graph.h"
using namespace std;

int main()
{
	table my_graph;
	char data_file_name [] = "data.txt";
	char edge_file_name [] = "edge.txt";
	char eventcode[10][10] = {"COLLEGE", "CAREER", "REUNION", "WORK"};
	int menu_in = 0;


	// data file read and insert
	if(!my_graph.load_data_file(data_file_name)) 
	{
		cout << "\n[ERROR] Data File loading process fail!" << endl;
		return 0;
	}
	else 
	{
		cout << "\n[SUCCESS] Data File is successfully loaded!\n\n";
	}

	if(!my_graph.load_edge_file(edge_file_name)) 
	{
		cout << "\n[ERROR] Edge File loading process fail!" << endl;
		return 0;
	}
	else 
	{
		cout << "\n[SUCCESS] Edge File is successfully loaded!\n\n";
	}

	
	while(menu_in != 9) {
		cout << "####################################################" << endl;
        cout << "##             My Friends graph                   ##" << endl;
        cout << "####################################################" << endl;
        cout << "#                                                  #" << endl;
        cout << "#  1. COLLEGE EVENT	                            #" << endl;
        cout << "#  2. CAREER EVENT			                        #" << endl;
        cout << "#  3. REUNION EVENT		                      #" << endl;
        cout << "#  4. WORK EVENT			                      #" << endl;
        cout << "#  5. Display All Event                          #" << endl;
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
				cout << "** COLLEGE EVENT" << endl;
				my_graph.display_event(eventcode[0]);
				break;

			case 2:
				cout << "****************************************************" << endl;
				cout << "**  CAREER EVENT" << endl;
				my_graph.display_event(eventcode[1]);
				break;

			case 3:
				cout << "****************************************************" << endl;
				cout << "** REUNION EVENT" << endl;
				my_graph.display_event(eventcode[2]);
				break;

			case 4:
				cout << "****************************************************" << endl;
				cout << "** WORK EVENT" << endl;
				my_graph.display_event(eventcode[3]);
				break;

			case 5:
				cout << "****************************************************" << endl;
				cout << "** ALL EVENTS" << endl;
				my_graph.display_all();
				break;

			// Exit Program
			case 0:
				cout << "Close the program." << endl;
				return 0;
				
			default:
				cout << "** Please choose number in the menu!" << endl;
				
		}
		
		cout << "\n\n";
	}	

	return 0;
}
