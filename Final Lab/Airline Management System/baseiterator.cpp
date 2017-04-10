#include<iostream>
using std::cout;
using std::cin; 
using std::endl; 

#include "baseiterator.h"

BaseIterator::BaseIterator()
{
	cout << "Default BaseIterator c'tor" << endl;
	m_cursor = nullptr; 
	CityList = nullptr; 
}

BaseIterator::BaseIterator(TLList<City> * citylist)
{
	cout << "1 arg BaseIterator c'tor" << endl;
	this->CityList = citylist;	//assigns pointer
	m_cursor = CityList->GetHead();
}

BaseIterator::~BaseIterator()
{
	cout << "BaseIterator d'tor" << endl;
}
