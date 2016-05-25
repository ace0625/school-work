//CS163
//Assignment #2
//4/29/2015
//Hyunchan Kim
//qeueue.h
#include "service.h"


//This queue.h manages services ordered (enqueue), payment (dequeue) 
//and also displays all orders. Everything is dealt with queue functions

struct queue_node
{
	service a_service;
	queue_node * next;
};

//This is the circular linked list for customers line
class queue
{
	public:
		queue(); // constructor
		~queue(); //destructor

		int enqueue(const service & to_add); //enqueue, a customer to the line
		int dequeue(service & paid); //dequeue, when the food is ready and customer paid
		int display_all(); //display the whole order information
		
	private:
		queue_node * rear; //CLL pointer
		int num_customer; // number of customers
};