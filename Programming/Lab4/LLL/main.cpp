#include "list.h"
using namespace std;

int main()
{
    int find;
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    cout << "Please enter a number to find num_times: ";
    cin >> find;
    cout << "We found " <<  num_times(head, find) << " times. " << endl;

    display_first_last_wrap(head);
    //if(remove_except(head))
    //cout << "remove_except success" << endl;
    remove_except(head);

    display(head);
    destroy(head);
    
    return 0;
}
