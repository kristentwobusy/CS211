/**********************************************
Kristen Osborne
Due 3/25/14
osbor030@cougars.csusm.edu

This program creates a dictionary based on words from an input file.
It will add, delete, print, search, insert, spell check, and process
different files and words. It will then output the info from the
commands from the transaction file.

dictionary.h
**********************************************/
#ifndef dictionary_h
#define dictionary_h

#include<string>
using namespace std;

const int SIZE = 26; //must use global to use a constant variable in array

//begin class declaration
class Dictionary
{
 protected:
  const int maxWordsInDict;
  const int maxWordsPerFile; 
  int totalWordsInDict; 
  int numOfWordsInFile[SIZE]; //size = 26
  static bool failure;
  static bool success;
  
 public:
  Dictionary(); //default constructor
  ~Dictionary(); //destructor
  Dictionary(int dictMaxWords, int fileMaxWords); //constructor
  //the following alter the dictionary
  bool AddAWord(string word);
  bool DeleteAWord(string word);
  bool SearchForWord(string word);
  bool PrintAFileInDict(string filename);
  bool SpellChecking(string fileName);
  bool InsertWordsIntoDict(string fileName);
  void ProcessTransactionFile();
}; //end class

#endif
