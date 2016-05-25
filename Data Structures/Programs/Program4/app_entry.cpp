//CS163
//Assignment #4
//Hyunchan kim

//app_entry.cpp

//This class is implementing for application entry
//that create a phone application, copy, retrieve, and display.

#include "app_entry.h"

//app entry default constructor
app_entry::app_entry()
{
	application_name = NULL;
	// for(int i = 0; i < 5; i++)
	// {
		// key_word[i] = NULL;
	// }
	key_word = NULL;
    description = NULL;
	rating = 0.0;
}

//app entry default destructor
app_entry::~app_entry()
{
	if(application_name)
		delete application_name;
	// for(int i = 0; i < 5; i++)
	// {
		// if(key_word[i])
			// key_word[i] = NULL;
	// }
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
	if(!an_app_name || !a_key_word || !a_description || !a_rating) //if any of the data has not come in
		return 0;
	
	if(application_name)
		delete application_name;
	if(key_word)
		delete key_word;
	if(description)
		delete description;
	if(rating)
		rating = 0.0;
	
	application_name = new char[strlen(an_app_name) + 1];
	strcpy(application_name, an_app_name);
	
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
	if(copy_from.application_name)
	{
		application_name = new char[strlen(copy_from.application_name) + 1];
		strcpy(application_name, copy_from.application_name);
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

		found.application_name = new char[strlen(application_name) + 1];
		strcpy(found.application_name, application_name);

		found.description = new char[strlen(description) + 1];
		strcpy(found.description, description);

		found.rating = rating;

	//cout << "entry retrieve" << endl;
	return 1;
}

//This function displays all application data
int app_entry::display_all()
{
	cout << "\n----------------------------------------" << endl;
	cout << "-- <<application name>> : " << application_name << endl;
	cout << "-- <<key words>> : " << key_word << endl;
	cout << "-- <<description>> : " << description << endl;
	cout << "-- <<rating>> : " << rating << endl;
	cout << "----------------------------------------" << endl << endl;
	return 1;
}


// String compare
int app_entry::str_compare(const char* s2)
{
	int result = 0;
	int slen = strlen(key_word);
	if(strlen(key_word) > strlen(s2))
		slen = strlen(s2);
	for(int i = 0; i < slen; i++) 
	{
		if(key_word[i] == s2[i]) {
			result = 0;
			continue;
		}
		else if(key_word[i] > s2[i]) {
			result = 1;
			break;
		}
		else {
			result = -1;
			break;
		}
	}

	// String length compare
	if(result == 0) {
		if(strlen(key_word) == strlen(s2)) 
			return 0;
		else if(strlen(key_word) > strlen(s2)) 
			return 1;
		else 
			return -1;
	}
	return result;
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