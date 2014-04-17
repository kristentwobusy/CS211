/**************************************************************
Kristen Osborne
Assignment 3
Due 4/17/14
osbor030@cougars.csusm.edu

This program processes a transaction file. It creates students, faculties, departments, and courses. It will add and drop classes and assign faculties to courses. It will output the information from students, faculties, departments, and courses to the screen.

department.C
**************************************************************/

#include <iostream>
using namespace std;

#include "department.h"

long Department::nextDeptId = 100; //initialization of static member


//--------------------------------------------------

Department::Department() //default constructor
{
    chairId = 0;
    name = location = " ";
    deptId = nextDeptId++;
}

//--------------------------------------------------

Department::~Department() //destuctor
{
   //destructor is empty because nothing will get decremented
}

//--------------------------------------------------

//constructor which assigns values to attributes
Department::Department(string n, string loc, long cId)
{
    name = n;
    location = loc;
    chairId = cId;
    deptId = nextDeptId++;
}

//--------------------------------------------------

void Department::printDept() const
{
  //only print these attributes so that ListDepartments() can be implemented 
    cout << "Department ID: " << deptId << endl
         << "\tName: " << name << endl;
}
