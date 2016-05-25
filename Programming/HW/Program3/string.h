//CS202
//Assignment #3
//Hyunchan Kim

//string.h

//This is string header file composing all prototypes for personal string class

#include <iostream>
#include <cstring>

#ifndef _STRING_H_
#define _STRING_H_
using namespace std;
class String
{
	private:
		int len;
		char * str;
	public:
		String(); // Constructor
		String(const char * s); // Constructor
		String(const String& s); // Constructor
		~String(); // Destructor
		String& operator= (const String& s); // operator for "="
		String& operator+= (const String& s); // operator for "+="
		bool operator== (const String& s); // operator for "=="
		bool operator!= (const String& s); // operator for "!="
		String operator+ (const String& s); // operator for "+"
		int getStrlen(); // get String length
		char* getCharP(); // get String's char pointer
		operator bool() const; // for checking null of the object

		friend ostream& operator<< (ostream& os, const String& s); // operator for "<<"
		friend istream& operator>> (istream& is, String& s); // operator for ">>"
};

#endif