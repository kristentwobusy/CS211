/*****************************************
Kristen Osborne
osbor030@cougars.csusm.edu
CS211
Assignment 4 Due 5-8-14

This program implements a linked list. It takes in information from a 
transaction file such as SSN and names. It will add and remove family
members. It will print one specific family or all of them.

Child.h
*****************************************/
#ifndef Child_h
#define Child_h

#include <iostream>
#include <string>
using namespace std;

#include "Person.h"

//prototype
class Child;

//creates a pointer
typedef Child* ChildPtr;

/*This class is written by K.Osborne. It inherits attributes from Person class. It will be used
to create nodes for a linked list and has pointers to point to next */
class Child: public Person
{
	friend class Family;
protected:
	//SSN, first, last name inherited from Person class
	ChildPtr mySibling;

	/*methods include default constructor, destructor, constructor that
	takes in attrubutes from Person class, and a print*/
public:
	Child(){SSN=0; fName=lName=" "; mySibling=NULL;};
	~Child(){mySibling=NULL;};
	Child(long id, string fN, string lN){SSN=id; fName=fN; lName=lN; mySibling=NULL;};
	void printChild() const {cout << "Child:\t" << "SSN: " << SSN << "\tName: " << fName << " " << lName << endl;};
};

#endif