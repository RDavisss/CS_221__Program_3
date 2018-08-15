/*******************************************************************
*   CustomerList.cpp
*   Ryan Davis
*   Programming Assignment 3 and Statement of Work
*   Due Date: July 16,2018
*   This program is entirely my own work
*******************************************************************/



#include <iostream>
#include "CustomerList.h"
#include "Store.h"
#include "EmployeeRecord.h"


using namespace std;

CustomerList::CustomerList()
{
	m_pHead = NULL;
}

CustomerList::~CustomerList()
{
	clearStores(m_pHead);
}

bool CustomerList::addStore(Store *s)
{
	Store *back = NULL;
	Store *temp = m_pHead;

	if (m_pHead == NULL)
	{
		m_pHead = s;

		return true;
	}

	else
	{
		while ((temp != NULL) && (temp->getStoreID() < s->getStoreID()))
		{
			back = temp;
			temp = temp->m_pNext;
		}

		if (back == NULL)
		{
			s->m_pNext = m_pHead;
			m_pHead = s;
			return true;
		}

		else
		{
			back->m_pNext = s;
			s->m_pNext = temp;
			return true;
		}

	}

	return false;
}

Store *CustomerList::getStore(int ID)
{
	Store *temp;
	temp = m_pHead;

	while ((temp != NULL) && (ID != temp->getStoreID()))
	{
		temp = temp->m_pNext;
	}

	if (temp == NULL)
		return NULL;

	else
	{
		Store *retItem = new Store();
		*retItem = *temp;
		retItem->m_pNext = NULL;
		return retItem;
	}
}

Store *CustomerList::removeStore(int ID)
{
	Store *back = NULL;
	Store *temp = m_pHead;

	while ((temp != NULL) && (ID != temp->getStoreID()))
	{
		back = temp;
		temp = temp->m_pNext;
	}

	if (temp == NULL)
		return NULL;

	else if (back == NULL)
	{
		m_pHead = m_pHead->m_pNext;
		return temp;
	}

	else
	{
		back->m_pNext = temp->m_pNext;
		return temp;
	}

	return NULL;
}

bool CustomerList::updateStore(int ID, char *name, char *addr, char *city,
	char *st, char *zip)
{
	Store *temp;
	temp = m_pHead;

	while ((temp != NULL) && (ID != temp->getStoreID()))
	{
		temp = temp->m_pNext;
	}

	if (temp == NULL)
	{
		return false;
	}

	else
	{
		temp->setStoreName(name);
		temp->setStoreAddress(addr);
		temp->setStoreCity(city);
		temp->setStoreState(st);
		temp->setStoreZip(zip);

		return true;
	}
}

void CustomerList::printStoresInfo()
{
	Store *temp = m_pHead;


	if (m_pHead == NULL)
	{
		cout << "The list is currently empty." << endl;
	}

	else
	{
		temp = m_pHead;

		while (temp != NULL)
		{
			temp->printStoreInfo();
			temp = temp->m_pNext;
		}
	}
}

void CustomerList::clearStores(Store *head)
{
	Store *temp;

	if (head != NULL)
	{
		temp = head;
		head = head->m_pNext;
		delete temp;
	}
}

