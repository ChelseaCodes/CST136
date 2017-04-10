#include "baseIterator.h"

BaseIterator::BaseIterator():m_cursor(0)
{
	cout << "In no arg base iterator" << endl; 
	students = nullptr; 
}

BaseIterator::BaseIterator(Student * s)
{
	cout << "In 2 arg base iterator c'tor" << endl;
	m_cursor = 0; 
	this->students = students; 
}

BaseIterator::~BaseIterator()
{
	cout << "In PVM Base iterator d'tor" << endl; 
}
