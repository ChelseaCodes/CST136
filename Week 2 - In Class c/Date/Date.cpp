#include "Date.h"
#include <string.h>

Date::Date()
{
	cout << "in no arg c'tor" << endl;
	_year = 0; _day = 0; _month = 0;
	_quote = new char[1];
	_quote[0] = '\0';
}

Date::Date(int m, int d, int year, char * quote) : _month(m), _day(d), _year(year)
//can also use colon initilization - not base member initilization (no inheritance) 
{
	cout << "In one arg c'tor" << endl;
	/*_month = m;
	_day = d;
	_year = year;*/
	_quote = new char[strlen(quote) + 1];
	strcpy(_quote, quote);
}

Date::Date(const Date& date)		//copy constructor - deep copy - separate addresses 
{
	cout << "in copy c'tor" << endl;
	_month = date._month;			//can use this-> 
	_day = date._day;
	_year = date._year;

	if (strlen(date._quote) == 0)	//if the quote isn't given - set to null
	{
		_quote = new char[1];
		_quote[0] = '\0';
	}
	else							//else copy the quote into new char array
	{
		_quote = new char[strlen(date._quote) + 1];
		strcpy(_quote, date._quote);
	}
}


Date& Date::operator = (const Date& date)	//const ref - pass by value efficiency, pass by ref protection 
{
	cout << "in op==" << endl;

	if (this != &date)										//if obj isn't itself - make sure address is different.
	{
		_month = date._month;
		_day = date._day;
		_year = date._year;

		//delete [] _quote;									//object that comes in already has info in quote - delete as to not have a dangling pointer 

		if (strlen(date._quote) == 0)						
		{
			_quote = new char[1];
			_quote[0] = '\0';
		}
		else
		{
			_quote = new char[strlen(date._quote) + 1];
			strcpy(_quote, date._quote);
		}
	}														//nothing to do if a = a - return *this
	return *this;											//returning this to be able to do a = b = c 
}

void Date::Display()
{
	cout << "the month day year is: " << _month << " " << _day << " " << _year << endl;
	cout << "the quote is: " << _quote << endl;
}

Date::~Date()
{
	cout << "in d'tor" << endl;
	delete[] _quote;
}

ostream& operator << (ostream& os, Date& date)
{
	cout << "the month day year is: " << date._month << " " << date._day << " " << date._year << endl;
	cout << "the quote is: " << date._quote << endl;
	return os;
}


