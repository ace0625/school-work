/**
 * Kwangwoong Yang
 * CS163, [Program #3]
 *
 * "song_hash_table.cpp" - Song Hash Table Program File
 * This program implements a hash table.
 *  
 */
#include "song_table.h"
using namespace std;


lll_artist_node::lll_artist_node()
{
}

lll_artist_node::~lll_artist_node()
{}

lll_artist_node::lll_artist_node(song_entry & a_entry): song_entry(a_entry)
{}

lll_artist_node*& lll_artist_node::go_next()
{
	return next;
}



//=========================================================================
//song_hash_table functions

// constructor - initialize data member to NULL
song_hash_table::song_hash_table()
{
	const int TABLE_SIZE = 13;
	// Allocate the hash table and initialize each
	// element and data member.
	p_hash_table = new lll_artist_node * [TABLE_SIZE];
	song_hash_table_size = TABLE_SIZE;
	
	// initialize each element to NULL
	for(int i = 0; i < song_hash_table_size; i++) {
		p_hash_table[i] = NULL;
	}
	rear = NULL;

}

// destructor - deallocate memory
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

// get hash number
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


// Add Song to hash table - create entry, copy entry, insert_hash_table hash table
int song_hash_table::add_song_hash_table(int p_song_no, String p_song_title, String p_song_artitst, String p_song_genre)
{
	song_entry entry = song_entry(p_song_no, p_song_title, p_song_artitst, p_song_genre);

	// insert_hash_table entry to the table
	// get hash value
	int hash_val = hash(p_song_artitst);

	// create new node
	lll_artist_node* temp = new lll_artist_node(entry);
	temp->go_next() = p_hash_table[hash_val];
	p_hash_table[hash_val] = temp;
	
	return 1;
}

int song_hash_table::init_playlist()
{
	cout << "\n############# This is initial play list ###########" << endl << endl;
	int ran = 0; 
	srand(time(NULL));
	for(int i = 0; i < 60; i++)
	{
		ran = rand() % 60 + 1;
		display_by_song_num(ran);
	}
	return 1;
}

int song_hash_table::display_by_song_num(int song_no)
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
				current->song_entry::display_all();  //Output
				current = current->go_next();
			}
			else
				current = current->go_next();  //Traverse until the data is not valid
	  }
	}
	return 1;
}

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
					//add data here 
					rear = copy;
					rear->go_next() = rear;
					return 1;
				}
				else
				{
					lll_artist_node * copy = current;
					lll_artist_node * temp = new lll_artist_node;
					lll_artist_node * temp2 = rear->go_next();
					temp = copy;
					temp->go_next() = temp2;
					rear->go_next() = temp;
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
	while(rear->go_next() != rear)
	{
		rear->song_entry::display_all();
		rear = rear->go_next();
	}
	return 1;
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