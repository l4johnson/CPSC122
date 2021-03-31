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

   
ListD::ListD()
{
 length = 0;
 
//create dummy nodes;
 head = new doubleNode;
 tail = new doubleNode;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;
}

ListD::ListD(ListD* lst)
{
 length = 0; 
 
//create dummy nodes;
 head = new doubleNode;
 tail = new doubleNode;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;

 //returns pointer to the first node, which is what we want here
 doubleNode* cur = lst->FindPosition(2);
 for (int i = 1; i <= lst->length; i++)
 {
  Insert(cur->item,i);
  cur = cur->next;
 }
}

ListD::~ListD()
{
	doubleNode* point = head;
	
	for(int i = 0; i < length; i++)
	{
		doubleNode* nextNode = point->next;
		delete point;
		point = nextNode;
	}
}

doubleNode* ListD::FindPosition(int pos)
{
 //Inserting at the tail is a special case.  It can be made much more efficient than
 //this.
 doubleNode* cur = head;
 int i = 0;  //begin at the dummy node
 while (i < pos - 1)
 {
  cur = cur->next;
  i++;
 }
 return cur;
} 
  
void ListD::Insert(itemType item, int pos)
{
 //new node goes between these two nodes
 doubleNode* insertPtA = FindPosition(pos);  
 doubleNode* insertPtB = insertPtA->next; 

 //create new node and set its values
 doubleNode* tmp = new doubleNode; 
 tmp->prev = insertPtA;
 tmp->item = item;
 tmp->next = insertPtB;

 //set pointers for nodes before and after the insertion point
 insertPtA->next = tmp;
 insertPtB->prev = tmp;

 length++;
}

void ListD::PrintForward()
{
 doubleNode*  cur = head->next;

 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->next;
  i++;
 }
}
 
void ListD::PrintBackward()
{
	doubleNode* point = tail->prev;
	
	for(int i = 0; i < length; i++)
	{
		cout << point->item << endl;
		point = point->prev;
	}
}

void ListD::Delete(int pos)
{
	doubleNode* point = head->next;
	
	for(int i = 1; i < pos; i++)
		point = point->next;
		
	doubleNode* nextNode = point->next;
	doubleNode* prevNode = point->prev;
	
	prevNode->next = nextNode;
	nextNode->prev = prevNode;
	
	length--;
}

int ListD::DeleteAll(itemType item)
{
	int numDeleted = 0;
	doubleNode* point = head->next;
	
	for(int i = 1; i < length; i++)
		if(point->item != item)
			point = point->next;
		else if(point == NULL)
			break;
		else
		{
			doubleNode* nextNode = point->next;
			doubleNode* prevNode = point->prev;
	
			prevNode->next = nextNode;
			nextNode->prev = prevNode;
			point = nextNode;
			length--;
			numDeleted++;
		}
		
		return numDeleted;
}

void ListD::Sort()
{
	for(int i = 1; i < length; i++)
	{
		doubleNode* point = head;
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

 
