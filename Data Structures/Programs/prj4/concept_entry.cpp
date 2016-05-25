//CS163
//Assignment #4
//Hyunchan kim

//concept_entry.cpp

#include "concept_entry.h"

//concept entry default constructor
concept_entry::concept_entry()
{
	number = NULL;
	concept = NULL;
	data_structure = NULL;
    advantage = NULL;
	disadvantage = NULL;
}

//concept entry default destructor
concept_entry::~concept_entry()
{
	if(number)
		delete number;
	if(concept)
		delete concept;
	if(data_structure)
		delete data_structure;
	if(advantage)
		delete advantage;
	if(disadvantage)
		delete disadvantage;
}

//This function creates a concept entry 
int concept_entry::create_entry(char * a_number, char * a_concept_name, char * a_data_structure, char * an_advantage, char * a_disadvantage)
{	
	number = new char[strlen(a_number) + 1];
	strcpy(number, a_number);
	
	concept = new char[strlen(a_concept_name) + 1];
	strcpy(concept, a_concept_name);
	
	data_structure = new char[strlen(a_data_structure) + 1];
	strcpy(data_structure, a_data_structure);
	
	advantage = new char[strlen(an_advantage) + 1];
	strcpy(advantage, an_advantage);
	
	disadvantage = new char[strlen(a_disadvantage) + 1];
	strcpy(disadvantage, a_disadvantage);
	
	return 1;
}

//This function copies a concept entry
int concept_entry::copy_entry(const concept_entry & copy_from)
{
	if(copy_from.number)
	{
		number = new char[strlen(copy_from.number) + 1];
		strcpy(number, copy_from.number);
	}
	if(copy_from.concept)
	{
		concept = new char[strlen(copy_from.concept) + 1];
		strcpy(concept, copy_from.concept);
	}
	if(copy_from.data_structure)
	{
		data_structure = new char[strlen(copy_from.data_structure) + 1];
		strcpy(data_structure, copy_from.data_structure);
	}
	if(copy_from.advantage)
	{
		advantage = new char[strlen(copy_from.advantage) + 1];
		strcpy(advantage, copy_from.advantage);
	}
	if(copy_from.disadvantage)
	{
		disadvantage = new char[strlen(copy_from.disadvantage) + 1];
		strcpy(disadvantage, copy_from.disadvantage);
	}
	return 1;
}

//This function retrieves a matching concept information by key word
int concept_entry::retrieve(char * matching_keyword, concept_entry & found)
{
	found.number = new char[strlen(number) + 1];
	strcpy(found.number, number);
	
	found.concept = new char[strlen(concept) + 1];
	strcpy(found.concept, concept);

	found.data_structure = new char[strlen(data_structure) + 1];
	strcpy(found.data_structure, data_structure);

	found.advantage = new char[strlen(advantage) + 1];
	strcpy(found.advantage, advantage);

	found.disadvantage = new char[strlen(disadvantage) + 1];
	strcpy(found.disadvantage, disadvantage);

	//cout << "entry retrieve" << endl;
	return 1;
}

//This function displays all concept data
int concept_entry::display_all()
{
	cout << endl;
	cout << number << ". " << concept << endl;
	cout << "\ta.Data Structure: " << data_structure << endl;
	cout << "\tb.Advantages: " << endl;
	cout << "\t=>" << advantage << endl;
	cout << "\tc.Disadvantages: " << endl; 
	cout << "\t=>" << disadvantage << endl;
	cout << endl << endl;
	return 1;
}

//This function displays concept name
int concept_entry::display_concept()
{
	cout << number << ". " << concept << endl;
	return 1;
}

// String compare
int concept_entry::str_compare(const char * s2)
{
	int result = 0;
	int slen = strlen(number);
	if(strlen(number) > strlen(s2))
		slen = strlen(s2);
	for(int i = 0; i < slen; i++) 
	{
		if(number[i] == s2[i]) 
		{
			result = 0;
			continue;
		}
		else if(number[i] > s2[i]) 
		{
			result = 1;
			break;
		}
		else 
		{
			result = -1;
			break;
		}
	}

	// String length compare
	if(result == 0) {
		if(strlen(number) == strlen(s2)) 
			return 0;
		else if(strlen(number) > strlen(s2)) 
			return 1;
		else 
			return -1;
	}
	return result;
}


//this function prompts to user to add more key words
bool concept_entry::again()
{
	char response;
	cout << "Would you like to add more key word? (Y/N): ";
	cin >> response;
	cin.ignore(100, '\n');
	if (toupper(response) == 'Y')
		return true;
	else
		return false;
}