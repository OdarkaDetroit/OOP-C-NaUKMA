#pragma once

#include <string>
#include <iostream>

using namespace std;

// Array.
template <typename T>
class Array
{
private:

	size_t _size;
	T* _elements;
	Array(const Array& other);
	Array& operator=(const Array& other);

public:
	explicit Array(size_t size);

	Array(Array&& other) noexcept;

	~Array();

	Array& operator=(Array&& other) noexcept;

	size_t size() const;

	T& operator [](size_t index);

	class BadArray;
};


// Exceptions array
template <typename T>
class Array<T>::BadArray 
{
private:
	const string _reason;
	const size_t _index;
public:
	explicit BadArray(string reason = "Unsigned exception", size_t index = 0);
	~BadArray();

	void diagnose() const;
};


// Constructor
template <typename T>
Array<T>::Array(size_t size) : _size(size), _elements(new T[_size])
{
#ifndef NDEBUG
	cout << "Array " << size << " created!\n";
#endif
}


// Destructor
template <typename T>
Array<T>::~Array()
{
	if (_elements != nullptr)
	{
		delete[] _elements;
		_elements = nullptr;
	}
#ifndef NDEBUG
	cout << "Array deleted!\n";
#endif
}


// Copy constructor
template <typename T>
Array<T>::Array(const Array& a) : _size(a._size), _elements(new T[a.size()])
{
	copy(a._elements, a._elements, _elements);
#ifndef NDEBUG
	cout << "Array " << a._size << " copied!\n";
#endif
}


// Copy constructor
template <typename T>
Array<T>::Array(Array&& a) noexcept : _size(0),
_elements(nullptr)
{
	_elements = a._elements;
	_size = a._size;

	a._elements = nullptr;
	a._size = 0;

#ifndef NDEBUG
	cout << "Array " << a._size << " copied!\n";
#endif
}


// Copy assignment operator
template <typename T>
Array<T>& Array<T>::operator=(const Array& a)
{
	if (this == &a)
	{
		return *this;
	}

	delete[] _elements;
	_size = a.size();
	_elements = new T[_size];

	copy(a._elements, a._elements, _elements);

#ifndef NDEBUG
	cout << "Array " << a._size << " copied!\n";
#endif
	return *this;
}


// Copyied assignment operator
template <typename T>
Array<T>& Array<T>::operator=(Array&& a) noexcept
{
	if (this == &a)
		return *this;

	delete[] _elements;

	_elements = a._elements;
	_size = a._size;

	a._elements = nullptr;
	a._size = 0;

#ifndef NDEBUG
	cout << "Array " << a._size << " assigned(copied)!\n";
#endif
	return *this;
}


// Selector of arrays length
template <typename T>
size_t Array<T>::size() const
{
	return _size;
}


// Arrays operator
template <typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= this->size() || index < 0)
	{
		throw BadArray("-- Bad index --", index);
	}
	return _elements[index];
}


// Constructor
template <typename T>
Array<T>::BadArray::BadArray(string s, const size_t index) : _reason(std::move(s)), _index(index)
{ }

// Destructor
template <typename T> Array<T>::BadArray:: ~BadArray() = default;


// Reason of the exception with wrong index
template <typename T>
void Array<T>::BadArray::diagnose() const
{
	cerr << _reason << ": " << _index << endl;
}