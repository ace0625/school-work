#include "store.h"
using namespace std;

//Implement each of these using exception handeling
//For each function consider if you should have the try block
//in the function or if you should have the try block in the
//calling routine. If you throw an exception without a
//try block, then add an exception specification list


//Step 5a - throw an exception if there is an invalid response
bool again()
{
    char response;
    cout << "Enter a Y or N: ";
    cin >> response;
    cin.ignore();
    response = toupper(response);
    try{
        if(response != 'Y' && response != 'N') 
            throw(response);
        else
            return true;
    }
    catch(char){
        cout << "Wrong charactor" << endl;
        return again();
    }
    catch(...){
        cout << "Try again ";
        return again();
    }
	 // int response = 1;
  //   }
  //   }
  //   char in_char;
  //   do {
  //       cout << "Enter a char!" << endl;
  //       cin >> in_char;
  //       cin.ignore();
  //       try {
  //           if(in_char == 'Y') {
  //               response = 1;
  //           } 
  //           else if(in_char == 'y') {
  //               response = 0;
  //               throw(response);
  //           } 
  //           else if(in_char != 'Y') {
  //               response = 9;
  //               throw(response);
  //           } 
  //       }
  //       catch(int) {
  //           cout << "catch for int" << endl;
  //           cout << "Try again" << endl;
  //       }
  //       catch(...) {
  //           cout << "catch for default" << endl;
  //           cout << "Try again" << endl;
  //       }

  //   }
  //   while(response);
}

//Step 5b - implement the address constructor and throw an
//exception if ther eis a null string being copied:

address::address(char * new_street, char * new_zip)
{
	// try {
 //        if(!new_street) {
 //            throw 99;
 //        }
 //    }
 //    catch(int e) {
 //        cout << "NULL Exception" << endl;
    // }
    try{
        if(!new_street || !new_zip) throw(NULL_STRING());

    }
    catch(char){
        cout << "NULL exception " << endl;
    }
    catch(...){
        cout << "error" << endl;
    }
}

//Step 5c - implement the set pay function and throw an
//exception if a zzero or negative pay is requested

void hourly_employee::set_pay_rate(float rate) throw(INVALID_PAY)
{
    try{
        if(rate <= 0) throw(INVALID_PAY());
    }
    catch(int){
        
    }
}

//Step 5d - implement the two compare functions. The first
//compares the employees name. Throw an exception if there is no match
bool employee::compare(const name & match)
{

}

//Step 5d - now travere the binary search tree of reviews and
//throw an exception if there is no match
bool employee::compare(char * match)
{

}

