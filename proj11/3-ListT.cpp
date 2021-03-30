/*
Name: Luke Johnson
Class: CPSC 122
Date Submitted: March 18, 2021
Assignment: Project 10 
Description: Testing out different member functions for a linked list with header and tail pointer
*/

#include <iostream>
using namespace std;

#include "3-ListT.h"

ListT::ListT()
{       
 length = 0;
 head = NULL;
 tail = NULL;
}


ListT::~ListT()
{
}

bool ListT::IsEmpty() const
{
	if(head == NULL)
 		return true;
 	else 
 		return false;
}

int ListT::GetLength() const
{
 return length;
}

void ListT::PutItemH(const itemType newItem)
{
 node* tmp = new node;
 tmp->item = newItem;
 tmp->next = head;
 head = tmp;
 if(IsEmpty())
 	tail = tmp;
 length++;
}

void ListT::PutItemT(const itemType itemIn)
{
	node* tmp = new node;
	tmp->item = itemIn;
	tmp->next = NULL;
	if(IsEmpty())
		head = tmp;
	else
		tail->next = tmp;	
	tail = tmp;
	length++;
}

itemType ListT::GetItemH() const
{
 return head->item;
}

itemType ListT::GetItemT() const
{
	return tail->item;
}

void ListT::DeleteItemH()
{
	node* point = head;
	head = point->next;
	length--;
}

void ListT::DeleteItemT()
{
	PtrTo()->next = NULL;
	length--;
}

	
void ListT::Print() const
{
	node* point = head;
	
	for(int i = 0; i < length; i++)
	{
		cout << point->item << endl;
		point = point->next;
	}
}

int ListT::FindItem(const itemType item) const
{
	node* point = head;
	int numItems = 0;
	
	for(int i = 0; i < length; i++)
	{
		if(point->item == item)
			numItems++;
		point = point->next;
	}
 return numItems;
}

int ListT::DeleteItem(const itemType target)
{
	node* point = new node;
	node* nextItem = new node;
	int 	position = 0;
	int numDeleted = 0;

	while(FindItem(target) != 0)
	{
		point = head;
		for(int j = 0; j < length; j++)
		{
			if(point->item == target)
			{
				nextItem->next = point->next;
				position = j;
				break;
			}
			point = point->next;			
		}

		point = head;
		
		for(int j = 0; j < position - 1; j++)
			point = point->next;
			
		point->next = nextItem->next;
		numDeleted++;
		length--;
	}
	return numDeleted;
}

node* ListT::PtrTo()
{
	node* point = head;
	for(int i = 0; i < length - 1; i++)	
		point = point->next;
		
	return point;
}

