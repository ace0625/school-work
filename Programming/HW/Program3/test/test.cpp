#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
   
	int ran = 0; 
	srand(time(NULL));
	for(int i = 0; i < 20; i++)
	{
		ran = rand() % 60 + 1;
		cout << ran << " ";
	}


	return 0;
}