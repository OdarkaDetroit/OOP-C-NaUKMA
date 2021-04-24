#pragma once

#include "Array.h"
#include "HSquare.h"
#include "HRectangle.h"

//class HRectangle;
template <class T>
class Container
{
public:
	class BadContainer;

	explicit Container<T>(const size_t capacity);
	~Container<T>() = default;

	size_t capacity() const { return _capacity; }
	size_t size() const { return _size; }

	bool empty() const { return size() == 0; }
	bool full() const { return size() == capacity(); }

	const T& operator[](const size_t index) const;
	T& operator[](const  size_t index);

	Container<T>& clear();
	Container<T>& add(const T&);
	Container<T>& remove(const size_t index);
	Container<T>& lessThan(const T&);

	const T& getCurrent() const { return *_current; }

	void start() const { _current = _start; }
	void next() const { ++_current; }
	bool stop() const { return (_current == _end); }

	HSquare toUnion();

private:
	size_t _size;
	size_t _capacity;
	static const size_t _default = 1;
	Array<T>* _all;
	T* _start;
	T* _end;
	mutable T* _current;
	void update_size();
	void enlarge(const size_t x = 2);

};


template <class T>
class Container<T>::BadContainer
{
private:
	const string _bad;
	const size_t _index;

public:
	~BadContainer() = default;
	explicit BadContainer(string bad = "!error detected! num: ", size_t index = 0);

	const string& bad() const { return _bad; }
	size_t index() const { return _index; }

	void diagnose() const;
};

///////////////// конструктор BadContainer /////////////////

template <class T>
Container<T>::BadContainer::BadContainer(string bad, const size_t index) :
	_bad(std::move(bad)), _index(index) {}

////////////////////////////////////////////////////////////////////

template <class T>
void Container<T>::BadContainer::diagnose() const
{
	cout << "Diagnose activated " << bad() << " ::> " << index() << '\n';
}


template <class T>
void Container<T>::update_size()
{
	_start = &(*_all)[0];

	if (size() == 0)   _end = _start;
	else  _end = &(*_all)[size() - 1];
}


template <class T>
Container<T>::Container(const size_t my_capacity) :
	_capacity(my_capacity), _size(0), _all(new Array<T>(my_capacity)),
	_start(&(*_all)[0]), _end(&(*_all)[capacity() - 1]) {}


template <class T>
Container<T>& Container<T>::clear()
{
	delete _all;
	_size = 0;
	_capacity = 0;
	return *this;
}


template <class T>
void Container<T>::enlarge(const size_t x)
{
	size_t new_cap = capacity() * x + capacity();
	auto* new_arr = new Array<T>(new_cap);

	for (size_t i = 0; i < size(); ++i)
	{
		(*new_arr)[i] = (*_all)[i];
	}

	delete _all;
	_all = new Array<T>(new_cap);

	for (size_t i = 0; i < size(); ++i)
	{
		(*_all)[i] = (*new_arr)[i];
	}

	_capacity = new_cap;
}

////////////////////////////////////////////////  operator[]

template <class T>
const T& Container<T>::operator[](const size_t index) const
{
	if (empty()) { throw BadContainer("Failed: manipulate the empty container"); }
	if (index > _size) { throw BadContainer("Failed: access a non existing element of the container"); }
	return (*_all)[index];
}

template <class T>
T& Container<T>::operator[](const size_t index)
{
	if (empty()) throw BadContainer("Failed: manipulate the empty container");
	if (index > _size) throw BadContainer("Failed: access a non existing element of the container");
	return (*_all)[index];
}

////////////////////////////////////////////////

template <class T>
Container<T>& Container<T>::add(const T& e)
{
	while (full()) enlarge();
	(*_all)[size()] = e;

	++_size;

	update_size();
	return *this;
}


template <class T>
Container<T>& Container<T>::remove(const size_t index)
{
	for (size_t i = index; i < size(); ++i)
	{
		(*this)[i] = (*this)[i + 1];
	}
	--_size;
	update_size();
	return *this;
}


template <class T>
Container<T>& Container<T>::lessThan(const T& a)
{
	Container<T> res(capacity());
	for (unsigned int i = 0; i < size(); i++)
	{
		if ((*this)[i] < a)
		{
			res.add((*this)[i]);
		}
	}
	return res;
}


template<class T>
HSquare Container<T>::toUnion()
{
	HSquare res((*this)[0]);
	for (unsigned int i = 1; i < size(); i++)
		res = res + (*this)[i];

	return res;
}

//////////////////////////////////////////////// Оператор виведення

template <class T>
ostream& operator<<(ostream& os, const Container<T>& c)
{
	os << ">>size: " << c.size() << '\n';
	os << ">>capacity: " << c.capacity() << '\n' << "[";
	for (size_t i = 0; i < c.size(); i++)
	{
		os << c[i];
		if (i != c.size() - 1) os << ", ";
	}
	os << "]";

	return os;
}
