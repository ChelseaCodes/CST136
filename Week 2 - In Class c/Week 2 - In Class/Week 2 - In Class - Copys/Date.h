#ifndef DATE_H
#define DATE_H
using namespace std;

class Date
{
	public:
		Date();
		Date(int m, int d, int y, char * quote); 
		Date(const Date & date);						//copy constructor 
		//copy c'tor 
		void Display(); 

	private:
		int m_month;
		int m_day;
		int m_year; 
		char * m_quote; 

};


#endif
