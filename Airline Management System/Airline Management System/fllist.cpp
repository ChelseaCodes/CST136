/*************************************************************
* Author:		Chelsea Christison
* Filename:		fllist.cpp
* Date Created:	02.17.2017
* Modifications:	
**************************************************************/
#include<iostream>
using std::cout;
using std::endl;

#include<fstream>
using std::ofstream;

#include<iomanip>
using std::setw;
using std::left;

#include "fllist.h"

FLList::FLList() :m_nodecount(0), m_head(nullptr), m_tail(nullptr)
{
	cout << "Default FLList c'tor" << endl;
}

FLList::FLList(const FLList & list_copy)
{
	cout << "FLList copy c'tor" << endl; 
	if (list_copy.m_nodecount == 0)
	{
		m_head = nullptr; 
		m_tail = nullptr; 
	}
	else
	{
		FNode * copytemp = list_copy.m_head; 
		FNode * thistemp = m_head; 
		for (int i(0); i < list_copy.m_nodecount; i++)
		{
			thistemp = new FNode(copytemp->m_data);
			thistemp = thistemp->m_next; 
		}
	}
}

void FLList::InsertOrdered(Flight * data)
{
	FNode * travel = m_head;
	FNode * trail = nullptr;
	FNode * nn = nullptr;
	nn = new FNode(data);

	if (m_head == nullptr || (*nn->m_data <= *m_head->m_data))		//head is null, first in the list
	{
		nn->m_next = m_head;				//set next to head
		m_head = nn; 						//head is new node 

		FNode * temp = m_head;
		while (temp->m_next != nullptr)		//while next isn't null
			temp = temp->m_next;				//traverse 

		m_tail = temp;
		m_tail->m_next = nullptr; 
	}
	else			//traverse until correct place is found 
	{
		while ((travel != nullptr) && (*nn->m_data >= *travel->m_data))
		{
			trail = travel;
			travel = travel->m_next;
		}

		trail->m_next = nn;				//exits loop at place it should be 
		nn->m_next = travel;			//set the node 
	}

	if (m_tail->m_next != nullptr)	//if tail node is not really tail
	{
		m_tail = m_tail->m_next;		//set tail to the node after 
	}
	m_nodecount++;						//incremement the node count 
}

FNode * FLList::NSearch(char * f_target)
{
	FNode * temp = m_head;
	while (temp->m_next != nullptr)
	{
		if (*temp->m_data == f_target)
		{
			return temp;
		}
		else
			temp = temp->m_next;
	}
	return nullptr;
}

bool FLList::Delete(char * f_target)
{
	FNode * prev = nullptr;
	FNode * del = nullptr;
	bool deleted = false;

	if (*m_head->m_data == f_target)
	{
		del = m_head;
		m_head = del->m_next;
		delete del;
		deleted = true;
	}
	else
	{
		bool loop = true;
		prev = m_head;
		del = m_head->m_next;

		while (del != nullptr && loop == true)
		{
			if (*del->m_data == f_target)
			{
				prev->m_next = del->m_next;		//previous next set to deletes next 				

				if (del == m_tail)
				{
					m_tail = prev;
				}
				delete del;
				deleted = true;
				loop = false;

			}
			prev = del;
			del = del->m_next;
		}
	}
	return deleted;
}

FNode * FLList::GetHead()
{
	return m_head;
}

FNode * FLList::GetTail()
{
	return m_tail;
}

void FLList::FLLPrintAll(ofstream & DataOut)
{
	FNode * temp = m_head;

	while (temp != nullptr)
	{
		DataOut << "- " <<temp << endl;
		temp = temp->m_next;
	}
}

FLList::~FLList()
{
	cout << "FLList d'tor" << endl;
	FNode * trail = nullptr;
	while (m_head != nullptr)
	{
		trail = m_head;
		m_head = m_head->m_next;
		delete trail;
	}
	m_nodecount = 0; 
	m_head = nullptr; 
	m_tail = nullptr; 
}

ostream & operator<<(ostream & os, FLList data)
{
	FNode * temp = data.GetHead(); 
	while (temp != nullptr)
	{
		os << temp; 
	}
	return os; 
}
