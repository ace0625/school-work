#include "cs163_bst.h"
using namespace std;

int main()
{
    table BST;	
	table BST_copy;
    BST.build();
    BST.display();

    /*  PLACE YOUR FUNCTION CALL HERE */
	cout << ">>>>count : " << BST.count() << endl;
	
	cout << ">>>>sum : " << BST.sum() << endl;
	
	cout << ">>>>height : " << BST.height() << endl;
	
//	cout << ">>>>remove_all : " << BST.remove_all() << " values removed " << endl;

	cout << ">>>>>BST copy : " << endl;
	BST_copy.copy(BST);
	
	BST_copy.display();
	
	

  //  BST.display();

    return 0;
}
