#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>

#include "String.h"
#include "String.h"

using namespace std;

String::String() :_allocator(new char[1]), _len(0)
{
	_allocator[0] = '\0';
#ifndef NDEBUG
	cout << "String created --> " << *this << '\n';
#endif
	return;
}

String::String(const char* s)
{
	if (s == 0)
		throw BadString("Bad string used...\n");
	_len = strlen(s);
	_allocator = new char[_len + 1];
	strcpy(_allocator, s);
#ifndef NDEBUG
	cout << "String created --> " << *this << '\n';
#endif
	return;
}

String::String(const char ch) :_allocator(new char[2]), _len(1)
{
	_allocator[0] = ch;
	_allocator[1] = '\0';
#ifndef NDEBUG
	cout << "String created --> " << *this << '\n';
#endif
	return;
}

String::String(const string& str) : _len(str.length()), _allocator(new char[_len + 1])
{
	strcpy(_allocator, str.c_str());
#ifndef NDEBUG
	cout << "String created --> " << *this << '\n';
#endif
}

String::String(const String& s, const unsigned int multiplayer) :_len(s._len* multiplayer), _allocator(new char[_len + 1])
{
	char* target = _allocator;
	for (int i = 0; i < multiplayer; i++)
	{
		strcpy(target, s._allocator);
		target += s._len;
	}
#ifndef NDEBUG
	cout << "String created --> " << *this << '\n';
#endif
	return;
}

String::String(String&& s)
{
	this->_allocator = s._allocator;
	this->_len = s._len;
#ifndef NDEBUG
	cout << "String created --> " << *this << '\n';
#endif
	return;
}

String::~String()
{
	if (!empty())
		delete[] _allocator;
	_allocator = 0;
	_len = 0;
#ifndef NDEBUG
	cout << "String deleted!\n";
#endif
	return;
}

void String::fillString(const char* c, const int len)
{
	if (c == 0)
		throw BadString("Bad string used...\n");

	delete[] _allocator;
	_len = len;
	_allocator = new char[_len + 1];
	strcpy(_allocator, c);
}


char& String::operator[](size_t i)
{
	if (_len <= i || i < 0)
		throw BadIndex(i);
	return _allocator[i];
}
const char String::operator[](const size_t i) const
{
	if (_len <= i || i < 0)
		throw BadIndex(i);
	return _allocator[i];
}

String& String::operator=(const String& s)
{
	fillString(s.c_str(), s.length());
	return *this;
}

String& String::operator=(const string& str)
{
	fillString(str.c_str(), str.length());
	return *this;
}

String& String::operator=(const char* ch)
{
	fillString(ch, strlen(ch));
	return *this = String(ch);
}

String& String::operator=(const char c)
{
	char* ch = new char[2];
	ch[0] = c;
	ch[1] = '\0';
	fillString(ch, 1);
	return *this;
}

String String::operator+(const String& s) const
{
	char* ch = new char[_len + s.length() + 1];
	for (int i = 0; i < _len; i++)
		ch[i] = _allocator[i];
	for (int i = _len; i < _len + s.length(); i++)
		ch[i] = s.c_str()[i - _len];

	ch[_len + s.length()] = '\0';
	return String(ch);
}

String String::operator+(const string& s) const
{
	char* ch = new char[_len + s.length() + 1];
	for (int i = 0; i < _len; i++)
		ch[i] = _allocator[i];
	for (int i = _len; i < _len + s.length(); i++)
		ch[i] = s.c_str()[i - _len];

	ch[_len + s.length()] = '\0';
	return String(ch);
}

String String::operator+(const char* c) const
{
	String res(*this);
	res += c;
	return res;
}

String String::operator+(const char& c) const
{
	String result(*this);
	result += c;
	return result;
}

String operator+(const string& s1, const String& s2)
{
	String result(s1);
	result += s2;
	return result;
}
String operator+(const char* c, const String& s)
{
	String result(c);
	result += s;
	return result;
}
String operator+(const char& c, const String& s)
{
	String result(c);
	result += s;
	return result;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool operator==(const String& s, const char* c)
{
	bool result = true;
	if (strlen(c) != s.length())
	{
		return false;
	}
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!result)
			break;
		result = *(s.c_str() + i) == *(c + i);
	}
	return result;
}

bool operator!=(const String& s, const char* c)
{
	return !(s == c);
}



bool operator==(const char& c, const String& s)
{
	if (s.length() != 1) {
		return false;
	}
	return *(s.c_str()) == c;
}



bool operator==(const string& s1, const String& s2)
{
	bool result = true;
	if (s1.length() != s2.length())
	{
		return false;
	}
	for (size_t i = 0; i < s2.length(); i++)
	{
		if (!result)
			break;
		result = *(s2.c_str() + i) == *(s1.c_str() + i);
	}
	return result;
}


bool String::operator==(const String& st) const
{
	if (length() != st.length()) return false;
	for (int i = 0; i < _len; i++)
	{
		if (_allocator[i] != st.c_str()[i])
			return false;
	}
	return true;
}

bool String::operator< (const String& s) const
{
	bool b = true;
	int i = 0;
	for (i = 0; b && i < min(_len, s.length()); i++)
	{
		b = s.c_str()[i] == _allocator[i];
	}
	if (b)
		return _len < s.length();

	return _allocator[--i] < s.c_str()[i];

}

void String::BadString::diagnose() const { cout << _reason << '\n'; }

void String::BadIndex::diagnose() const { cout << "Bad index: " << _index << '\n'; }

ostream& operator<<(ostream& os, const String& s)
{
	for (size_t i = 0; i < s.length(); i++)
		os << s[i];
	return os;
}