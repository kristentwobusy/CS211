/**************************************************************
Kristen Osborne
Assignment 3
Due 4/17/14
osbor030@cougars.csusm.edu

This program processes a transaction file. It creates students, faculties, departments, and courses. It will add and drop classes and assign faculties to courses. It will output the information from students, faculties, departments, and courses to the screen.

course.C
**************************************************************/

#include <iostream>
using namespace std;

#include "course.h"

long Course::nextCRN = 200; //initialization of static member

//-------------------------------------------------------------

Course::Course() //default constructor
{
    maxSeats = 0;
    name = " ";
    deptId = assignedSeats = taughtBy = 0;
    CRN = nextCRN++;
}

//-------------------------------------------------------------

Course::~Course() //destructor
{
    //empty because a course will never get deleted
}

//-------------------------------------------------------------

//constructor which assigns values to attributes
Course::Course(int mSeats, string n, long dId, long t)
{
    maxSeats = mSeats;
    assignedSeats = 0;
    name = n;
    deptId = dId;
    taughtBy = t;
    CRN = nextCRN++;
}

//-------------------------------------------------------------

//void func which prints attributes of class.
void Course::printCourse() const
{
  //only print these attributes so ListCourses() can be implemented
    cout << "Course CRN: " << CRN << endl
         << "\tName: " << name << endl;
}
