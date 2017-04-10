#ifndef NODE_H
#define NODE_H
#include<iostream>

template<typename T>
class Node
{
public:

	Node();
	Node(T * data);
	Node(const Node& node);
	Node & operator=(const Node& node);

	Node<T> * GetNext();
	Node<T> * GetPrevious();
	void SetNext(Node<T> * next);
	void SetPrevious(Node<T> * previous); 
	T * GetData();

	//friend bool operator<=(const T& ls, const T& rs);

	friend ostream& operator<<(ostream& os, Node<T>* data)
	{
		os << data->GetData(); 
		return os; 
	}

	~Node();
private:
	T * m_data;
	Node<T> * m_next;
	Node<T> * m_previous;
};


/**************************************************************************************/
//								        Node<T>									      //
/**************************************************************************************/
template<typename T>
inline Node<T>::Node() : m_data(nullptr), m_next(nullptr), m_previous(nullptr)
{}

template<typename T>
inline Node<T>::Node(T * data) : m_data(data), m_next(nullptr), m_previous(nullptr)
{}

template<typename T>
inline Node<T>::Node(const Node & node) : m_data(node.m_data), m_next(node.m_next),
m_previous(node.m_previous)
{}

template<typename T>
inline Node<T> & Node<T>::operator=(const Node & node)
{
	if (this != &node)
	{
		m_data = node.m_data;
		m_next = node.m_next;
		m_previous = node.m_previous;
	}
	return *this;
}

template<typename T>
inline Node<T>* Node<T>::GetNext()
{
	if(this != nullptr)
		return m_next;
}

template<typename T>
inline Node<T>* Node<T>::GetPrevious()
{
	if(this != nullptr)
		return m_previous;
}

template<typename T>
inline void Node<T>::SetNext(Node<T>* next)
{
	m_next = next; 
}

template<typename T>
inline void Node<T>::SetPrevious(Node<T>* previous)
{
	m_previous = previous;
}

template<typename T>
inline T * Node<T>::GetData()
{

	return m_data;
}

//template<typename T>
//bool operator<= (const T& ls, const T& rs)
//{
//	return (stricmp(ls, rs) <= 0);
//}

template<typename T>
inline Node<T>::~Node()
{
	delete m_data;	//delete data allocated in insert 
}
#endif // !NODE_H