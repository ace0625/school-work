//CS163
//Assignment #4
//Hyunchan Kim
//bst.cpp


//This is bst.cpp that implements binary search tree 
#include "bst.h"


//default constructor
bst::bst()
{
	root = NULL;
}

//default destructor
bst::~bst()
{
	remove_all();
}

//read an external data file into binary search tree
int bst::build()
{
	const int MAX_LINE_LEN = 500;
	const int MAX_TOKEN = 6;
	const char* const DELIM = ";";

	ifstream fin; //file input
	ofstream fout; //file output
	
	fin.open("data.txt");  //open up the file
	if(fin.fail()) 
		return 0;

	char *number, *concept, *data_structure, *advantage, *disadvantage;
	//read data line by line
	while(!fin.eof()) 
	{
		char buff[MAX_LINE_LEN];
		fin.getline(buff, MAX_LINE_LEN);

		const char* token[MAX_TOKEN] = {};

		token[0] = strtok(buff, DELIM);
		if(!token[0]) break;
		
		for(int i = 1; i < MAX_TOKEN; i++) 
		{
			token[i] = strtok(0, DELIM);
		}
			
		number = new char[strlen(token[0]) + 1];
		strcpy(number, token[0]);
		
		concept = new char[strlen(token[1]) + 1];
		strcpy(concept, token[1]);

		data_structure  = new char[strlen(token[2]) + 1];
		strcpy(data_structure, token[2]);

		advantage = new char[strlen(token[3]) + 1];
		strcpy(advantage, token[3]);

		disadvantage = new char[strlen(token[4]) + 1];
		strcpy(disadvantage, token[4]);
	
	
	// cout << "\n----------------------------------------" << endl;
	// cout << number  << ". " << concept << endl;
	// cout << "\ta. " << data_structure << endl;
	// cout << "\tb. " << advantage << endl;
	// cout << "\tc. " << disadvantage << endl;
	// cout << "----------------------------------------" << endl << endl;
	
		node * temp = new node;
		if(!temp->entry.create_entry(number, concept, data_structure, advantage, disadvantage)) //if copy entry returns 0
		{
			delete temp; //deallocate temp pointer
			return 0;
		}
		insert(number, temp->entry);
		// cout << "insert" << endl;
		
	}
	fin.close(); //close the file

	return 1;
}

//insert to BST wrapper
int bst::insert(char * key_word, const concept_entry & to_add)
{
	return insert(root, key_word, to_add);
}

//insert to BST 
int bst::insert(node * & root, char * key_word, const concept_entry & to_add)
{
	if(!root) 
	{
		root = new node;
		root->entry.copy_entry(to_add);
		root->left = root->right = NULL;
	}
	else if(root->entry.str_compare(key_word) > 0)
		return insert(root->left, key_word, to_add);
	else
		return insert(root->right, key_word, to_add);
	
	return 1;
}

int bst::retrieve(char * keyword_to_find)
{
	return retrieve(root, keyword_to_find);
}
int bst::retrieve(node * root, char * keyword_to_find)
{
	if(!root)
		return 0;
	
	if(root->entry.str_compare(keyword_to_find) == 0)
	{
		cout << "\nThe matching data detected" << endl;
		root->entry.display_all();
		return 1;
	}
	else if(root->entry.str_compare(keyword_to_find) > 0)
		return display(root->left, keyword_to_find);
	else
		return display(root->right, keyword_to_find);
	
	return 0;
}

//display function by key word wrapper
int bst::display(char * key_word)
{
	return display(root, key_word);
}
//display function  by key word
int bst::display(node * & root, char * key_word)
{
	if(!root)
		return 0;
	
	if(root->entry.str_compare(key_word) == 0)
	{
		cout << "\n>>>>>>>>> We found the data <<<<<<<<<" << endl;
		root->entry.display_all();
		return 1;
	}
	else if(root->entry.str_compare(key_word) > 0)
		return display(root->left, key_word);
	else
		return display(root->right, key_word);
	
	return 0;
	
}

//display all BST wrapper
int bst::display_all_bst()
{
	return display_all_bst(root);
}
//display all BST 
int bst::display_all_bst(node * root)
{
	if(!root)
		return 0;
	
	display_all_bst(root->left);
	root->entry.display_all();
	display_all_bst(root->right);
	
	return 1;
}

//display concept name wrapper
int bst::display_concept()
{
	return display_concept(root);
}

//display concept name function
int bst::display_concept(node * root)
{
	if(!root)
		return 0;
	
	display_concept(root->left);
	root->entry.display_concept();
	display_concept(root->right);
	
	return 1;
}

//Remove all data in BST wrapper 
int bst::remove_all()
{
	return remove_all(root);
}
//Remove all data in BST 
int bst::remove_all(node * & root)
{
	if(!root) 
		return 0;

	int val = remove_all(root->left) + remove_all(root->right) + 1;
	//delete root->entry;
	delete root;
	root = NULL;
	return val;
}