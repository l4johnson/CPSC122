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

List::List()
{       
 length = 0;
 head = NULL;
}


List::~List()
{
}

bool List::IsEmpty() const
{
	if(head == NULL)
 		return true;
 	else 
 		return false;
}

int List::GetLength() const
{
		
 return length;
}

void List::PutItemH(const itemType newItem)
{
 node* tmp = new node;
 tmp->item = newItem;
 tmp->next = head;
 head = tmp;
 length++;
 tmp = NULL;
}

itemType List::GetItemH() const
{
 return head->item;
}

void List::DeleteItemH()
{
	node* point = head;
	
	head = point->next;
	
	length--;
	
}

	
void List::Print() const
{
	node* point = head;
	
	for(int i = 0; i < length; i++)
	{
		cout << point->item << endl;
		point = point->next;
	}
}

int List::Find(const itemType item) const
{
	node* point = head;
	
	for(int i = 0; i < length; i++)
		if(point->item == item)
			return i;
		else 
			point = point->next;
 return -1;
}

void List::DeleteItem(const int pos)
{
	node* point = head;
	
	for(int i = 0; i < pos; i++)
		point = point->next;
		
	node* nextItem = point->next;
	point = head;
		
	for(int i = 0; i < pos-1; i++)
		point = point->next;
		
	point->next = nextItem;
	length--;
}

