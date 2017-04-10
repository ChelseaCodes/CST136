#ifndef PERSON_H
#define PERSON_H

using namespace std; 

class Person
{
	public:
		Person();
		Person(int age, char * fname, char * lname);

		int GetAge();
		void Display();	

		~Person(); 
	private:
		int m_age; 
		char m_fname[10]; //using arrays to keep it simple - no worry about copy c'tor ect. 
		char m_lname[10];		
};
#endif
