/**************************************************************
Kristen Osborne
Assignment 3
Due 4/17/14
osbor030@cougars.csusm.edu

This program processes a transaction file. It creates students, faculties, departments, and courses. It will add and drop classes and assign faculties to courses. It will output the information from students, faculties, departments, and courses to the screen.

A3_main.C
**************************************************************/

#include <iostream>
using namespace std;

#include "university.h"

int main()
{
    University CSUSM;
    CSUSM.ProcessTransFile();

    return 0;
} //end main program
