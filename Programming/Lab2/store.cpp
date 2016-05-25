#include "store.h"
using namespace collection;

//These are the functions you will be implementing for Lab #2

//Default constructor
binary_tree::binary_tree() // root(0){}
{
    root = NULL;
}


//Place your binary_tree copy constructor here. Make this a
//wrapper function, calling the recursive copy function below
//
//You should have already placed the prototype for this function
//in the .h file (that was NOT done for you already!)
//Use CARE when deciding the SYNTAX for the copy constructor!
//
//YOU WILL NEED TO "uncomment out" THIS CODE ONCE THIS 
//FUNCTION IS WRITTEN!
binary_tree::binary_tree(const binary_tree &obj)
{
    if(obj.root)
	copy_tree(root, obj.root);


} 

//Recursive copy function
void binary_tree::copy_tree(node * & result, node * source)
{
   if(!source)
	result = NULL;
   else
   {
	result = new node(*source);
	copy_tree(result->go_left(), source->go_left());
	copy_tree(result->go_right(), source->go_right());
   }
}

//Implement the binary_tree destructor. Make this a
//wrapper function, calling the recursive delete_all function below
binary_tree::~binary_tree()
{
    delete_all(root);
}

//Recursive delete all function
void binary_tree::delete_all(node * & root)
{
   if(root)
   {
	delete_all(root->go_left());
	delete_all(root->go_right());
	delete root;
	root = NULL;
   }
}

//BST constructor
BST::BST() : balance_factor(0)
{


}

//store default constructor
//Think about what this should do
store::store()
{
     cout << "Enter a store name: ";
     store_name.read();
     location.read();

}

//Store constructor with an argument
//Hint: Think about initialization lists
store::store(char * new_store_name, address & stores_location):store_name(new_store_name),location(stores_location)
{



}

//Display all - think about what the job of this function should be:
void store::display_all() 
{
 //  binary_tree::display_all();
   cout << "Store: ";
   store_name.display();
   cout << "\nLocation: ";
   location.display();
   BST::display_all();
}













































