/**********************************************
Kristen Osborne
Due 3/25/14
osbor030@cougars.csusm.edu

This program creates a dictionary based on words from an input file.
It will add, delete, print, search, insert, spell check, and process
different files and words. It will then output the info from the
commands from the transaction file.

A2.C
**********************************************/
#include <iostream>
using namespace std;
#include "dictionary.h"

//a variable is declared and it calls the process trans file which will implement add, delete, print, etc.
int main()
{
  Dictionary myDict;
  myDict.ProcessTransactionFile();

  return 0;
}
