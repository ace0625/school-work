#ifndef _LIKED_PLAYLIST_H
#define _LIKED_PLAYLIST_H

#include "song_entry.h"
#include "string.h"

class cll_node: public song_entry
{
	public:
		cll_node();
		~cll_node();
		cll_node *& go_next();
	protected:
		song_entry * entry;
		cll_node * next;
};


class liked_playlist : public cll_node
{
	public:
		liked_playlist();
		~liked_playlist();
		int add_to_liked_list(int song_no_to_add);
		int add_to_liked_list(cll_node * & rear, int song_no_to_add);
	//	int remove_from_liked_list(int song_no_to_delete);
		int remove_from_liked_list(cll_node * & rear, int song_no_to_delete);
		int remove_all_list(cll_node * & rear);
		int display_all_liked_list();
		
	protected:
		cll_node * rear;
};


#endif