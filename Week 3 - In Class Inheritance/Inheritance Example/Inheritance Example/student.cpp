#include<iostream>
using std::cout;
using std::endl;

#include "student.h"

Student::Student() :m_id(0), m_gpa(0.00)
{
	cout << "No arg student c'tor" << endl; 
}

Student::Student(int id, float gpa) : m_id(id), m_gpa(gpa)
{
	cout << "in student 2 arg c'tor" << endl;
}

//will now be using base class initilization for eff. 
Student::Student(int age, char * fname, char * lname, 
	 int id, float gpa): Person(age, fname, lname),
	 m_id(id),m_gpa(gpa)
{
	cout << "5 arg student c'tor" << endl; 
}

void Student::Display()
{
	//Person parent class can already display
	//call the base class display, then display student info
	Person::Display(); 

	cout << "\nID, GPA: " << m_id << " " << m_gpa << "\n" << endl;
	//cout << "wow" << GetAge() << endl; 
	//InternalMethod(); 
}

Student::~Student()
{
	cout << "in student d'tor" << endl; 
}
