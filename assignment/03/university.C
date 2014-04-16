//university.C

#include <iostream>
#include <fstream>
using namespace std;

#include "university.h"

//----------------------------------------------------

bool University::failure = false;
bool University::success = true;

//----------------------------------------------------

University::University()
{
    //empty because vectors will never use it
}

//----------------------------------------------------

University::~University()
{
    //empty again
}

//----------------------------------------------------

bool University::CreateNewDept(string deptName, string deptLoc, long deptChairId)
{
    if((deptChairId!=0) && !(ValidFacultyId(deptChairId)))
    {
        cout << deptChairId << " is not a valid chair ID.\n";
        return failure;
    }

    Department newDept(deptName,deptLoc,deptChairId);
    Departments.push_back(newDept); //fills the vector
    return success;
}

//----------------------------------------------------

bool University::CreateNewStu(string sName, string sEmail, string sAddress, string sDOB, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId)
{
    if((sMajor != 0) && !(ValidDeptName(sMajor)))
    {
        cout << sMajor << " is not a valid major.\n";
        return failure;
    }

    if((sAdvisorId!=0) && !(ValidFacultyId(sAdvisorId))) //CHECK THIS!!!
    {
        cout << sAdvisorId << " is not a valid advisor ID.\n";
        return failure;
    }

    Student newStu(sName,sEmail,sAddress,sDOB,sGender,sYearOfStudy,sMajor,sAdvisorId);
    Students.push_back(newStu);
    return success;
}

//----------------------------------------------------

bool University::CreateNewCourse(string cName, long cDeptId, long cTaughtBy, int cMaxSeats)
{
    if((cTaughtBy!=0) && !(ValidFacultyId(cTaughtBy)))
    {
        cout << cTaughtBy << " is not a valid faculty.\n";
        return failure;
    }

    if(!(ValidDeptId(cDeptId)))
    {
        cout << cDeptId << " is not a valid department ID.\n";
        return failure;
    }

    Course newCourse(cName,cDeptId,cTaughtBy,cMaxSeats);
    Courses.push_back(newCourse);
    return success;
}

//----------------------------------------------------

bool University::CreateNewFaculty(string fName, string fEmail, string fAddress, string fDOB, string fGender, float fSalary, int fYearOfExp, long fDeptId)
{
    if(!(ValidDeptId(fDeptId)))
    {
        cout << fDeptId << " is not a valid department ID.\n";
        return failure;
    }

    Faculty newFac(fName,fEmail,fAddress,fDOB,fGender,fSalary,fYearOfExp,fDeptId);
    Faculties.push_back(newFac);
    return success;
}

//----------------------------------------------------

bool University::ListCoursesTaught(long facultyId)
{
    if(!(ValidFacultyId(facultyId)))
    {
        cout << facultyId << " is not a valid faculty ID.\n";
        return failure;
    }

    //FINISH THIS
    return success;
}

//----------------------------------------------------

bool University::ListCoursesTaken(long studentId)
{
    if(!(ValidStuId(studentId)))
    {
        cout << studentId << " is not a valid student ID.\n";
        return failure;
    }

     for(int i=0; Students.size(); i++)
    {
        for(int j=0; Students[i].coursesTaken.size(); j++)
        {
            if(Students[i].coursesTaken[j].taughtBy == facultyId)
            {
                cout << "Student ID: " << Students[i].stuId << endl
                     << "Student Name: " << Students[i].name << endl;
            }
                
        }
    }
    
    return success;
}

//----------------------------------------------------

bool University::ListFacultiesInDept(long deptId)
{
    if(!(ValidDeptId(deptId)))
    {
        cout << deptId << " is not a valid department ID.\n";
        return failure;
    }
    
    for(int i=0; i<Faculties.size(); i++)
    {
        if(Faculties[i].departId == deptId)
        {
            cout << "Faculty ID: " << Faculties[i].facId << endl
                 << "Faculty Name: " << Faculties[i].name << endl;
        }
    }
    return success;
}

//----------------------------------------------------

bool University::ListStudentsOfFaculty(long facultyId)
{
    if(!(ValidFacultyId(facultyId)))
    {
        cout << facultyId << " is not a valid faculty ID.\n";
        return failure;
    }
    
    for(int i=0; Students.size(); i++)
    {
        for(int j=0; Students[i].coursesTaken.size(); j++)
        {
            if(Students[i].coursesTaken[j].taughtBy == facultyId)
            {
                cout << "Student ID: " << Students[i].stuId << endl
                     << "Student Name: " << Students[i].name << endl;
            }
                
        }
    }
    return success;
}

//----------------------------------------------------

bool University::ListCoursesOfDept(long deptId)
{
    if(!(ValidDeptId(deptId)))
    {
        cout << deptId << " is not a valid depatment ID.\n";
        return failure;
    }

    //FINISH THIS
    return success;
}

//----------------------------------------------------

bool University::AddCourse(long courseId, long stuId)
{
    if(!(ValidCourseId(courseId)))
    {
        cout << courseId << " is not a valid course ID.\n";
        return failure;
    }

    if(!(ValidStuId(stuID)))
    {
        cout << stuId << " is not a valid student ID.\n";
        return failure;
    }

    for(int i=0; i<Students.size(); i++)
    {
        for(int j=0; j<Students[i].coursesTaken.size(); j++)
        {
            if(Students[i].courseTaken[j].CRN == courseId)
            {
                cout << "Student is already taking the course " << courseId << endl;
                return failure;
            }
        }

        for(int j=0; j<Courses.size(); j++)
        {
            if(Courses[j].maxSeats == Courses[j].assignedSeats)
            {
                cout << "Course is full. It could not be added.\n";
                return failure;
            }

            if(Courses[j].CRN == courseId)
            {
                Students[i].coursesTaken.push_back(Courses[j]);
                return success;
            }
        }
    }
}

//----------------------------------------------------

bool University::DropCourse(long courseId, long stuId)
{

}

//----------------------------------------------------

bool University::AssignDeptChair(long facultyId, long deptId)
{
    if(!(ValidFacultyId(facultyId)))
    {
        cout << facultyId << " is not a valid faculty ID.\n";
        return failure;
    }

    if(!(ValidDeptId(deptId)))
    {
        cout << deptId << " is not a valid dept ID.\n";
        return failure;
    }
    for(int i=0; i<Departments.size(); i++)
    {
        if(Department[i].deptId == deptId)
        {
            Department[i].chairId = facultyId;
            return success;
        }
    }
    return failure;
}

//----------------------------------------------------

bool University::AssignInstructor(long facultyId, long courseId)
{
    if(!(ValidFacultyId(facultyId)))
    {
        cout << facultyId << " is not a valid faculty ID.\n";
        return failure;
    }

    if(!(ValidCourseId(courseId)))
    {
        cout << courseId << " is not a valid course ID.\n";
        return failure;
    }
    /*not checking to see if the instructor is already assigned because it will keep the user from being able to change instructors for courses later*/
    for(int i=0; i<Courses.size(); i++)
    {
        if(Courses[i].CRN == courseId)
        {
            Courses[i].taughtBy = facultyId;
            return success;
        }
    }
}

//----------------------------------------------------

bool University::ListDepartments()
{
    for(int i=0; i<Departments.size(); i++)
    {
        Departments[i].printDept();
        cout << endl;
    }
}

//----------------------------------------------------

bool University::ListStudents()
{
    for(int i=0; i<Students.size(); i++)
    {
        Students[i].printStu()
        cout << endl;
    }
}

//----------------------------------------------------

bool University::ListCourses()
{
    for(int i=0; i<Courses.size(); i++)
    {
        Courses[i].printCourse();
        cout << endl;
    }
}

//----------------------------------------------------

bool University::ListFaculties()
{
    for(int i=0; i<Faculties.size(); i++)
    {
        Faculties[i].printFac();
        cout << endl;
    }
}

//----------------------------------------------------

bool University::ProcessTransFile()
{
    ifstream input;
    input.open("transFile.txt");
    string command;
    bool status;

    while(!input.eof())
    {
        input >> command;

        if(command == "CreateNewDepartment")
        {
            string deptName, deptLoc;
            long deptChairId;
            
            input >> deptName >> deptLoc >> deptChairId;
            status = CreateNewDept(deptName,deptLoc,deptChairId);
            if(status)
                cout << "==========New Dept Created==========" << endl;
        }

        else if(command == "CreateNewFaculty")
        {
            string fName, fEmail, fAddress, fDOB, fGender;
            float fSalary;
            int fYearOfExp;
            long fDeptId;

            input >> fName >> fEmail >> fAddress >> fDOB >> fGender >> fSalary >> fYearOfExp >> fDeptId;
            status = CreateNewFaculty(fName,fEmail,fAddress,fDOB,fGender,fSalary,fYearOfExp, fDeptId);
            if(status)
                cout << "==========New Faculty Created==========" << endl;
        }

        else if(command == "CreateNewStudent")
        {
            string sName, sEmail, sAddress, sDOB, sGender, sMajor;
            int sYearOfStudy;
            long sAdvisorId;

            input >> sName >> sEmail >> sAddress >> sDOB >> sGender >> sYearOfStudy >> sMajor >> sAdvisorId;
            status = CreateNewStu(sName,sEmail,sAddress,sDOB,sGender,sYearOfStudy,sMajor,sAdvisorId);
            if(status)
                cout << "==========New Student Created==========" << endl;
        }
    
        else if(command == "CreateNewCourse")
        {
            string cName;
            long cDeptId, cTaughtBy;
            int cMaxSeats;

            input >> cName >> cDeptId >> cTaughtBy >> cMaxSeats;
            status = CreateNewCourse(string cName, long cDeptId, long cTaughtBy, int cMaxSeats);
            if(status)
                cout << "==========New Course Created==========" << endl;
        }

        else if(command == "ListDepartments")
        {
            cout << "==========Departments==========" << endl;
            status = ListDepartments();
            if(!status)
            {
                cout << "Failure." << endl;
            }
        }

        else if(command == "ListFaculties")
        {
            cout << "==========Faculties==========" << endl;
            status = ListFaculties();
            if(!status)
            {
                cout << "Failure." << endl;
            }
        }

        else if(command == "ListStudents")
        {
            cout << "==========Students==========" << endl;
            status = ListStudents();
            if(!status)
            {
                cout << "Failure." << endl;
            }
        }

        else if(command == "ListCourses")
        {
            cout << "==========Courses==========" << endl;
            status = ListCourses();
            if(!status)
            {
                cout << "Failure." << endl;
            }
        }

        else if(command == "ListFacultiesInDepartment")
        {
            long deptId;
            input >> deptId;
            cout << "==========Faculties In Dept " << deptId << "==========" << endl;
            status = ListFacultiesInDept(deptId);
            if(!status)
            {
                cout << "Failure." << endl;
            }
        }

        else if(command == "ListStudentsOfAFaculty")
        {
            long facultyId;
            input >> facultyId;
            cout << "==========Students Of Faculty " << facultyId << "==========" << endl;
            status = ListStudentsOfFaculty(facultyId);
            if(!status)
            {
                cout << "Failure." << endl;
            }
        }

        else if(command == "ListCoursesTaughtByFaculty")
        {
            long facultyId;
            input >> facultyId;
            cout << "==========Courses Of Faculty " << facultyId << "==========" << endl;
            status = ListCoursesTaught(facultyId);
            if(!status)
            {
                cout << "Failure." << endl;
            }
        }

        else if(command == "ListCoursesOfADepartment")
        {
            long deptId;
            input >> deptId;
            cout << "==========Courses Of Dept " << deptId << "==========" << endl;
            status = ListCoursesOfDept(deptId);
            if(!status)
            {
                cout << "Failure." << endl;
            }
        }
        else if(command == "ListCoursesTakenByStudent")
        {
            long studentId;
            input >> studentId;
            cout << "==========Courses Taken by Student " << studentId << "==========" << endl;
            status = ListCoursesTaken(studentId);
            if(!status)
            {
                cout << "Failure." << endl;
            }
        }

        else if(command == "AddACourseForAStudent")
        {
            long courseId, stuId;
            input >> courseId >> stuId;
            status = AddCourse(courseId,stuId);
            if(status)
                cout << "==========Course " << courseId << " Added==========" << endl;
        }

        else if(command == "DropACourseForAStudent")
        {
            long courseId, stuId;
            input >> courseId << stuId;
            status = DropCourse(courseId,stuId);
            if(status)
                cout << "==========Course " << courseId << " Dropped==========" << endl;
        }
    
        else if(command == "AssignDepartmentChair")
        {
            long facultyId, deptId;
            input >> facultyId >> deptId;
            status = AssignDeptChair(facultyId,deptId);
            if(status)
                cout << "==========" << facultyId << " Assigned to Dept " << deptId << "==========" << endl;
        }

        else if(command == "AssignInstructorToCourse")
        {
            long facultyId, courseId;
            input >> facultyId >> courseId;
            status = AssignInstructor(facultyId,courseId);
            if(status)
                cout << "==========" << facultyId << " Assigned to Course " << courseId << "==========" << endl;
        }

        else
        {
            cout << "Unrecognized Command." << endl;
            return failure;
        }
    }
    return success;
}

//----------------------------------------------------

bool University::ValidFacultyId(long chairId)
{
    for(int i=0; i<Faculties.size(); i++)
    {
        if(chairId == Faculties[i].facId)
            return success;
    }
    return failure;
}

//----------------------------------------------------

bool University::ValidStuId(long stuId)
{
    for(int i=0; i<Students.size(); i++)
    {
        if(stuId == Students[i].stuId)
            return success;
    }
    return failure;
}

//----------------------------------------------------

bool University::ValidDeptName(string deptName)
{
    for(int i=0; i<Departments.size(); i++)
    {
        if(deptName == Departments[i].name)
            return success;
    }
    return failure;
}

//----------------------------------------------------

bool University::ValidDeptId(long deptId)
{
    for(int i=0; i<Departments.size(); i++)
    {
        if(deptId == Departments[i].deptId)
            return success;
    }
    return failure;
}

//----------------------------------------------------

bool University::ValidCourseId(long courseId)
{
    for(int i=0; i<Courses.size(); i++)
    {
        if(courseId == Courses[i].CRN)
            return success;
    }
    return failure;
}
