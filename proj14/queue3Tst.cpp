#include <iostream>
using namespace std;

#include "queue3.h"


int main()
{

 PQueue* que = new PQueue;
 int i = 1;
 while (i < 24)
 {
  que->Enqueue(i);
  i = i + 2;
 }
 que->Print();
 cout << endl;
 que->Enqueue(9);
 que->Enqueue(6);
 que->Enqueue(12);
 que->Enqueue(0);
 que->Enqueue(31);
 que->Enqueue(31);
 que->Enqueue(32);
 que->Enqueue(3);
 que->Print();
 cout << endl;
 cout << que->Peek() << endl;
 que->Dequeue();
 cout << que->Peek() << endl;
 delete que;
 
}
