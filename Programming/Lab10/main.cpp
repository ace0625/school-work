#include "table.h"
using namespace std;

int main()
{
    table BST, BST2;	
    BST.build();
    BST.display();

    /*  PLACE YOUR FUNCTION CALL HERE */
	cout << "count the number of nodes: " << BST.count() << endl;
	cout << "count the number of nodes with no children: " << BST.count_leaf() << endl;
	// cout << "remove largest: " << BST.remove_largest() << endl;
	cout << "sum of all data: " << BST.sum() << endl;
	cout << "copy function: " << endl;
	BST2.copy(BST);
	cout << "BST2 here: " << endl;
	BST2.display();
	
	
	
    BST.display(0);

    return 0;
}
