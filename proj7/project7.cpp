/*
 Name: Luke Johson
 Class: CPSC 122, Section 01
 Date Submitted: February 20, 2021
 Assignment: Project 7                                                                     
 Description: write a program that 1. generates a Cypher encryption key 2. encrypts a text file and writes the cypher text to a new file 3. decrypts a cypher text file and writes the plain text to a file
*/
#include <iostream>
#include <fstream> 
#include <cstdlib>  //necessary for the constant EXIT_FAILURE
#include <string>
#include <ctime>

using namespace std;

void fileOpen(fstream&, string, char);
void keyGen(string filename);
void sortDecodeKey(int [][2], int decode[][2], int);
void getKey(string keyFile, int key[] [2]);
void fileControl (string keyFile, string fileIn, string fileOut, int mode);
char transform(char ch, int encDec[][2]);
int find_small(int, int [][2], int, int);
void swap(int, int, int [][2], int);


int main(int argc, char* argv[])
{

 int mode = atoi(argv[1]);
 int key[26][2];

 if (mode == 0)
  keyGen(argv[2]);
 if (mode == 1)
  fileControl (argv[2], argv[3], argv[4], mode);
 if (mode == 2)
  fileControl (argv[2], argv[3], argv[4], mode);
	

 return 0;
}

/*
Description: Randomly generates and writes a key to the input file.  
Output: 26x2 array
*/
void keyGen(string keyFile)
{
 fstream fout;
 bool validate[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
 int  key[26];
 int k;
 srand(time(NULL));
 
 for(int i = 0; i < 26; i++)
 {	
 	do
 	{
 		k = rand() % 26;
 	} while(validate[k] == true);
 	validate[k] = true;
 	key[i]=k;
 } 
 
 fileOpen(fout, keyFile, 'w');
 for(int i = 0; i < 26; i++)
 	fout << char(i + 'A') << char(key[i] + 'A') << endl;
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
Description: outer, control loop for selection sort  
Input: array of integers to be sorted along with its length
Output: array is sorted at the end of function
*/
void sortDecodeKey(int arr[][2], int decode[][2], int length)
{
	int pass = 0;
 int start = 0;
 int idx_small, temp; 
 
 //swap columns
 for(int i = 0; i < length; i++) 
 {
 	decode[i][1] = arr[i][0];
 	decode[i][0] = arr[i][1];
 }

 // selection sort using the values of the first column
 while(pass < length - 1 )        
 {
  int idx_small = find_small(start, decode, length, 0);
  swap(start,idx_small,decode, 0);
  swap(start,idx_small,decode, 1);
  start++;
  pass++; 
 }
 
 
}

/*
Description: opens a key file and reads the key values
Inputs: key file name
Returns: integer key array
*/
void getKey(string keyFile, int key[] [2])
{
	fstream fin;
	fileOpen(fin, keyFile, 'r');
	int k = 0;
	string line;
	
	while(fin.peek() != EOF)
	{
		getline(fin, line);
		key[k][0] = line.at(0);
		key[k][1] = line.at(1);
		k++;
	}
	
	fin.close();
}

/*
Description: invokes fileOpen on all files.  closes all files.  Reads key file. Reads the input file and either invokes encrypt or decrypt,  depending on the value of mode.  Writes to the output file. 
Input: names of key file, input file and output file. mode value of 1 or 2
Output: writes to the output file
*/
void fileControl (string keyFile, string fileIn, string fileOut, int mode)
{
	int key[26][2];
	int decodeKey[26][2];
	char ch;
	
	getKey(keyFile, key);
	sortDecodeKey(key, decodeKey, sizeof(key)/(2*sizeof(int)));
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
				ch = transform(ch, key);
			if(mode == 2)
				ch = transform(ch, decodeKey);
		}
		
		fout.put(ch);
	}
	
	fin.close();
	fout.close();
}

/*
Description: Encrypts/Decrypts an upper case alphabetic character using the transposition cipher. Operation depends on whether it is sent the encrypt or decrypt key
Input: upper case alphabetic character, 2-D encryption or decryption array
Returns: encrypted or decrypted  version of ch
*/
char transform(char ch, int encDec[][2])
{
	int num = ch - 'A';
	return encDec[num][1];
}

/*
Description: linear search through an array looking for smallest element
Input: position to start search, array, length of array
Output: returns smallest element in the array
*/
int find_small(int start, int arr[][2], int length, int col)
{
 int idx_small = start;  //candidate smallest
 int next = start + 1;    //start searching here
 while(next < length)         
 {
  if (arr[next][col] < arr[idx_small][col]) //we've found a new smallest integer
     idx_small = next;
  next++;                        //look at the next position whether or not
                                //we've found a new smallest 
 }
 return idx_small;
}


/*
Description: swaps the contents of two posiitons in an array 
Input: position whose contents is swapped with smallest,  position of smallest, array 
Output: returns smallest element in the array
*/
void swap(int pos, int idx_small, int arr[][2], int col)
{
 int tmp = arr[pos][col];
 arr[pos][col] = arr[idx_small][col];
 arr[idx_small][col] = tmp;
}

