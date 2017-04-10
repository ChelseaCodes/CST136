#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
	Date();											//default c'tor 
	Date(int m, int d, int year, char * quote);		//4 arg c'tor 
	Date(const Date& date);							//copy constructor - deep copy 
	Date& operator = (const Date& date);			//Op= return reference obj to do a = b = c; 
	
	void Display();

	friend ostream& operator << (ostream& os, Date& date);
	~Date();

private:
	int _month;
	int _day;
	int _year;
	char * _quote;
};