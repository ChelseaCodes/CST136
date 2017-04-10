#include "hashnode.h"

HashNode::HashNode() : m_next(nullptr), m_previous(nullptr), m_city(nullptr), m_flight(nullptr)
{
	m_key[0] = '\0';
}

HashNode::HashNode(City* city, Flight* flight) : m_next(nullptr), m_previous(nullptr), m_city(city),
				m_flight(flight)
{
	strcpy(m_key, flight->GetName());
}

HashNode::HashNode(const HashNode& copy) : m_next(copy.m_next), m_previous(copy.m_previous), m_city(copy.m_city), m_flight(copy.m_flight)
{
	strcpy(m_key, copy.m_key);
}

HashNode& HashNode::operator=(const HashNode& copy)
{
	if(this != & copy)
	{
		m_next = copy.m_next;
		m_city = copy.m_city; 
		m_flight = copy.m_flight; 
		m_previous = copy.m_previous; 
		strcpy(m_key, copy.m_key); 
	}
	return *this; 
}

HashNode* HashNode::getNext()
{
	return m_next;
}

HashNode* HashNode::getPrevious()
{
	return m_previous;
}

char* HashNode::getKey()
{
	return m_key;
}

void HashNode::setNext(HashNode* next)
{
	m_next = next; 
}

void HashNode::setPrevious(HashNode* prev)
{
	if(this != nullptr)
		m_previous = prev; 
}

Flight* HashNode::getFlight()
{
	return m_flight; 
}

City* HashNode::getCity()
{
	return m_city; 
}

HashNode::~HashNode()
{
	m_next = nullptr;
	m_city = nullptr;
	m_key[0] = '\0'; 
	m_previous = nullptr; 
	m_flight = nullptr; 
}
