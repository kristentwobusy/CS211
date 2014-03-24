/**********************************************
Kristen Osborne
Due 3/25/14
osbor030@cougars.csusm.edu

This program creates a dictionary based on words from an input file.
It will add, delete, print, search, insert, spell check, and process
different files and words. It will then output the info from the
commands from the transaction file.

dictionary.C
**********************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

#include "dictionary.h"

//static variables initialized
bool Dictionary::failure=false;
bool Dictionary::success=true;

//-----------------------------------------------------
//default constructor which initializes array to zero and consts to desired size; written 3/18/14
Dictionary::Dictionary():maxWordsInDict(10000),maxWordsPerFile(100)
{
  totalWordsInDict=0; //start of words in dic is 0
  for(int i=0;i<SIZE;i++)
    numOfWordsInFile[i]=0;
}

//-----------------------------------------------------
//destructor
Dictionary::~Dictionary()
{
  //empty because nothing will ever get decremented
}

//-----------------------------------------------------
//constructor initializes array to zero and consts to desired size; written 3/18/14
Dictionary::Dictionary(int dictMaxWords, int fileMaxWords):maxWordsInDict(dictMaxWords),maxWordsPerFile(fileMaxWords)//constants are intialized with passed parameters
{
  totalWordsInDict=0; //initialize to zero
  for(int i=0;i<SIZE;i++)
    numOfWordsInFile[i]=0;
}

//-----------------------------------------------------
//grabs words and tells what to do with them; written 3/18/14
void Dictionary::ProcessTransactionFile()
{
  string file; //name of file
  string command; //tells program which to call (add, insert, etc)
  string word; //name the command takes in
  string fileName; //file the command takes in

  cout << "Please enter the name of the transaction file: ";
  cin >> file;
   
  ifstream transFile; //name for the transaction file
  transFile.open(file.data());
  if(!transFile)
    cout << "Could not open the file." << endl;
  else
    {
      while(!transFile.eof()) //loops until the end of file is reached
	{
	  transFile >> command;
	  
	  if(command=="AddW") //adds to dictionary
	    {
	      transFile >> word;
	      cout << endl << "========== Add: " << word << " ==========" << endl;
	      word[0]=tolower(word[0]);
	      AddAWord(word);
	    }
	  else if(command=="InsertF") //inserts a file
	    {
	      transFile >> fileName;
	      cout << endl << "========== Insert: " << fileName << " ==========" << endl;
	      InsertWordsIntoDict(fileName);
	    }
	  else if(command=="PrintF") //prints a file
	    {
	      transFile >> fileName;
	      cout << endl << "========== Print: " << fileName << " ==========" << endl;
	      PrintAFileInDict(fileName);
	    }
	  else if(command=="DeleteW") //deletes word from dictionary
	    {
	      transFile >> word;
	      word[0]=tolower(word[0]);
	      cout << endl << "========== Delete: " << word << " ==========" << endl;
	      DeleteAWord(word);
	    }
	  else if(command=="SpellCheck") //checks spelling of word
	    {
	      transFile >> fileName;
	      cout << endl << "========== SpellCheck: " << fileName << " ==========" << endl;
	      SpellChecking(fileName);
	    }
	  else if(command=="SearchW") //searches for word in dictionary
	    {
	      transFile >> word;
	      cout << endl << "========== Search: " << word << " ==========" << endl;
	      word[0]=tolower(word[0]);
	      bool found = SearchForWord(word);
	      //displays different message depending if found returns true or false
	      if(found)
		cout << word << " was found." << endl;
	      else
		cout << word << " was not found." << endl;
	    }
	  else //this is the fall back for unrecognized command. The rest of the file will still be processed
	    {
	      transFile >> word; //takes in the word so that the next command is recognized
	      cout << "Unrecognized command but will continue running." << endl;
	    }
	}
      transFile.close();
    }
}

//-----------------------------------------------------
//searches for a word and if it does not exist, it will add it; written 3/18/14
bool Dictionary::AddAWord(string word)
{
  string file = "#.txt";
  file[0]=toupper(word[0]); //finds file name
  ofstream output;
  output.open(file.data(),ios::app);

  if(totalWordsInDict >= maxWordsInDict)
    {
      cout << "Total words exceeds or equals maximum words for the dictionary." << endl;
      return failure;
    }

  int index=file[0]-'A'; //finds the index of which file to do action
  if(numOfWordsInFile[index] >= maxWordsPerFile)
    {
      cout << "Total words exceeds or equals maximum words for the file." << endl;
      return failure;
    }

  if(!SearchForWord(word)) //this func means word did not exist so add it
    {
      output << word << endl;
      totalWordsInDict++; //increment
      numOfWordsInFile[index]++; //then increment it
      return success;
    }

  else //word did exist
    {
      return failure;
    }
}

//-----------------------------------------------------
//deletes the word if it exists; written 3/18/14
bool Dictionary::DeleteAWord(string word)
{
  //find which file to do the action on
  string file= "#.txt";
  file[0]=toupper(word[0]);
    
  ifstream input;
  ofstream output;
    
  if(SearchForWord(word)) //if word exists, delete it
    {
      vector<string> Vec;
      string word2; //temporary place holder
      input.open(file.data());
      if(!input)
        {
	  cout << "This file did not exist." << endl;
	  return failure;
        }
         
      else
        {
	  while(input >> word2) //fill word2 until input is empty
	    {
	      Vec.push_back(word2); //fill vec with word2
            }
	  output.open(file.data());
	  //fill output
	  for(int i=0;i<Vec.size();i++)
            {
	      if(Vec[i]!=word)
		output << Vec[i] << endl;
            }
         
	  totalWordsInDict--; //decrement
	  int index=word[0]-'a'; //index of the letter
	  numOfWordsInFile[index]--; //decrement that file
	  return success;
        }
    }
  else //if word was not found
    {
      return failure;
    }
}

//-----------------------------------------------------
//searches for a word in the file; written 3/18/14
bool Dictionary::SearchForWord(string word)
{
  string temp; //temporary place holder while searching
  //find which file to do action on
  string file = "#.txt";
  file[0]=toupper(word[0]);

  ifstream input; //the file to search
  input.open(file.data());

  if(!input)
    {
      cout << "The file does not exist." << endl;
      return failure;
    }
  else
    {
      while(input >> temp)
	{
	  if(temp==word) //if word matches temp then it was found
	    return success;
	}
      return failure;
      input.close();
    }
}

//-----------------------------------------------------
//prints the words in a certain file; written 3/18/14
bool Dictionary::PrintAFileInDict(string fileName)
{
  ifstream input;
  input.open(fileName.data());
  string word;

  if(!input)
    {
      cout << "The file does not exist." << endl;
      return failure;
    }
  else //input was found, so print
    {
      int i = 0;
      while(input >> word)
	{
	  cout << word << ", ";
	  i++; //increment so only 5 words per line
	  if(i%5==0) //5 outputs per line
	    cout << endl;
	}
      cout << endl;
      return success;
    }

}

//-----------------------------------------------------
//checks the spelling of myEssay based on words that are in data.txt; written 3/18/14
bool Dictionary::SpellChecking(string fileName)
{
  ifstream input;
  input.open(fileName.data());
  string word;

  if(!input)
    {
      cout << "The file does not exist." << endl;
      return failure;
    }
  else //input does exist so check spelling
    {
      while(input >> word)
        {
	  if(!SearchForWord(word)) //check if word exists, if not then spelled wrong
            {   
	      cout << word << " is spelled incorrectly." << endl; 
            }   
        }
      return success;
    }
}

//-----------------------------------------------------
//uses addWord to insert words into dictionary; written 3/18/14
bool Dictionary::InsertWordsIntoDict(string fileName)
{
  ifstream input;
  input.open(fileName.data());
  string word;

  if(!input)
    {
      cout << "The file does not exist." << endl;
      return failure;
    }
  else //input does exist
    {
      while(input >> word)
	{
	  AddAWord(word); //utilize other routine
	}
    }
  return success;
}
//-----------------------------------------------------
