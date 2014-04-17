/**************************************************************
Kristen Osborne
Assignment 3
Due 4/17/14
osbor030@cougars.csusm.edu

This program processes a transaction file. It creates students, faculties, departments, and courses. It will add and drop classes and assign faculties to courses. It will output the information from students, faculties, departments, and courses to the screen.

person.h
**************************************************************/

//this class is a parent. student and faculty classes inherit from here

#ifndef person_h
#define person_h

#include <string>
using namespace std;

//declaration of class
class Person
{
  friend class University;

    protected:
    string name;
    string email;
    string address;
    string DOB;
    string gender;

    public:
    Person(); //default
    ~Person(); //destructor
    Person(string n, string e, string a, string dob, string gen); //constructor
};

#endif
