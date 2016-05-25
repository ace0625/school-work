//CS202
//Assignment #3
//Hyunchan Kim

//string.cpp
//This is string class implementation section dealing with all my string class functions

#include "string.h"

//constructor
String::String()
{
	len = 0;
	str = NULL;
}

//Constructor
String::String(const char* s)
{
	if(!s) {
		len = 0;
		strcpy(str, "");
	}
	else {
		len = strlen(s) + 1;
		str = new char[len];
		strcpy(str, s);
	}
}

//Constructor
String::String(const String& s)
{
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}

//Destructor
String::~String() 
{
	if(str != NULL)
		delete []str; 
}

//function for string length
int String::getStrlen()
{
	return len;
}

//function for String's char pointer
char* String::getCharP()
{
	return str;
}

//function for operator for "="
String& String::operator =  (const String& s)
{
	if(str != NULL)
		delete []str;
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
	return *this;
}

//function for operator for "+="
String& String::operator +=  (const String& s)
{
	len += (s.len - 1);
	char* tempstr = new char[len];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);

	if(str != NULL)
		delete []str;
	str = tempstr;
	return *this;
}

//function for operator for "=="
bool String::operator ==  (const String& s)
{
	if(!str || !s) return false;
	return strcmp(str, s.str) ? false : true;
}

//function for operator for "!="
bool String::operator !=  (const String& s)
{
	return strcmp(str, s.str) ? true : false;
}

//function for operator for "+"
String String::operator + (const String& s)
{
	char* tempstr = new char[len + s.len - 1];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);
	
	String temp(tempstr);
	delete []tempstr;
	return temp;
}

//function for operator for "<<"
ostream& operator<< (ostream& os, const String& s)
{
	os<<s.str;
	return os;
}

//function for operator for ">>"
istream& operator>> (istream& is, String& s)
{
	char str[100];
	is >> str;
	s = String(str);
	return is;
}

//function for checking null 
String::operator bool() const 
{ 
	if(len == 0) return false;
    else return true;
}

