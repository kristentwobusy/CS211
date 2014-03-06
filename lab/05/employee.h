//employee.h
#ifndef employee_h
#define employee_h

#include <string>
using namespace std;

class Employee
{
  friend void SetSalary(Employee& emp);
 protected:
  string name;
  const long officeNo;
  const long empId;
  int deptNo;
  char empPosition;
  int yearOfExp;
  float salary;
  static  int totalNumOfEmployees;
  static  int nextEmpId;
  static  int nextOfficeNo;

 public:
  Employee();
  ~Employee();
  Employee(string theName, int theDeptNo, char theEmpPosition, int theYearOfExp);
  void Print() const;
  void GetInfo();
};

#endif
