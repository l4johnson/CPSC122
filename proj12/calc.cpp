#include <iostream>
using namespace std;

#include "calc.h"
#include <cstring>


//Write functions in this order.  Constructor and destructor will be built as the
//functions it invokes are written

Calc::Calc(char* argvIn)
{
	inFix = new char[strlen(argvIn) + 1];
 	strcpy(inFix,argvIn);
 	
	if(!CheckTokens())
	{
		cout << "Error... Check Tokens" << endl;
		exit(EXIT_FAILURE);
	}
	for(int i = 0; i < sizeof(valueTbl)/sizeof(int); i++)
		cout << valueTbl[i] << endl;
		
		
	stk = new Stack;
}

Calc::~Calc()
{

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
}

void Calc::Parse()
{
}

bool Calc::CheckParens()
{
 return true;
}

void Calc::DisplayInFix()
{}
