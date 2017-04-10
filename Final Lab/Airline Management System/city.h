/************************************************************************
* Class: city.h
*
* Purpose: This class is the City, containing a linked list of Flights
*
* Manager functions:
* 	City()					
*		default flights is 0, all members null 
*	City(char c[], char n[], char m[], char pn[], int nf)	
*		sets code, name, manager, phone number and flight number 
*	City(const City & city)	
*	City & operator=(const City & city)
*	~City()
*		Deletes flight linked list, sets members to null
*
* Methods:
*	char * GetName()
*	char * GetCode()
*	char * GetMan()
*	char * GetPhone()
*	int GetFlightNum()
*	FLList * GetFlightList()
*	InsertIntoFlightList(Flight * new_flight)
*		Inserts flight information into flight linked list
*	friend bool operator<=(const City& ls, const City& rs)
*		Comparison overloaded <=
*	friend bool operator>=(const City& ls, const City& rs) 
*		Comparison overloaded >=
*	friend bool operator==(const City& ls, const char * rs) 
*		Comparison overloaded ==
*	Display()
*
*************************************************************************/

#ifndef city_h
#define city_h
#include<fstream>
using std::ostream; 

#include<iomanip>
using std::setw;
using std::left; 

#include "TLList.h"
#include "flight.h"
#include "Node.h"

class City
{
	public:
		City();															//Default d'tor 
		City(char c[], char n[], char m[], char pn[], int nf);			//Five arg c'tor.Passed: code, name, manager, phone num, num of flights
		City(const City & city);										//Copy c'tor 
		City & operator=(const City & city); 

		char * GetName(); 
		char * GetCode(); 
		char * GetMan();
		char * GetPhone(); 
		int GetFlightNum(); 
		TLList<Flight> * GetFlightList(); 

		void InsertIntoFlightList(Node<Flight> * flight_data); 
		//void PrintAllFlights(ofstream& DataOut); 

		friend bool operator<=(const City& ls, const City& rs);
		friend bool operator>=(const City& ls, const City& rs); 
		friend bool operator==(const City& ls, const char * rs); 

		void Display();		//Displays into to console - echo is false 

		friend ostream& operator<<(ostream& os, City * data); 

		~City(); 
	private:
		char m_code[5];		//City code
		char m_name[11];	//City name
		char m_mangr[11];	//City manager 
		char m_phone[11];	//City phone 
		int m_flights;		//Number of flights 

		TLList<Flight> * flight_list; 
};
#endif

