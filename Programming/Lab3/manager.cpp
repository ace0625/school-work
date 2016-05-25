#include "manager.h"
using namespace std;


//FINISH THIS FUNCTION.
//HINT - it needs an initialization list to set up the
//managers information
manager::manager( const salaried_employee & managers_information) : salaried_employee(managers_information)//STEP 8a
 {
    cout <<"\nPlease enter the group name: ";
    group_name.read();
    cout <<"\nHow many group_members? ";
    cin >> num_employees; cin.ignore(100,'\n');

    //COMPLETE THIS FUNCTION - allocating the dynamic array of
    //employees in this group:
    group = new employee * [num_employees];
    for(int i = 0; i < num_employees; ++i)
    {
        group[i] = NULL;
    }
}

//Deallocate the array of employee pointers
manager::~manager()
{
    for(int i = 0; i < num_employees; ++i)
        delete group[i];
    if(group)
        delete [] group;
    group = NULL;

}


//THIS FUNCTION REQUIRES RTTI!!!
void manager::add_to_group( const employee & to_add)
{
    const employee * temp = &to_add;
    const salaried_employee * ptr = dynamic_cast<const salaried_employee*>(temp);
     for(int i = 0; i < num_employees; ++i)
    {
       if(ptr)
        group[i] = new salaried_employee(*ptr);
    }
}

//SAMPLE
void manager::display() const
{
    cout <<"MANAGER ";
    salaried_employee::display();
    cout <<"\nGROUP NAME: ";
    group_name.display();
    for (int i = 0; i < num_employees; ++i)
      if (group[i]) group[i]->display();
}   
