#pragma once

#include "Array.h"

#include <ostream>
#include <string>

template <typename T>

class Sequence 
{

public:
	class BadSeq; 

	explicit Sequence(const size_t capacity = _default); 

	~Sequence() 
	{ 
		delete _allocator; 
		return; 
#ifndef NDEBUG
		cout << "Sequence deleted!\n";
#endif
	} 

	size_t capacity() const { return _allocator->size(); } 
	size_t size() const { return _size; } 
	bool empty() const { return size() == 0; } 
	bool full() const { return size() == capacity(); } 

	Sequence& clear() { _size = 0; return *this; }

	const T& operator[](const size_t index) const;
	T& operator[](const size_t index);

	Sequence& add(const T& elem) { return doinsert(elem, _size); };

	Sequence& insert(const T& elem, const size_t index);

	Sequence& cut() { return doremove(_size); }
	Sequence& remove(const size_t index);

	bool contains(const T& elem) 
	{
		for (size_t i = 0; i < size(); i++)
			if (elem == (*_allocator)[i]) return true;
		return false;
	}
private:

	size_t _size;
	static const size_t _default = 0;
	Array<T>* _allocator;

	void enlarge(const size_t times = 2);
	Sequence& doinsert(const T& elem, const size_t index);
	void reduce(const size_t times = 2);
	Sequence& doremove(const size_t index);
	Sequence(const Sequence&);
	Sequence& operator=(const Sequence&);
};

template <typename T>
Sequence<T>::Sequence(const size_t capacity) :_size(0), _allocator(new Array<T>(capacity)) 
{
#ifndef NDEBUG
		cout << "Sequence " << capacity << " created!\n";
#endif
}

template <typename T>
const T& Sequence<T>::operator[](const size_t index) const
{
	if (empty())
		throw BadSeq("Try to manipulate the empty sequence");
	if (index >= _size)
		throw BadSeq("Try to access a non existing element of the sequence");
	return (*_allocator)[index];
}

template <typename T>
T& Sequence<T>::operator[](const size_t index)
{
	if (empty())
		throw BadSeq("Failed: manipulating the empty sequence.");
	if (index >= _size)
		throw BadSeq("Failed: accessing a non existing element of the sequence.");
	return (*_allocator)[index];
}

template <class T>
Sequence<T>& Sequence<T>::insert(const T& elem, const size_t index)
{
	if (_size < index)
		throw BadSeq("Failed: inserting after a non existing element of the sequence.");
	return doinsert(elem, index);
}

template <typename T>
Sequence<T>& Sequence<T>::remove(const size_t index) 
{
	if (_size <= index)
		throw BadSeq("Failed: removing unexisting element.");

	return doremove(index);
}

template <typename T>
Sequence<T>& Sequence<T>::doinsert(const T& elem, const size_t index)
{
	if (index > _size)
		throw BadSeq("Failed: adding of unexisting index " + index + '.');

	if (_size + 1 > capacity())
		enlarge();
	++_size;

	for (size_t i = _size - 1; i > index; i--)
		(*_allocator)[i] = (*_allocator)[i - 1];
	(*_allocator)[index] = elem;
	return *this;
}

template <typename T>
Sequence<T>& Sequence<T>::doremove(const size_t index)
{
	if (empty())
		throw BadSeq("No sequence element to remove.");

	for (size_t i = index + 1; i < size(); i++)
		(*_allocator)[i - 1] = (*_allocator)[i];

	--_size;

	if (_size < capacity()) reduce();

	return *this;
}

template <typename T>
void Sequence<T>::enlarge(const size_t times)
{
	Array<T>* newArray = new Array<T>(times * _default + capacity() + 1);

	for (size_t i = 0; i < _size; i++)
		(*newArray)[i] = (*_allocator)[i];
	delete _allocator;
	_allocator = newArray;
	return;
}

template <typename T>
void Sequence<T>::reduce(const size_t times)
{
	Array<T>* newArray = new Array<T>(times * _default + capacity() - 1);

	for (size_t i = 0; i < _size; i++)
		(*newArray)[i] = (*_allocator)[i];
	delete _allocator;
	_allocator = newArray;
	return;
}

template <typename T>
ostream& operator<<(ostream& os, const Sequence<T>& seq)
{
	os << "size: " << seq.size() << '\n';
	os << "capacity: " << seq.capacity() << '\n' << "[";
	for (size_t i = 0; i < seq.size(); i++) 
	{
		os << seq[i];
		if (i != seq.size() - 1) os << ", ";
	}
	os << "]";

	return os;
}

template <typename T> 
class Sequence<T>::BadSeq
{
private:

	string _reason;

public:

	BadSeq(const string& reason = "Unknown sequence") :_reason(reason) {}

	~BadSeq() {}

	void diagnose() const { cerr << _reason << endl; }
};