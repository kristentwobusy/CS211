/**************************************************************
Kristen Osborne
Assignment 3
Due 4/17/14
osbor030@cougars.csusm.edu

This program processes a transaction file. It creates students, faculties, departments, and courses. It will add and drop classes and assign faculties to courses. It will output the information from students, faculties, departments, and courses to the screen.

faculty.C
**************************************************************/

#include <iostream>
using namespace std;

#include "faculty.h"

long Faculty::nextFacultyId = 600; //initialization of static member

//---------------------------------------------------

//default constructor
Faculty::Faculty()
{
    salary = 0.00;
    yearOfExp = 0;
    departId = 0;
    facId = nextFacultyId++;
}

//---------------------------------------------------

//destructor
Faculty::~Faculty()
{
    //empty because faculty will never get decremented
}

//---------------------------------------------------

//constructor which assigns values to attributes
Faculty::Faculty(string n, string e, string a, string dob, string gen, float sal, int yExp, long deptId)
{
    name = n;
    email = e;
    address = a;
    DOB = dob;
    gender = gen;
    salary = sal;
    yearOfExp = yExp;
    departId = deptId;
    facId = nextFacultyId++;
}

//---------------------------------------------------

void Faculty::printFac() const
{
  //only these attributes printed so ListFaculties() can be accessed
    cout << "Faculty ID: " << facId << endl
         << "\tName: " << name << endl;
}

//---------------------------------------------------
