/*****************************************
Kristen Osborne
CS211
Assignment 4

This program implements a linked list.
*****************************************/
#ifndef Husband_h
#define Husband_h

#include <iostream>
#include <string>
using namespace std;

#include "Person.h"
#include "Wife.h"

class Husband;
typedef Husband* HusbandPtr;
typedef Wife* WifePtr;

class Husband: public Person
{
	friend class Family;
	friend class Wife;
protected:
	//SSN, first, last name inherited from Person class
	HusbandPtr nextFamily;
	WifePtr myWife;
public:
	Husband(){SSN=0; fName=lName=" "; nextFamily=NULL; myWife=NULL;};
	~Husband(){nextFamily=NULL; myWife=NULL;};
	Husband(long id, string fN, string lN){SSN=id;fName=fN;lName=lN; nextFamily=NULL; myWife=NULL;};
	void printHusb() const {cout << "SSN: " << SSN << "\tName: " << fName << " " << lName << endl;};
};

#endif