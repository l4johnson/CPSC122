/*
 Name: Luke Johson
 Class: CPSC 122, Section 01
 Date Submitted: February 5, 2021
 Assignment: Project 6                                                                     
 Description: write a program that 1. generates an Affine Cypher encryption key 2. encrypts a text file and writes the cypher text to a new file 3. decrypts a cypher text file and writes the plain text to a file
 Notes: using th Affine cypher
*/
#include <iostream>
#include <fstream> 
#include <cstdlib>  //necessary for the constant EXIT_FAILURE
#include <string>
#include <ctime>

using namespace std;

void fileOpen(fstream&, string, char);
void keyGen(string filename);
char encrypt (char ch, int alpha, int beta);
char decrypt (char ch, int alpha, int beta, int MI[]);
void getKey(string keyFile, int& aplpha, int& beta);
void fileControl (string keyFile, string fileIn, string fileOut, int mode);


int main(int argc, char* argv[])
{

 int mode = atoi(argv[1]);

 if (mode == 0)
  keyGen(argv[2]);
 if (mode == 1)
  fileControl (argv[2], argv[3], argv[4], mode);
 if (mode == 2)
  fileControl (argv[2], argv[3], argv[4], mode);

 return 0;
}

/*
Description: Randomly generates and stores alpha and beta values.
The alpha value is randomly drawn from the the set:  {1,3,5,7,11, 17,19,25}
The beta value is randomly drawn from the range: [1..25]  
Output: alpha and beta values on subsequent lines of keyFile
*/
void keyGen(string keyFile)
{
 fstream fout;
 int possibleAlphas[] = {1,3,5,7,11,17,19,25};
 srand(time(NULL));
 
 int alpha = possibleAlphas[rand() % 8];
 int beta = rand() % 25 + 1;
   
 fileOpen(fout, keyFile, 'w');
 fout << alpha << endl;
 fout << beta << endl;
 fout.close();
}

/*
Description: function opens a file
Input: file stream object reference, name of the file, mode of open
Output: input file name is opened. 
*/

void fileOpen(fstream& file, string name, char mode)
//void fileOpen(fstream& file, char name[], char mode)
{
 string fileType;

 if (mode == 'r')
  fileType = "input";
 if (mode == 'w')
  fileType = "output";

 if (mode == 'r')
  file.open(name, ios::in);  //available thorugh fstream
 if (mode == 'w')
  file.open(name, ios::out);  //available through fstream;

 if (file.fail()) //error condition 
 {
  cout << "Error opening " << fileType << " file" << endl; 
  exit(EXIT_FAILURE);
 }
}

/*
Description: Encrypts an upper case alphabetic character using the affine cipher
Input: upper case alphabetic character, valid alpha and beta values
Returns: encrypted version of ch
*/
char encrypt (char ch, int alpha, int beta)
{
	int num = ch - 'A';
	num = (alpha * num + beta) % 26;
	return num + 'A';
}

/*
Description: Decrypts an upper case alphabetic character using the affine cipher
Input: upper case alphabetic character, valid alpha and beta values. Dictionary of multiplicative inverse values mod 26
Returns: decrypted version of input
*/
char decrypt (char ch, int alpha, int beta, int MI[])
{
	int num = ch - 'A';
	num = (MI[alpha]*num - MI[alpha]*beta + 25*26) % 26 ;
	return num + 'A';
}

/*
Description: opens a key file and reads the key value
Inputs: key file name
Returns: integer key
*/
void getKey(string keyFile, int& alpha, int& beta)
{
	fstream fin;
	fileOpen(fin, keyFile, 'r');
	
	fin >> alpha;
	fin >> beta;
	
	fin.close();
}

/*
Description: invokes fileOpen on all files.  closes all files.  Reads key file. Reads the input file and either invokes encrypt or decrypt,  depending on the value of mode.  Writes to the output file. 
Input: names of key file, input file and output file. mode value of 1 or 2
Output: writes to the output file
*/
void fileControl (string keyFile, string fileIn, string fileOut, int mode)
{
	int alpha, beta;
	char ch;
	int MI[] = {0,1,0,9,0,21,0,15,0,0,0,19,0,0,0,0,0,23,0,11,0,0,0,0,0,25};
	
	getKey(keyFile, alpha, beta);
	
	fstream fin;
	fileOpen(fin, fileIn, 'r');
	
	fstream fout;
	fileOpen(fout, fileOut, 'w');

	while(fin.peek() != EOF)
	{
		ch = fin.get();
		
		if( isalpha(ch))
		{
			ch = toupper(ch);
			if(mode == 1)
				ch = encrypt(ch, alpha, beta);
			if(mode == 2)
				ch = decrypt(ch, alpha, beta, MI);
		}
		
		fout.put(ch);
	}
	
	fin.close();
	fout.close();
}

