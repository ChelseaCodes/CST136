#ifndef STUDENT_H
#define STUDENT_H
using namespace std;

//#include"person.h"

class Student
{
	friend class GoodGradesIterator;
public:
	Student();
	Student(char n[], int s);
	Student(const Student & s); 

	void Display();	

	~Student();
private:
	char m_fname[30];
	int m_score; 
};
#endif