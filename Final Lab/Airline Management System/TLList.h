/************************************************************************
* Class: TLList.h
*
* Purpose: 
*
* Manager functions:
*
* Methods:
*************************************************************************/
#ifndef TLLIST_H
#define TLLIST_H


#include<fstream>
using std::ostream;

#include "Node.h"
template<typename T>
class TLList
{
	public:
		TLList();
		TLList(const TLList& list);

		void InsertOrdered(Node<T> * data);	//insert a node type
		T * Search(char * c_target);
		bool Delete(char * c_target);

		Node<T> * GetHead();
		Node<T> * GetTail();

		void PrintAll(ostream& DataOut);

		~TLList(); 
	private:
		int m_nodecount;
		Node<T> * m_head;
		Node<T> * m_tail; 
};


template<typename T>
inline TLList<T>::TLList() : m_nodecount(0), m_head(nullptr), m_tail(nullptr)
{}

template<typename T>
inline TLList<T>::TLList(const TLList & list) : m_nodecount(list.m_nodecount), m_head(list.m_head),
m_tail(list.m_tail)
{}

template<typename T>
inline void TLList<T>::InsertOrdered(Node<T> * data)
{
	Node<T> * travel = m_head;
	Node<T> * trail = nullptr;

	if (m_head == nullptr || *data->GetData() <= *m_head->GetData())//head is null, first in the list
	{
		data->SetNext(m_head);				//set next to head
		if (m_head != nullptr)
			m_head->SetPrevious(data);

		m_head = data; 						//head is new node 

		Node<T> * temp = m_head;
		while (temp->GetNext() != nullptr)	//while next isn't null
			temp = temp->GetNext();			//traverse 

		m_tail = temp;
	}
	else			//traverse until correct place is found 
	{
		while ((travel != nullptr) && (*data->GetData() >= *travel->GetData()))
		{
			trail = travel;
			travel = travel->GetNext();
		}

		trail->SetNext(data);			//exits loop at place it should be 
		data->SetNext(travel);			//set the node
		data->SetPrevious(trail);
		if (travel != nullptr)
			travel->SetPrevious(data);
	}

	if (m_tail->GetNext() != nullptr)	//if tail node is not really tail
	{
		m_tail = m_tail->GetNext();		//set tail to the node after 
	}
	m_nodecount++;						//incremement the node count 
}

template<typename T>
inline T * TLList<T>::Search(char * c_target)
{
	Node<T> * temp = m_head; 
	while (temp != nullptr)
	{
		if (*temp->GetData() == c_target)
		{
			return temp->GetData();
		}
		else
			temp = temp->GetNext();
	}
	return nullptr; 
}

template<typename T>
inline bool TLList<T>::Delete(char * c_target)
{
	Node<T> * prev = nullptr; 
	Node<T> * del = nullptr;
	bool deleted = false; 
	
	if (*m_head->GetData() == c_target)
	{
		del = m_head; 
		m_head = del->GetNext(); 
		if(m_head != nullptr)
			m_head->SetPrevious(nullptr);
		delete del;
		deleted = true; 
	}
	else
	{
		bool loop = true; 
		prev = m_head; 
		del = m_head->GetNext(); 

		while (del != nullptr && loop == true)
		{
			if (*del->GetData() == c_target)
			{
				prev->SetNext(del->GetNext());
				del->GetNext()->SetPrevious(prev); 

				if (del == m_tail)
				{
					m_tail = prev; 
				}
				delete del;
				deleted = true;
				loop = false; 
			}
			prev = del;
			del = del->GetNext(); 
		}
	}
	return deleted; 
}

template<typename T>
inline Node<T> * TLList<T>::GetHead()
{
	return m_head;
}

template<typename T>
inline TLList<T>::~TLList()
{
	Node<T> * trail = nullptr;
	while (m_head != nullptr)
	{
		trail = m_head;
		m_head = m_head->GetNext();
		delete trail;
	}
	m_nodecount = 0;
	m_head = nullptr;
	m_tail = nullptr;
}

template<typename T>
inline Node<T> * TLList<T>::GetTail()
{
	return m_tail;
}

template<typename T>
inline void TLList<T>::PrintAll(ostream & DataOut)
{
	Node<T> * temp = m_head;

	while (temp != nullptr)
	{
		DataOut << "- " << temp << endl;
		temp = temp->GetNext();
	}
}
#endif

