/**************************************************************
Kristen Osborne
Assignment 3
Due 4/17/14
osbor030@cougars.csusm.edu

This program processes a transaction file. It creates students, faculties, departments, and courses. It will add and drop classes and assign faculties to courses. It will output the information from students, faculties, departments, and courses to the screen.

university.h
**************************************************************/

#ifndef university_h
#define university_h

#include <vector>
#include <string>
using namespace std;

#include "student.h"
#include "course.h"
#include "faculty.h"
#include "department.h"

//declaration of classes which has vectors of the other classes 
class University
{
protected:
    vector<Department> Departments;
    vector<Student> Students;
    vector<Course> Courses;
    vector<Faculty> Faculties;
    static bool failure;
    static bool success;

public:
    University(); //default constructor
    ~University(); //destructor

    /*these methods create, list, add and drop, and assign different departments, students, courses, and faculties*/
    bool CreateNewDept(string deptName, string deptLoc, long deptChairId);
    bool CreateNewStu(string sName, string sEmail, string sAddress, string sDOB, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId);
    bool CreateNewCourse(int cMaxSeats, string name, long cDeptId, long cTaughtBy);
    bool CreateNewFaculty(string fName, string fEmail, string fAddress, string fDOB, string fGender, float fSalary, int fYearOfExp, long fDeptId);

    bool ListCoursesTaught(long facultyId);
    bool ListCoursesTaken(long studentId);
    bool ListFacultiesInDept(long deptId);
    bool ListStudentsOfFaculty(long facultyId);
    bool ListCoursesOfDept(long deptId);
    bool AddCourse(long courseId, long stuId);
    bool DropCourse(long courseId, long stuId);
    bool AssignDeptChair(long facultyId, long deptId);
    bool AssignInstructor(long facultyId, long courseId);

    bool ListDepartments();
    bool ListStudents();
    bool ListCourses();
    bool ListFaculties();

    /*these methods check the validity of passed parameters. ProcessTransFile checks for commands and follows them*/
    bool ProcessTransFile();
    bool ValidFacultyId(long chairId);
    bool ValidStuId(long stuId);
    bool ValidDeptName(string deptName);
    bool ValidDeptId(long deptId);
    bool ValidCourseId(long courseId);
};

#endif
