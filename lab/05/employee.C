//employee.C
#include<iostream>
#include<string>
using namespace std;
#include "employee.h"

//initialize static members
int Employee::totalNumOfEmployees=0;
int Employee::nextEmpId=1000;
int Employee::nextOfficeNo=10;

Employee::Employee():officeNo(nextOfficeNo),empId(nextEmpId) //default constructor
{
  name="Unknown";
  deptNo=0;
  empPosition='E';
  yearOfExp=0;
  salary=0.0;
  totalNumOfEmployees++;
  nextEmpId++;
  nextOfficeNo++;
}

Employee::~Employee() //deconstructor
{
  totalNumOfEmployees--;
  nextEmpId--;
  nextOfficeNo--;
}

Employee::Employee(string theName, int theDeptNo, char theEmpPosition, int theYearOfExp):officeNo(nextOfficeNo),empId(nextEmpId) //this constructor accesses private members
{
  name=theName;
  deptNo=theDeptNo;
  empPosition=theEmpPosition;
  yearOfExp=theYearOfExp;
  salary=0.0;
  totalNumOfEmployees++;
  nextEmpId++;
  nextOfficeNo++;
}

void Employee::GetInfo()
{
  cout << "Please enter your name: ";
  getline(cin, name); //gets name from user

  do{ //gets a valid dept number
    cout << "Please enter your dept number: ";
    cin >> deptNo;
  }while(deptNo<0);

  do{ //gets a valid employee position
    cout << "Please enter your employee position, 'E': entry level, 'M': manager, 'D': Director, 'P':Project_leader: ";
    cin >> empPosition;
  }while(!(empPosition=='E'||empPosition=='M'||empPosition=='D'||empPosition=='P'));

  do{ //gets valid years of experience
    cout << "Please enter years of experience: " << endl;
    cin >> yearOfExp;
  }while(yearOfExp<0);

}

void Employee::Print()const
{
  cout << "Name: " << name << endl
       << "Office Number: " << officeNo << endl
       << "Employee ID: " << empId << endl
       << "Department Number: " << deptNo << endl
       << "Employee Position: " << empPosition << endl
       << "Years of Experience: " << yearOfExp << endl
       << "Salary: $" << salary << endl
       << "Number of Employees: " << totalNumOfEmployees << endl
       << "Next Employee ID: " << nextEmpId << endl
       << "Next Office Number: " << nextOfficeNo << endl;

}
