/*****************************************
Kristen Osborne
CS211
Assignment 4

This program implements a linked list.
*****************************************/
#ifndef Person_h
#define Person_h

#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
	long SSN;
	string fName;
	string lName;
public:
	Person(){SSN=0; fName=lName=" ";};
	~Person(){};
	Person(long id, string fN, string lN){SSN=id; fName=fN; lName=lN;};
};

#endif