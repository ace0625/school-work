//CS163
//Program#2
//Hyunchan Kim
//product.h

//This is product header file that designs product list from an external file

#ifndef _PRODUCT_H
#define _PRODUCT_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;

//ADT class
class product
{
	public:
		product(); //default constructor
		~product(); //default destructor
		int readfile(char file_name[]); //read in all data from the text file
		int retrieve(char * pos, char file_name[]); //retrieve an item
		int copy_product(const product & copyfrom); //copy function
		void display_all(); //display all data in the file

	private:
		char * description;
		char * barcode;
		char * manufacturer;
		char * quantity;
		char * position;
};

#endif