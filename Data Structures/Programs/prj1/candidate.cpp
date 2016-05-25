//CS163
//Program #1
//10/14/2015
//Hyunchan Kim
//candidate.cpp

//This file Implements the Abstract Data Type

#include "candidate.h"

/*
Default constructor
*/
candidate::candidate()
{
	first_name = NULL;
	last_name = NULL;
	view1 = NULL;
	view2 = NULL;
	view3 = NULL;
	view4 = NULL;
	view5 = NULL;
	rank = 0;
	thoughts = NULL;
}
/*
Default desctructor
*/
candidate::~candidate()
{
	if(first_name)
		first_name = NULL;
	if(last_name)
		last_name = NULL;
	if(view1)
		view1 = NULL;
	if(view2)
		view2 = NULL;
	if(view3)
		view3 = NULL;
	if(view4)
		view4 = NULL;
	if(view5)
		view5 = NULL;
	if(rank)
		rank = 0;
	if(thoughts)
		thoughts = NULL;
}


//This function creates a candidate information
int candidate::create_candidate(char * firstname, char * lastname, char * a_view1, char * a_view2, char * a_view3, char * a_view4, char * a_view5, int a_rank, char * a_thoughts)
{
	
	first_name = new char[strlen(firstname) + 1];
	strcpy(first_name, firstname);
	
	last_name = new char[strlen(lastname) + 1];
	strcpy(last_name, lastname);
	
	view1 = new char[strlen(a_view1) + 1];
	strcpy(view1, a_view1);
	
	view2 = new char[strlen(a_view2) + 1];
	strcpy(view2, a_view2);
	
	view3 = new char[strlen(a_view3) + 1];
	strcpy(view3, a_view3);
	
	view4 = new char[strlen(a_view4) + 1];
	strcpy(view4, a_view4);
	
	view5 = new char[strlen(a_view5) + 1];
	strcpy(view5, a_view5);
	
	rank = a_rank;
	
	thoughts = new char[strlen(a_thoughts) + 1];
	strcpy(thoughts, a_thoughts);
	
	return 1;
}

//This is a copy constructor that copies candidate's information
int candidate::copy_candidate(const candidate & copy_from)
{
	if(copy_from.first_name)
	{
		first_name = new char[strlen(copy_from.first_name) + 1];
		strcpy(first_name, copy_from.first_name);
	}
	if(copy_from.last_name)
	{
		last_name = new char[strlen(copy_from.last_name) + 1];
		strcpy(last_name, copy_from.last_name);
	}
	if(copy_from.view1)
	{
		view1 = new char[strlen(copy_from.view1) + 1];
		strcpy(view1, copy_from.view1);
	}
	if(copy_from.view2)
	{
		view2 = new char[strlen(copy_from.view2) + 1];
		strcpy(view2, copy_from.view2);
	}
	if(copy_from.view3)
	{
		view3 = new char[strlen(copy_from.view3) + 1];
		strcpy(view3, copy_from.view3);
	}
	if(copy_from.view4)
	{
		view4 = new char[strlen(copy_from.view4) + 1];
		strcpy(view4, copy_from.view4);
	}
	if(copy_from.view5)
	{
		view5 = new char[strlen(copy_from.view5) + 1];
		strcpy(view5, copy_from.view5);
	}
	if(copy_from.rank)
	{
		rank = copy_from.rank;
	}
	if(copy_from.thoughts)
	{
		thoughts = new char[strlen(copy_from.thoughts) + 1];
		strcpy(thoughts, copy_from.thoughts);
	}
	
	return 1;
}

// Retrieve a candidate's information by last name
int candidate::retrieve(char * keyword, candidate & found)
{
	if(!first_name || !last_name || !view1 || !view2 || !view3 || !view4 || !view5)
		return 0;
	
	if(strcmp(last_name, keyword))
		return 0;
	
	if(first_name)
	{
		found.first_name = new char[strlen(first_name) + 1];
		strcpy(found.first_name, first_name);
	}
	if(last_name)
	{
		found.last_name = new char[strlen(last_name) + 1];
		strcpy(found.last_name, last_name);
	}
	if(view1)
	{
		found.view1 = new char[strlen(view1) + 1];
		strcpy(found.view1, view1);
	}
	if(view2)
	{
		found.view2 = new char[strlen(view2) + 1];
		strcpy(found.view2, view2);
	}
	if(view3)
	{
		found.view3 = new char[strlen(view3) + 1];
		strcpy(found.view3, view3);
	}
	if(view4)
	{
		found.view4 = new char[strlen(view4) + 1];
		strcpy(found.view4, view4);
	}
	if(view5)
	{
		found.view5 = new char[strlen(view5) + 1];
		strcpy(found.view5, view5);
	}
	if(rank)
		found.rank = rank;
	
	if(thoughts)
	{
		found.thoughts = new char[strlen(thoughts) + 1];
		strcpy(found.thoughts, thoughts);
	}
	
	return 1;
	
}

//Display a candidate's information
int candidate::display()
{
	cout << "\n-> Name : " << first_name << " " << last_name << endl;
	cout << "-> Major views : " << endl;
	cout << "\t\t1. " << view1 << endl;
	cout << "\t\t2. " << view2 << endl;
	cout << "\t\t3. " << view3 << endl;
	cout << "\t\t4. " << view4 << endl;
	cout << "\t\t5. " << view5 << endl;
	cout << "-> Number of Poll : " << rank << endl;
	cout << "-> Thoughts : " << thoughts << endl << endl;
	
	return 1;
}

//add a poll
void candidate::add_poll()
{
	++rank;
	
}

//add your thoughts
void candidate::add_thoughts(char * a_thought)
{
	thoughts = a_thought;
}

//this function prompts to user to add more key words
bool candidate::again()
{
	char response;
	cout << "Would you like to add more candidate? (Y/N): ";
	cin >> response;
	cin.ignore(100, '\n');
	if (toupper(response) == 'Y')
		return true;
	else
		return false;
}


//============================================================================================
//list part
//============================================================================================


//default constructor
list::list()
{
	head = NULL;
	number_of_candidate = 0;
}


//default destructor
list::~list()
{
	if (head)
	{
		node * temp;
		while (head)
		{
			temp = head->next;
			delete head;
			head = temp;
		}
	}
	
	number_of_candidate = 0;
}


//insert a candidate to a linear linked list
int list::insert(candidate & to_add)
{
	//when head is null
   if(!head)
   {
		head = new node;
		head->a_candidate.copy_candidate(to_add);
		head->next = NULL;
   }
   //else
   else
   {
	   node * current = head;
	   while(current->next)
	   {
		   current = current->next;
	   }
	   current->next = new node;
	   current = current->next;
	   current->a_candidate.copy_candidate(to_add);
	   current->next = NULL;
   }
   
   ++number_of_candidate; //number of candidates
   return 1;
}

//update the poll to the particular candidate you choose
int list::update_poll(char * name, candidate & found)
{ 
	//if head is null
	if(!head)
		return 0;
    
    node * current = head;
    while(current)
    {
		if(current->a_candidate.retrieve(name, found))
		{
			current->a_candidate.add_poll();
			current->a_candidate.display();
			return 1;
		}
		current = current->next;
    }
    return 0;
}

int list::update_information(char * findbylastname, char * a_thought, candidate & found)
{
	
	//if head is null
	if(!head)
		return 0;
    
    node * current = head;
    while(current)
    {
		if(current->a_candidate.retrieve(findbylastname, found))
		{	
			current->a_candidate.add_thoughts(a_thought);
			current->a_candidate.display();
			
			return 1;
		}
		current = current->next;
    }
    return 0;
}

//Display all candidates' information
int list::display_all(void)
{
	if(!head)
		return 0;

    node * current = head;
    while(current)
    {
		current->a_candidate.display();
		current = current->next;
    }
    return 1;	

}

