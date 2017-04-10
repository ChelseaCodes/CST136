/*************************************************************
* Author:		Chelsea Christison
* Filename:		atoliterator.cpp
* Date Created:	02.17.2017
* Modifications:	
**************************************************************/
#include<iostream>
using std::cout;
using std::endl;

#include "atoliterator.h"

AtoLIterator::AtoLIterator()
{
	cout << "Default AtoLIterator c'tor" << endl; 
}

AtoLIterator::AtoLIterator(TLList<City> * citylist) : BaseIterator(citylist)
{
	cout << "1 arg AtoLIterator c'tor" << endl; 
}

void AtoLIterator::First()
{
	if (CityList->GetHead() != nullptr)
	{
		m_cursor = CityList->GetHead();
		while (IsDone())
		{
			m_cursor = m_cursor->GetNext();
		}
	}
}

void AtoLIterator::MoveNext()
{
	char * name = nullptr;
	int i(0);
	if (!IsDone())
	{
		m_cursor = m_cursor->GetNext();
		if (!IsDone())
		{
			name = m_cursor->GetData()->GetName();
			i = 0;
			while (name[i] != '\0')
				i++;
			i--; //looks at the very last letter of name
			if (name[i] > 'l')
				AtoLIterator::MoveNext(); 
		}
	}
}

bool AtoLIterator::IsDone()
{
	//at the end? 
	if (this->m_cursor == nullptr)
		return true;
	else
		return false;
}

Node<City> * AtoLIterator::GetCurrent()
{
	if (IsDone())
	{
		cout << "At end of Air List's A - L, returning to beginning" << endl;
		First();
	}
	else
		return m_cursor;
}

AtoLIterator::~AtoLIterator()
{
	cout << "AtoLIterator d'tor" << endl; 
}