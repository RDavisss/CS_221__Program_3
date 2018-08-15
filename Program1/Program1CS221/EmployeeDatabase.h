/*******************************************************************
*   EmployeeDatabase.h
*   Ryan Davis
*   Programming Assignment 3 and Statement of Work
*   Due Date: July 16,2018
*   This program is entirely my own work
*******************************************************************/


#pragma once
#include "EmployeeRecord.h"
#include <fstream>

using namespace std;


class EmployeeDatabase
{

private:
	EmployeeRecord *m_pRoot;
	ifstream inFile;
	bool getNextLine(char *line, int lineLen);
	void printEmployeeRecords(EmployeeRecord *rt);
	void destroyTree(EmployeeRecord *rt);

public:
	EmployeeDatabase();
	~EmployeeDatabase();
	bool addEmployee(EmployeeRecord *e);
	EmployeeRecord *getEmployee(int ID);
	EmployeeRecord *removeEmployee(int ID);
	void printEmployeeRecords();
	bool buildDatabase(char *dataFile);
};

