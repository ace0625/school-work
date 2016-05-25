#include "cs163_list.h"
using namespace std;

int main()
{
    
    //First try this out as is. Then start adding in your function calls!
    list my_list;
    list new_list;
    my_list.build();
    my_list.display_all();
    //PLACE YOUR FUNCTION CALL HERE!
    // TOTAL fuction
   //  cout << "total sum = " << my_list.sum_total() << endl;
    // Recursive total
    cout << "\nffffffrecursive total = " << my_list.sum_total() << endl;
    
    //remove  last  & Recursive remove last
    if(my_list.remove_last() == true)
    {
	cout << "\n\nRemove last complete" << endl << endl;
    }
    else
      cout << "\n\nRemove last failed" << endl << endl;
      
    my_list.display_all();

    //remove all & remove all recursively
  /*  if(my_list.remove_all() == true)
           cout << "Remove all complete" << endl;
    else 
	 cout << "Remove last failed" <<endl;
*/

     //find item
     int find = 0;
     cout << "\nEnter an item to find : ";
     cin >> find;
     if(my_list.find_item(find) == true)
	cout << "\nItem " << find << " has been found!" << endl << endl;
     else
	cout << "\nThere's no item " << find << endl << endl;

    //copy 
    if(new_list.copy(my_list) == true)
	cout << "\nCopy list complete!\n " << endl;
    else
	cout << "\nCopy list failed!\n " << endl;


    cout << "new copy list: " << endl;
    new_list.display_all();	

    cout << "original list: " << endl; 
    my_list.display_all();
    return 0;    
}
