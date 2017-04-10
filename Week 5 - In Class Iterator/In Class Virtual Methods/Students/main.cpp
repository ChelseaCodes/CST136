#include<iostream>
using std::cout;
using std::endl;
using namespace std;


#include "student.h"
#include "genericIterator.h"

int main()
{
	/********************* - 2.6.2017 MONDAY - *************************/
	/*Student students[5] = { Student("Hey", 30), Student("Sally", 50),
		Student("Todd", 80), Student("Tomm", 100), Student("Me", 90) }; 
	
	for each(Student student in students)
	{
		student.Display(); 
	}*/

	/********************* - 2.8.2017 WEDNESDAY - **********************/
	/*Student students[5] = { Student("Hey", 30), Student("Sally", 50),
		Student("Todd", 80), Student("Tomm", 100), Student("Me", 90) };*/

	Student * s0 = new Student("Hey", 30);
	Student * s1 = new Student("Sally", 50);
	Student * s2 = new Student("Todd", 80);
	Student * s3 = new Student("Tomm", 100);
	Student * s4 = new Student("Me", 90);

	Student * s_array[] = {s0, s1, s2, s3, s4};

	GenericIterator iter(s_array); 

	for (iter.First(); !iter.IsDone(); iter.MoveNext())
	{
		iter.GetCurrent().Display(); 
	}

	system("pause"); 
	return 0; 
}
/****************************************
*	Iterator(an abstract class - using virt methods)
*	First() = 0; 
*	MoveNext() = 0;
*	bool IsDone() = 0; 
*	object GetCurrent() = 0; 
*	__________
*	int m_cursor 
*	objext * collection
****************************************/
//build a base iterator - PURE VIRT CLASS
//derive and build a sub iterator 
//before building sub iterator need to create
//and implement the pure virtual base class 
