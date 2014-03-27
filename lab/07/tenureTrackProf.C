#include <iostream>
#include <iomanip>
using namespace std;

#include "tenureTrackProf.h"

//--------------------------------
//default constructor
TenureTrackProf::TenureTrackProf()
{
    rank = ' ';
    yearOfExp=0;
}

//--------------------------------
//destructor
TenureTrackProf::~TenureTrackProf()
{

}

//--------------------------------
//constructor
TenureTrackProf::TenureTrackProf(string n, string e, long id, char r, int y)
{
    name = n;
    email = e;
    facultyId = id;
    rank = r;
    yearOfExp = y;
}

//--------------------------------

float TenureTrackProf::findSalary() const
{
    float salary;
    
    if(rank=='A')
        salary = 65000.0 + (1500.0*yearOfExp);

    else if(rank=='S')
        salary = 80000.0 + (1500.0*yearOfExp);

    else if(rank =='F')
        salary = 90000.0 + (1500.0*yearOfExp);

    else
        cout << "Invalid rank." << endl;

    cout << "\tSalary: $" << salary << endl;

    return salary;
}

//--------------------------------

void TenureTrackProf::print() const
{
    cout << "Professor Name: " << name << endl
         << "\tEmail: " << email << endl
         << "\tID: " << facultyId << endl
         << "\tRank: " << rank << endl
         << "\tYears of Experience: " << yearOfExp << endl;
}
