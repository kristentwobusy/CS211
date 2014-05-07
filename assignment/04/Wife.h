/*****************************************
Kristen Osborne
CS211
Assignment 4

This program implements a linked list.
*****************************************/
#ifndef Wife_h
#define Wife_h

#include <iostream>
#include <string>
using namespace std;

#include "Person.h"
#include "Child.h"
class Wife;
typedef Child* ChildPtr;

class Wife: public Person
{
	friend class Family;
	friend class Child;
protected:
	//SSN, first, last name inherited from Person class
	ChildPtr myChildren;
public:
	Wife(){SSN=0; fName=lName=" "; myChildren=NULL;};
	~Wife(){myChildren=NULL;};
	Wife(long id, string fN, string lN){SSN=id; fName=fN; lName=lN; myChildren=NULL;};
	void printWife() const {cout << "SSN: " << SSN << "\tName: " << fName << " " << lName << endl;};
};

#endif