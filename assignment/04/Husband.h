/*****************************************
Kristen Osborne
osbor030@cougars.csusm.edu
CS211
Assignment 4 Due 5-8-14

This program implements a linked list. It takes in information from a 
transaction file such as SSN and names. It will add and remove family
members. It will print one specific family or all of them.

Husband.h
*****************************************/
#ifndef Husband_h
#define Husband_h

#include <iostream>
#include <string>
using namespace std;

#include "Person.h"
#include "Wife.h"

//prototype
class Husband;
//creates pointers
typedef Husband* HusbandPtr;
typedef Wife* WifePtr;

/*This class is written by K.Osborne. It inherits attributes from Person class. It will be used
to create nodes for a linked list and has pointers to point to next */
class Husband: public Person
{
	friend class Family;
	friend class Wife;
protected:
	//SSN, first, last name inherited from Person class
	HusbandPtr nextFamily;
	WifePtr myWife;

	/*methods include default constructor, destructor, constructor that
	takes in attrubutes from Person class, and a print*/
public:
	Husband(){SSN=0; fName=lName=" "; nextFamily=NULL; myWife=NULL;};
	~Husband(){nextFamily=NULL; myWife=NULL;};
	Husband(long id, string fN, string lN){SSN=id;fName=fN;lName=lN; nextFamily=NULL; myWife=NULL;};
	void printHusb() const {cout << "Husband:\tSSN: " << SSN << "\tName: " << fName << " " << lName << endl;};
};

#endif