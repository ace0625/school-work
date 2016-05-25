#include "employee.h"
using namespace std;

//Step 6 implement select functions as provided here:

employee::employee(char * name, char * street, char * zip, int id): person(name, street, zip), employee_id(id), root(0) {}
{
	//Avoid accessing the base class members here.
        //Instead, use an initialization list to cause the
        //base class constructor to be called with the name


}

//Set up a new hourly employee, give a person's information
//Think about how to use the member functions inherited to
//initialize the new hourly employee.
//Avoid use of the = operator as it does a shallow copy!
hourly_employee::hourly_employee(const person & input): employee(input){}
{

}

//Implement the wrapper function to display an employee
//and then call the recursive display function to display
//the BST containing performance review information
void employee::display() const
{
	person::display();
	cout << "employee ID: " << employee_id << endl;
	if(root)
	{
		cout << "information : " << endl;
		display(root);
	}
}


//Implement the recursive display function using the 
//functions available within the hierarchy
void employee::display(node * root) const
{
   if(root != NULL)
   {
	display(root->go_left);
	root->display();
	display(root->go_right);
   }

}

//Challenge - implement a recursive copy function
void employee::copy_tree(node * & dest_root, node * source_root) const
{
	if(!source_root)
	{
		dest_root = NULL;
	}
	else
	{
		dest_root = new node(*source_root);
		copy_tree(dest_root->go_left(), source_root->go_left());
		copy_tree(dest_root->go_right(), source_root->go_right());
	}
}
