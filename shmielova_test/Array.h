#pragma once

#include <utility>
#include <string>
#include <iostream>

using namespace std;

template <class T>
class Array
{
private:
    const size_t _size;
    T* _allocator;

    //Array& operator=(const Array&);
    Array(const Array&);

public:
    class BadArray;

    explicit Array(size_t size);
    ~Array();

    size_t size() const { return _size; }

    T& operator[] (size_t);
    T operator[] (size_t) const;
};

////////////////////////////////////////////////////////////////////////

template<class T>
class Array<T>::BadArray
{
private:
    const string _bad;
    const size_t _index;

public:
    explicit BadArray(string  bad = "", size_t index = 0);
    ~BadArray();

    const string& bad() const { return _bad; }
    size_t index() const { return _index; }

    void diagnose();
};

////////////////////////////////////////////////////////////////////////

// конструктор
template<class T>
Array<T>::Array(const size_t my_size) :
    _size(my_size), _allocator(new T[size()]) {}

// деструктор
template<class T>
Array<T>::~Array()
{
    delete[] this->_allocator;
}

/////////////////////////////////////////////////////////// operator[]

template<class T>
T& Array<T>::operator[](const size_t index)
{
    if (index >= size() || index < 0)
        throw BadArray("Bad index detected. Num: ", index);
    return _allocator[index];
};


template<class T>
T Array<T>::operator[](const size_t index) const
{
    if (index >= size() || index < 0)
        throw BadArray("*Bad index detected. Num: ", index);
    return _allocator[index];
}

///////////////// конструктор та деструктор BadArray

template<class T>
Array<T>::BadArray::BadArray(string bad, const size_t index) :
    _bad(std::move(bad)), _index(index) {}


template<class T>
Array<T>::BadArray::~BadArray() = default;

////////////////////  діагнозтика бед ерея
template<class T>
void Array<T>::BadArray::diagnose()
{
    cout << "Diagnose activated " << bad() << " ::> " << index() << endl;
}