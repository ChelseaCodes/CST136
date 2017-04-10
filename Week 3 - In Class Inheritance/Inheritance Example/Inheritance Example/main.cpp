#include<iostream>
using std::cout; 
using std::endl;
using namespace std; 


#include "student.h"		//since it inherits Person, you don't really need "person.h"
#include "teacher.h"
int main()
{
	/*cout << "Person class no arg c'tor in main" << endl;
	Person p0;
	p0.Display();
	cout << endl; */

	/*cout << "Person class 3 arg c'tor in main" << endl;
	Person p1(20, "joe", "bob");
	p1.Display();
	cout << endl;*/

	/*cout << "Student class no arg c'tor in main" << endl;
	Student s0;
	s0.Display();
	cout << endl*/;

	//Student needs a 5 arg c'tor for other Base class members 
	//That way we can have the fname and lname for student 
	//currently only id and gpa 

	//cout << "calling student 2 arg c'tor in main" << endl;
	//Student s1(5, 3.0); 
	//s1.Display();
	//cout << endl; 

	/*cout << "calling stduent 5 arg c'tor in main" << endl;
	Student s2(25, "Joe", "bob", 5, 3.0);
	s2.Display();
	cout << endl;
*/
//Student s3 = p1;		//cant do it this way
//Person p2 = s2;		//copys person part, bt "shears" off 
						//student data. DONT DO 

//////////
//Person p; Student s;

//Student * foo[] = { &s, &p };		//doesnt like p - not a student 

//Person * foo[] = { &s, &p };		//pointer to stud, ptr to person
//C++ loves to upcase - no prob taking std ptr and casting it to person ptr

//Student * s0 = new Student(25, "first", "last", 1, 4.0);
//foo[0]->Display(); //a student ptr here, casted to person *
//s0->Display(); 
//cout << endl; 

// Person * p0 = new Person(25, "first", "last");
//Student * s0 = new Student(25, "first", "last", 1, 4.0);
//Person * moo[] = { s0, p0 }; //using base class pointers
////s0->Display();		
//cout << endl; 
//moo[0]->Display(); 

//***********-1.30.17 - Monday-*********//
//Student * s0 = new Student(20, "Student1", "Lname1", 1, 3.5);
//Student * s1 = new Student(18, "Student2", "lname2", 2, 3.0);
//Teacher * t0 = new Teacher(45, "Teacher1", "lname3", 5);
//Teacher * t1 = new Teacher(55, "Teacher2", "lname4", 10);
//cout << endl;
//
//Person * foo[] = { s0, t0, s1, t1 };	//base class pointer collection
//for (int i(0); i < 4; i++)	
//{
//	foo[i]->Display();	//we want to call the display for each 
//}
//for (int i(0); i < 4; i++)
//{
//	delete foo[i];
//}

//***********-2.6.2017 - Monday-*********//
//Student students[5] = { Student("Jenny", 85), Student("Rick", 34),
//Student("Penny", 24), Student("Todd", 45), Student("Sarah", 20) }; 


	return 0; 
}
//polymorphism 1 - i want to display things - calling display needed
//display wanted will be the derived one, for specific class
//collection of base class pointers needed, but can't call the most derived
//method

//METHOD OVERIDING: (solve above issue)
// "virtual" Allows base class to call the MOST DERIVED method needed
// Adding virtual to your display will allow derived display method
//override "this" method, and go to the next one. 
