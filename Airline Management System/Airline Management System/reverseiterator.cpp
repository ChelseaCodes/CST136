/*************************************************************
* Author:		Chelsea Christison
* Filename:		reverseiterator.cpp
* Date Created:	02.17.2017
* Modifications:
**************************************************************/
#include<iostream>
using std::cout;
using std::endl;

#include "reverseiterator.h"

ReverseIterator::ReverseIterator()
{
	cout << "Default ReverseIterator c'tor" << endl; 
}

ReverseIterator::ReverseIterator(Llist * citylist) : BaseIterator(citylist)
{
	cout << "1 arg ReverseIterator c'tor" << endl;
}

void ReverseIterator::First()
{
	m_cursor = CityList->GetTail(); 
}

void ReverseIterator::MoveNext()
{
	if (!IsDone())
	{
		m_cursor = m_cursor->GetPrevious(); 
	}
}

bool ReverseIterator::IsDone()
{
	if (m_cursor == nullptr)
		return true;
	else
		return false; 
}

Node * ReverseIterator::GetCurrent()
{
	if (IsDone())
	{
		cout << "At the end of list, returning to beginning" << endl;
		First();
	}
	else
		return m_cursor; 
}

ReverseIterator::~ReverseIterator()
{
	cout << "ReverseIterator d'tor" << endl; 
}
