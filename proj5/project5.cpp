#include <iostream>
#include <fstream> 
#include <cstdlib>  //necessary for the constant EXIT_FAILURE
#include <string>
#include <ctime>
using namespace std;

void fileOpen(fstream&, string, char);
void generateKey(string filename);
int keyGen();
char encrypt (char ch, int key);
char decrypt (char ch, int key);
void encryptFile(string keyFile, string plainText, string cypherText);
void decryptFile(string keyFile, string cypherText, string plainText);
int readKey(string file);


int main(int argc, char* argv[])
{

 int mode = atoi(argv[1]);

 if (mode == 0)
  generateKey(argv[2]);
 if (mode == 1)
  encryptFile(argv[2], argv[3], argv[4]);
 if (mode == 2)
  decryptFile(argv[2], argv[3], argv[4]);


 return 0;
}

/*
Description: function genrates a random number between 0 and 26 and writes it to a file
Input: file name
Returns: n/a
*/
void generateKey(string keyFile)
{
 fstream fout;
 int key = keyGen(); 
 fileOpen(fout, keyFile, 'w');
 fout << key << endl;
 fout.close();
}

/*
Description: function generates a random number from 1 to 25
*/
int keyGen()
{
	srand(time(0));
	return (rand() % 25) + 1;
}

/*
Description: function opens a file 
Input: file stream object reference, name of the file, mode of open
Output: void function, but at exit, file stream object is tied to 
the input file name. 
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
Description: Encrypts an upper case alphabetic character using the Caesar cipher
Input: upper case alphabetic character, valid key
Returns: encrypted version of ch
*/
char encrypt (char ch, int key)
{
	int num = ch - 'A';
	num = (num + key) % 26;
	return num + 'A';
}

/*
Description: Decrypts an upper case alphabetic character using the Caesar cipher
Input: upper case alphabetic character, valid key
Returns: decrypted version of input
*/
char decrypt (char ch, int key)
{
	int num = ch - 'A';
	num = (num - key + 26) % 26;
	return num + 'A';
}

/*
Description: encrypts every char in a file and prints it to a new file
Input: key file, filename to be encrypted, and output filename
Returns: n/a
*/
void encryptFile(string keyFile, string plainText, string cypherText)
{
	int key = readKey(keyFile);
	char ch;
	
	fstream fin;
	fileOpen(fin, plainText, 'r');
	
	fstream fout;
	fileOpen(fout, cypherText, 'w');
	
	while(fin.peek() != EOF)
	{
		ch = fin.get();
		
		if(isalpha(ch))
		{
			ch = toupper(ch);
			ch = encrypt(ch, key);
		}
		fout.put(ch);
	}
	
	fin.close();
	fout.close();
}	

/*
Description: decrypts every char in a file and prints decrypted info to a new file
Inputs: key file name, file to be encrypted, and output filename
Returns: n/a
*/
void decryptFile(string keyFile, string cypherText, string plainText)
{
	int key = readKey(keyFile);
	char ch;
	
	fstream fin;
	fileOpen(fin, cypherText, 'r');
	
	fstream fout;
	fileOpen(fout, plainText, 'w');
	
	while(fin.peek() != EOF)
	{
		ch = fin.get();
		
		if(isalpha(ch))
			ch = decrypt(ch, key);
		
		fout.put(ch);
	}
	
	fin.close();
	fout.close();
}

/*
Description: opens a key file and reads the key value
Inputs: key file name
Returns: integer key
*/
int readKey(string file)
{
	fstream fin;
	fileOpen(fin, file, 'r');
	string line;
	getline(fin, line);
	
	int key = stoi(line);
	
	fin.close();
	return key;
}
