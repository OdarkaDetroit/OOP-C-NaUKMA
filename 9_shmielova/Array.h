#pragma once

#include <string>
#include <iostream>

using namespace std;

// Array.
template <size_t n, typename T>
class Array
{
private:

	size_t _size;
	T* _elements;
	Array(const Array& other);
	Array& operator=(const Array& other);

public:
	explicit Array();

	Array(Array&& other) noexcept;

	~Array();

	Array& operator=(Array&& other) noexcept;

	size_t size() const;

	T& operator [](size_t index);

	class BadArray;
};


// Exceptions array
template <size_t n, typename T>
class Array<n, T>::BadArray 
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
template <size_t n, typename T>
Array<n, T>::Array() : _size(n), _elements(new T[_size])
{
#ifndef NDEBUG
	cout << "Array " << n << " created!\n";
#endif
}


// Destructor
template <size_t n, typename T>
Array<n, T>::~Array()
{
	if (_elements != nullptr)
	{
		delete[] _elements;
		_elements = nullptr;
	}
#ifndef NDEBUG
	cout << "Array " << n << " deleted!\n";
#endif
}


// Copy constructor
template <size_t n, typename T>
Array<n, T>::Array(const Array& a) : _size(a._size), _elements(new T[a.size()])
{
	copy(a._elements, a._elements, _elements);
#ifndef NDEBUG
	cout << "Array " << n << " copied!\n";
#endif
}


// Copy constructor
template <size_t n, typename T>
Array<n, T>::Array(Array&& a) noexcept : _size(0),
_elements(nullptr)
{
	_elements = a._elements;
	_size = a._size;

	a._elements = nullptr;
	a._size = 0;

#ifndef NDEBUG
	cout << "Array " << n << " copied!\n";
#endif
}


// Copy assignment operator
template <size_t n, typename T>
Array<n, T>& Array<n, T>::operator=(const Array& a)
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
	cout << "Array " << n << " copied!\n";
#endif
	return *this;
}


// Copyied assignment operator
template <size_t n, typename T>
Array<n, T>& Array<n, T>::operator=(Array&& a) noexcept
{
	if (this == &a)
		return *this;

	delete[] _elements;

	_elements = a._elements;
	_size = a._size;

	a._elements = nullptr;
	a._size = 0;

#ifndef NDEBUG
	cout << "Array " << n << " assigned(copied)!\n";
#endif
	return *this;
}


// Selector of arrays length
template <size_t n, typename T>
size_t Array<n, T>::size() const
{
	return _size;
}


// Arrays operator
template <size_t n, typename T>
T& Array<n, T>::operator[](size_t index)
{
	if (index >= this->size() || index < 0)
	{
		throw BadArray("-- Bad index --", index);
	}
	return _elements[index];
}


// Constructor
template <size_t n, typename T>
Array<n, T>::BadArray::BadArray(string s, const size_t index) : _reason(std::move(s)), _index(index)
{ }

// Destructor
template <size_t n, typename T> Array<n, T>::BadArray:: ~BadArray() = default;


// Reason of the exception with wrong index
template <size_t n, typename T>
void Array<n, T>::BadArray::diagnose() const
{
	cerr << _reason << ": " << _index << endl;
}