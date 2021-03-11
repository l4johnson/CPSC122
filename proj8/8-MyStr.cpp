#include <iostream>
using namespace std;

#include "8-MyStr.h"
#include <cstring>

//Constructor function
MyString::MyString(char const* strIn)
{
	length = strlen(strIn);
	str = new char[length + 1];
	strcpy(str, strIn);
}

//Destructor function
//once you get the constructor working, remove the comments.
MyString::~MyString()
{
delete []str; 
}

void MyString::myDisplay()
{
	cout << str << endl;
}

int MyString::myStrlen()
{
	return length;
}

bool MyString::isEqual(char const* strIn)
{
	for(int i = 0; i < length; i++)
		if(str[i] != strIn[i])
			return false;
	
	
	return true;
}

int MyString::find(char const* strIn)
{
	int size = strlen(strIn);

	for(int i = 0; i < length; i++)
		if(str[i] == strIn[0])
			for(int j = 1; j < size; j++)
				if(str[i + j] != strIn[j])
					break;
				else if (j == size - 1)
					return i;

	return -1;
					
}


void MyString::concat(char const* strIn)
{
	for(int i = 0; i < strlen(strIn); i++)
		str[length + i] = strIn[i];
}

