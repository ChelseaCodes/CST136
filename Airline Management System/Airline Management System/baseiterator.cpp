/*************************************************************
* Author:		Chelsea Christison
* Filename:		baseiterator.cpp
* Date Created:	02.17.2017
* Modifications:	
**************************************************************/
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

BaseIterator::BaseIterator(Llist * citylist)
{
	cout << "1 arg BaseIterator c'tor" << endl;
	this->CityList = citylist;	//assigns pointer
	m_cursor = CityList->m_head;
}

BaseIterator::~BaseIterator()
{
	cout << "BaseIterator d'tor" << endl;
}
