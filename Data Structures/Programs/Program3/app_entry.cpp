//CS163
//Assignment #3
//Hyunchan kim

//app_entry.cpp

//This class is implementing for candidate entry
//that create a candidate list, copy, retrieve, and display.

#include "app_entry.h"

//app entry default constructor
app_entry::app_entry()
{
	//cout << "app_entry()" << endl;
	app_name = NULL;
	key_word = NULL;
    description = NULL;
	rating = 0.0;
}

//app entry default destructor
app_entry::~app_entry()
{
	//cout << "~app_entry()" << endl;
	if(app_name)
		delete app_name;
	if(key_word)
		delete key_word;	
	if(description)
		delete description;
	if(rating)
		rating = 0.0;
}

//This function creates an app entry with name, key word, description, and rating
int app_entry::create_entry(char * an_app_name, char * a_key_word, char * a_description, float a_rating)
{
	//cout << "create entry" << endl;
	if(!an_app_name || !a_key_word || !a_description || !a_rating) //if any of the data has not come in
		return 0;
	
	if(app_name)
		delete app_name;
	if(key_word)
		delete key_word;
	if(description)
		delete description;
	if(rating)
		rating = 0.0;
	
	app_name = new char[strlen(an_app_name) + 1];
	strcpy(app_name, an_app_name);
	
	key_word = new char[strlen(a_key_word) + 1];
	strcpy(key_word, a_key_word);
	
	description = new char[strlen(a_description) + 1];
	strcpy(description, a_description);
	
	rating = a_rating;
	
	return 1;
}

//This function copies an application entry
int app_entry::copy_entry(const app_entry & copy_from)
{
	if(copy_from.app_name)
	{
		app_name = new char[strlen(copy_from.app_name) + 1];
		strcpy(app_name, copy_from.app_name);
	}
	if(copy_from.key_word)
	{
		key_word = new char[strlen(copy_from.key_word) + 1];
		strcpy(key_word, copy_from.key_word);
	}
	if(copy_from.description)
	{
		description = new char[strlen(copy_from.description) + 1];
		strcpy(description, copy_from.description);
	}
	if(copy_from.rating)
	{
		rating = copy_from.rating;
	}
	return 1;
}

//This function retrieves an application information by key word
int app_entry::retrieve(char * matching_keyword, app_entry & found)
{
		found.key_word = new char[strlen(key_word) + 1];
		strcpy(found.key_word, key_word);

		found.app_name = new char[strlen(app_name) + 1];
		strcpy(found.app_name, app_name);

		found.description = new char[strlen(description) + 1];
		strcpy(found.description, description);

		found.rating = rating;

	//cout << "entry retrieve" << endl;
	return 1;
}

//This function displays all application data
int app_entry::display_all()
{
	cout << "\n<<application name>> : " << app_name << endl;
	cout << "<<key words>> : " << key_word << endl;
	cout << "<<description>> : " << description << endl;
	cout << "<<rating>> : " << rating << endl << endl;
	
	return 1;
}


//this function prompts to user to add more key words
bool app_entry::again()
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