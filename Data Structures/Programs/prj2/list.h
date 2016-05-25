//CS163
//Program#2
//Hyunchan Kim
//list.h

//This is list header file that builds linear linked list 
//for shopping cart list

#include "product.h"

struct node
{
	product a_product; //Array that holds the data
	node * next; //points to the next node
};


//list class for LLL
class list
{
	public:
		list(); //default constructor
		~list(); //default destructor
		int add(product & to_add); //insert function that adds a product to LLL
		int remove(char * position, product & found); //remove an imtem
		int display_all(void); //display all data in LLL
	
	private:
		node * head; //head pointer
		
};