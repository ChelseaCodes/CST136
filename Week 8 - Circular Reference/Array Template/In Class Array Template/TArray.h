#pragma once
#include<iostream>
using std::cout; 
using std::endl; 

template <typename T>
class TArray
{
	public:
		TArray();
		TArray(int length, int base = 0);		//begin array index at 0
		TArray(const TArray<T>& copy); 
		TArray<T> &operator=(const TArray<T>& rhs);	//returns templated array
		T &operator[](int index);	//overload subscript operator

		int GetLength();
		void SetLength(int length);
		~TArray(); 
	private:
		int m_base;
		int m_length; 
		T* m_data;	//pointer to whatever type 
};

template<typename T>
inline TArray<T>::TArray() : m_data(new T[0]), m_base(0), m_length(0)
{
	//cout << "Default TArray c'tor" << endl; 
}

template<typename T>
inline TArray<T>::TArray(int length, int base) : m_data(new T[length]), m_length(length),
m_base(base)
{
	//cout << "2 arg TArray c'tor" << endl; 
}

template<typename T>
inline TArray<T>::TArray(const TArray<T> & copy) : m_base(copy.m_base), m_length(copy.m_length)
{
	cout << "TArray copy c'tor" << endl; 
	m_data = new T[m_length];
	for (int i(0); i < m_length; i++)
	{
		m_data[i] = copy.m_data[i]; 
	}
}

template<typename T>
inline TArray<T> & TArray<T>::operator=(const TArray<T> & rhs)
{
	cout << "op=s" << endl; 
	if (this != &rhs)
	{
		m_base = rhs.m_base;
		m_length = rhs.m_length; 

		delete [] m_data; 
		m_data = new T[m_length]; 

		for (int i(0); i < m_length; i++)
		{
			m_data[i] = rhs.m_data[i];
		}
	}
	return *this;
}

template<typename T>
inline T &TArray<T>::operator[](int index)
{
	if (index < m_base || index > m_base + m_length)
		throw("Index out of Range"); 

	return m_data[index - m_base];
}

template<typename T>
inline int TArray<T>::GetLength()
{
	return m_length;
}

template<typename T>
inline void TArray<T>::SetLength(int length)
{
	//is m_len less than new length?	
	int min = m_length < length ? m_length : length;

	T* newdata = new[length];
	for (int i(0); i < min; i++)
	{
		newdata[i] = m_data[i];
	}
	delete[] m_data; 
	m_data = newdata; 

	m_length = length; 
}

template<typename T>
inline TArray<T>::~TArray()
{
	cout << "TArray d'tor" << endl; 
	delete[] m_data; 
}
