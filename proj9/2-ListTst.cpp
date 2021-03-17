/*
Name: Luke Johnson
Class: CPSC 122
Date Submitted: March 17, 2021
Assignment: Project 9 
Description: Testing out different member functions for a linked list 
*/

#include <iostream>
using namespace std;

#include "2-List.h"

int main()
{
/*//// Test 1 - PutItemH & GetItemH ///////////////////////////////////
 //Use of a static list 
 List lst;
 lst.PutItemH(77);
 cout << lst.GetItemH() << endl;
 
 for (int i = 0; i < 5; i++) 
   lst.PutItemH(i);
 lst.Print();
 cout << endl;
 //Use of a dynamic list
 List* lst1 = new List;
 for (int i = 0; i < 5; i++)
   lst1->PutItemH(10*i);
 lst1->Print();
 cout << endl;

 delete lst1; //necessary to invoke destructor on dynamic list
 *///
 
 
/*/// Test 2 - IsEmpty //////////////////////////////////////////////////
	cout << "Test IsEmpty" << endl;
  //Use of a static list 
  List lst;
  cout << "Is the list empty? " << lst.IsEmpty() << endl;
  cout << "adding item to list..." << endl;
  cout << "New list: ";
  for (int i = 0; i < 5; i++) 
  lst.PutItemH(i);
  lst.Print();
  cout << endl;
  cout << "Is the list empty? " << lst.IsEmpty() << endl;
 
  //Use of a dynamic list
  List* lst1 = new List;
  cout << "Is the list empty? " << lst1->IsEmpty() << endl;
  cout << "adding item to list..." << endl;
  for (int i = 0; i < 5; i++)
		lst1->PutItemH(10*i);
  cout << "New list: ";
  lst1->Print();
  cout << "Is the list empty? " << lst1->IsEmpty() << endl;
  cout << endl;

  delete lst1; //necessary to invoke destructor on dynamic list
*///
 
 
/*/// Test 3 - DeleteItemH ////////////////////////////////////////////
	cout << "Test DeleteItemH" << endl;
  //Use of a static list 
  List lst;
  cout << "List: ";
  for (int i = 0; i < 5; i++) 
    lst.PutItemH(i);
  lst.Print();
  cout << "Deleting first item..." << endl;
  lst.DeleteItemH();
  cout << "New List: ";
  lst.Print();
  cout << endl;
  
  //Use of a dynamic list
  List* lst1 = new List;
  cout << "List: " << endl;
  for (int i = 0; i < 5; i++)
   lst1->PutItemH(10*i);
  lst1->Print();
  cout << "Deleting first item..." << endl;
  lst1->DeleteItemH();
  cout << "New list: ";
  lst1->Print();
  cout << endl;

  delete lst1; //necessary to invoke destructor on dynamic list
*/
 
 
/*/// Test 4 - GetLength ////////////////////////////////////////////
	cout << "Test GetLength" << endl;
  //Use of a static list 
  List lst;
  cout << "How long is the list?" << lst.GetLength() << endl;
  cout << "adding item to list..." << endl;
  cout << "New list: ";
  for (int i = 0; i < 5; i++) 
		lst.PutItemH(i);
  lst.Print();
  cout << endl;
  cout << "How long is the list? " << lst.GetLength() << endl;
  
  //Use of a dynamic list
  List* lst1 = new List;
  cout << "How long is the list?" << lst1->GetLength() << endl;
  cout << "adding item to list..." << endl;
  for (int i = 0; i < 5; i++)
		lst1->PutItemH(10*i);
  cout << "New list: ";
  lst1->Print();
  cout << "How long is the list?" << lst1->GetLength() << endl;
  cout << endl;

  delete lst1; //necessary to invoke destructor on dynamic list
*///
 
 
/*/// Test 5 - Find /////////////////////////////////////////////////////
	cout << "Test Find" << endl;
  //Use of a static list 
  List lst;
  cout << "Where is \"2\" in the list? " << lst.Find(2) << endl;
  cout << "adding items to list..." << endl;
  cout << "List: ";
  for (int i = 0; i < 5; i++) 
		lst.PutItemH(i);
 	lst.Print();
  cout << endl;
 	cout << "Where is \"2\" in the list? " << lst.Find(2) << endl;
  
 	//Use of a dynamic list
 	List* lst1 = new List;
 	cout << "Where is \"20\" in the list? " << lst1->Find(20) << endl;
 	cout << "adding item to list..." << endl;
 	for (int i = 0; i < 5; i++)
 	  lst1->PutItemH(10*i);
	cout << "New list: ";
 	lst1->Print();
 	cout << "Where is \"20\" in the list? " << lst1->Find(20) << endl;
 	cout << endl;

 	delete lst1; //necessary to invoke destructor on dynamic list
*///

 
/*// Test 6 - Delete Item /////////////////////////////////////////////
 	cout << "Test DeleteItem" << endl;
 	//Use of a static list 
 	List lst;
 	cout << "List: ";
 	for (int i = 0; i < 5; i++) 
   	lst.PutItemH(i);
 	lst.Print();
 	cout << endl;
 	cout << "Deleting item 2..." << endl;
 	lst.DeleteItem(2);
 	cout << "New List: ";
 	lst.Print();
  
 	//Use of a dynamic list
 	List* lst1 = new List;
 	cout << "List: ";
 	for (int i = 0; i < 5; i++)
   	lst1->PutItemH(10*i);
 	lst1->Print();
 	cout << "Deleting item w... " << endl;
 	lst1->DeleteItem(2);
 	cout << "New List: ";
 	lst1->Print();
 	cout << endl;

 	delete lst1; //necessary to invoke destructor on dynamic list
*///
 
 
 cout << endl;
 return 0;
}
