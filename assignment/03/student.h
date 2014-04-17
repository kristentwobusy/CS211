/**************************************************************
Kristen Osborne
Assignment 3
Due 4/17/14
osbor030@cougars.csusm.edu

This program processes a transaction file. It creates students, faculties, departments, and courses. It will add and drop classes and assign faculties to courses. It will output the information from students, faculties, departments, and courses to the screen.

student.h
**************************************************************/

#ifndef student_h
#define student_h

#include <vector>
using namespace std;

#include "person.h"
#include "course.h"

//declaration of class which inherits attributes of Person
class Student: public Person
{
  friend class University;

    protected:
    long stuId;
    int yearOfStudy;
    string major;
    long advisorId;
    vector<Course> coursesTaken;
    static long nextStuId;

    public:
    Student(); //default
    ~Student(); //destructor
    Student(string n, string e, string a, string dob, string gen, int y, string m, long adId); //constructor
    void printStu() const;
};

#endif
