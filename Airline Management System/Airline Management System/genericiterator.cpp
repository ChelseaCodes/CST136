/*************************************************************
* Author:		Chelsea Christison
* Filename:		genericiterator.cpp
* Date Created:	02.17.2017
* Modifications:	
**************************************************************/
#include<iostream>
using std::cout;
using std::endl; 

#include "genericiterator.h"

GenericIterator::GenericIterator()
{
	cout << "Default GenericIterator c'tor" << endl; 
	CityList = nullptr; 
}

GenericIterator::GenericIterator(Llist * citylist) : BaseIterator(citylist)
{
	cout << "1 arg GenericIterator c'tor" << endl;
}

void GenericIterator::First()
{
	//set to head of linked list
	m_cursor = CityList->GetHead(); 
}

void GenericIterator::MoveNext()
{
	if (!IsDone())
		m_cursor = m_cursor->GetNext();
}

bool GenericIterator::IsDone()
{
	if (m_cursor == nullptr)
		return true;
	else
		return false; 
}

Node * GenericIterator::GetCurrent()
{
	if (IsDone())
	{
		cout << "At end of Air List, returning to beginning" << endl;
		First(); 
	}
	else
		return m_cursor;
}

GenericIterator::~GenericIterator()
{
	cout << "GenericIterator d'tor" << endl; 
}
