/*******************************************************************
*   EmployeeRecord.h
*   Ryan Davis
*   Programming Assignment 3 and Statement of Work
*   Due Date: July 16,2018
*   This program is entirely my own work
*******************************************************************/


#pragma once
#include <iostream>
#include <string.h>
#include "CustomerList.h"
#include <iomanip>


class EmployeeRecord
{
private:

	int m_iEmployeeID;
	char m_LastName[32];
	char m_FirstName[32];
	int m_iDeptID;
	double m_dSalary;
	CustomerList *m_pCustomerList;


public:

	EmployeeRecord();
	EmployeeRecord(int ID, char *fName, char *lName, int dept, double sal);
	~EmployeeRecord();
	int getID();
	void setID(int ID);
	void getName(char *fName, char *lName);
	void setName(char *fName, char *lName);
	int getDept();
	void setDept(int d);
	double getSalary();
	void setSalary(double sal);
	void printRecord();
	void removeCustomerList();
	void destroyCustomerList();
	CustomerList *getCustomerList();
	EmployeeRecord *m_pLeft;
	EmployeeRecord *m_pRight;

};



