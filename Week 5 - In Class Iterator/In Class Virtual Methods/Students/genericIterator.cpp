#include<iostream>
using std::cout; 
using std::endl;

#include "genericIterator.h"

GenericIterator::GenericIterator() : BaseIterator()
{
	cout << "In no arg generic iterator c'tor" << endl; 
}

GenericIterator::GenericIterator(Student * s) :
	BaseIterator(s)
{
	cout << "in 2 arg generic iterator c'tor" << endl; 
}

void GenericIterator::First()
{
	m_cursor = 0;	//set to the first element of array
}

void GenericIterator::MoveNext()
{
	++m_cursor;		//increment by one 
}

bool GenericIterator::IsDone()
{
	return m_cursor >= 5;	//5 is an arbitrary num
}

Student & GenericIterator::GetCurrent()
{
	if (IsDone())
		cout << "Maybe throw an exception" << endl;

	return students[m_cursor]; 
}

GenericIterator::~GenericIterator()
{
	cout << "in generic iterator d'tor" << endl; 
}
