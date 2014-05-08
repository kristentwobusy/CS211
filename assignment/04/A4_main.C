/*****************************************
Kristen Osborne
osbor030@cougars.csusm.edu
CS211
Assignment 4 Due 5-8-14

This program implements a linked list. It takes in information from a 
transaction file such as SSN and names. It will add and remove family
members. It will print one specific family or all of them.

main.C
*****************************************/

#include <iostream>
using namespace std;
#include "Family.h"

int main()
{
	Family USAFam;
	USAFam.processTransFile();
	return 0;
}