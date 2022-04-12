#pragma once
#ifndef CONTAINER_H
#define CONTAINER_H

#include <cassert>

class Container
{
private:
	int m_length;
	int* m_data;
	void swap(int & first, int & second) {
		int temp = first;
		first = second;
		second = temp;
	}
public:
	Container() : m_length(0), m_data(nullptr) { }
	Container(int length) :	m_length(length){
		assert(length >= 0);
		if (length > 0)
			m_data = new int[length];
		else
			m_data = nullptr;
	}
	int getLength() { return m_length; }
	void erase() {
		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}
	int& operator[](int index) {
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}
	void resize(int newLength)
	{
		if (newLength == m_length)
			return;
		if (newLength <= 0)
		{
			erase();
			return;
		}
		int* data = new int[newLength];
			if (m_length > 0)
			{
				int elementsToCopy = (newLength > m_length) ? m_length : newLength;
				for (int index = 0; index < elementsToCopy; ++index)
					data[index] = m_data[index];
			}
		delete[] m_data;
		m_data = data;
		m_length = newLength;
	}
	void insertBefore(int value, int index) {
		assert(index >= 0 && index <= m_length);
		int* data = new int[m_length + 1];
		for (int before = 0; before < index; ++before)
			data[before] = m_data[before];
		data[index] = value;
		for (int after = index; after < m_length; ++after)
			data[after + 1] = m_data[after];
		delete[] m_data;
		m_data = data;
		++m_length;
	}
	void push_back(int value) { insertBefore(value, m_length); }
	void pop_back(){
		if (m_length == 0)
			return;
		resize(m_length - 1);
	}
	void pop_front(){
		if (m_length == 0)
			return;
		if (m_length - 1 == 0)
		{
			erase();
			return;
		}
		int* data = new int[m_length - 1];
		for (size_t index = 1; index < m_length; ++index)
			data[index - 1] = m_data[index];
		delete[] m_data;
		m_data = data;
		--m_length;
	}
	void sort() {
		for (size_t i = 0; i < m_length; i++) {
			for (size_t j = 0; j < m_length - 1; j++) {
				if (m_data[j] > m_data[j + 1])
					swap(m_data[j], m_data[j + 1]);
			}
		}
	}
	friend std::ostream& operator<<(std::ostream&, Container&);
	~Container(){
		delete[] m_data;
	}
};
std::ostream& operator<<(std::ostream& l, Container& c)
{
	int length = c.getLength();

	for (int i = 0; i < length; ++i)
		l << c[i] << (((length == 1) || (length - 1 == i)) ? "" : " ");

	return l;
}
#endif