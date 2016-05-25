// CS202
// Program #1
// school.cpp

#include "school.h"

/*
	default constructor implementation
*/
school::school() : head(NULL) {}

/*
	destructor implementation
*/
school::~school()
{
	remove_all();
}

/*
	remove all data in DLL
*/
void school::remove_all()
{
	dll_node * current = head;
	while(current)
	{
		current = current->go_next();
		delete head;
		head->go_prev() = NULL;
		head = current;
	}
	head = NULL;
	current = NULL;
}

/*
	read in an external file "school.txt"
*/
int school::load_school_data()
{
	char school_name[100];
	char age[100];
	char class_num[100];
	char best_size[100];
	char ave_size[100];

    ifstream file;
    file.open("school.txt");
    if(file)
    {
        while(!file.eof())
        {
            file.getline(school_name,100,'\n');
            file.getline(age,100,'\n');
            file.getline(class_num,100,'\n');
            file.getline(best_size,100,'\n');
            file.getline(ave_size,100,'\n');
            file.ignore(100, '\n');
            add_school(school_name, age, class_num, best_size, ave_size);
        }

    }
    file.close();
    return 1;
}

/*
	This is add_school method that creates a school data to DLL
*/
int school::add_school(char * a_name, char * a_age, char * a_class_num, char * best_size, char * ave_size)
{
	dll_node * new_node = new dll_node(a_name, a_age, a_class_num, best_size, ave_size);
	new_node->go_next() = new_node->go_prev() = NULL;
	if(!head)
        head = new_node;
    else
    {
        dll_node * current = head;
        while(current->go_next())
            current = current->go_next();

        current->go_next() = new_node;
        new_node->go_prev() = current;
    }
    return 1;
}

/*
	remove an item by postion number
*/
// int school::remove(int pos)
// {
// 	int l = get_length();
// 	if(pos > l)
// 	{
// 		cout << "Nothing to delete" << endl;
// 		return 0;
// 	}
// 	else
// 	{
// 		dll_node * current = head;
// 		int cnt = 1;
// 		while(cnt != pos)
// 		{
// 			current->display_school();
// 			current = current->go_next();
// 			++cnt;
// 		}
// 		if(!current->go_next()) // when it's the last node
// 		{
// 			dll_node * temp = current->go_prev();
// 			delete current;
// 			temp->go_next() = NULL;
// 			return 1;
// 		}
// 		if(!current->go_prev()) //when it's the first node
// 		{
// 			dll_node * temp = current->go_next();
// 			delete current;
// 			head = temp;
// 			return 1;
// 		}
// 		else //when it's in the middle
// 		{
// 			dll_node * temp = current->go_prev();
// 			temp->go_next() = current->go_next();
// 			delete temp;
// 		}
// 	}
// 	return 1;
// }


/*
	get the length of the list.
*/
int school::get_length()
{
	int num = 1;
	dll_node * current = head;
	while(current->go_next())
	{
		current = current->go_next();
		num++;
	}
	return num;
}


/*
	find appropriate school information
*/
int school::retrieve_school()
{
	int cnt = 1;
	dll_node * current = head;
	while(current && (cnt != 4))
	{
		current->display_school();
		current = current->go_next();
		cnt++;
	}
	return 1;
}

/*
	Display all school data in the doubly linked list
*/
int school::display_all()
{
	if(!head)
	{
		cout << "Empty data" << endl;
		return 0;
	}

	dll_node * current = head;
	while(current)
	{
		current->display_school();
		current = current->go_next();
	}
	return 1;
}






















