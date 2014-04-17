/**************************************************************
Kristen Osborne
Assignment 3
Due 4/17/14
osbor030@cougars.csusm.edu

This program processes a transaction file. It creates students, faculties, departments, and courses. It will add and drop classes and assign faculties to courses. It will output the information from students, faculties, departments, and courses to the screen.

department.h
**************************************************************/

#ifndef department_h
#define department_h

#include <string>
using namespace std;

//declaration of class
class Department
{
  friend class University; //makes University a friend
    protected:
    long deptId; 
    string name;
    string location;
    long chairId;
    static long nextDeptId;

    public:
    Department(); //default constructor
    ~Department(); //destructor
    Department(string n, string loc, long cId); //constructor
    void printDept() const;
};

#endif
