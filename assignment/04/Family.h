/*****************************************
Kristen Osborne
CS211
Assignment 4

This program implements a linked list.
*****************************************/
#ifndef Family_h
#define Family_h

#include <iostream>
#include <string>
using namespace std;

#include "Husband.h"
#include "Wife.h"
#include "Child.h"
class Family;
typedef Husband* HusbandPtr;

class Family
{
protected:
	HusbandPtr top;
	static bool success;
	static bool failure;
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