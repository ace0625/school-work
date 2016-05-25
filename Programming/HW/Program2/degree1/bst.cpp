#include <iostream>
#include <cstdlib>
#include "bst.h"
using namespace std;

// class - snode ****************************
// constructor - snode for a linear linked list
snode::snode()
{
	cout << "snode::snode()" << endl;
	next = NULL;
}


snode::~snode()
{
	cout << "snode::~snode()" << endl;
}

snode::snode(sclass* a_sclass): sclass(a_sclass)
{}

snode::snode(char* a_course_type, int a_course_code, int a_course_term, char* a_course_grade): sclass(a_course_type, a_course_code, a_course_term, a_course_grade)
{}

// snode move to next
snode *& snode::go_next()
{
	return next;
}

bool snode::if_next()
{
	if(next) return true;
	else return false;
}

void snode::display_snode()
{
	display_sclass();
}

int snode::retrieve(const char* a_course_type, int a_course_code)
{
	if(course_type == a_course_type && course_code == a_course_code)
		return 1;
	else
		return 1;
}

// class - bst_node ****************************
// constructor - bst_node for binary search tree
bst_node::bst_node()
{
	cout << "bst_node::bst_node() *******" << endl;
	left = right = NULL;
}


bst_node::~bst_node()
{
	cout << "bst_node::~bst_node()" << endl;
	delete left;
	delete right;
	left = right = NULL;
}

bst_node::bst_node(const int a_term): term(a_term)
{}

// bst_node move to left
bst_node *& bst_node::go_left()
{
	return left;
}

// bst_node move to right
bst_node *& bst_node::go_right()
{
	return right;
}

bool bst_node::if_left()
{
	if(left) return true;
	else return false;
}

bool bst_node::if_right()
{
	if(right) return true;
	else return false;
}

void bst_node::display_bst()
{
	if(!head) return;
	snode* temp = head;
	while(temp) {
		temp->display_snode();
		temp = temp->go_next();
	}
}

int bst_node::get_term()
{
	return term;
}

int bst_node::compare(int a_term)
{
	if(term == a_term)	return 0;
	else if(term > a_term) return -1;
	else return 1;
}

void bst_node::set_term(int a_term)
{
	term = a_term;
}

// check match term 
bool bst_node::match_term(const int a_term)
{
	if(term == a_term) return true;
	else return false;
}

// add lll node
void bst_node::add_snode(int a_term, sclass* a_sclass)
{
	if(!head) {
		term = a_term;
		head = new snode(a_sclass);
	}
	else {
		term = a_term;
		snode* temp = new snode(a_sclass);
		temp->go_next() = head;
		head = temp;
	}
	
}

// class - bst ****************************
// constructor for bst class
bst::bst()
{
	root = NULL;
}

// destructor for bst class
bst::~bst()
{
	remove_all();
	delete root;
}

void bst::add(int a_term, sclass* a_sclass)
{
	// if term is exist, add LLL node
	if(!find_add(root, a_term, a_sclass))
		add_bst_node(root, a_term, a_sclass);
}

int bst::find_add(bst_node* root, int a_term, sclass* a_sclass)
{
	if(!root) return 0;
	cout << "**************root->get_term():" << root->get_term();
	cout << " a_term():" << a_term << endl;
	if(root->get_term() == a_term) {
		root->add_snode(a_term, a_sclass);
		return 1;
	}
	else {
		return find_add(root->go_left(), a_term, a_sclass) + find_add(root->go_right(), a_term, a_sclass);
	}
}

// add bst node
void bst::add_bst_node(bst_node*& root, const int a_term, sclass* a_sclass)
{
	if(!root) {
		root = new bst_node;
		//root->set_term(a_term);
		root->add_snode(a_term, a_sclass);
		root->go_left() = root->go_right() = NULL;
	}
	else if(compare(a_term, root->get_term()) < 0)
		add_bst_node(root->go_left(), a_term, a_sclass);
	else
		add_bst_node(root->go_right(), a_term, a_sclass);
}

int bst::compare(const int a_term, const int b_term)
{
	if(a_term == b_term)	return 0;
	else if(a_term > b_term) return -1;
	else return 1;
}

void bst::remove(const int a_term)
{
	remove(root, a_term);
}

void bst::remove(bst_node* &root, const int a_term)
{
	if(!root) return;
	
	cout << "a_term:" << a_term << "; get_term():" << root->get_term() << endl;
	if(compare(a_term, root->get_term()) == 0) {
		cout << "test1************" << endl;
		// 1. no child
		if(!root->go_left() && !root->go_right()) {
			delete root;
			root = NULL;
		}
		// 2-1. one child on left
		else if(root->go_left() && !root->go_right()) {
			bst_node* temp = root;
			root = root->go_left();
			delete temp;
		}
		// 2-2. one child on right
		else if(!root->go_left() && root->go_right()) {
			bst_node* temp = root;
			root = root->go_right();
			delete temp;
		}
		// 3. two child
		else {
			// 3.1 
			bst_node* is = root->go_right();
			bst_node* is_pa = root->go_right();
			
			while(is->go_left()) {
				is_pa->set_term(is->get_term());
				is = is->go_left();
			}
			
			// replace data root from IS (inorder successor)
			root->set_term(is->get_term());

			// 3.1 IS has no left child
			if(is == is_pa) {
				root->go_right() = is->go_right();
			}
			else {
				// 3.2 IS has right child
				if(is->go_right())
					is_pa->go_left() = is->go_right();
				else
					is_pa->go_left() = NULL;
			}
			
			delete is;
			is = NULL;

			return;
		}
	}
//	else if(data < root->data) {
	else if(compare(a_term, root->get_term()) < 0) {
		return remove(root->go_left(), a_term);
	}
	else {
		return remove(root->go_right(), a_term);
	}
}

void bst::display_all()
{
	display_all(root);
}

void bst::display_all(bst_node* root)
{
	if(!root) return;

	display_all(root->go_left());
	root->display_bst();
	//root->display_snode();
	display_all(root->go_right());
}

int bst::remove_all()
{
	int result = remove_all(root);
	cout << "remove_all: " << result << endl;
	return 1;
}

int bst::remove_all(bst_node * & root)
{
	if(!root) return 0;
	int val = remove_all(root->go_left()) + remove_all(root->go_right()) + 1;
	delete root;
	root = NULL;
	return val;	
}

