/**************************************************************
Kristen Osborne
Assignment 3
Due 4/17/14
osbor030@cougars.csusm.edu

This program processes a transaction file. It creates students, faculties, departments, and courses. It will add and drop classes and assign faculties to courses. It will output the information from students, faculties, departments, and courses to the screen.

student.C
**************************************************************/

#include <iostream>
using namespace std;

#include "student.h"

long Student::nextStuId = 500; //initialization of static member

//------------------------------------------------------

Student::Student() //default constructor
{
    yearOfStudy = 0;
    major = " ";
    advisorId = 0;
    stuId = nextStuId++;
}

//------------------------------------------------------

Student::~Student() //destructor
{
    //empty because student will never get decremented
}

//------------------------------------------------------

//constructor which assigns values to attributes
Student::Student(string n, string e, string a, string dob, string gen, int y, string m, long adId)
{
    name = n;
    email = e;
    address = a;
    DOB = dob;
    gender = gen;
    yearOfStudy = y;
    major = m;
    advisorId = adId;
    stuId = nextStuId++;
}

//------------------------------------------------------

void Student::printStu() const
{
  //only print these attributs so ListStudents() can be accessed
    cout << "Student ID: " << stuId << endl
         << "\tName: " << name << endl;
}

//------------------------------------------------------
