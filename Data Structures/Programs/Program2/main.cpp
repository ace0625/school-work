//CS163
//Assignment #2
//4/29/2015
//Hyunchan Kim
//main.cpp

#include "queue.h"
#include "stack.h"
#include "service.h"

// This main.cpp prompts the user order food, pay, check the waiting time, and statistics.

int main()
{
 	service a_service; //a service object
	time_t t; //current time
	char * curTime; //current time pointer
	char * name; //for temporary name
	char * burgername;
	queue line; //queue object for wating line
	stack stats; //stack object for statistics
	int menu; //menu choice
	int burger; //burger choice

	cout << "======================================================================" << endl;
	cout << "                  <Welcome to Kim's Burger>                           " << endl;
	cout << "======================================================================" << endl << endl;
   
	do
	{
		cout << "\n================ MENU ===============" << endl;
		cout << "1. Make an order" << endl;
		cout << "2. An order paid(dequeue, pop)" << endl;
		cout << "3. Look at the waiting list" << endl;
		cout << "4. Total wating time(peek)" << endl;
		cout << "5. Average and stats" << endl;
		cout << "6. Exit" << endl;
		cin >> menu;
		switch (menu)
		{
		case 1: //Make an order
			cout << "\n--> What would you like to order? " << endl;
			cout << "======================================" << endl;
			cout << "1. Cheese Burger" << endl;
			cout << "2. Angus Burger" << endl;
			cout << "3. Veggi Burger" << endl;
			cout << "4. Steak Burger" << endl;
			cout << "5. Chicken Burger" << endl;
			cin >> burger;
			//Burger menu select
			switch (burger)
			{
			case 1:  //cheese burger takes 5 mins
				burgername = new char[20];
			    strcpy(burgername, "Cheese Burger");
				cout << "Name : ";
				name = new char[10];
				cin >> name;
				t = time(0);
				curTime = ctime(&t);
				if(a_service.createOrder(name, burgername, curTime, 5))
					cout << "Your order has been created. To see the waiting time, select 2(waiting list)" << endl;
				line.enqueue(a_service);
				stats.push(a_service);
				break;
			case 2:	 //Angus burger takes 9 mins
				burgername = new char[20];
				strcpy(burgername, "Angus Burger");
				cout << "Name : ";
				name = new char[10];
				cin >> name;
				t = time(0);
				curTime = ctime(&t);
				if (a_service.createOrder(name, burgername, curTime, 9))
					cout << "Your order has been created. To see the waiting time, go to 2" << endl;
				line.enqueue(a_service);
				stats.push(a_service);
				break;
			case 3:   //veggi burger takes 4 mins
				burgername = new char[20];
				strcpy(burgername, "Veggi Burger");
				cout << "Name : ";
				name = new char[10];
				cin >> name;
				t = time(0);
				curTime = ctime(&t);
				if(a_service.createOrder(name, burgername, curTime, 4))
					cout << "Your order has been created. To see the waiting time, go to 2" << endl;
				line.enqueue(a_service);
				stats.push(a_service);
				break;
			case 4: //Steak burger takes 10 mins
				burgername = new char[20];
				strcpy(burgername, "Steak Burger");
				cout << "Name : ";
				name = new char[10];
				cin >> name;
				t = time(0);
				curTime = ctime(&t);
				if(a_service.createOrder(name, burgername, curTime, 10))
					cout << "Your order has been created. To see the waiting time, go to 2" << endl;
				line.enqueue(a_service);
				stats.push(a_service);
				break;
			case 5:   //Chicken burger takes 8 mins
				burgername = new char[20];
				strcpy(burgername, "Chicken Burger");
				cout << "Name : ";
				name = new char[10];
				cin >> name;
				t = time(0);
				curTime = ctime(&t);
				if(a_service.createOrder(name, burgername, curTime, 8))
					cout << "Your order has been created. To see the waiting time, go to 2" << endl;
				line.enqueue(a_service);
				stats.push(a_service);
				break;
			}

			break;

		case 2: //an oder has been paid, dequeue
			line.dequeue(a_service);
			stats.pop();
			break;

		case 3: //check the waiting line
			if (!line.display_all())
				cout << "There is no order" << endl;
			break;
		case 4:
			stats.peek(a_service);
			break;
		case 5:
		cout << stats.display_stack();
			break;
		case 6: //exit. see you next time
			cout << ">>>>>>>>SEE YOU NEXT TIME!" << endl;
			return 0;
			break;
		}


	} while (true);
	
	return 0;
}
