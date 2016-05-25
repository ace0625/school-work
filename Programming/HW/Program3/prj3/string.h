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
		String();
		String(const char * s);
		String(const String& s);
		~String();
		String& operator= (const String& s);
		String& operator+= (const String& s);
		bool operator== (const String& s);
		bool operator!= (const String& s);
		String operator+ (const String& s);
		int getStrlen();
		char* getCharP();
		operator bool() const;

		friend ostream& operator<< (ostream& os, const String& s);
		friend istream& operator>> (istream& is, String& s);
};

#endif