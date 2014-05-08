/*****************************************
Kristen Osborne
osbor030@cougars.csusm.edu
CS211
Assignment 4 Due 5-8-14

This program implements a linked list. It takes in information from a 
transaction file such as SSN and names. It will add and remove family
members. It will print one specific family or all of them.

Family.h
*****************************************/
#ifndef Family_h
#define Family_h

#include <iostream>
#include <string>
using namespace std;

#include "Husband.h"
#include "Wife.h"
#include "Child.h"

//prototype
class Family;

//create a pointer
typedef Husband* HusbandPtr;

/*This class was written by K.Osborne. It declares static members and 
a pointer. It has various methods described below.*/
class Family
{
protected:
	HusbandPtr top;
	static bool success;
	static bool failure;

	/*methods include default constructor and destructor. It has
	search, add, and remove functions for family members. It
	also has print methods and a method that processes a file*/
public:
	Family(){top=NULL;};
	~Family(){top=NULL;};
	bool SearchHusband(long id);
	bool SearchChild(long fatherId, long id);
	bool SearchWife(long husbandId);
	bool AddHusband(long id, string first, string last);
	bool RemoveHusband(long id);
	bool AddWife(long id, string first, string last, long husbandId);
	bool RemoveWife(long husbandId);
	bool AddChild(long id, string first, string last, long fatherId);
	bool RemoveChild(long fatherId, long id);
	void PrintFamily(long fatherId);
	void PrintAllFamilies();
	void processTransFile();
};

#endif