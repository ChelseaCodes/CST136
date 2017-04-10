#ifndef hashnode_h
#define hashnode_h

#include "city.h"

class HashNode
{
public:
	HashNode();
	HashNode(City * city, Flight * flight); 
	HashNode(const HashNode& copy);
	HashNode& operator=(const HashNode& copy);

	HashNode * getNext(); 
	HashNode * getPrevious(); 
	char * getKey();
	Flight * getFlight();
	City * getCity();
	void setNext(HashNode * next);
	void setPrevious(HashNode * prev); 

	~HashNode(); 
private:	
	char m_key[11];
	HashNode * m_next;
	HashNode * m_previous; 
	City * m_city;
	Flight * m_flight;
};


#endif
