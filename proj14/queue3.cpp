/*
Name: Luke Johnson
Class: CPSC 122, Section 1
Date Submitted: April 27, 2021
Priority queue .cpp file
*/

//Queue using List and composition 
#include <iostream>
using namespace std;
#include "queue3.h"

PQueue::PQueue() : Queue()
{}

PQueue::PQueue(PQueue* q) : Queue(q)
{}

void PQueue::Enqueue(itemType newItem)
{
	if(length < 1)
		PutItemT(newItem);
	else
	{
		node* newNode = new node;
		newNode->item = newItem;
		if(head->item >= newItem)
		{
			newNode->next = head;
			head = newNode;
		}
		else
		{
			node* place = PtrTo(newItem);
			newNode->next = place->next;
			place->next = newNode;
		}
	}
}

node* PQueue::PtrTo(itemType newItem)
{
	node* ptr = head;
	node* nextPtr = ptr->next;
	while(nextPtr != NULL)
	{
		if(newItem <= nextPtr->item)
			break;

		ptr = nextPtr;
		nextPtr = nextPtr->next;
	}
	
 return ptr;
}
	
