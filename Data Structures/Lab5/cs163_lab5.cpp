#include "cs163_list.h"
using namespace std;

int main()
{
    node * head = NULL;
	node * head2 = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
	// insert_after(head);
	
	// insert_before(head);
	
	//display_last_two(head);
	// remove_last_two(head);
    
	if(same_length(head, head2))
		cout << "Same length!" << endl;
	else
		cout << "not the same length" << endl;
	
	display(head);
    
    return 0;
}
