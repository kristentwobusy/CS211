/*****************************************
Kristen Osborne
CS211
Assignment 4

This program implements a linked list.
*****************************************/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "Family.h"

//------------------------------------------------------

bool Family::success = true;
bool Family::failure = false;

//------------------------------------------------------

bool Family::SearchHusband(long id)
{
	HusbandPtr curr = top;
	while(curr != NULL)
	{
		if(curr->SSN == id)
		{
			return success;
		}

		curr = curr->nextFamily;
	}
	return failure;
}

//------------------------------------------------------

bool Family::SearchWife(long husbandId)
{
	HusbandPtr curr = top;
	while(curr != NULL)
	{
		if((curr->SSN == husbandId) && (curr->myWife != NULL))
			return success;
		curr = curr->nextFamily;
	}
	return failure;
}

//------------------------------------------------------

bool Family::SearchChild(long fatherId, long id)
{
	HusbandPtr curr = top;
	while((curr->SSN != fatherId) && (curr!=NULL))
		curr = curr->nextFamily;
	if(curr == NULL)
	{
		cout << "The father did not exist so therefore the child does not exist.\n";
		return failure;
	}

	WifePtr W = curr->myWife;

	if(W == NULL)
	{
		cout << "The mother did not exist so therefore the child does not exist.\n";
		return failure;
	}

	ChildPtr C = W->myChildren;
	while(C != NULL)
	{
		if(C->SSN == id)
			return success;

		C = C->mySibling;
	}
	return failure;
}

//------------------------------------------------------

bool Family::AddHusband(long id, string first, string last)
{
	if(SearchHusband(id))
	{
		cout << "This husband already exists.\n";
		return failure;
	}

	HusbandPtr H = new Husband(id, first, last);
	if(H==NULL)
	{
		top = H;
		return success;
	}
	H->nextFamily = top;
	top = H;
	return success;
}

//------------------------------------------------------

bool Family::RemoveHusband(long id)
{
	if(!SearchHusband(id))
	{
		cout << "Husband does not exist.\n";
		return failure;
	}

	HusbandPtr curr = top;
	HusbandPtr prev = top;
	while(curr->SSN != id)
	{
		prev = curr;
		curr = curr->nextFamily;
	}
	if(curr->myWife != NULL)
		RemoveWife(id);

	prev->nextFamily = curr->nextFamily;
	delete curr;
	return success;
}

//------------------------------------------------------

bool Family::AddWife(long id, string first, string last, long husbandId)
{
	HusbandPtr H = top;
	while((H->SSN != husbandId) && (H->nextFamily !=NULL))
		H = H->nextFamily;
	if(H->nextFamily == NULL)
	{
		cout << "The husband did not exist so the wife does not exist.\n";
		return failure;
	}

	if(H->myWife != NULL)
	{
		cout << "This man already has a wife.\n";
		return failure;
	}

	WifePtr W = new Wife(id, first, last);
	H->myWife = W;
	return success;
}

//------------------------------------------------------

bool Family::RemoveWife(long husbandId)
{
	if(!SearchWife(husbandId))
	{
		cout << "Wife did not exist so could not remove.\n";
		return failure;
	}

	HusbandPtr curr = top;
	while(curr->SSN != husbandId)
		curr = curr-> nextFamily;
	WifePtr W = curr->myWife;

	while(W->myChildren != NULL)
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

	delete W;
	curr->myWife = NULL;
	return success;
}

//------------------------------------------------------

bool Family::AddChild(long id, string first, string last, long fatherId)
{
	if(SearchChild(fatherId,id))
	{
		cout << "This child already exists.\n";
		return failure;
	}
	if(SearchHusband(fatherId) && SearchWife(fatherId))
	{
		ChildPtr C = new Child(id, first, last);
		HusbandPtr H = top;
		while(H->SSN != fatherId)
			H = H->nextFamily;
		WifePtr W = H->myWife;
		if(W->myChildren == NULL)
		{
			W->myChildren = C;
			return success;
		}
		C->mySibling = W->myChildren;
		W->myChildren = C;
		return success;
	}
	return failure;
}

//------------------------------------------------------

bool Family::RemoveChild(long fatherId, long childId)
{
	if(!SearchChild(fatherId, childId))
	{
		cout << "Child does not exist.\n";
		return failure;
	}

	HusbandPtr curr = top;
	while(curr->SSN != fatherId)
		curr = curr-> nextFamily;
	WifePtr W = curr->myWife;
	ChildPtr C = W->myChildren;
	if(C->SSN == childId)
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
	prev->mySibling = C->mySibling;
	delete C;
	return success;
}

//------------------------------------------------------

void Family::PrintFamily(long fatherId)
{
	if(!SearchHusband(fatherId))
	{
		cout << "Family does not exist so could not be deleted.\n";
		return;
	}
	HusbandPtr H = top;
	while(H->SSN != fatherId)
		H = H->nextFamily;

	H->printHusb();
	if(H->myWife != NULL)
	{
		WifePtr W = H->myWife;
		W->printWife();
		if(W->myChildren != NULL)
		{
			ChildPtr C = W->myChildren;
			C->printChild();
			while(C->mySibling != NULL)
			{
				C = C->mySibling;
				C->printChild();
			}
		}
	}
}

//------------------------------------------------------

void Family::PrintAllFamilies()
{
	cout << "=============Families=============" << endl;
	HusbandPtr H = top;
	while(H != NULL)
	{
		H->printHusb();
		WifePtr W = H->myWife;
		if(W == NULL)
		{
			H = H->nextFamily;
			continue;
		}
		W->printWife();
		ChildPtr C = W->myChildren;
		while(C != NULL)
		{
			C->printChild();
			C = C->mySibling;
		}

		H = H->nextFamily;
	}
	
}

//------------------------------------------------------

void Family::processTransFile()
{
	long ssn, ManSsn;
	string fN, lN;

	ifstream input;
	input.open("transFile.txt");

	if(!input)
		cout << "The file could not be opened." << endl;
	else
	{
		string command;
		
		while(input >> command)
		{
			if(command=="AddHusband")
			{
				input >> ssn >> fN >> lN;
				if(AddHusband(ssn,fN,lN))
					cout << "==========Husband " << fN << " Added==========\n";
			}

			if(command=="AddWife")
			{
				input >> ssn >> fN >> lN >> ManSsn;
				if(AddWife(ssn,fN,lN,ManSsn))
					cout << "==========Wife " << fN << " Added==========\n";
			}

			if(command=="AddAchild")
			{
				input >> ssn >> fN >> lN >> ManSsn;
				if(AddChild(ssn,fN,lN,ManSsn))
					cout << "==========Child " << fN << " Added==========\n";
			}

			if(command=="RemoveHusband")
			{
				input >> ssn;
				if(RemoveHusband(ssn))
					cout << "==========Husband " << ssn << " Removed==========\n";
			}

			if(command=="RemoveWife")
			{
				input >> ssn; //husband's ssn
				if(RemoveWife(ssn))
					cout << "==========Wife of Husband " << ssn << " Removed==========\n";

			}

			if(command=="RemoveAchild")
			{
				input >> ManSsn >> ssn;
				if(RemoveChild(ManSsn, ssn))
					cout << "==========Child " << ssn << " Removed==========\n";

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