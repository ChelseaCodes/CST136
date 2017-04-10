#include<iostream>
using std::strcpy; 
using std::strlen; 

#include "Date.h"
using namespace std; 

Date::Date()
{
	cout << "No arg c'tor" << endl; 

	m_month = 0;
	m_day = 0; 
	m_year = 0; 

	m_quote = new char[1]; 
	m_quote[0] = '\0'; 
}

Date::Date(int m, int d, int y, char * quote)
{
	cout << "Four arg c'tor" << endl;

	m_month = m;
	m_day = d; 
	m_year = y; 

	m_quote = new char[strlen(quote + 1)];
	strcpy(m_quote, quote); 

}

Date::Date(const Date & date)
{
	cout << "in copy c'tor" << endl;
	m_month = date.m_month; 
	m_day = date.m_day; 
	m_year = date.m_year; 

	if (strlen(date.m_quote) == 0)
	{
		m_quote = new char[1]; 
		strcpy(m_quote, date.m_quote); 

	}
}

void Date::Display()
{
	cout << m_month << " " << m_day << " " << m_year
		<< " " << m_quote << endl; 
}
