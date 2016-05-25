#include "cs163_2-3.h"
using namespace std;

int main()
{
    table trees;
    trees.build();
    trees.display();

    /*  PLACE YOUR FUNCTION CALL HERE */
	cout << "========= Display all leaves ============" << endl;
	trees.display_23();
	cout << "\n========= Find largest ============" << endl;
	cout << trees.find_largest() << endl;
	cout << endl;
    return 0;
}
