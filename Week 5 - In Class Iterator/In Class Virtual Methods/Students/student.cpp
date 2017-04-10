#include<iostream>
using std::cout;
using std::endl;

#include "student.h"

Student::Student() :m_score(0)
{
	cout << "No arg student c'tor" << endl;
	m_fname[0] = '\0';
}

Student::Student(char n[], int s) : m_score(s)
{
	cout << "in student 2 arg c'tor" << endl;
	strcpy(m_fname, n); 
}

Student::Student(const Student & s)
{
	cout << "In student copy c'tor" << endl; 
	if (s.m_fname == 0)
	{
		m_fname[0] = '\0';
	}
	else
	{
		strcpy(m_fname, s.m_fname);
		m_score = s.m_score; 
	}
}

void Student::Display()
{
	cout << m_fname << ", " << m_score << endl;
}

Student::~Student()
{
	cout << "in student d'tor" << endl;
}
