/*************************************************************
* Author:		Chelsea Christison
* Filename:		llist.cpp
* Date Created:	02.17.2017
* Modifications:	2.17.2017 - Overloaded comparison ops,
*		2.17.2017 - inserted previous pointer
**************************************************************/
#include<iostream>
using std::cout;
using std::endl;

#include<fstream>
using std::ofstream;

#include<iomanip>
using std::setw;
using std::left; 

#include "llist.h"

Llist::Llist():m_nodecount(0), m_head(nullptr), m_tail(nullptr)
{
	cout << "Default LList c'tor" << endl;
}

Llist::Llist(const Llist & list) : m_head(list.m_head), m_nodecount(list.m_nodecount), m_tail(list.m_tail)
{
	cout << "Llist copy c'tor" << endl;
}

void Llist::InsertOrdered(City * data)
{
	Node * travel = m_head; 
	Node * trail = nullptr;
	Node * nn = nullptr;
	nn = new Node(data);
	
	if ( m_head == nullptr || *nn->m_data <= *m_head->m_data)		//head is null, first in the list
	{
		nn->m_next = m_head;				//set next to head
		if(m_head != nullptr)
			m_head->m_previous = nn;

		m_head = nn; 						//head is new node 

		Node * temp = m_head;
		while (temp->m_next!= nullptr)		//while next isn't null
			temp = temp->m_next;				//traverse 

		m_tail = temp;
	}
	else			//traverse until correct place is found 
	{
		while ((travel != nullptr) && (*nn->m_data >= *travel->m_data))
		{
			trail = travel;
			travel = travel->m_next;
		}
			
		trail->m_next = nn;				//exits loop at place it should be 
		nn->m_next = travel;			//set the node
		nn->m_previous = trail;
		if(travel != nullptr)
			travel->m_previous = nn; 
	}

	if (m_tail->m_next != nullptr)	//if tail node is not really tail
	{
		m_tail = m_tail->m_next;		//set tail to the node after 
	}	
	m_nodecount++;						//incremement the node count 
}

Node * Llist::NSearch(char * c_target)
{
	Node * temp = m_head; 
	while (temp->m_next != nullptr)
	{
		if (*temp->m_data == c_target)
		{
			return temp;
		}
		else
			temp = temp->m_next; 
	}
	return nullptr;
}

bool Llist::Delete(char * c_target)
{
	Node * prev = nullptr; 
	Node * del = nullptr; 
	bool deleted = false; 

	if (*m_head->m_data == c_target)
	{
		del = m_head; 
		m_head = del->m_next; 
		m_head->m_previous = nullptr; 
		delete del; 
		deleted = true; 
	}
	else
	{
		bool loop = true; 
		prev = m_head; 
		del = m_head->m_next;

		while (del != nullptr && loop == true)
		{
			if (*del->m_data == c_target)
			{
				prev->m_next = del->m_next;		//previous next set to deletes next 	
				del->m_next->m_previous = prev;			//ensure previous is linked 

				if (del == m_tail)
				{
					m_tail = prev; 
				}
				delete del; 
				deleted = true; 
				loop = false; 

			}
			prev = del;
			del = del->m_next; 
		}
	}
	return deleted; 
}

Node * Llist::GetHead()
{
	return m_head;
}

Node * Llist::GetTail()
{
	return m_tail;
}

//void Llist::LLPrintAll(ofstream & DataOut)
//{
//	Node * temp = m_head; 
//
//	DataOut << "FORMAT:" << endl;
//	DataOut << "_______________________________- Info -________________________________\n";
//	DataOut << setw(11) << left << "City Code"
//		    << setw(15) << left << "City Name"
//		    << setw(15) << left << "City Manager"
//		    <<setw(15) << left << "City Phone Num"
//		    << endl;
//	DataOut << "\t\t\t\t\t\t\t   **Flights**\n";
//	DataOut << setw(11) << left << "Fl Code"
//		<< setw(10) << left << "Fl Name"
//		<< setw(15) << left << "Fl Manager"
//		<< setw(15) << left << "Fl Dest"
//		<< setw(15) << left << "Fl Distance"
//		<< setw(15) << left << "Fl Cost"
//		<< endl;
//	DataOut << "_______________________________________________________________________\n\n"
//		<< endl; 
//
//	//print the city information
//	//then print ALL the flight information
//	while (temp != nullptr)
//	{
//		DataOut << "_______________________________- Info -________________________________\n";
//		DataOut << "**CITY**\t" << temp << endl;	
//		temp->m_data->PrintAllFlights(DataOut); 
//		
//		DataOut << "\n" << endl; 
//
//		temp = temp->m_next;
//	}
//
//	DataOut << "******************-END Info-*******************\n\n\n";
//}

Llist::~Llist()
{
	cout << "in Linked List d'tor" << endl;
	Node * trail = nullptr;
	while (m_head != nullptr)
	{
		trail = m_head;
		m_head = m_head->m_next;
		delete trail;
	}
	m_nodecount = 0; 
	m_head = nullptr; 
	m_tail = nullptr;  
}


