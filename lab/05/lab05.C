/********************************************************
Kristen Osborne
CS 211
Lab 5
3/4/2014
********************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "employee.h"

void SetSalary(Employee& emp); //prototype

int main()
{
  Employee E1; //employee 1
  cout << "Employee 1: " << endl;
  SetSalary(E1);
  E1.Print();
  cout << endl;
  
  Employee E2;
  E2.GetInfo();
  SetSalary(E2);
  cout << "Employee 2: " << endl;
  E2.Print();

  return 0;
}

void SetSalary(Employee& emp) //sets salary depending on position
{
  if(emp.empPosition=='E') //entry level
    {
      if(emp.yearOfExp<2)
	emp.salary=50000;
      else // >2
	emp.salary=55000;
    }

  else if(emp.empPosition=='P') //project leader
    {
      if(emp.yearOfExp<4)
	emp.salary=60000;
      else //>4
	emp.salary=65000;
    }

  else if(emp.empPosition=='M') //manager
    emp.salary=70000;

  else //director
    emp.salary=80000;

}
