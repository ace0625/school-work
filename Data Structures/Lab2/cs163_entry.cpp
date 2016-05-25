#include "cs163_entry.h"


//Step #2: Implement this function
//This function takes the argument and copies it into
//the journal's data members
int journal_entry::copy_entry(const journal_entry & copy_from)
{

       //Place your code here
	int result = 0;

	if(copy_from.title)
	{
	   title = new char[strlen(copy_from.title) + 1];
	   strcpy(title, copy_from.title);
	   result = 1;	   
	}
	if(copy_from.notes)
	{
	   notes = new char[strlen(copy_from.notes) + 1];
	   strcpy(notes, copy_from.notes);
	   result = 1;	   
	}
	return result;


}


//Step #2: Implement this function
//This function will return non-zero if the title sent
//in as an argument matches the data member. It supplies
//the matching journal back as an argument
int journal_entry::retrieve(char * matching_title, journal_entry & found)
{

      //Pilace your code here
	if(!title || !matching_title)
	    return 0;

	if(!strcmp(title, matching_title))
	    return 0;
	if(title)
	{
	   found.title = new char[strlen(title) + 1];
	   strcpy(found.title, title);
	}
	if(notes)
	{
	   found.notes = new char[strlen(title) + 1];
	   strcpy(found.notes, notes);
	}
	
	return 1;
}

