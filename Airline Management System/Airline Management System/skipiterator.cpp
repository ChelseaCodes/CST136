#include<iostream>
using std::cout;
using std::endl; 

#include "skipiterator.h"

SkipIterator::SkipIterator()
{
	cout << "Default SkipIterator c'tor" << endl;
	CityList = nullptr; 
}

SkipIterator::SkipIterator(Llist * citylist) : GenericIterator(citylist)
{
	cout << "1 arg SkipIterator c'tor" << endl; 
}

void SkipIterator::First()
{
	GenericIterator::First();
}

void SkipIterator::MoveNext()
{
	GenericIterator::MoveNext(); 
	GenericIterator::MoveNext(); 
}

bool SkipIterator::IsDone()
{
	return GenericIterator::IsDone(); 
}

Node * SkipIterator::GetCurrent()
{
	if (IsDone())
	{
		cout << "At end of Air List, returning to beginning" << endl;
		First();
	}
	else
		return m_cursor;
}

SkipIterator::~SkipIterator()
{
	cout << "SkipIterator d'tor" << endl;
}
