/**************************************************************
Kristen Osborne
Assignment 3
Due 4/17/14
osbor030@cougars.csusm.edu

This program processes a transaction file. It creates students, faculties, departments, and courses. It will add and drop classes and assign faculties to courses. It will output the information from students, faculties, departments, and courses to the screen.

university.C
**************************************************************/


#include <iostream>
#include <fstream>
using namespace std;

#include "university.h"

//----------------------------------------------------

//declaration of static members
bool University::failure = false;
bool University::success = true;

//----------------------------------------------------

//default constructor.created 4/15
University::University()
{
    //empty because vectors will never use it
}

//----------------------------------------------------
//destructor.created 4/15
University::~University()
{
    //empty because university will never be decremented
}

//----------------------------------------------------

//this creates a new department with name, location, and id. created 4/15
bool University::CreateNewDept(string deptName, string deptLoc, long deptChairId)
{
  if((deptChairId!=0) && !(ValidFacultyId(deptChairId))) //check validity of id
    {
        cout << deptChairId << " is not a valid chair ID.\n";
        return failure;
    }

    Department newDept(deptName,deptLoc,deptChairId);
    Departments.push_back(newDept); //fills the vector
    return success;
}

//----------------------------------------------------

//this creates a new student with the passed parameters. created 4/15
bool University::CreateNewStu(string sName, string sEmail, string sAddress, string sDOB, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId)
{
  if((sMajor != " ") && !(ValidDeptName(sMajor))) //check validity of name
    {
        cout << sMajor << " is not a valid major.\n";
        return failure;
    }

  if((sAdvisorId!=0) && !(ValidFacultyId(sAdvisorId))) //check validity of id
    {
        cout << sAdvisorId << " is not a valid advisor ID.\n";
        return failure;
    }

    Student newStu(sName,sEmail,sAddress,sDOB,sGender,sYearOfStudy,sMajor,sAdvisorId);
    Students.push_back(newStu); //fills vector
    return success;
}

//----------------------------------------------------

//creates new course with passed parameters. created 4/15
bool University::CreateNewCourse(int cMaxSeats, string name, long cDeptId, long cTaughtBy)
{
  if((cTaughtBy!=0) && !(ValidFacultyId(cTaughtBy))) //checks validity of id
    {
        cout << cTaughtBy << " is not a valid faculty.\n";
        return failure;
    }

  if(!(ValidDeptId(cDeptId))) //checks validity of id
    {
        cout << cDeptId << " is not a valid department ID.\n";
        return failure;
    }

    Course newCourse(cMaxSeats,name,cDeptId,cTaughtBy);
    Courses.push_back(newCourse); //fills the vector
    return success;
}

//----------------------------------------------------

//creates new faculty with the passed parameters. created 4/15
bool University::CreateNewFaculty(string fName, string fEmail, string fAddress, string fDOB, string fGender, float fSalary, int fYearOfExp, long fDeptId)
{
  if(!(ValidDeptId(fDeptId))) //checks validity of id
    {
        cout << fDeptId << " is not a valid department ID.\n";
        return failure;
    }

    Faculty newFac(fName,fEmail,fAddress,fDOB,fGender,fSalary,fYearOfExp,fDeptId);
    Faculties.push_back(newFac); //fill the vector
    return success;
}

//----------------------------------------------------

//this lists the courses taught by the faculty that gets passed. created 4/15
bool University::ListCoursesTaught(long facultyId)
{
  if(!(ValidFacultyId(facultyId))) //checks validity of id
    {
        cout << facultyId << " is not a valid faculty ID.\n";
        return failure;
    }

    for(int i=0; i<Courses.size(); i++)
    {
      //only print the attibutes of the fac if it matches
      if(Courses[i].taughtBy == facultyId)
        {
	  cout << "Course: " << i+1 << endl 
	       << "\tName: " << Courses[i].name << endl
	       << "\tCRN: " << Courses[i].CRN << endl;
        }
    }
    return success;
}

//----------------------------------------------------

//this lists the courses taken by the passed student. created 4/15
bool University::ListCoursesTaken(long studentId)
{
  if(!(ValidStuId(studentId))) //check validity of id
    {
        cout << studentId << " is not a valid student ID.\n";
        return failure;
    }
   
    for(int i=0; i<Students.size(); i++)
    {
      //only print the attributes if the id matches
        if(Students[i].stuId == studentId)
        {
            for(int j=0; j<Students[i].coursesTaken.size(); j++)
            {
                cout << "Course " << j+1 << ":\n"
                     << "\tName: " << Students[i].coursesTaken[j].name << endl
                     << "\tCRN: " << Students[i].coursesTaken[j].CRN << endl;
            }
         }
    }
    return success;
}

//----------------------------------------------------

//this prints the faculties in the passed department id. created 4/15
bool University::ListFacultiesInDept(long deptId)
{
  if(!(ValidDeptId(deptId))) //check validity of id
    {
        cout << deptId << " is not a valid department ID.\n";
        return failure;
    }
    
    for(int i=0; i<Faculties.size(); i++)
    {
      //only print attributes if id matches
        if(Faculties[i].departId == deptId)
        {
            cout << "Faculty ID: " << Faculties[i].facId << endl
                 << "Faculty Name: " << Faculties[i].name << endl;
        }
    }
    return success;
}

//----------------------------------------------------

//this lists the students of the passed faculty id. created 4/15
bool University::ListStudentsOfFaculty(long facultyId)
{
  if(!(ValidFacultyId(facultyId))) //check validity of fac id
    {
        cout << facultyId << " is not a valid faculty ID.\n";
        return failure;
    }

    for(int i=0; i<Students.size(); i++)
      {
	if(Students[i].advisorId == facultyId)
	  {
	    //only print attributes if id matches
	    cout << "Student Name: " << Students[i].name << endl
	         << "Student Id: " << Students[i].stuId << endl;
	  }
      }
    
    return success;
}

//----------------------------------------------------

//this lists the courses of the passed department id. created 4/15
bool University::ListCoursesOfDept(long deptId)
{
  if(!(ValidDeptId(deptId))) //check validity of id
    {
        cout << deptId << " is not a valid depatment ID.\n";
        return failure;
    }

    for(int i=0; i<Courses.size(); i++)
    {
        if(Courses[i].deptId == deptId)
        {
	  //only print these if the departId matches
            cout << "Course: " << Courses[i].name << endl
                 << "\tCRN: " << Courses[i].CRN << endl;
        }
    }
    return success;
}

//----------------------------------------------------

//this adds a course to a student with the passed course id and stu id
bool University::AddCourse(long courseId, long stuId)
{
  if(!(ValidCourseId(courseId))) //check validity of course id
    {
        cout << courseId << " is not a valid course ID.\n";
        return failure;
    }

  if(!(ValidStuId(stuId))) //check validity of stu id
    {
        cout << stuId << " is not a valid student ID.\n";
        return failure;
    }
  
    for(int i=0; i<Students.size(); i++)
    {
      //dont add the course if the student is already enrolled in it
        for(int k=0; k<Students[i].coursesTaken.size(); k++)
        {
            if(Students[i].coursesTaken[k].CRN == courseId)
            {
                cout << "Student is already taking the course " << courseId << endl;
                return failure;
            }
        }

	//dont add the course if it is full
        for(int j=0; j<Courses.size(); j++)
        {
            if(Courses[j].assignedSeats >= Courses[j].maxSeats)
            {
                cout << "Course is full. It could not be added.\n";
                return failure;
            }

            if(Courses[j].CRN == courseId)
            {
	      Students[i].coursesTaken.push_back(Courses[j]); //add class in vector
                return success;
            }
        }
    }
}

//----------------------------------------------------

//this drops a course from a student with passed parameters
bool University::DropCourse(long courseId, long stuId)
{
  if(!(ValidCourseId(courseId))) //check validity of course id
    {
        cout << courseId << " is not a valid course ID.\n";
        return failure;
    }

  if(!(ValidStuId(stuId))) //check validity of stu id
    {
        cout << stuId << " is not a valid student ID.\n";
        return failure;
    }

    for(int i=0; i<Students.size(); i++)
    {
        if(Students[i].stuId == stuId)
        {
            for(int j=0; i<Students[i].coursesTaken.size(); j++)
            {
                if(Students[i].coursesTaken[j].CRN == courseId)
		  Students[i].coursesTaken.erase(Students[i].coursesTaken.begin()+j);//erase course from vector
            }
        }
    }
    return success;
}

//----------------------------------------------------

//this assigns a fac to a dept using the passed parameters. created 4/15
bool University::AssignDeptChair(long facultyId, long deptId)
{
  if(!(ValidFacultyId(facultyId))) //check validity of fac id
    {
        cout << facultyId << " is not a valid faculty ID.\n";
        return failure;
    }

  if(!(ValidDeptId(deptId))) //check validity of dept id
    {
        cout << deptId << " is not a valid dept ID.\n";
        return failure;
    }
    for(int i=0; i<Departments.size(); i++)
    {
        if(Departments[i].deptId == deptId)
        {
	  Departments[i].chairId = facultyId; //assigns the fac to the chair of dept
            return success;
        }
    }
    return failure;
}

//----------------------------------------------------

//this assigns instructor to a course with passed parameters. created 4/15
bool University::AssignInstructor(long facultyId, long courseId)
{
  if(!(ValidFacultyId(facultyId))) //checks validity of fac id
    {
        cout << facultyId << " is not a valid faculty ID.\n";
        return failure;
    }

  if(!(ValidCourseId(courseId))) //checks validity of course id
    {
        cout << courseId << " is not a valid course ID.\n";
        return failure;
    }
    /*not checking to see if the instructor is already assigned because it will keep the user from being able to change instructors for courses later*/
    for(int i=0; i<Courses.size(); i++)
    {
        if(Courses[i].CRN == courseId)
        {
	  Courses[i].taughtBy = facultyId; //assigns fac to course
            return success;
        }
    }
}

//----------------------------------------------------

//lists the dept using print method of class Department. created 4/15
bool University::ListDepartments()
{
    for(int i=0; i<Departments.size(); i++)
    {
      Departments[i].printDept();
        cout << endl;
    }
}

//----------------------------------------------------

//lists the students using the print method of class Student. created 4/15
bool University::ListStudents()
{
    for(int i=0; i<Students.size(); i++)
    {
        Students[i].printStu();
        cout << endl;
    }
}

//----------------------------------------------------

//list the courses using the print method of class Course. created 4/15
bool University::ListCourses()
{
    for(int i=0; i<Courses.size(); i++)
    {
        Courses[i].printCourse();
        cout << endl;
    }
}

//----------------------------------------------------

//list the faculties using the print method of class Faculty. created 4/15
bool University::ListFaculties()
{
    for(int i=0; i<Faculties.size(); i++)
    {
        Faculties[i].printFac();
        cout << endl;
    }
}

//----------------------------------------------------

/*finds commands in the process transaction file and calls the appropriate methods to run the command. It also passes the attributes it needs. attributes are declared within each if statement to save memory. created 4/15*/
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
	    else
	      {
		cout << "Department could not be created.\n";
	      }
	    cout << endl;
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
	    else
	      cout << "Faculty could not be created.\n";

	    cout << endl;
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
	    else
	      cout << "Student could not be created.\n";

	    cout << endl;
        }
    
        else if(command == "CreateNewCourse")
        {
            string name;
            long cDeptId, cTaughtBy;
            int cMaxSeats;

            input >> name >> cDeptId >> cTaughtBy >> cMaxSeats;
            status = CreateNewCourse(cMaxSeats,name,cDeptId,cTaughtBy);
            if(status)
                cout << "==========New Course Created==========" << endl;
	    else
	      cout << "Course could not be created.\n";

	    cout << endl;
        }

        else if(command == "ListDepartments")
        {
            cout << "==========Departments==========" << endl;
            status = ListDepartments();
            
	    if(!status)
                cout << "Department could not be listed bacause it could not be created." << endl;
	    
	    cout << endl;
        }

        else if(command == "ListFaculties")
        {
            cout << "==========Faculties==========" << endl;
            status = ListFaculties();
            
	    if(!status)
                cout << "Faculty could not be listed bacause it could not be\
 created." << endl;
           
	    cout << endl;
        }

        else if(command == "ListStudents")
        {
            cout << "==========Students==========" << endl;
            status = ListStudents();
            
	    if(!status)
                cout << "Student could not be listed bacause it could not be\
 created." << endl;

	    cout << endl;
        }

        else if(command == "ListCourses")
        {
            cout << "==========Courses==========" << endl;
            status = ListCourses();
            
	    if(!status)
                cout << "Course could not be listed bacause it could not be\
 created." << endl;
         
	    cout << endl;
        }

        else if(command == "ListFacultiesInDepartment")
        {
            long deptId;
            input >> deptId;
            cout << "==========Faculties In Dept " << deptId << "==========" << endl;
            status = ListFacultiesInDept(deptId);
            
	    if(!status)
                cout << "Could not list faculty of department" << endl;
            
	    cout << endl;
        }

        else if(command == "ListStudentsOfAFaculty")
        {
            long facultyId;
            input >> facultyId;
            cout << "==========Students Of Faculty " << facultyId << "==========" << endl;
            status = ListStudentsOfFaculty(facultyId);
            
	    if(!status)
                cout << "Could not list student of faculty." << endl;
            
	    cout << endl;
        }

        else if(command == "ListCoursesTaughtByFaculty")
        {
            long facultyId;
            input >> facultyId;
            cout << "==========Courses Of Faculty " << facultyId << "==========" << endl;
            status = ListCoursesTaught(facultyId);
            
	    if(!status)
                cout << "Course taught by faculty could not be listed" << endl;
            
	    cout << endl;
        }

        else if(command == "ListCoursesOfADepartment")
        {
            long deptId;
            input >> deptId;
            cout << "==========Courses Of Dept " << deptId << "==========" << endl;
            status = ListCoursesOfDept(deptId);
            
	    if(!status)
                cout << "Could not list course of department." << endl;
            
	    cout << endl;
        }
        else if(command == "ListCoursesTakenByStudent")
        {
            long studentId;
            input >> studentId;
            cout << "==========Courses Taken by Student " << studentId << "==========" << endl;
            status = ListCoursesTaken(studentId);
            
	    if(!status)
                cout << "Could not list course taken by student." << endl;
            
	    cout << endl;
        }

        else if(command == "AddACourseForAStudent")
        {
            long courseId, stuId;
            input >> courseId >> stuId;
            status = AddCourse(courseId,stuId);
            if(status)
	      cout << "==========Course " << courseId << " Added For Student " << stuId <<"==========" << endl;
	    else
	      cout << "Course could not be added.\n";

	    cout << endl;
        }

        else if(command == "DropACourseForAStudent")
        {
            long courseId, stuId;
            input >> courseId >> stuId;
            status = DropCourse(courseId,stuId);
            if(status)
                cout << "==========Course " << courseId << " Dropped==========" << endl;
	    else
	      cout << "Course could not be dropped.\n";

	    cout << endl;
        }
    
        else if(command == "AssignDepartmentChair")
        {
            long facultyId, deptId;
            input >> facultyId >> deptId;
            status = AssignDeptChair(facultyId,deptId);
            if(status)
                cout << "==========" << facultyId << " Assigned to Dept " << deptId << "==========" << endl;
	    else
	      cout << "Chair could not be assigned to department.\n";

	    cout << endl;
        }

        else if(command == "AssignInstructorToCourse")
        {
            long facultyId, courseId;
            input >> facultyId >> courseId;
            status = AssignInstructor(facultyId,courseId);
            if(status)
                cout << "==========" << facultyId << " Assigned to Course " << courseId << "==========" << endl;
	    else
	      cout << "Faculty could not be assigned to course.\n";

	    cout << endl;
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

//checks the validity of the passed id. it fails if it is not valid. created 4/15
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

//checks the validity of the passed id. it fails if it is not valid. created 4/15
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

//checks the validity of the passed name. it fails if it is not valid. created 4/15
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

//checks the validity of the passed id. it fails if it is not valid. created 4/15
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

//checks the validity of the passed id. it fails if it is not valid. created 4/15
bool University::ValidCourseId(long courseId)
{
    for(int i=0; i<Courses.size(); i++)
    {
        if(courseId == Courses[i].CRN)
            return success;
    }
    return failure;
}
