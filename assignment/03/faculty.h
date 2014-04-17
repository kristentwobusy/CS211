/**************************************************************
Kristen Osborne
Assignment 3
Due 4/17/14
osbor030@cougars.csusm.edu

This program processes a transaction file. It creates students, faculties, departments, and courses. It will add and drop classes and assign faculties to courses. It will output the information from students, faculties, departments, and courses to the screen.

faculty.h
**************************************************************/

#ifndef faculty_h
#define faculty_h

#include <string>
using namespace std;

#include "person.h"

//declaration of class inheriting attributes of class Person
class Faculty: public Person
{
  friend class University;

    protected:
    long facId;
    float salary;
    int yearOfExp;
    long departId;
    static long nextFacultyId;

    public:
    Faculty(); //default constructor
    ~Faculty(); //destructor
    Faculty(string n, string e, string a, string dob, string gen, float sal, int yExp, long deptId); //constructor
    void printFac() const;
};

#endif
