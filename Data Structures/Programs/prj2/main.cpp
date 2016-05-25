//CS163
//Program#2
//Hyunchan Kim
//main.cpp

//This is main file that starts this program

#include "list.h"
#include "queue.h"
#include "stack.h"


int main()
{
 	product product_list, a_product;
	list cart_list;
	queue ordered_list;
	stack waiting_list;
	char file[] = "data.txt";
	char pos[10];
	int menu; //menu choice

	cout << "======================================================================" << endl;
	cout << "                  <Welcome to Kim's AMAZON>                           " << endl;
	cout << "======================================================================" << endl << endl;
   
	do
	{
		cout << "\n================ MENU ===============" << endl;
		cout << "1. Loop up product list" << endl;
		cout << "2. Add a product to your shopping cart(list)" << endl;
		cout << "3. Display your all item in your cart" << endl;
		cout << "4. Order a product(enqueue)" << endl;
		cout << "5. Process a product(dequeue)" << endl;
		cout << "6. Display your ordered list(in queue)" << endl;
		cout << "7. Add to the wating list(push)" << endl;
		cout << "8. Loop up the wating list at the top(peek)" << endl;
		cout << "9. Remove an item from the wating list(pop)" << endl;
		cout << "0. Exit" << endl;
		cin >> menu;
		switch (menu)
		{
		case 1: 
			product_list.readfile(file);
			break;

		case 2: 
			cout << "Enter the position you would like to add in your shopping cart: ";
			cin >> pos;
			product_list.retrieve(pos, file);
			if(cart_list.add(product_list))
				cout << "Your order has been added in your cart! " << endl;
			else
				cout << "Cannot find the item " << endl;
			break;

		case 3:
			cout << "\n ============ Your shopping cart list ================" << endl;
			if(!cart_list.display_all())
				cout << "Your shopping cart is empty" << endl;
				
			break;
			
		case 4:
			cout << "Enter the position you would like to order: ";
			cin >> pos;
			product_list.retrieve(pos, file);
			if(ordered_list.enqueue(product_list))
				cout << "Your order has been added" << endl;
			else
				cout << "Cannot find the item " << endl;
			break;
			
		case 5:
			if(ordered_list.dequeue())
				cout << "An order has been processed" << endl;
			else
				cout << "Cannot process the order" << endl;
			break;
			
		case 6:
			cout << "\n ============ Your Ordered list ================" << endl;
			ordered_list.display_all();
			break;
			
		case 7:
			cout << "Enter the position number that is out of stock : ";
			cin >> pos;
			product_list.retrieve(pos, file);
			if(waiting_list.push(product_list))
				cout << "Your order has been added to the wating list" << endl;
			else
				cout << "Cannot find the item " << endl;
			break;
			
		case 8:
			cout << "\n ============ Peek ================" << endl;
			waiting_list.peek(a_product);
			break;
		
		case 9:
			cout << "\n ============ Pop ================" << endl;
			if(waiting_list.pop())
				cout << "The top item has been removed " << endl;
			else
				cout << "no item to remove" << endl;	
			
			break;
		
		case 0: //exit. see you next time
			cout << ">>>>>>>>SEE YOU NEXT TIME!" << endl;
			return 0;
			break;
		}


	} while (true);
	
	return 0;
}
