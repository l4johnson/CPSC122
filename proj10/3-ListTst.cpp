/*
Name: Luke Johnson
Class: CPSC 122
Date Submitted: March 17, 2021
Assignment: Project 9 
Description: Testing out different member functions for a linked list 
*/

#include <iostream>
using namespace std;

#include "3-ListT.h"

int main()
{
/*//// Test 1 - PutItemH & GetItemH ///////////////////////////////////
 //Use of a static list 
 ListT lst;
 lst.PutItemH(77);
 cout << lst.GetItemH() << endl;
 
 for (int i = 0; i < 5; i++) 
   lst.PutItemH(i);
 lst.Print();
 cout << endl;
 //Use of a dynamic list
 ListT* lst1 = new ListT;
 for (int i = 0; i < 5; i++)
   lst1->PutItemH(10*i);
 lst1->Print();
 cout << endl;

 delete lst1; //necessary to invoke destructor on dynamic list
*///


/*//// Test 2 - PutItemT & GetItemT ///////////////////////////////////
 //Use of a static list 
 ListT lst;
 lst.PutItemT(77);
 cout << lst.GetItemT() << endl;
 
 for (int i = 0; i < 5; i++) 
   lst.PutItemT(i);
 lst.Print();
 cout << endl;
 //Use of a dynamic list
 ListT* lst1 = new ListT;
 for (int i = 0; i < 5; i++)
   lst1->PutItemT(10*i);
 lst1->Print();
 cout << endl;

 delete lst1; //necessary to invoke destructor on dynamic list
*///
 
 
/*/// Test 3 - IsEmpty //////////////////////////////////////////////////
	cout << "Test IsEmpty" << endl;
  //Use of a static list 
  ListT lst;
  cout << "Is the list empty? " << lst.IsEmpty() << endl;
  cout << "adding item to list..." << endl;
  cout << "New list: ";
  for (int i = 0; i < 5; i++) 
  lst.PutItemH(i);
  lst.Print();
  cout << endl;
  cout << "Is the list empty? " << lst.IsEmpty() << endl;
 
  //Use of a dynamic list
  ListT* lst1 = new ListT;
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
 
 
/*/// Test 4 - DeleteItemH ////////////////////////////////////////////
	cout << "Test DeleteItemH" << endl;
  //Use of a static list 
  ListT lst;
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
  ListT* lst1 = new ListT;
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


/*/// Test 5 - DeleteItemT & PtrTo////////////////////////////////////////////
	cout << "Test DeleteItemT" << endl;
  //Use of a static list 
  ListT lst;
  cout << "List: ";
  for (int i = 0; i < 5; i++) 
    lst.PutItemT(i);
  lst.Print();
  cout << "Deleting tail item..." << endl;
  lst.DeleteItemT();
  cout << "New List: ";
  lst.Print();
  cout << endl;
  
  //Use of a dynamic list
  ListT* lst1 = new ListT;
  cout << "List: " << endl;
  for (int i = 0; i < 5; i++)
   lst1->PutItemT(10*i);
  lst1->Print();
  cout << "Deleting tail item..." << endl;
  lst1->DeleteItemT();
  cout << "New list: ";
  lst1->Print();
  cout << endl;

  delete lst1; //necessary to invoke destructor on dynamic list
*///
 
 
/*/// Test 6 - GetLength ////////////////////////////////////////////
	cout << "Test GetLength" << endl;
  //Use of a static list 
  ListT lst;
  cout << "How long is the list?" << lst.GetLength() << endl;
  cout << "adding item to list..." << endl;
  cout << "New list: ";
  for (int i = 0; i < 5; i++) 
		lst.PutItemH(i);
  lst.Print();
  cout << endl;
  cout << "How long is the list? " << lst.GetLength() << endl;
  
  //Use of a dynamic list
  ListT* lst1 = new List;
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
 
 
/*/// Test 7 - FindItem /////////////////////////////////////////////////////
	cout << "Test FindItem" << endl;
  //Use of a static list 
  ListT lst;
  cout << "How many times is \"2\" in the empty list? " << lst.FindItem(2) << endl;
  cout << "adding items to list..." << endl;
  cout << "List: ";
  for (int i = 0; i < 5; i++) 
  {
		lst.PutItemH(i);
		lst.PutItemH(i);
	}
 	lst.Print();
 	cout << "How many times is \"2\" in the list? " << lst.FindItem(2) << endl;
  cout << endl;
  
 	//Use of a dynamic list
 	ListT* lst1 = new ListT;
 	cout << "How many times is \"20\" in the empty list? " << lst1->FindItem(20) << endl;
 	cout << "adding item to list..." << endl;
 	for (int i = 0; i < 5; i++)
 	{
 	  lst1->PutItemH(10*i);
 	  lst1->PutItemH(10*i); 	  
 	}
	cout << "New list: ";
 	lst1->Print();
 	cout << "How many times is \"20\" in the list? " << lst1->FindItem(20) << endl;
 	cout << endl;

 	delete lst1; //necessary to invoke destructor on dynamic list
*///

 
/*// Test 8 - DeleteItem /////////////////////////////////////////////
 	cout << "Test DeleteItem" << endl;
 	//Use of a static list 
 	ListT lst;
 	cout << "List: ";
 	for (int i = 0; i < 5; i++) 
  {
		lst.PutItemH(i);
		lst.PutItemH(i);
	}
 	lst.Print();
 	cout << endl;
 	cout << "Deleting items == 2..." << endl;
 	lst.DeleteItem(2);
 	cout << "New List: ";
 	lst.Print();
  
 	//Use of a dynamic list
 	ListT* lst1 = new ListT;
 	cout << "List: ";
 	for (int i = 0; i < 5; i++)
  {
 	  lst1->PutItemH(10*i);
 	  lst1->PutItemH(10*i); 	  
 	}
 	lst1->Print();
 	cout << "Deleting items == 20... " << endl;
 	cout << lst1->DeleteItem(20) << endl;
 	cout << "New List: ";
 	lst1->Print();
 	cout << endl;

 	delete lst1; //necessary to invoke destructor on dynamic list
*///
 
 
 cout << endl;
 return 0;
}
