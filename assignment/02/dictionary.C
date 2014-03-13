//dictionary.C

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "dictionary.h"

bool Dictionary::failure=false;
bool Dictionary::success=true;

//-----------------------------------------------------

Dictionary::Dictionary():maxWordsInDict(10000),maxWordsPerFile(100)//constants initialized with default values
{
    totalWordsInDict=0; //start of words in dic is 0
    for(int i=0;i<26;i++) //fills the array of numOfWordsInFile with zeros
        numOfWordsInFile[i]=0;
}

//-----------------------------------------------------

Dictionary::Dictionary(int dictMaxWords, int fileMaxWords):maxWordsInDict(dictMaxWords),maxWordsPerFile(fileMaxWords)//constants are intialized with passed parameters
{
    totalWordsInDict=0; //initialize to zero
    for(int i=0;i<26;i++) //initialize array
        numOfWordsInFile[i]=0;
}

//-----------------------------------------------------

void Dictionary::ProcessTransactionFile() //grabs file and tells what to do with the words in the file
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
        while(!transFile.eof()) //loops until the end of file is reached
        {
            transFile >> command;

            if(command=="AddW") //adds to dictionary
            {
                transFile >> word;
                word[0]=tolower(word[0]);
                AddAWord(word);
            }
            else if(command=="InsertF") //inserts a file
            {
                transFile >> fileName;
                InsertWordsIntoDict(fileName);
            }
            else if(command=="PrintF") //prints a file
            {
                transFile >> fileName;
                PrintAFileInDict(fileName);
            }
            else if(command=="DeleteW") //deletes word from dictionary
            {
                transFile >> word;
                word[0]=tolower(word[0]);
                DeleteAWord(word);
            }
            else if(command=="SpellCheck") //checks spelling of word
            {
                transFile >> fileName;
                word[0]=tolower(word[0]);
                SpellChecking(fileName);
            }
            else if(command=="SearchW") //searches for word in dictionary
            {
                transFile >> word;
                word[0]=tolower(word[0]);
                SearchForWord(word);

            }
            else //this is the fall back for unrecognized command. The rest of the file will still be processed
            {
                transFile >> word; //takes in the word so that the next command is recognized
                cout << "Unrecognized command." << endl;
            }
        }
}

//-----------------------------------------------------

bool Dictionary::AddAWord(string word)
{
    string file = "#.txt";
    file[0]=toupper(word[0]); //finds file name
    ofstream output;
    output.open(file.data(),ios::app);
 
    if(!SearchForWord(word)) //this func means word did not exist
    {
        output << word << endl;
	    totalWordsInDict++; //increment
	    int index=word[0]-'a'; //finds which file to inc
        numOfWordsInFile[index]++;
	    return Dictionary::success;
    }
    else //word did exist
    {
        cout << "This word already exists." << endl;
	    return Dictionary::failure;
    }
}

//-----------------------------------------------------

bool Dictionary::DeleteAWord(string word)
{
    string file= "#.txt";
    file[0]=toupper(word[0]);
    
    ifstream input;
    ofstream output;
    
    if(SearchForWord(word))
    {
        vector<string> Vec;
        string word2;
        input.open(file.data());
        if(!input)
            cout << "This file did not exist." << endl;
        else
        {
            while(input >> word2)
                    Vec.push_back(word2);
            
            output.open(file.data());
            for(int i=0;i<Vec.size();i++)
            {
                if(Vec[i]!=word);
                    output << Vec[i] << " ";
            }
         
            totalWordsInDict--;
            int index=word[0]-'a';
            numOfWordsInFile[index]--;
            return Dictionary::success;
        }
    }
    else
    {
        cout << "The word could not be deleted because it did not exist." << endl;
        return Dictionary::failure;
    }
}

//-----------------------------------------------------

bool Dictionary::SearchForWord(string word)
{
    string temp; //temporary place holder while searching
    string file = "#.txt";
    file[0]=toupper(word[0]);

    ifstream input; //the file to search
    input.open(file.data());

    if(!input)
    {
        cout << "The file does not exist." << endl;
        return Dictionary::failure;
    }
    else
    {
         while(input >> temp)
            {
                if(temp==word)
                    return Dictionary::success;
            }
         return Dictionary::failure;
         input.close();
    }
}

//-----------------------------------------------------

bool Dictionary::PrintAFileInDict(string fileName)
{
    ifstream input;
    input.open(fileName.data());
    string word;

    if(!input)
    {
        cout << "The file does not exist." << endl;
        return Dictionary::failure;
    }
    else
    {
        while(input >> word)
            {
                for(int i=0;i<!input.eof();i++)
                {
                    cout << word << " ";
                    if(i%5==0)
                        cout << endl;
                }
            }
        return Dictionary::success;
    }

}

//-----------------------------------------------------

bool Dictionary::SpellChecking(string fileName)
{
    ifstream input;
    input.open(fileName.data());
    string word;

    if(!input)
    {
        cout << "The file does not exist." << endl;
        return Dictionary::failure;
    }
    else
    {
        while(!input.eof())
        {
            if(!SearchForWord(word))
            {   
                cout << word << " is spelled incorrectly." << endl; 
            }   
        }
        return Dictionary::success;
    }
}

//-----------------------------------------------------

bool Dictionary::InsertWordsIntoDict(string fileName)
{
    ifstream input;
    input.open(fileName.data());
    string word;

    if(!input)
    {
        cout << "The file does not exist." << endl;
        return Dictionary::failure;
    }
    else
    {
        while(input >> word)
            AddAWord(word);
        return Dictionary::success;
    }   
    input.close();
}
//-----------------------------------------------------

