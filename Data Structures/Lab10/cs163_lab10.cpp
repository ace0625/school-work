#include "cs163_tree.h"
using namespace std;

int main()
{
    table trees, tree_copy;
    trees.build();
    trees.display();
	
    /*  PLACE YOUR FUNCTION CALL HERE */
	trees.display_largest();
	
	cout << "STEP2 : count root : " << trees.count_root() << endl;
	
	tree_copy.copy(trees);
	cout << "STEP3 : COPY TREE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> " << endl;
	tree_copy.display();
	
	cout << "\nSTEP4 : count_3_data: " << trees.count_3_data() << endl;
	cout << "STEP 5 : 2-3-4 tree height: " <<trees.height() << endl;
	
	cout << "STEP6 : COPY 2-3-4 tree >>>>>>>>>>>>>>>>>>>" << endl;
	tree_copy.copy_234(trees);
	tree_copy.display();
    return 0;
}
