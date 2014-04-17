/**************************************************************
Kristen Osborne
Assignment 3
Due 4/17/14
osbor030@cougars.csusm.edu

This program processes a transaction file. It creates students, faculties, departments, and courses. It will add and drop classes and assign faculties to courses. It will output the information from students, faculties, departments, and courses to the screen.

person.C
**************************************************************/

#include <iostream>
using namespace std;

#include "person.h"

//-----------------------------------------------

Person::Person() //default constructor
{
    name = email = address = DOB = gender = " ";
}

//-----------------------------------------------

Person::~Person() //destructor
{
    //empty
}

//-----------------------------------------------

//constructor which assigns values to attributes
Person::Person(string n, string e, string a, string dob, string gen)
{
    name = n;
    email = e;
    address = a;
    DOB = dob;
    gender = gen;
}

//-----------------------------------------------
