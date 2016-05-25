#include "list.h"
using namespace std;
int num_times(node * head, int match)
{
/*
    int cnt = 0;
    if(!head)
        return 0;
    if(head->data == match)
    {
        cnt = 1+ num_times(head->next, match);
    }
    else
        num_times(head->next, match);

    return cnt;
*/

   if(!head) return 0;
   if(head->data == match)
	return num_times(head->next, match) + 1;
   else
       return num_times(head->next, match);
}

int display_first_last_wrap(node * head)
{
   if(!head || !head->next) return 0;
   cout << "first: " << head->data << endl;
    cout << "Sum : " << head->data + display_first_last(head) << endl;
}

int display_first_last(node * head)
{
  if(!head->next)
  {
	cout << "last: " << head->data << endl;
	return head->data;
  } 
  return display_first_last(head->next);
}

bool remove_except(node * & head)
{
	// if(!head || !head->next)
	// 	return false;
	// else
	// {
	// 	node * current = head;
	// 	if(current->next->next)
	// 	{
	// 		remove_except(current->next);
	// 	delete current;
	// 		current = NULL;
			
	// 	}
	// }
	
	// return true;
    if(!head || !head->next || !head->next->next) 
      return false;
    else
    {
        delete head;
        head = NULL;
        return remove_except(head->next);      
    }

    return true;
}
