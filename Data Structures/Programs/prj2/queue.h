#include "product.h"


//This queue.h manages services ordered (enqueue), payment (dequeue) 
//and also displays all orders. Everything is dealt with queue functions

struct queue_node
{
	product a_product;
	queue_node * next;
};

//This is the circular linked list for customers line
class queue
{
	public:
		queue(); // constructor
		~queue(); //destructor
		int enqueue(const product & to_add); //enqueue, a customer to the line
		int dequeue(); //dequeue, when the food is ready and customer paid
		int display_all(); //display the whole order information
		
	private:
		queue_node * rear; //CLL pointer
};