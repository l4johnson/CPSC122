/*
Name: Luke Johnson
Class: CPSC 122
Date Submitted: March 18, 2021
Assignment: Project 11 
Description: Testing out different member functions for a doubly linked list with header and tail pointer
*/
#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"

   
template <typename T>
ListD<T>::ListD()
{
 makeList();
}

template <typename T>
ListD<T>::ListD(ListD<T>* lst)
{
 makeList();

 //returns pointer to the first node, which is what we want here
 doubleNode<T>* cur = lst->FindPosition(2);
 for (int i = 1; i <= lst->length; i++)
 {
  Insert(cur->item,i);
  cur = cur->next;
 }
}

template <typename T>
void ListD<T>::makeList()
{
	length = 0; 
 
//create dummy nodes;
 head = new doubleNode<T>;
 tail = new doubleNode<T>;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;
}

template <typename T>
ListD<T>::~ListD()
{
	doubleNode<T>* point = head;
	
	for(int i = 0; i < length; i++)
	{
		doubleNode<T>* nextNode = point->next;
		delete point;
		point = nextNode;
	}
}

template <typename T>
doubleNode<T>* ListD<T>::FindPosition(int pos)
{
 //Inserting at the tail is a special case.  It can be made much more efficient than
 //this.
 doubleNode<T>* cur = head;
 int i = 0;  //begin at the dummy node
 while (i < pos - 1)
 {
  cur = cur->next;
  i++;
 }
 return cur;
} 

template <typename T>
void ListD<T>::Insert(T item, int pos)
{
 //new node goes between these two nodes
 doubleNode<T>* insertPtA = FindPosition(pos);  
 doubleNode<T>* insertPtB = insertPtA->next; 

 //create new node and set its values
 doubleNode<T>* tmp = new doubleNode<T>; 
 tmp->prev = insertPtA;
 tmp->item = item;
 tmp->next = insertPtB;

 //set pointers for nodes before and after the insertion point
 insertPtA->next = tmp;
 insertPtB->prev = tmp;

 length++;
}

template <typename T>
void ListD<T>::PrintForward()
{
 doubleNode<T>*  cur = head->next;

 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->next;
  i++;
 }
}

template <typename T>
void ListD<T>::PrintBackward()
{
	doubleNode<T>* point = tail->prev;
	
	for(int i = 0; i < length; i++)
	{
		cout << point->item << endl;
		point = point->prev;
	}
}

template <typename T>
void ListD<T>::Delete(int pos)
{
	doubleNode<T>* point = head->next;
	
	for(int i = 1; i < pos; i++)
		point = point->next;
		
	doubleNode<T>* nextNode = point->next;
	doubleNode<T>* prevNode = point->prev;
	
	prevNode->next = nextNode;
	nextNode->prev = prevNode;
	
	length--;
}

template <typename T>
int ListD<T>::DeleteAll(T item)
{
	int numDeleted = 0;
	doubleNode<T>* point = head->next;
	
	for(int i = 1; i < length; i++)
		if(point->item != item)
			point = point->next;
		else if(point == NULL)
			break;
		else
		{
			doubleNode<T>* nextNode = point->next;
			doubleNode<T>* prevNode = point->prev;
	
			prevNode->next = nextNode;
			nextNode->prev = prevNode;
			point = nextNode;
			length--;
			numDeleted++;
		}
		
		return numDeleted;
}

template <typename T>
void ListD<T>::Sort()
{
	for(int i = 1; i < length; i++)
	{
		doubleNode<T>* point = head;
		for(int j = 1; j <= i; j++)
			point = point->next;

		int min = point->item;
		int minPos = i;
		point = point->next;
		
		for(int j = i + 1; j <= length; j++)
		{
			if(point->item <= min)
			{
				min = point->item;
				minPos = j;
			}
			point = point->next;
		}
				
		Delete(minPos);
		Insert(min, i);			
	}
	
}
