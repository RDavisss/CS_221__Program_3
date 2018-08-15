/*******************************************************************
*   EmployeeRecord.cpp
*   Ryan Davis
*   Programming Assignment 3 and Statement of Work
*   Due Date: July 16,2018
*   This program is entirely my own work
*******************************************************************/

#include "EmployeeRecord.h"
#include "CustomerList.h"
#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;


EmployeeRecord::EmployeeRecord()
{
	strcpy(m_FirstName, " ");
	strcpy(m_LastName, " ");
	int m_iEmployeeID = 0;
	int m_iDeptID = 0;
	double m_dSalary = 0.0;
	m_pCustomerList = new CustomerList();
	m_pLeft = NULL;
	m_pRight = NULL;
}


EmployeeRecord::EmployeeRecord(int ID, char *fName, char *lName, int dept, double sal)
{
	strcpy(m_FirstName, fName);
	strcpy(m_LastName, lName);

	m_iEmployeeID = ID;
	m_iDeptID = dept;
	m_dSalary = sal;
}


EmployeeRecord::~EmployeeRecord()
{
	if (m_pCustomerList != NULL)
	{
		delete m_pCustomerList;
	}

	else
	{
		return;
	}
}

int EmployeeRecord::getID()
{
	return m_iEmployeeID;
}


void EmployeeRecord::setID(int ID)
{
	m_iEmployeeID = ID;

}


void EmployeeRecord::getName(char *fName, char *lName)
{

	strcpy(fName, m_FirstName);
	strcpy(lName, m_LastName);
}


void EmployeeRecord::setName(char *fName, char *lName)
{
	strcpy(m_FirstName, fName);

	strcpy(m_LastName, lName);

}


int EmployeeRecord::getDept()
{
	return m_iDeptID;
}


void EmployeeRecord::setDept(int d)
{
	m_iDeptID = d;

	
}


double EmployeeRecord::getSalary()
{
	return m_dSalary;
}


void EmployeeRecord::setSalary(double sal)
{
	m_dSalary = sal;
}

CustomerList *EmployeeRecord::getCustomerList()
{
	return m_pCustomerList;
}

void EmployeeRecord::printRecord()
{
	cout << "\tID = " << m_iEmployeeID << endl;
	cout << "\tLast = " << m_LastName << endl;
	cout << "\tFirst = " << m_FirstName << endl;
	cout << "\tDept = " << m_iDeptID << endl;
	cout << "\tSalary = $" << m_dSalary << endl;
	cout << "\n\n";

}

void EmployeeRecord::removeCustomerList()
{
	m_pCustomerList = NULL;
}

void EmployeeRecord::destroyCustomerList()
{
	delete(m_pCustomerList);
	m_pCustomerList = NULL;
}


