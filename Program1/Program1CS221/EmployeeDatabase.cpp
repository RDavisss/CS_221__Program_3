/*******************************************************************
*   EmployeeDatabase.cpp
*   Ryan Davis
*   Programming Assignment 3 and Statement of Work
*   Due Date: July 16,2018
*   This program is entirely my own work
*******************************************************************/


#include <iostream>
#include <fstream>
#include "EmployeeRecord.h"
#include "CustomerList.h"
#include "EmployeeDatabase.h"

using namespace std;

//-----------------------------------------------------
// Build the database
//-----------------------------------------------------
bool EmployeeDatabase::buildDatabase(char *dataFile)
{
	bool OK = true;
	int numEmp, id, dept, numStores, sID;
	double sal;
	EmployeeRecord *empRec;
	CustomerList *theList;
	Store *theStore;
	char inStr[128];
	char fName[32];
	char lName[32];
	char sName[64];
	char sAddr[64];
	char sSt[32];
	char sCity[32];
	char sZip[12];


	inFile.open(dataFile, ifstream::in);
	if (!inFile.is_open())
	{
		// inFile.is_open() returns false if the file could not be found or
		//    if for some other reason the open failed.
		cout << "Unable to open file" << dataFile << "\nProgram terminating...\n";
		cout << "Press Enter to continue...";
		getc(stdin);
		return false;
	}

	// Get number of employees
	getNextLine(inStr, 128);
	numEmp = atoi(inStr);
	for (int i = 0; i<numEmp; i++)
	{
		// Instantiate an EmployeeRecord
		empRec = new EmployeeRecord();
		// Read and set the ID
		getNextLine(inStr, 127);
		id = atoi(inStr);
		empRec->setID(id);
		// Read and set the name
		getNextLine(fName, 31);
		getNextLine(lName, 31);
		empRec->setName(fName, lName);
		// Read and set the Department ID
		getNextLine(inStr, 127);
		dept = atoi(inStr);
		empRec->setDept(dept);
		// Read and set the Salary
		getNextLine(inStr, 127);
		sal = atof(inStr);
		empRec->setSalary(sal);
		// Get the customer list
		theList = empRec->getCustomerList();
		// Get the number of stores
		getNextLine(inStr, 127);
		numStores = atoi(inStr);
		for (int j = 0; j<numStores; j++)
		{
			// Read the store ID
			getNextLine(inStr, 127);
			sID = atoi(inStr);
			// Read the store name
			getNextLine(sName, 63);
			// Read the store address
			getNextLine(sAddr, 63);
			// Read the store city
			getNextLine(sCity, 31);
			// Read the store state
			getNextLine(sSt, 31);
			// Read the store zip
			getNextLine(sZip, 11);
			// Create a new Store object
			theStore = new Store(sID, sName, sAddr, sCity, sSt, sZip);
			theList->addStore(theStore);
		}
		cout.flush();
		addEmployee(empRec);
	}
	inFile.close();
	return true;    // Successfully built the database
}



//--------------------------------------------
// GetNextLine()
// Read a line from a data file.
// Author: Rick Coleman
// Used by permission
//--------------------------------------------
bool EmployeeDatabase::getNextLine(char *line, int lineLen)
{
	int    done = false;
	while (!done)
	{
		inFile.getline(line, 128);

		if (inFile.good())    // If a line was successfully read
		{
			if (strlen(line) == 0)  // Skip any blank lines
				continue;
			else if (line[0] == '#')  // Skip any comment lines
				continue;
			else return true;    // Got a valid data line so return with this line
		}
		else
		{
			strcpy(line, "");
			return false;
		}
	} // end while
	return false;
}

EmployeeDatabase::EmployeeDatabase()
{
	m_pRoot = NULL;
}

EmployeeDatabase::~EmployeeDatabase()
{
	destroyTree(m_pRoot);
	m_pRoot = NULL;
}

void EmployeeDatabase::destroyTree(EmployeeRecord *rt)
{
	if (rt == NULL)
		return;

	destroyTree(rt->m_pLeft);
	cout << "Delete: " << rt->getID() << endl;
	destroyTree(rt->m_pRight);
	delete rt;
}

bool EmployeeDatabase::addEmployee(EmployeeRecord *e)
{
	EmployeeRecord *temp;
	EmployeeRecord *back;

	temp = m_pRoot;
	back = NULL;

	while (temp != NULL)
	{
		back = temp;
		if (e->getID() < temp->getID())
			temp = temp->m_pLeft;
		else
			temp = temp->m_pRight;
	}


	if (back == NULL)
	{
		m_pRoot = e;
	}


	else
	{
		if (e->getID() < back->getID())
			back->m_pLeft = e;
		else
			back->m_pRight = e;
	}

	return(true);

}

void EmployeeDatabase::printEmployeeRecords()
{
	printEmployeeRecords(m_pRoot);
}

void EmployeeDatabase::printEmployeeRecords(EmployeeRecord *rt)
{
	if (rt != NULL)
	{
		printEmployeeRecords(rt->m_pLeft);

		rt->printRecord();

		printEmployeeRecords(rt->m_pRight);
	}
}

EmployeeRecord* EmployeeDatabase::getEmployee(int ID)
{
	EmployeeRecord *temp;
	temp = m_pRoot;

	while ((temp != NULL) && (temp->getID() != ID))
	{
		if (ID < temp->getID())
		{
			temp = temp->m_pLeft;
		}

		else
		{
			temp = temp->m_pRight;
		}

	}

	if (temp == NULL)
	{
		return NULL;
	}

	else
	{
		return temp;
	}
}

EmployeeRecord *EmployeeDatabase::removeEmployee(int ID)
{
	EmployeeRecord *back, *temp, *delParent, *delNode, *left, *right;

	temp = m_pRoot;
	back = NULL;

	while ((temp != NULL) && (ID != temp->getID()))
	{
		back = temp;
		if (ID < temp->getID())
			temp = temp->m_pLeft;
		else
			temp = temp->m_pRight;
	}

	if (temp == NULL)
	{
		return NULL;
	}

	else
	{
		delNode = temp;
		delParent = back;
	}

	//one child on left
	if (delNode == NULL)
	{
		if (delParent == NULL)
		{
			m_pRoot = delNode->m_pLeft;
			delNode->m_pLeft = NULL;
			return delNode;
		}

		else
		{
			if (delParent->m_pLeft == delNode)
				delParent->m_pLeft = delNode->m_pLeft;
			else
				delParent->m_pRight = delNode->m_pLeft;
			delNode->m_pLeft = NULL;
			return delNode;
		}
	}

	else
	{
		if (delNode->m_pLeft == NULL)
		{
			if (delParent == NULL)
			{
				m_pRoot = delNode->m_pRight;
				delNode->m_pRight = NULL;
				return delNode;
			}

			else
			{
				if (delParent->m_pLeft == delNode)
					delParent->m_pLeft = delNode->m_pRight;
				else
					delParent->m_pRight = delNode->m_pRight;
				delNode->m_pRight = NULL;
				return delNode;
			}
		}

		else
		{
			temp = delNode->m_pLeft;
			back = delNode;

			while (temp->m_pRight != NULL)
			{
				back = temp;
				temp = temp->m_pRight;
			}

			EmployeeRecord *side = new EmployeeRecord();
			side->destroyCustomerList();
			right = delNode->m_pRight;
			left = delNode->m_pLeft;

			*side = *delNode;
			*delNode = *temp;
			delNode->m_pLeft = left;
			delNode->m_pRight = right;

			temp->removeCustomerList();
			side->m_pRight = NULL;
			side->m_pLeft = NULL;

			if (back == delNode)
				back->m_pLeft = temp->m_pLeft;
			else
				back->m_pRight = temp->m_pRight;
			delete temp;
			return side;
		}
	}
}