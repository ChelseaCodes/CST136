#ifndef STUDENT_H
#define STUDENT_H
using namespace std; 

#include"person.h"

//Inheritance has 3 acces mods: pub, priv, prot
//need to specify public inheritance - default is private
class Student : public Person	
{
	public:
		Student();
		Student(int id, float gpa); 
		Student(int age, char * fname, char * lname, int id, float gpa); 
		virtual	void Display();	//will work without "virt" but stylistically it is SELF DOCUMENTING 
		~Student();

		//if you declare an op= or copy c'tor 
		//you should have one for person 
	private:
		int m_id;
		float m_gpa; 
};
#endif

