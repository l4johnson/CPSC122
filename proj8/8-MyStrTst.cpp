/*
Name: Paul De Palma
Class: CPSC 122, Section 1
Date Submitted: February 18, 2021
Assignment: N/A 
Description: Program illustrates using class MyString 
*/

#include "8-MyStr.h"
#include <iostream> 
using namespace std;


int main(int argc, char* argv[])
{
 MyString str1(argv[1]);
 MyString* str2 = new MyString(argv[1]);

  
/* 
 //Test of myDisplay
 cout << "***************************************" << endl;
 cout << "*****Test 1 myDisplay*****" << endl;
 cout << "static test" << endl;
 cout << "output should be the command line input" << endl;
 str1.myDisplay();
 cout << endl;
 cout << "*****Test 1  myDisplay*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the command line input" << endl;
 str2->myDisplay();
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of myDisplay 
*/
 
/*  
 //Test of myStrlen
 cout << "***************************************" << endl;
 cout << "*****Test 2 myStrlen*****" << endl;
 cout << "static test" << endl;
 cout << "output should be the length of the command line input" << endl;
 cout << str1.myStrlen() << endl;
 cout << endl;
 cout << "*****Test 2  myStrlen*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the length of the command line input" << endl;
 cout << str2->myStrlen() << endl;
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of myStrlen 
*/
 
/*  
 //Test of isEqual
 cout << "***************************************" << endl;
 cout << "*****Test 3 isEqual*****" << endl;
 cout << "static test" << endl;
 cout << "output should be true if the command line input is Luke" << endl;
 cout << bool(str1.isEqual("Luke\0")) << endl;
 cout << endl;
 cout << "*****Test 3  isEqual*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be true if the command line input is Luke" << endl;
 cout << bool(str2->isEqual("Luke\0")) << endl;
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of isEqual 
*/
 
/* 
 //Test of find
 cout << "***************************************" << endl;
 cout << "*****Test 4 find*****" << endl;
 cout << "static test" << endl;
 cout << "output should be starting index of the substring \"uke\" if it is in the command line input" << endl;
 cout << str1.find("uke") << endl;
 cout << endl;
 cout << "*****Test 4  find*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be starting index of the substring \"uke\" if it is in the command line input" << endl;
 cout << str2->find("uke") << endl;
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of find
*/
 
/*
 //Test of concat
 cout << "***************************************" << endl;
 cout << "*****Test 5 concat*****" << endl;
 cout << "static test" << endl;
 cout << "output should be the command line input followed by \" concat\"" << endl;
 str1.concat(" concat");
 str1.myDisplay();
 cout << endl;
 cout << "*****Test 5 concat*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the command line input followed by \" concat\"" << endl;
 str2->concat(" concat");
 str2->myDisplay();
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of concat
*/
 

 delete str2;
 return 0;  
}
   
  
