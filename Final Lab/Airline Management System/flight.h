/************************************************************************
* Class: flight.h
*
* Purpose: This class is a flight object holding Flight data on:
*	code, name, manager, destination, distance and cost 
*
* Manager functions:
* 	Flight()
*		defaults all members to null or zero
*	Flight(char c[], char n[], char m[], char d[], int dis, int cost)
*		create flight based on passed information
*	Flight(const Flight & flight)
*	Flight & operator=(const Flight & flight)
*	~Flight()
*		reset all members to null or zero
*
* Methods:
*	char * GetCode()
*	char * GetName()
*	char * GetMan()
*	char * GetDest()
*	int GetDist()
*	int GetCost()
*	friend bool operator<=(const Flight& ls, const Flight& rs)
*		comparison overloaded <=
*	friend bool operator>=(const Flight& ls, const Flight& rs)
*		comparison overloaded >=
*	friend bool operator==(const Flight& ls, char * rs)
*		comparison overloaded == 
*	Display()
*************************************************************************/
#ifndef flight_h
#define flight_h

#include<iomanip>
using std::setw;
using std::left;

class Flight
{
public:
	Flight();
	Flight(char c[], char n[], char m[], char d[], int dis, int cost); 
	Flight(const Flight & flight); 
	Flight & operator=(const Flight & flight); 

	//getters
	char * GetCode();
	char * GetName();
	char * GetMan();
	char * GetDest();
	int GetDist();
	int GetCost();

	friend bool operator<=(const Flight& ls, const Flight& rs);
	friend bool operator>=(const Flight& ls, const Flight& rs);
	friend bool operator==(const Flight& ls, char * rs); 
	void Display(); 

	friend ostream& operator<<(ostream& os, Flight * data);
	
	~Flight(); 
private:
	char m_flcode[5];
	char m_flname[11];
	char m_flmana[11];
	char m_destination[11];
	int m_distance;
	int m_cost; 
	
};
#endif // !flight_h
