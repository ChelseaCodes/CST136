#ifndef TStack_h
#define TStack_h
#include<iostream>
using std::cout;
using std::endl; 

//const int MAX(5);

template <typename T>	//needed for template, T is placeholder
class TStack
{
	public:
		TStack();
	
		void Push(const T& item);	//push takes a "T" object
		T Pop();
		bool IsFull();
		bool IsEmpty();
		int GetStackSize();

		~TStack();

	private:
		T m_stack[5];
		int m_size; 
};
#endif // !TStack_h

//inline: "i want the method in .h"
template<typename T>
inline TStack<T>::TStack()
{
	m_size = 0; 
}

template<typename T>
inline void TStack<T>::Push(const T & item)
{
	m_stack[m_size++] = item; 
}

template<typename T>
inline T TStack<T>::Pop()
{
	return m_stack[--m_size];
}

template<typename T>
inline bool TStack<T>::IsEmpty()
{
	return m_size == 0; 
}

template<typename T>
inline bool TStack<T>::IsFull()
{
	return m_size == 5; 
}

template<typename T>
inline int TStack<T>::GetStackSize()
{
	return m_size; 
}

template<typename T>
inline TStack<T>::~TStack()
{
	cout << "TStack d'tor" << endl; 
}