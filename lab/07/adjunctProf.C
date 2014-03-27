#include <iostream>
#include <iomanip>
using namespace std;
#include "adjunctProf.h"


//default
AdjunctProf::AdjunctProf()
{
    degree = ' ';
    numOfTAs = numOfCourses = 0;
}

//------------------------------------
//destructor
AdjunctProf::~AdjunctProf()
{
  //what goes here??
}

//------------------------------------
//constructor
AdjunctProf::AdjunctProf(string n, string e, long id, char d, int numT, int numC)
{
    name = n; //uses parent
    email = e; //parent
    facultyId = id; //parent
    degree = d;
    numOfTAs = numT;
    numOfCourses = numC;
}

//------------------------------------

float AdjunctProf::findSalary() const
{
    float salary;
    
    if(degree=='B')
        salary = (numOfTAs*1500.0) + (numOfCourses*3000.0);

    else if(degree=='M')
        salary = (numOfTAs*2000.0) + (numOfCourses*4000.0);
 
    else if(degree=='P')
        salary = (numOfTAs*2500.0) + (numOfCourses*5000.0);
    
    else
	cout << "Invalid degree." << endl;

    cout << "\tSalary: $" << fixed << setprecision(2) << salary << endl;

    return salary;

}

//------------------------------------

void AdjunctProf::print() const
{
    cout << "Professor name: " << name << endl
         << "\tEmail: " << email << endl
         << "\tID: " << facultyId << endl
         << "\tDegree: " << degree << endl
         << "\tNumber of TAs: " << numOfTAs << endl
         << "\tNumber of Courses: " << numOfCourses << endl;
}

