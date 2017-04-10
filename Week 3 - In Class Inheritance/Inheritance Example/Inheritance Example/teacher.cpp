#include "teacher.h"

Teacher::Teacher()
{
	cout << "no arg Teacher c'tor" << endl;
}

Teacher::Teacher(int age, char * fname, char * lname, int years)
	: Person(age, fname, lname),
	m_years(years)
{
	cout << "4 arg teacher c'tor" << endl; 
}

void Teacher::Display()
{
	Person::Display();
	cout << "\nYears of service: " << m_years << "\n" << endl; 
}

Teacher::~Teacher()
{
	cout << "in teacher d'tor" << endl;
}
