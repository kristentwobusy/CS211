/**************************************************************
Kristen Osborne
Assignment 3
Due 4/17/14
osbor030@cougars.csusm.edu

This program processes a transaction file. It creates students, faculties, departments, and courses. It will add and drop classes and assign faculties to courses. It will output the information from students, faculties, departments, and courses to the screen.

course.h
**************************************************************/

#ifndef course_h
#define course_h

#include <string>
using namespace std;

//declaration of class
class Course
{
  friend class University; //makes University a friend

    protected:
    long CRN;
    int maxSeats;
    string name;
    long deptId;
    long assignedSeats;
    long taughtBy;
    static long nextCRN;

    public:
    Course(); //default constructor
    ~Course(); //destructor
    Course(int mSeats, string n, long dId, long t); //constructor
    void printCourse() const;
};

#endif
