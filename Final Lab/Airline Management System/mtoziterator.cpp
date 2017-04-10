/*************************************************************
* Author:		Chelsea Christison
* Filename:		mtoziterator.cpp
* Date Created:	02.17.2017
* Modifications:
**************************************************************/
#include<iostream>
using std::cout;
using std::endl;

#include "mtoziterator.h"

MtoZIterator::MtoZIterator()
{
	cout << "Default MtoZIterator c'tor" << endl; 
}

MtoZIterator::MtoZIterator(TLList<City> * citylist) : BaseIterator(citylist)
{
	cout << "1 arg MtoZIterator c'tor" << endl;
}

void MtoZIterator::First()
{
	if (CityList->GetHead() != nullptr)
	{
		m_cursor = CityList->GetHead();
		MtoZIterator::MoveNext();
	}
}

void MtoZIterator::MoveNext()
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
			if (name[i] < 'm')
				MtoZIterator::MoveNext();
		}
	}
}

bool MtoZIterator::IsDone()
{
	if (this->m_cursor == nullptr)
		return true;
	else
		return false;
}

Node<City> * MtoZIterator::GetCurrent()
{
	if (IsDone())
	{
		cout << "At end of Air List's M - Z, returning to beginning" << endl;
		First();
	}
	else
		return m_cursor;
}

MtoZIterator::~MtoZIterator()
{
	cout << "MtoZIterator d'tor" << endl; 
}
