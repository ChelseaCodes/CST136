#ifndef TEACHER_H
#define TEACHER_H

#include<iostream>
using namespace std; 

#include"person.h"

class Teacher :  public Person
{
	public:
		Teacher(); 
		Teacher(int age, char * fname, char * lname, int years); 

		virtual void Display(); //again, virtual not needed, but it's explicit
		~Teacher(); 
	private:
		int m_years; 

};
#endif

