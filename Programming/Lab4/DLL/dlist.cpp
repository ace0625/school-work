#include "dlist.h"

void duplicate(node * & new_copy, node * original)
{

}



bool same_length(node * head1, node * head2)
{
        if(!head1 || !head2)
        {
                if(!head1 && !head2)
                        return true;
                else
                        return false;
        }
        return same_length(head1->next, head2->next);
}

