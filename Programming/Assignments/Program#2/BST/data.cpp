#include "data.h"

data::data() : menu(NULL)
{
	for(int i = 0; i < 5; i++)
	{
		ingredients[i] = NULL;
	}
}

data::data(char * a_menu, char * a_ingredients[5])
{
	menu = new char[strlen(a_menu) + 1];
	strcpy(menu, a_menu);
	for(int i = 0; i < 5; i++)
	{
		if(a_ingredients[i])
		{
			ingredients[i] = new char[strlen(a_ingredients[i]) + 1];
			strcpy(ingredients[i], a_ingredients[i]);
		}
	}

}

data::data(const data & copy_from)
{
	if(copy_from.menu)
	{
		menu = new char[strlen(copy_from.menu) + 1];
		strcpy(menu, copy_from.menu);
	}
	for(int i = 0; i < 5; i++)
	{
		if(copy_from.ingredients[i])
		{
			ingredients[i] = new char[strlen(copy_from.ingredients[i]) + 1];
			strcpy(ingredients[i], copy_from.ingredients[i]);
		}
	}

}

data::~data()
{
	menu = NULL;
	for(int i = 0; i < 5; i++)
	{
		ingredients[i] = NULL;
	}

}

void data::display_data()
{
	cout << "menu : " << menu << endl;
	cout << "ingredients : ";
	for(int i = 0; i < 5; i++)
	{
		if(ingredients[i])
		{
			cout << ingredients[i] << ", ";
		}
	}

}