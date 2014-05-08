/*****************************************
Kristen Osborne
osbor030@cougars.csusm.edu
CS211
Assignment 4 Due 5-8-14

This program implements a linked list. It takes in information from a 
transaction file such as SSN and names. It will add and remove family
members. It will print one specific family or all of them.

Family.C
*****************************************/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "Family.h"

//------------------------------------------------------

//set static members
bool Family::success = true;
bool Family::failure = false;

//------------------------------------------------------
/*This routine searches for a specific husband using the SSN that
is passed in. Written 5-5-14*/
bool Family::SearchHusband(long id)
{
	HusbandPtr curr = top; //makes a current pointer set to the top
	while(curr != NULL)
	{
		if(curr->SSN == id) //if SSNs match then it was found
			return success;

		curr = curr->nextFamily;
	}
	return failure;
}

//------------------------------------------------------
/*This routine searches for a specific wife using the SSN that
is passed in. Written 5-5-14*/
bool Family::SearchWife(long husbandId)
{
	HusbandPtr curr = top; //makes a current pointer set to the top
	while(curr != NULL)
	{
		if((curr->SSN == husbandId) && (curr->myWife != NULL)) //if the SSN matches and he has a wife
			return success;
		curr = curr->nextFamily;
	}
	return failure;
}

//------------------------------------------------------
/*This routine searches for a specific child using the SSN that
is passed in. Written 5-5-14*/
bool Family::SearchChild(long fatherId, long id)
{
	HusbandPtr curr = top; //makes a current pointer set to the top
	while((curr->SSN != fatherId) && (curr!=NULL)) //SSN does not match and current isn't NULL
		curr = curr->nextFamily;
	if(curr == NULL)
	{
		cout << "The father did not exist so therefore the child does not exist.\n\n";
		return failure;
	}

	WifePtr W = curr->myWife;

	if(W == NULL)
	{
		cout << "The mother did not exist so therefore the child does not exist.\n\n";
		return failure;
	}

	ChildPtr C = W->myChildren;
	while(C != NULL)
	{
		if(C->SSN == id) //if SSNs match then it was found
			return success;

		C = C->mySibling;
	}
	return failure;
}

//------------------------------------------------------
/*This routine adds a specific husband using the SSN that
is passed in. Written 5-5-14*/
bool Family::AddHusband(long id, string first, string last)
{
	if(SearchHusband(id)) //jump to other routine
	{
		cout << "This husband already exists.\n\n";
		return failure;
	}

	HusbandPtr H = new Husband(id, first, last); //create a new node
	if(H==NULL)
	{
		top = H;
		return success;
	}

	//makes sure the pointers will point to the correct part
	H->nextFamily = top; 
	top = H;
	return success;
}

//------------------------------------------------------
/*This routine removes a specific husband using the SSN that
is passed in. Written 5-5-14*/
bool Family::RemoveHusband(long id)
{
	if(!SearchHusband(id))
	{
		cout << "Husband does not exist.\n\n";
		return failure;
	}

	HusbandPtr curr = top; //makes a current pointer set to the top
	HusbandPtr prev = top; //makes a pointer that start a top; will be one node behind curr
	while(curr->SSN != id)
	{
		prev = curr;
		curr = curr->nextFamily;
	}
	if(curr->myWife != NULL) //SSNs match so go to remove wife to make sure she is removed first
		RemoveWife(id);

	//once wife and children are deleted, husband can be deleted
	prev->nextFamily = curr->nextFamily;
	delete curr;
	return success;
}

//------------------------------------------------------
/*This routine adds a specific wife using the husband's SSN that
is passed in. Written 5-5-14*/
bool Family::AddWife(long id, string first, string last, long husbandId)
{
	HusbandPtr H = top; //makes a current pointer set to the top
	while((H->SSN != husbandId) && (H->nextFamily !=NULL)) //SSN doesn't match and next isn't NULL
		H = H->nextFamily;
	if(H->nextFamily == NULL)
	{
		cout << "The husband did not exist so the wife does not exist.\n\n";
		return failure;
	}

	if(H->myWife != NULL)
	{
		cout << "This man already has a wife.\n\n";
		return failure;
	}

	//creates new node and adds it after husband
	WifePtr W = new Wife(id, first, last);
	H->myWife = W;
	return success;
}

//------------------------------------------------------
/*This routine removes a specific wife using the husband's SSN that
is passed in. Written 5-5-14*/
bool Family::RemoveWife(long husbandId)
{
	if(!SearchWife(husbandId))
	{
		cout << "Wife did not exist so could not remove.\n\n";
		return failure;
	}

	HusbandPtr curr = top; //makes a current pointer set to the top
	while(curr->SSN != husbandId) //SSN doesn't match husband so keep moving on
		curr = curr-> nextFamily;
	WifePtr W = curr->myWife; //create new node

	while(W->myChildren != NULL) //deletes children
	{
		ChildPtr C = W->myChildren;
		ChildPtr prev = C;
		while(C->mySibling != NULL)
		{
			prev = C;
			C = C->mySibling;
		}

		if(prev = C)
			W->myChildren = NULL;
		
		delete C;
		prev->mySibling = NULL;
	}

	//once children are deleted, wife can be deleted
	delete W;
	curr->myWife = NULL;
	return success;
}

//------------------------------------------------------
/*This routine adds a specific child using the father's SSN and child's SSN that
is passed in. Written 5-5-14*/
bool Family::AddChild(long id, string first, string last, long fatherId)
{
	if(SearchChild(fatherId,id))
	{
		cout << "This child already exists.\n\n";
		return failure;
	}
	if(SearchHusband(fatherId) && SearchWife(fatherId)) //make sure the parents exist if they don't then no children can be added
	{
		ChildPtr C = new Child(id, first, last); //new node
		HusbandPtr H = top; //makes a current pointer set to the top
		while(H->SSN != fatherId) 
			H = H->nextFamily;
		WifePtr W = H->myWife;
		if(W->myChildren == NULL) //if there are no other children
		{
			W->myChildren = C;
			return success;
		}

		//adds when there are other children
		C->mySibling = W->myChildren;
		W->myChildren = C;
		return success;
	}
	return failure;
}

//------------------------------------------------------
/*This routine removes a specific child using the father's SSN and child's SSN that
is passed in. Written 5-5-14*/
bool Family::RemoveChild(long fatherId, long childId)
{
	if(!SearchChild(fatherId, childId))
	{
		cout << "Child does not exist.\n\n";
		return failure;
	}

	HusbandPtr curr = top; //makes a current pointer set to the top
	while(curr->SSN != fatherId)
		curr = curr-> nextFamily;
	WifePtr W = curr->myWife;
	ChildPtr C = W->myChildren; 
	if(C->SSN == childId) //if SSNs match(no other children)
	{
		W->myChildren = NULL;
		delete C;
		return success;
	}
	ChildPtr prev = C;
	while(C->SSN != childId)
	{
		prev = C;
		C = C->mySibling;
	}
	//delete when there is more than one sibling
	prev->mySibling = C->mySibling;
	delete C;
	return success;
}

//------------------------------------------------------
/*This routine prints a specific family using the father's SSN that
is passed in. Written 5-5-14*/
void Family::PrintFamily(long fatherId)
{
	if(!SearchHusband(fatherId))
	{
		cout << "Family does not exist so could not be deleted.\n\n";
		return;
	}
	HusbandPtr H = top; //makes a current pointer set to the top
	while(H->SSN != fatherId)
		H = H->nextFamily;

	H->printHusb(); //print husband info
	if(H->myWife != NULL)
	{
		WifePtr W = H->myWife;
		W->printWife(); //print wife info
		if(W->myChildren != NULL)
		{
			ChildPtr C = W->myChildren;
			C->printChild(); //print child info
			while(C->mySibling != NULL) //if there are more siblings, print them too
			{
				C = C->mySibling;
				C->printChild();
			}
		}
	}
	cout << endl;
}

//------------------------------------------------------
/*This routine prints all families. Written 5-5-14*/
void Family::PrintAllFamilies()
{
	cout << "=============Families=============" << endl;
	HusbandPtr H = top; //makes a current pointer set to the top
	
	//goes through all families
	while(H != NULL)
	{
		H->printHusb(); //print husband
		WifePtr W = H->myWife;
		if(W == NULL)
		{
			H = H->nextFamily;
			continue;
		}
		W->printWife(); //print wife
		ChildPtr C = W->myChildren;
		while(C != NULL) //print children
		{
			C->printChild();
			C = C->mySibling;
		}

		cout << endl;
		H = H->nextFamily;
	}
	
}

//------------------------------------------------------
/*This routine opens a transaction file and intakes commands. It will
then call methods depending on commands. Written 5-5-14*/
void Family::processTransFile()
{
	long ssn, ManSsn;
	string fN, lN;

	//opens the file
	ifstream input;
	input.open("transFile.txt");

	if(!input)
		cout << "The file could not be opened." << endl;
	else
	{
		string command; //variable that will be used to determine what to do
		
		while(input >> command)
		{
			if(command=="AddHusband")
			{
				input >> ssn >> fN >> lN;
				if(AddHusband(ssn,fN,lN))
					cout << "==========Husband " << fN << " Added==========\n\n";
			}

			if(command=="AddWife")
			{
				input >> ssn >> fN >> lN >> ManSsn;
				if(AddWife(ssn,fN,lN,ManSsn))
					cout << "==========Wife " << fN << " Added==========\n\n";
			}

			if(command=="AddAchild")
			{
				input >> ssn >> fN >> lN >> ManSsn;
				if(AddChild(ssn,fN,lN,ManSsn))
					cout << "==========Child " << fN << " Added==========\n\n";
			}

			if(command=="RemoveHusband")
			{
				input >> ssn;
				if(RemoveHusband(ssn))
					cout << "==========Husband " << ssn << " Removed==========\n\n";
			}

			if(command=="RemoveWife")
			{
				input >> ssn; //husband's ssn
				if(RemoveWife(ssn))
					cout << "==========Wife of Husband " << ssn << " Removed==========\n\n";

			}

			if(command=="RemoveAchild")
			{
				input >> ManSsn >> ssn;
				if(RemoveChild(ManSsn, ssn))
					cout << "==========Child " << ssn << " Removed==========\n\n";

			}

			if(command=="PrintAFamily")
			{
				input >> ssn;
				cout << "==========Family " << ssn << "==========\n";
				PrintFamily(ssn);
			}

			if(command=="PrintAllFamilies")
			{
				PrintAllFamilies();
			}
		}
	}
}