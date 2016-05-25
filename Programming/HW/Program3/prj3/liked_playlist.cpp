#include "liked_playlist.h"

cll_node::cll_node
{
	
}

cll_node::~cll_node
{
	
}

cll_node * & cll_node::go_next()
{
	return next;
}



liked_playlist::liked_playlist()
{
	rear = NULL;
}

liked_playlist::~liked_playlist()
{
	
}


int liked_playlist::add_to_liked_list(cll_node * & rear, int song_no_to_add)
{
	if(!rear)
	{
		rear = new cll_node;
		//add data here
		rear->go_next() = rear;
		return 1;
	}
	else
	{
		cll_node * temp = head;
		while(temp->go_next() != rear)
			temp = temp->go_next();
		temp->go_next() = new cll_node;
		//data add temp-->go_next()->data = add;
		temp->go_next()->go_next() = rear;
		
		return 1;
	}	
}
int liked_playlist::remove_from_liked_list(cll_node * & rear, int song_no_to_delete)
{
	
}

int liked_playlist::remove_all_list(cll_node * & rear)
{
	if(!rear)
		return 0;
	if(rear->next = rear)
	{
		delete rear;
		rear = NULL;
	}
	else
	{
		remove_all_list(rear->next);
		delete rear;
		rear = NULL;
	}
	return 1;
}

int liked_playlist::display_all_liked_list()
{
	
}
