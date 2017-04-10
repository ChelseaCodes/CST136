/*************************************************************
* Author:		Chelsea Christison
* Filename:		fnode.cpp
* Date Created:	02.17.2017
* Modifications:	
**************************************************************/
#include<iostream>
using std::cout;
using std::endl;

#include<iostream>
using std::ostream;

#include<iomanip>
using std::setw;
using std::left;

#include "fnode.h"

FNode::FNode()
{
	cout << "Default Fnode c'tor" << endl; 
	m_next = nullptr;
}

FNode::FNode(Flight * f_new) :m_next(nullptr)
{
	cout << "1 arg FNode c'tor" << endl;
	m_data = f_new;		//assigning pointer only 
}

FNode::FNode(const FNode & newnode)
{
	cout << "FNode copy c'tor" << endl;
	m_data = newnode.m_data; 
	m_next = newnode.m_next; 
}

FNode & FNode::operator=(const FNode & newnode)
{
	cout << "FNode op=" << endl; 
	if (this != &newnode)
	{
		m_data = newnode.m_data;
		m_next = newnode.m_next;
	}
	return *this; 
}

char * FNode::GetCode()
{
	return m_data->GetCode();
}

char * FNode::GetName()
{
	return m_data->GetName(); 
}

char * FNode::GetMan()
{
	return m_data->GetMan();
}

char * FNode::GetDest()
{
	return m_data->GetDest(); 
}

int FNode::GetDist()
{
	return m_data->GetDist();
}

int FNode::GetCost()
{
	return m_data->GetCost();
}

FNode::~FNode()
{
	cout << "FNode d'tor" << endl;
	delete m_data; //need to delete this
}

ostream & operator<<(ostream & os, FNode * data)
{
	os << setw(11) << left << data->m_data->GetCode()
		<< setw(15) << left << data->m_data->GetName()
		<< setw(15) << left << data->m_data->GetMan()
		<< setw(12) << left << data->m_data->GetDest()
		<< data->m_data->GetDist() << " mi.\t"
		<< "$" << data->m_data->GetCost();

	return os; 
}
