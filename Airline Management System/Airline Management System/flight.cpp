/*************************************************************
* Author:		Chelsea Christison
* Filename:		flight.cpp
* Date Created:	02.17.2017
* Modifications:	
**************************************************************/
#include<iostream>
using std::cout;
using std::endl;

#include<fstream>
using std::ofstream;

#include<iostream>
using std::ostream;

#include "flight.h"

Flight::Flight() :m_distance(0), m_cost(0)
{
	cout << "Default Flight c'tor" << endl; 
	m_flcode[0] = '\0';
	m_flname[0] = '\0';
	m_flmana[0] = '\0';
	m_destination[0] = '\0';
}

Flight::Flight(char c[], char n[], char m[], char d[], int dis, int cost)
	:m_distance(dis), m_cost(cost)
{
	cout << "6 arg Flight c'tor" << endl;

	strcpy(m_flcode, c); 
	strcpy(m_flname, n); 
	strcpy(m_flmana, m); 
	strcpy(m_destination, d); 
}

Flight::Flight(const Flight & flight)
{
	cout << "Flight copy c'tor" << endl;
	if (strlen(flight.m_flcode) == 0 || strlen(flight.m_flname) == 0 ||
		strlen(flight.m_flmana) == 0 || strlen(flight.m_destination) == 0)
	{
		m_flcode[0] = '\0';
		m_flname[0] = '\0';
		m_flmana[0] = '\0';
		m_destination[0] = '\0';
	}
	else
	{
		strcpy(m_flcode, flight.m_flcode);
		strcpy(m_flname, flight.m_flname);
		strcpy(m_flmana, flight.m_flmana);
		strcpy(m_destination, flight.m_destination);
		m_distance = flight.m_distance; 
		m_cost = flight.m_cost; 
	}
}

Flight & Flight::operator=(const Flight & flight)
{
	cout << "Flight op=" << endl; 

	if (this != &flight)
	{
		if (strlen(flight.m_flcode) == 0 || strlen(flight.m_flname) == 0 ||
			strlen(flight.m_flmana) == 0 || strlen(flight.m_destination) == 0)
		{
			m_flcode[0] = '\0';
			m_flname[0] = '\0';
			m_flmana[0] = '\0';
			m_destination[0] = '\0';
		}
		else
		{
			strcpy(m_flcode, flight.m_flcode);
			strcpy(m_flname, flight.m_flname);
			strcpy(m_flmana, flight.m_flmana);
			strcpy(m_destination, flight.m_destination);
			m_distance = flight.m_distance;
			m_cost = flight.m_cost;
		}
	}

	return *this; 
}

char * Flight::GetCode()
{
	return m_flcode;
}

char * Flight::GetName()
{
	return m_flname;
}

char * Flight::GetMan()
{
	return m_flmana;
}

char * Flight::GetDest()
{
	return m_destination;
}

int Flight::GetDist()
{
	return m_distance;
}

int Flight::GetCost()
{
	return m_cost;
}

void Flight::Display()
{
	cout << m_flcode << ' ' << m_flname << ' ' << m_flmana << ' '
		<< m_destination << ' ' << m_distance << ' ' << m_cost << "\n"; 
}

Flight::~Flight()
{
	cout << "Flight d'tor" << endl;
	m_flcode[0] = '\0';
	m_flname[0] = '\0';
	m_flmana[0] = '\0';
	m_destination[0] = '\0';
}

bool operator<=(const Flight & ls, const Flight & rs)
{
	return (stricmp(ls.m_flname, rs.m_flname) <= 0);
}

bool operator>=(const Flight & ls, const Flight & rs)
{
	return (stricmp(ls.m_flname, rs.m_flname) >= 0);
}

bool operator==(const Flight & ls, char * rs)
{
	return (stricmp(ls.m_flname, rs) == 0 || stricmp(ls.m_flcode, rs) == 0);
}
