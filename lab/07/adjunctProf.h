#ifndef adjunctProf_h
#define adjunctProf_h

#include "compSciProf.h"

class AdjunctProf: public CompSciProf
{
 protected:
  char degree; //B = Bachelor, M = Masters, P = PhD
  int numOfTAs;
  int numOfCourses;

 public:
 AdjunctProf(); //default
 ~AdjunctProf(); //destructor
 AdjunctProf(string n, string e, long id, char d, int numT, int numC); //constructor
 char getDegree(){return degree;};
 void setDegree(char d){degree=d;};
 int getNumTAs(){return numOfTAs;};
 void setNumTAs(int numT){numOfTAs=numT;};
 int getNumCourses(){return numOfCourses;};
 void setNumCourses(int numC){numOfCourses=numC;};
 float findSalary() const;
 void print() const;
};

#endif
