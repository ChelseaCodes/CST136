#ifndef hashtable_H
#define hashtable_H
#include "hashnode.h"

const int TABLESIZE = 8; 

class HashTable
{
public:
	HashTable();

	void Prepend(City * city, Flight * flight); 
	static int Hash(char flightname[]);
	
	HashNode* Search(char* target);

	bool DeleteFlight(char * flight);
	HashNode * getHead(int index); 

	void PrintHistogram(); 

	~HashTable(); 
private:
	HashNode * m_hash_table[TABLESIZE]; 
};
#endif
