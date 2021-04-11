#include <iostream>
using namespace std;

#include "calc.h"
#include <cstring>
#include <cmath>


//Write functions in this order.  Constructor and destructor will be built as the
//functions it invokes are written

Calc::Calc(char* argvIn)
{
	inFix = new char[strlen(argvIn) + 1];
 	strcpy(inFix,argvIn);
 	
 	if(!CheckParens())
	{
		cout << "Error... Check Parentheses" << endl;
		exit(EXIT_FAILURE);
	}
	if(!CheckTokens())
	{
		cout << "Error... Check Tokens" << endl;
		exit(EXIT_FAILURE);
	}
	
	
	MakeValueTbl();
	Parse();
	
		
	stk = new Stack;
}

Calc::~Calc()
{
	delete stk;
	delete inFix;

}

bool Calc::CheckTokens()
{
	for(int i = 0; i < strlen(inFix); i++)
	{
		char ch = inFix[i];
		switch (ch){
			case '('	:
				continue;
			case ')'	:
				continue;
			case '+'	:
				continue;
			case '-'	:
				continue;
			case '*'	:
				continue;
			case '/'	:
				continue;
		}
		
		if(ch >= '0' && ch <= '9')
			continue;
		else if (ch >= 'A' && ch <= 'Z')
			continue;
		else 
			return false;
	}

	return true;
}

void Calc::MakeValueTbl()
{
	valueTbl = new int[26];
	for(int i = 0; i < 26; i++)
		valueTbl[i] = 0;
	valueIdx = 0;
}

void Calc::Parse()
{
	int totalVal = 0;
	int digitIdx = 0;
	int currentVal = 0;
	Stack* digits = new Stack;
	int idx = 0;
	valueIdx = 0;
	while(inFix[idx] != 0)
	{
		if(inFix[idx] >= '0' && inFix[idx] <= '9')
		{
			digits->Push(inFix[idx] - '0');
			digitIdx++;
		}
		else if (digitIdx != 0)
		{
			for(int j = 0; j < digitIdx; j++)
			{
				totalVal += digits->Peek() * pow(10, j);
				digits->Pop();
			}
			valueTbl[valueIdx] = totalVal;
			idx = replaceNum();
			valueIdx++;
			totalVal = 0;
			digitIdx = 0;
		}
		idx++;
	}
	delete digits;
}

bool Calc::CheckParens()
{
	Stack* parens = new Stack;
	parens->Push(0);
	
	for(int i = 0; i < strlen(inFix); i++)
		if (inFix[i] == '(')
			parens->Push(1);
		else if (inFix[i] == ')' && parens->Peek() == 0)
		{
			delete parens;
			return false;
		}
		else if (inFix[i] == ')')
			parens->Pop();

	if(parens->Peek() == 0)
	{
		delete parens;
 		return true;
 	}
 		delete parens;
 		return false;
}

void Calc::DisplayInFix()
{
	cout << inFix << endl;
}

int Calc::replaceNum()
{
	int i = 0;
	while(inFix[i] < '0' || inFix[i] > '9')
		i++;
	inFix[i] = valueIdx + 'A';
	int startValue = i;
	i++;
	int j = i;
	while(inFix[j] >= '0' && inFix[j] <= '9')
		j++;
	while(inFix[j] != 0)
		inFix[i++] = inFix[j++];
	inFix[i] = inFix[j];
	
	return startValue;
}

int Calc::FindLast(int cur)
{
	int i = -1;
	while(inFix[cur] != 0)
	{
		if(inFix[cur] >= '0' && inFix[cur] <= '9')
			i = cur;
		cur++;
	}
	if(i == -1)
		return cur;
	return i;
}
