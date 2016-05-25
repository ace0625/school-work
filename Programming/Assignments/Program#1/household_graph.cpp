// CS202
// Program #1
// household_graph.cpp

#include "household_graph.h"

/*
	This is household default constructor implementation
*/
household::household() : region(NULL), race(NULL), income(NULL), age_group(NULL) {}


/*
	household destructor implementation
*/
household::~household()
{
	// if(region)
	// 	delete [] region;
	// if(race)
	// 	delete [] race;
	// if(income)
	// 	delete [] income;
	// if(age_group)
	// 	delete [] age_group;
}

/*
	copy constructor implementation with region, race, income, age group information
*/
household::household(char * a_region, char * a_race, char * a_income, char * a_age_group)
{
	region = new char[strlen(a_region) + 1];
	strcpy(region, a_region);
	race = new char[strlen(a_race) + 1];
	strcpy(race, a_race);
	income = new char[strlen(a_income) + 1];
	strcpy(income, a_income);
	age_group = new char[strlen(a_age_group) + 1];
	strcpy(age_group, a_age_group);
}


/*
	copy constructor implementation with household information
*/
household::household(const household & copy_info)
{
	if(copy_info.region)
	{
		region = new char[strlen(copy_info.region) + 1];
		strcpy(region, copy_info.region);
	}
	if(copy_info.race)
	{
		race = new char[strlen(copy_info.race) + 1];
		strcpy(race, copy_info.race);
	}
	if(copy_info.income)
	{
		income = new char[strlen(copy_info.income) + 1];
		strcpy(income, copy_info.income);
	}
	if(copy_info.age_group)
	{
		age_group = new char[strlen(copy_info.age_group) + 1];
		strcpy(age_group, copy_info.age_group);
	}
}

/*
	display house hold information
*/
int household::display_household()
{
	cout << region << endl;
	cout << race << endl;
	cout << income << endl;
	cout << age_group << endl << endl;

	return 1;
}


//=========================================================================

/*
	edge_node default constructor implementation
*/
edge_node::edge_node()
{
	destination = 0;
	next = NULL;
}

/*
	edge_node destructor implementation
*/
edge_node::~edge_node()
{}

/*
	edge_node copy constructor with region, race, income, age_group inputs
*/
edge_node::edge_node(char * a_region, char * a_race, char * a_income, char * a_age_group) : household(a_region, a_race, a_income, a_age_group) {}

/*
	edge_node copy constructor with household instance
*/
edge_node::edge_node(const household & copy_info) : household(copy_info) {}


/*
	destination setter
*/
int edge_node::set_destination(int a_destination)
{
	if(a_destination)
		destination = a_destination;

	return 1;
}

/*
	destination getter
*/
int edge_node::get_destination()
{
	return destination;
}

/*
	returning a pointer to go to the next 
*/
edge_node * & edge_node::go_next()
{
	return next;
}


//===================================================================================

/*
	adjacency_list default constructor implementation
*/
adjacency_list::adjacency_list() : head(NULL) {}

/*
	adjacency_list destructor implementation
*/
adjacency_list::~adjacency_list()
{
	// if(head)
	// {
	// 	delete head;
	// 	head = NULL;
	// }
}

/*
	function for setting head pointer to null
*/
void adjacency_list::sethead()
{
	head = NULL;
}

/*

*/
edge_node * & adjacency_list::go_to_head()
{
	return head;
}


//==================================================================================

/*
	This is household_graph default constructor implementation
*/
household_graph::household_graph()
{
	vertex_size = 7;
	list = new adjacency_list[vertex_size];
	for(int i = 0; i < vertex_size; ++i)
		list[i].sethead();
}

/*
	destructor implementation
*/
household_graph::~household_graph()
{
	remove_all();
}

/*
	loading census data from an external file
*/
void household_graph::load_census_data()
{
	char region[100];
	char race[100];
	char income[100];
	char age[100];
	int num = 0;

	ifstream file;
	file.open("census.txt");
	if(file)
	{
		while(!file.eof())
		{
			file.getline(region, 100, '\n');
			file.getline(race, 100, '\n');
			file.getline(income, 100, '\n');
			file.getline(age, 100, '\n');
			file.ignore(100, '\n');
			add_edge_data(region, race, income, age, num, (num + 1));
			num++;
		}
	}
	file.close();
}

/*
	implement creating the household graph
*/
int household_graph::create(char * a_region, char * a_race, char * a_income, char * a_age_group, int number)
{
	int randNum = rand() % 4;
	add_edge_data(a_region, a_race, a_income, a_age_group, number, randNum);

	return 1;
}


/*
	creating edge data with start and end
*/
int household_graph::add_edge_data(char * a_region, char * a_race, char * a_income, char * a_age_group, int start, int end)
{
	edge_node * temp = a_edge_node(a_region, a_race, a_income, a_age_group, end);
	temp->go_next() = list[start].go_to_head();
	list[start].go_to_head() = temp;

	temp = a_edge_node(a_region, a_race, a_income, a_age_group, start);
	temp->go_next() = list[start].go_to_head();
	list[end].go_to_head() = temp;

	return 1;
}

/*
	returning a edge_node information from the census file
*/
edge_node * household_graph::a_edge_node(char * a_region, char * a_race, char * a_income, char * a_age_group, int end)
{
	edge_node * a_edge_node = new edge_node(a_region, a_race, a_income, a_age_group);
	a_edge_node->set_destination(end);
	a_edge_node->go_next() = NULL;
	return a_edge_node;
}

/*
	delete all data in the graph
*/
void household_graph::remove_all()
{
	for(int i = 0; i < 2; i++)
	{
		edge_node * current = list[i].go_to_head();
		while(current)
		{

			edge_node * temp = current->go_next();
			delete current;
			current = temp;
		}
	}

	for(int j = 0; j < vertex_size; j++)
	{
		list[j].sethead();
	}
	delete [] list;
}

/*
	Display all data in the graph
*/
int household_graph::display()
{
	for(int i = 0; i < vertex_size; i++)
	{
		edge_node * current = list[i].go_to_head();
		cout << "Vertex : " << i << endl;
		while(current)
		{
			cout << "Edge: " <<current->get_destination() << endl;
			current->display_household();
			current = current->go_next();
		}
	}
	return 1;
}

