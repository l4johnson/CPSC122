/*
Name: Luke Johnson
Class: CPSC 122
Date Submitted: March 18, 2021
Assignment: Project 11 
Description: Testing out different member functions for a doubly linked list with header and tail pointer
*/
#include <iostream>
using namespace std;

#include "4-ListD.cpp"


int main()
{
/*//	Test1: Insert and PrintForward	//////////
 ListD<int>* lst = new ListD<int>;
 
 for (int i = 1; i <= 10; i++)
   lst->Insert(i,i);

 lst->PrintForward();

 cout << endl;
 
 ListD<int>* lst1 = new ListD<int>(lst);

 lst1->PrintForward();
*///	End Test1


/*//	Test2: PrintBackward	//////////
 ListD<int>* lst = new ListD<int>;
 
 for (int i = 1; i <= 10; i++)
   lst->Insert(i,i);

 lst->PrintBackward();

 cout << endl;
 
 ListD<int>* lst1 = new ListD<int>(lst);

 lst1->PrintBackward();
*///	End Test2


/*//	Test3: Delete	//////////
 ListD<int>* lst = new ListD<int>;
 
 cout << "List: "<< endl;
 for (int i = 1; i <= 10; i++)
   lst->Insert(i,i);

 lst->PrintForward();
 cout << endl;
 
 cout << "Deleting item 5..." << endl;
 lst->Delete(5);
 cout << "Updated List: " << endl;
 lst->PrintForward();
 cout << endl;
 
 ListD<int>* lst1 = new ListD<int>(lst);

 cout << "List 1: "<< endl;
 for (int i = 1; i <= 10; i++)
   lst1->Insert(i,i);

 lst1->PrintForward();
 cout << endl;
 
 cout << "Deleting item 5..." << endl;
 lst1->Delete(5);
 cout << "Updated List 1: " << endl;
 lst1->PrintForward();
 cout << endl;
 
*///	End Test3


/*//	Test4: DeleteAll	//////////
 ListD<int>* lst = new ListD<int>;
 
 cout << "List: "<< endl;
 for (int i = 1; i <= 20; i++)
   lst->Insert(i/2,i);

 lst->PrintForward();
 cout << endl;
 
 cout << "Deleting All 5's..." << endl;
 cout << "Deleted " << lst->DeleteAll(5) << " items!" << endl;
 cout << "Updated List: " << endl;
 lst->PrintForward();
 cout << endl;
 
 ListD<int>* lst1 = new ListD<int>(lst);

 cout << "List 1: "<< endl;
 for (int i = 1; i <= 20; i++)
   lst1->Insert(i/2,i);

 lst1->PrintForward();
 cout << endl;
 
 cout << "Deleting All 5's..." << endl;
 cout << "Deleted " << lst1->DeleteAll(5) << " items!" << endl;
 cout << "Updated List 1: " << endl;
 lst1->PrintForward();
 cout << endl;
 
*///	End Test4


/*//	Test5: Sort	//////////
 ListD<char>* lst = new ListD<char>;
 
 cout << "Please enter items to be put in the list to be sorted." << endl;
 char item;
 for (int i = 1; i <= 5; i++)
 {
	 cout << "Item " << i << ": ";
	 cin >> item;
   lst->Insert(item,i);
 }
 cout << endl << "List: " << endl;
 lst->PrintForward();
 cout << endl;
 
 cout << "Sorting list..." << endl;
 lst->Sort();
 cout << "Updated List: " << endl;
 lst->PrintForward();
 cout << endl;
 
 
 
*///	End Test5

 return 0;
}
