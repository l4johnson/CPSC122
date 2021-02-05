/*
Name: Luke Johnson
Class: CPSC 122
Date Submitted: January 17, 2021
Assignment: Project 4 
Description: printing a certain number of prime numbers in a certain number of columns to an output file 

	**More efficient algorithim: To determine whether a value was prime, I only needed to check and see if it was divisible by 2, 3, 5, or 7. The number is not prime if it is evenly divisible by at least one of these numbers because all other numbers are either divisible by these numbers as well, or prime.
	
							** I did the bonus ^^^^ **
*/

#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int num);
void displayPrimes(ofstream& fout, int nums, int cols);


int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		cout << "Incorrect number of command line arguments" << endl;
		exit(EXIT_FAILURE);
	}

	int numPrimes = 0;
	int count = 0;
	int i = 2;
	int numCols = 0;

	ofstream fout;

	fout.open(argv[1]);

	cout << "How many prime numbers would you like to print?" << endl;
	cin >> numPrimes;
	
	cout << "How many columns would you like to display them in?" << endl;
	cin >> numCols;
	
	displayPrimes(fout, numPrimes, numCols);
	
	/*while(count < numPrimes)
	{
		if(isPrime(i))
		{
			fout << i << ", ";
			count++;
		}
		i++;
	}*/
	fout << endl;
	
	fout.close();
}


/*
Description: Determines whether input integer is prime
Input: integer whose primality is to be judged
Returns: true if num is prime, flase otherwise
*/
bool isPrime(int num)
{
	int primes[] = {2,3,5,7};
	
	for(int testPrime : primes)
		if(num == testPrime)
			return true;
		else if(num % testPrime == 0)
			return false;
			
	return true;
}


/*
Description: prints a number of prime numbers in a certain number of columns to the output file
Input: output file, number of prime numbers, and number of columns
Returns: void
*/
void displayPrimes(ofstream& fout, int nums, int cols)
{
	int testValue = 2;
	int ct = 0;
	int rowCt = 1;
 
	while (ct < nums)
	{
		while(!isPrime(testValue))
			testValue++;
			
		fout << testValue << '\t';         //tab to next col 
		if (ct % cols == cols - 1)  //think about this one 
			fout << endl;
		testValue++;
		ct++;
  }
}
