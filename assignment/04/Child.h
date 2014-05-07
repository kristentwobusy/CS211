/*****************************************
Kristen Osborne
CS211
Assignment 4

This program implements a linked list.
*****************************************/
#ifndef Child_h
#define Child_h

#include <iostream>
#include <string>
using namespace std;

#include "Person.h"
class Child;
typedef Child* ChildPtr;

class Child: public Person
{
	friend class Family;
protected:
	//SSN, first, last name inherited from Person class
	ChildPtr mySibling;
public:
	Child(){SSN=0; fName=lName=" "; mySibling=NULL;};
	~Child(){mySibling=NULL;};
	Child(long id, string fN, string lN){SSN=id; fName=fN; lName=lN; mySibling=NULL;};
	void printChild() const {cout << "SSN: " << SSN << "\tName: " << fName << " " << lName << endl;};
};

#endif