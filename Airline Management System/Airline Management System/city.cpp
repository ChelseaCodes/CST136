/*************************************************************
* Author:		Chelsea Christison
* Filename:		city.cpp
* Date Created:	02.17.2017
* Modifications:	2.17.2017 - Overloaded comparison ops
**************************************************************/
#include<iostream>
using std::cout;
using std::endl;

#include<fstream>
using std::ofstream; 

#include<iostream>
using std::ostream;

#include "city.h"

City::City():m_flights(0)
{
	cout << "Default City c'tor" << endl;
	m_code[0] = '\0'; 
	m_name[0] = '\0';
	m_mangr[0] = '\0';
	m_phone[0] = '\0';
}

City::City(char c[] , char n[], char m[], char pn[], int nf):m_flights(nf)
{
	cout << "5 arg City c'tor" << endl; 

	strcpy(m_code, c); 
	strcpy(m_name, n);
	strcpy(m_mangr, m);
	strcpy(m_phone, pn);

	flight_list = new FLList(); 
}

City::City(const City & city)
{
	cout << "City copy c'tor" << endl; 
	if (strlen(city.m_code) == 0 || strlen(city.m_name) == 0 ||
		strlen(city.m_mangr) == 0 || strlen(city.m_phone) == 0)
	{
		m_code[0] = '\0';
		m_name[0] = '\0';
		m_mangr[0] = '\0';
		m_phone[0] = '\0';
	}
	else
	{
		strcpy(m_code, city.m_code);
		strcpy(m_name, city.m_name);
		strcpy(m_mangr, city.m_mangr);
		strcpy(m_phone, city.m_phone);
		m_flights = city.m_flights;
		flight_list = city.flight_list;
	}
}

City & City::operator=(const City & city)
{
	cout << "City op=" << endl; 
	if (this != &city)
	{
		if (strlen(city.m_code) == 0 || strlen(city.m_name) == 0 ||
			strlen(city.m_mangr) == 0 || strlen(city.m_phone) == 0)
		{
			m_code[0] = '\0';
			m_name[0] = '\0';
			m_mangr[0] = '\0';
			m_phone[0] = '\0';
		}
		else
		{
			strcpy(m_code, city.m_code);
			strcpy(m_name, city.m_name);
			strcpy(m_mangr, city.m_mangr);
			strcpy(m_phone, city.m_phone);
			m_flights = city.m_flights;
			flight_list = city.flight_list; 
		}
	}
	return *this; 
}

char * City::GetName()
{
	char * name = m_name; 
	return m_name;
}

char * City::GetCode()
{
	char * code = m_code; 
	return m_code;
}

char * City::GetMan()
{
	char * mangr = m_mangr; 
	return m_mangr;
}

char * City::GetPhone()
{
	char * phone = m_phone; 
	return m_phone; 
}

int City::GetFlightNum()
{
	return m_flights;
}

FLList * City::GetFlightList()
{
	return flight_list;
}

void City::InsertIntoFlightList(Flight * new_flight)
{
	flight_list->InsertOrdered(new_flight); 
}

void City::Display()
{
	cout << m_code << " " << m_name << " " << m_mangr << " " << m_phone
		<< " " << m_flights << "\n";
}

City::~City()
{
	cout << "City d'tor" << endl; 
	delete flight_list;
	m_code[0] = 0;
	m_name[0] = 0;
	m_mangr[0] = 0;
	m_phone[0] = 0; 
}

bool operator<=(const City & ls, const City & rs)
{
	return (stricmp(ls.m_name, rs.m_name) <= 0);
}

bool operator>=(const City & ls, const City & rs)
{
	return (stricmp(ls.m_name, rs.m_name) >= 0);
}

bool operator==(const City & ls, const char * rs)
{
	return (stricmp(ls.m_name, rs) == 0 || stricmp(ls.m_code, rs) == 0);
}
