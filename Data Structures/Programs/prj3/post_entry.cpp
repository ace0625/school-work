//CS163
//Assignment #3
//Hyunchan kim

//post_entry.cpp

//This class is implementing for post entry
//that create a post list, copy, retrieve, and display.

#include "post_entry.h"

//post entry default constructor
post_entry::post_entry()
{
	//cout << "post_entry()" << endl;
	name = NULL;
	date = NULL;
    content = NULL;
	likes = NULL;
	key_words = NULL;
}

//post entry default destructor
post_entry::~post_entry()
{
	//cout << "~app_entry()" << endl;
	if(name)
		delete name;
	if(date)
		delete date;	
	if(content)
		delete content;
	if(likes)
		delete likes;
	if(key_words)
		delete key_words;
	
}

//This function creates an post entry 
int post_entry::create_entry(char * a_name, char * a_date, char * a_content, char * a_like, char * a_key_words)
{
	//cout << "create entry" << endl;
	if(!a_name || !a_date || !a_content || !a_like || !a_key_words) //if any of the data has not come in
		return 0;
	
	if(name)
		delete name;
	if(date)
		delete date;	
	if(content)
		delete content;
	if(likes)
		delete likes;
	if(key_words)
		delete key_words;
	
	name = new char[strlen(a_name) + 1];
	strcpy(name, a_name);
	
	date = new char[strlen(a_date) + 1];
	strcpy(date, a_date);
	
	content = new char[strlen(a_content) + 1];
	strcpy(content, a_content);
	
	likes = new char[strlen(a_like) + 1];
	strcpy(likes, a_like);
	
	key_words = new char[strlen(a_key_words) + 1];
	strcpy(key_words, a_key_words);
	
	return 1;
}

//This function copies a post entry
int post_entry::copy_entry(const post_entry & copy_from)
{
	if(copy_from.name)
	{
		name = new char[strlen(copy_from.name) + 1];
		strcpy(name, copy_from.name);
	}
	if(copy_from.date)
	{
		date = new char[strlen(copy_from.date) + 1];
		strcpy(date, copy_from.date);
	}
	if(copy_from.content)
	{
		content = new char[strlen(copy_from.content) + 1];
		strcpy(content, copy_from.content);
	}
	if(copy_from.likes)
	{
		likes = new char[strlen(copy_from.likes) + 1];
		strcpy(likes, copy_from.likes);
	}
	if(copy_from.key_words)
	{
		key_words = new char[strlen(copy_from.key_words) + 1];
		strcpy(key_words, copy_from.key_words);
	}

	return 1;
}

//This function retrieves a post information by key word
int post_entry::retrieve(char * matching_keyword, post_entry & found)
{
		found.name = new char[strlen(name) + 1];
		strcpy(found.name, name);

		found.date = new char[strlen(date) + 1];
		strcpy(found.date, date);

		found.content = new char[strlen(content) + 1];
		strcpy(found.content, content);
		
		found.likes = new char[strlen(likes) + 1];
		strcpy(found.likes, likes);
		
		found.key_words = new char[strlen(key_words) + 1];
		strcpy(found.key_words, key_words);

	//cout << "entry retrieve" << endl;
	return 1;
}

//This function displays all application data
int post_entry::display_all()
{
	cout << "\n<<NAME>> : " << name << endl;
	cout << "<<DATE>> : " << date << endl;
	cout << "<<CONTENT>> : " << content << endl;
	cout << "<<LIKES>> : " << likes << endl;
	cout << "<<KEY WORDS>> : " << key_words << endl << endl;
	
	return 1;
}


//this function prompts to user to add more key words
bool post_entry::again()
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