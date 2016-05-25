//CS163
//Program#2
//Hyunchan Kim
//product.cpp

#include "product.h"

/*
default constructor
*/
product::product()
{
	description = NULL;
	barcode = NULL;
	manufacturer = NULL;
	quantity = NULL;
	position = NULL;
}

/*
default destructor
*/
product::~product()
{
	description = NULL;
	barcode = NULL;
	manufacturer = NULL;
	quantity = NULL;
	position = NULL;
}


/*
This function reads in product list from an external file
*/
int product::readfile(char file_name[])
{
	const int MAX_LINE_LEN = 500;
	const int MAX_TOKEN = 6;
	const char* const DELIM = ";";

	ifstream fin; //file input
	ofstream fout; //file output
	
	fin.open(file_name);  //open up the file
	if(fin.fail()) 
		return 0;

	//read data line by line
	while(!fin.eof()) 
	{
		char buff[MAX_LINE_LEN];
		fin.getline(buff, MAX_LINE_LEN);

		const char* token[MAX_TOKEN] = {};

		token[0] = strtok(buff, DELIM);
		if(!token[0]) break;
		
		for(int i = 1; i < MAX_TOKEN; i++) 
		{
			token[i] = strtok(0, DELIM);
		}
		
		// deallocate the data space
		if(description) 
			delete [] description;
		if(barcode)  
			delete [] barcode;
		if(manufacturer) 
			delete [] manufacturer;
		if(quantity)  
			delete [] quantity;
		if(position)  
			delete [] position;
		
			
		position = new char[strlen(token[0]) + 1];
		strcpy(position, token[0]);
		
		description = new char[strlen(token[1]) + 1];
		strcpy(description, token[1]);

		barcode  = new char[strlen(token[2]) + 1];
		strcpy(barcode , token[2]);

		manufacturer = new char[strlen(token[3]) + 1];
		strcpy(manufacturer, token[3]);

		quantity = new char[strlen(token[4]) + 1];
		strcpy(quantity, token[4]);
	
	
		
		cout << "\n>>>>>>> Product <<<<<<<<<<<" << endl;
		cout << "-> DESCRIPTION: " << description << endl;
		cout << "-> BARCODE: " << barcode << endl;
		cout << "-> MANUFACTURER: " << manufacturer << endl;
		cout << "-> QUANTITY: " << quantity << endl;
		cout << "-> POSITION: " << position << endl << endl;
		
	}
	fin.close(); //close the file

	return 1;
}

/*
This function retrives a specific product by position number
*/
int product::retrieve(char * pos, char file_name[])
{
	const int MAX_LINE_LEN = 500;
	const int MAX_TOKEN = 6;
	const char* const DELIM = ";";

	ifstream fin; //file input
	ofstream fout; //file output
	
	fin.open(file_name);  //open up the file
	if(fin.fail()) 
		return 0;

	//read data line by line
	while(!fin.eof()) 
	{
		char buff[MAX_LINE_LEN];
		fin.getline(buff, MAX_LINE_LEN);

		const char* token[MAX_TOKEN] = {};

		token[0] = strtok(buff, DELIM);
		if(!token[0]) break;
		
		for(int i = 1; i < MAX_TOKEN; i++) 
		{
			token[i] = strtok(0, DELIM);
		}
		
		if(!strcmp(token[0], pos))
		{
			
			//deallocate the data space
			if(description) 
				delete [] description;
			if(barcode)  
				delete [] barcode;
			if(manufacturer) 
				delete [] manufacturer;
			if(quantity)  
				delete [] quantity;
			if(position)  
				delete [] position;
			
				
			position = new char[strlen(token[0]) + 1];
			strcpy(position, token[0]);
			
			description = new char[strlen(token[1]) + 1];
			strcpy(description, token[1]);

			barcode  = new char[strlen(token[2]) + 1];
			strcpy(barcode , token[2]);

			manufacturer = new char[strlen(token[3]) + 1];
			strcpy(manufacturer, token[3]);

			quantity = new char[strlen(token[4]) + 1];
			strcpy(quantity, token[4]);
		
			
			cout << "\n>>>>>>> Product <<<<<<<<<<<" << endl;
			cout << "-> DESCRIPTION: " << description << endl;
			cout << "-> BARCODE: " << barcode << endl;
			cout << "-> MANUFACTURER: " << manufacturer << endl;
			cout << "-> QUANTITY: " << quantity << endl;
			cout << "-> POSITION: " << position << endl << endl;
		
		}
		
	}
	fin.close(); //close the file

	return 1;
}

/*
This functoin copies a product
*/
int product::copy_product(const product & copyfrom)
{
	if (copyfrom.description)
	{
		description = new char[strlen(copyfrom.description) + 1];
		strcpy(description, copyfrom.description);
	}
		
	if (copyfrom.barcode)
	{
		barcode = new char[strlen(copyfrom.barcode) + 1];
		strcpy(barcode, copyfrom.barcode);
	}
	
	if (copyfrom.manufacturer)
	{
		manufacturer = new char[strlen(copyfrom.manufacturer) + 1];
		strcpy(manufacturer, copyfrom.manufacturer);
	}
	
	if (copyfrom.quantity)
	{
		quantity = new char[strlen(copyfrom.quantity) + 1];
		strcpy(quantity, copyfrom.quantity);
	}
	
	if (copyfrom.position)
	{
		position = new char[strlen(copyfrom.position) + 1];
		strcpy(position, copyfrom.position);
	}
	
	return 1;
}


/*
This function displays a product information
*/
void product::display_all()
{
	cout << "\n>>>>>>> Product <<<<<<<<<<<" << endl;
	cout << "-> DESCRIPTION: " << description << endl;
	cout << "-> BARCODE: " << barcode << endl;
	cout << "-> MANUFACTURER: " << manufacturer;
	cout << "-> QUANTITY: " << quantity << endl;
	cout << "-> POSITION: " << position << endl << endl;
}