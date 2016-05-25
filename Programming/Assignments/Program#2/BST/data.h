#include <iostream>
#include <cstring>
#include <iomanip>

class data
{
	public:
		data();
		data(char * a_menu, char ** a_ingredients);
		data(const data & copy_from);
		~data()
		void display_data();

	private:
		char * menu;
		char * ingredients[5];
};