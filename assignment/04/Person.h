/*****************************************
Kristen Osborne
osbor030@cougars.csusm.edu
CS211
Assignment 4 Due 5-8-14

This program implements a linked list. It takes in information from a 
transaction file such as SSN and names. It will add and remove family
members. It will print one specific family or all of them.

Person.h
*****************************************/
#ifndef Person_h
#define Person_h

#include <iostream>
#include <string>
using namespace std;

/*this class is written by K. Osborne. It is a parent class which includes
social security, first name, and last name. Three other classes will
inherit its attributes*/
class Person
{
protected:
	long SSN;
	string fName;
	string lName;
public:
	Person(){SSN=0; fName=lName=" ";}; //default
	~Person(){}; //destructor
	Person(long id, string fN, string lN){SSN=id; fName=fN; lName=lN;}; //constructor that takes in attributs
};

#endif