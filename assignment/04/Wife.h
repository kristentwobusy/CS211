/*****************************************
Kristen Osborne
osbor030@cougars.csusm.edu
CS211
Assignment 4 Due 5-8-14

This program implements a linked list. It takes in information from a 
transaction file such as SSN and names. It will add and remove family
members. It will print one specific family or all of them.

Wife.h
*****************************************/
#ifndef Wife_h
#define Wife_h

#include <iostream>
#include <string>
using namespace std;

#include "Person.h"
#include "Child.h"

//prototype
class Wife;

//creates a pointer
typedef Child* ChildPtr;

/*This class is written by K.Osborne. It inherits attributes from Person class. It will be used
to create nodes for a linked list and has pointers to point to next */
class Wife: public Person
{
	friend class Family;
	friend class Child;
protected:
	//SSN, first, last name inherited from Person class
	ChildPtr myChildren;

	/*methods include default constructor, destructor, constructor that
	takes in attrubutes from Person class, and a print*/
public:
	Wife(){SSN=0; fName=lName=" "; myChildren=NULL;};
	~Wife(){myChildren=NULL;};
	Wife(long id, string fN, string lN){SSN=id; fName=fN; lName=lN; myChildren=NULL;};
	void printWife() const {cout << "Wife:\t" << "SSN: " << SSN << "\tName: " << fName << " " << lName << endl;};
};

#endif