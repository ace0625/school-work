//CS202
//Assignment #3
//Hyunchan Kim

//song_table.cpp

//This is the song_table.cpp file implementing all table functions such as 
//sorting by artist and adding songs to my favourite list

#include "song_table.h"
using namespace std;

//artist node constructor
lll_artist_node::lll_artist_node(){}

//artist node copy constructor
lll_artist_node::lll_artist_node(const lll_artist_node & copy): song_entry(copy){}

//artist node destructor
lll_artist_node::~lll_artist_node(){}

//artist node copy constructor
lll_artist_node::lll_artist_node(song_entry & a_entry): song_entry(a_entry){}

//artist node go next function
lll_artist_node*& lll_artist_node::go_next()
{
	return next;
}


//=========================================================================
//song_hash_table functions

// default table constructor which initialize all data and set table size
song_hash_table::song_hash_table()
{
	const int TABLE_SIZE = 13;
	song_ran_size = 12;

	p_hash_table = new lll_artist_node * [TABLE_SIZE];
	song_hash_table_size = TABLE_SIZE;
	
	// initialize each element to NULL
	for(int i = 0; i < song_hash_table_size; i++) 
	{
		p_hash_table[i] = NULL;
	}
}

// default destructor 
song_hash_table::~song_hash_table()
{
	// deallocate each element of hash table
	for(int i = 0; i < song_hash_table_size; i++) 
	{
		if(p_hash_table[i]) 
		{
			lll_artist_node* temp = p_hash_table[i];
			lll_artist_node* temp2 = p_hash_table[i];
			while(temp->go_next()) 
			{
				temp2 = temp->go_next();
				delete temp;
				temp = temp2;
			}
			temp = NULL;
		}
	}
	delete [] p_hash_table;
}

// hash function 
int song_hash_table::hash(String key_value) const
{
	int keyLen = key_value.getStrlen();
	int temp = 0;
	int sum = 0;

	for (int i = 0; i < keyLen; i++) 
	{
		temp = key_value.getCharP()[i];
		sum += temp;
	}
	return sum % song_hash_table_size;
}


// Add Song to hash table with a key value(artist) 
int song_hash_table::add_song_hash_table(int p_song_no, String p_song_title, String p_song_artitst, String p_song_genre[])
{
	song_entry entry = song_entry(p_song_no, p_song_title, p_song_artitst, p_song_genre);

	int hash_val = hash(p_song_artitst); //get an unique key value

	lll_artist_node* temp = new lll_artist_node(entry);
	temp->go_next() = p_hash_table[hash_val];
	p_hash_table[hash_val] = temp;
	return 1;
}

//Initial play list sorted random order
int song_hash_table::init_playlist()
{
	cout << "\n############# <<Initial play list>> ###########" << endl << endl;
	int ran = 0;
	srand(time(NULL));
	for(int i = 0; i < song_ran_size; i++)
	{
		ran = rand() % song_ran_size + 1;
		display_by_song_num(ran);
	}
	return 1;
}

//This function displays a song by song number
int song_hash_table::display_by_song_num(int song_no)
{
	for(int i = 0; i < song_hash_table_size; ++i)
	{
	  if(!p_hash_table[i]) //if table is empty
	  {}		 		   //do nothing
	  
	  lll_artist_node * current = p_hash_table[i]; 
	  while(current)  //While the data is still valid,
	  {
			if(current->song_entry::retrieve_by_song_no(song_no))//retrieve
			{
				current->song_entry::display_all();  //Output
				current = current->go_next();
			}
			else
				current = current->go_next();  //Traverse until the data is not valid
	  }
	}
	return 1;
}

//This function displays all data in the table
int song_hash_table::display_all_table()
{
	for(int i = 0; i < song_hash_table_size; ++i)
	{
	  if(!p_hash_table[i])
	  {
		  //If empty list, display nothing
	  }		 
	  
	  lll_artist_node * current = p_hash_table[i]; 
	  while(current)  //While the data is still valid,
	  {
		current->song_entry::display_all();  //Output
		current = current->go_next();  //Traverse until the data is not valid
	  }
	}
	
	return 1;
}

//Add a song to my favourite list 
int song_hash_table::add_to_cll(int song_no)
{
	return add_to_cll(rear, song_no);
}
//Add a song to my favourite list, wrapper function
int song_hash_table::add_to_cll(lll_artist_node*&rear, int song_no)
{
	for(int i = 0; i < song_hash_table_size; ++i)
	{
	  if(!p_hash_table[i]) //if table is empty
	  {}		 		   //do nothing
	  
	  lll_artist_node * current = p_hash_table[i]; 
	  while(current)  //While the data is still valid,
	  {
			if(current->song_entry::retrieve_by_song_no(song_no))//Output
			{
				if(!rear)
				{
					lll_artist_node * copy = current;
					rear = new lll_artist_node;
					rear = copy;
					rear->go_next() = rear;
					return 1;
				}
				else
				{
					lll_artist_node * newNode = new lll_artist_node;
					newNode = current;
					newNode->go_next() = rear->go_next();
					rear->go_next() = newNode;
					rear = newNode;
					return 1;
				}
			}
			else
				current = current->go_next();  //Traverse until the data is not valid
	   }
	  
	}
	return 0;	
}

//Display all songs from my favourite list
int song_hash_table::display_cll()
{
	return display_cll(rear);
}
//Display all songs from my favourite list, wrapper function
int song_hash_table::display_cll(lll_artist_node * rear)
{
	if(!rear) return 0;
	
	lll_artist_node * temp = rear;
	temp->song_entry::display_all();
	temp = temp->go_next();

	while(temp != rear) 
	{
		temp->song_entry::display_all();
		temp = temp->go_next();
	}
	return 1;
}


//Remove all songs in my favourite list by song number
int song_hash_table::remove_to_cll(int song_no)
{
	return remove_to_cll(rear, song_no);
}

//Remove all songs in my favourite list by song number, wrapper function
int song_hash_table::remove_to_cll(lll_artist_node*&rear, int song_no)
{
	if(!rear) return 0;

	if(rear->go_next() == rear) 
	{
		if(rear->song_entry::retrieve_by_song_no(song_no)) 
		{
			delete rear;
			rear = NULL;
		}
	}
	lll_artist_node * prev = rear;
	lll_artist_node * temp = rear->go_next();
	while(temp != rear) 
	{
		if(temp->song_entry::retrieve_by_song_no(song_no)) 
		{
			if(temp == rear) rear = prev;
			prev->go_next() = temp->go_next();
			delete temp;
			temp = NULL;
			break;
			return 1;
		}
		prev = temp;
		temp = temp->go_next();
	}
	return 0;
}


//Remove all songs from my favourite list
int song_hash_table::remove_all_cll()
{
	return remove_all_cll(rear);
}
//Remove all songs from my favourite list, wrapper function
int song_hash_table::remove_all_cll(lll_artist_node * rear)
{
	if(!rear)
		return 0;
	if(rear->go_next() = rear)
	{
		delete rear;
		rear = NULL;
	}
	else
	{
		remove_all_cll(rear->go_next());
		delete rear;
		rear = NULL;
	}
	return 1;
}