//CS163
//Assignment#5
//Hyunchan Kim

#include "task_graph.h"
using namespace std;

int main()
{
	table my_task;
	char task_info_file_name [] = "task_info.txt";
	char task_edge_file_name [] = "task_edge.txt";
	char taskcode[4][4] = {"AA", "BB", "CC", "DD"};
	int menu_in = 0;


	// task info file read and insert
	if(!my_task.load_task_info_file(task_info_file_name)) 
	{
		cout << "\n[ERROR] task Information File loading process fail!" << endl;
		return 0;
	}
	else 
	{
		cout << "\n[SUCCESS] task Information File is successfully loaded!\n\n";
	}

	// task edge file read and insert
	if(!my_task.load_task_edge_file(task_edge_file_name)) 
	{
		cout << "\n[ERROR] task Edge File loading process fail!" << endl;
		return 0;
	}
	else 
	{
		cout << "\n[SUCCESS] task Edge File is successfully loaded!\n\n";
	}

	
	while(menu_in != 9) {
		cout << "####################################################" << endl;
        cout << "##            			MY TASK                    ##" << endl;
        cout << "####################################################" << endl;
        cout << "#                                                  #" << endl;
        cout << "#  1. FIRST TASK		                            #" << endl;
        cout << "#  2. SECOND TASK			                        #" << endl;
        cout << "#  3. THIRD TASK			                        #" << endl;
        cout << "#  4. FOURTH TASK			                        #" << endl;
        cout << "#  5. Display All TASKS                            #" << endl;
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
				cout << "** FIRST TASK" << endl;
				my_task.display_taskno(taskcode[0]);
				break;

			case 2:
				cout << "****************************************************" << endl;
				cout << "** SECOND TASK" << endl;
				my_task.display_taskno(taskcode[1]);
				break;

			case 3:
				cout << "****************************************************" << endl;
				cout << "** THIRD TASK" << endl;
				my_task.display_taskno(taskcode[2]);
				break;

			case 4:
				cout << "****************************************************" << endl;
				cout << "** FOURTH TASK" << endl;
				my_task.display_taskno(taskcode[3]);
				break;

			case 5:
				cout << "****************************************************" << endl;
				cout << "** ALL TASKS" << endl;
				my_task.display_all();
				break;

			// Exit Program
			case 0:
				cout << "Close the program." << endl;
				break;
				
			default:
				cout << "** Please choose number in the menu!" << endl;
				break;
		}
		
		cout << "\n\n";
	}	

	return 0;
}
