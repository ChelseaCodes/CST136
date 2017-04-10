#include<iostream>
using std::cout;
using std::endl; 
using namespace std; 

#include "person.h"

Person::Person():m_age(0)
{
	cout << "In Person no arg c'tor" << endl;
	m_fname[0] = '\0';
	m_lname[0] = '\0';
}

Person::Person(int age, char * fname, char * lname) :m_age(age)
{
	cout << "in person 3 arg c'tor" << endl; 
	strcpy(m_fname, fname);
	strcpy(m_lname, lname); 
}

int Person::GetAge()
{
	return m_age; 
}

void Person::Display()
{
	cout << m_fname << ", " << m_lname 
		 << ", " << m_age; 
}

Person::~Person()
{
	cout << "in person d'tor " << endl; 
}
