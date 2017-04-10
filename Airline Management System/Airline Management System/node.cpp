/*************************************************************
* Author:		Chelsea Christison
* Filename:		node.cpp
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

#include "node.h"

Node::Node()
{
	cout << "Default Node c'tor" << endl;
	m_next = nullptr;
	m_previous = nullptr;
}

Node::Node(City * c_new) : m_next(nullptr), m_previous(nullptr)
{
	cout << "1 arg Node c'tor" << endl; 
	m_data = c_new;		//This will just point to the new city obj made 
}

Node::Node(const Node & c_node)
{
	cout << "Node copy c'tor" << endl; 
	m_data = c_node.m_data; 
	m_next = c_node.m_next; 
	m_previous = c_node.m_previous;
}

Node & Node::operator=(const Node & c_node)
{
	cout << "Node op=" << endl; 
	if (this != &c_node)
	{
		m_data = c_node.m_data;
		m_next = c_node.m_next;
		m_previous = c_node.m_previous;
	}
	return *this; 
}

char * Node::GetName()
{
	return m_data->GetName();
}

char * Node::GetCode()
{
	return m_data->GetCode();
}

char * Node::GetMan()
{
	return m_data->GetMan(); 
}

char * Node::GetPhone()
{
	return m_data->GetPhone(); 
}

FLList * Node::GetCityFlights()
{
	return  m_data->GetFlightList();
}

Node * Node::GetNext()
{
	if (m_next == nullptr)
		return nullptr;
	else
		return m_next;
}

Node * Node::GetPrevious()
{
	return m_previous;
}

Node::~Node()
{
	cout << "Node d'tor" << endl; 
	delete m_data;	//need to free mem allocated during read in 
}

ostream & operator<<(ostream & os, Node * data)
{
	os << setw(11) << left << data->m_data->GetCode()
		<< setw(15) << left << data->m_data->GetName()
		<< setw(15) << left << data->m_data->GetMan()
		<< setw(15) << left << data->m_data->GetPhone();		
	return os; 
}
