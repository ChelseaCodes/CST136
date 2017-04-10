#ifndef PERSON_H
#define PERSON_H

using namespace std; 

class Person
{
	public:
		Person();
		Person(int age, char * fname, char * lname); 
		int GetAge();
		virtual void Display();		//This here "virtual" will call most derived method! 
		//Will need virtual d'tor 
		virtual ~Person(); 


	protected:	//public to the derived class, private to the rest
		//int m_age;		//now student has access to age - NOT for c'tors
		//int GetAge();		//protected method for the student class
		void InternalMethod();

	private:
		int m_age; 
		char m_fname[10]; //using arrays to keep it simple - no worry about copy c'tor ect. 
		char m_lname[10];		
		

};
#endif
