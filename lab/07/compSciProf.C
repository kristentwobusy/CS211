#include "compSciProf.h"

//default constructor
CompSciProf::CompSciProf()
{
    name = email = " ";
    facultyId = 0;
}

//----------------------------------------
//destructor
CompSciProf::~CompSciProf()
{
  //what gets decremented??
}

//----------------------------------------
//constructor
CompSciProf::CompSciProf(string n, string e, long id)
{
    name = n;
    email = e;
    facultyId = id;
}
