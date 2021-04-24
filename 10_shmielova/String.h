#pragma once

#include <string>
#include <iostream>

using namespace std;


class String

{
private:
	size_t _len;
	char* _allocator;

	void fillString(const char*, int len);

public:
	class BadString;
	class BadIndex;

	String();
	explicit String(const char*);
	String(const char);
	explicit String(const string&);
	String(const String& s, const unsigned int multiplayer = 1);
	String(String&&);

	~String();

	String& operator=(const String&);
	String& operator=(const string&);
	String& operator=(const char*);
	String& operator=(const char);

	const string STL_string() const { return string(_allocator); }
	const char* c_str() const { return _allocator; }
	size_t length() const { return _len; }

	bool empty() const { return _len == 0; }
	void clear() { fillString("", 0); }

	char& operator[](size_t);
	const char operator[](const size_t) const;

	bool operator==(const String&) const;
	bool operator!=(const String& s) const { return !(*this == s); }

	bool operator< (const String&) const;
	bool operator<=(const String& s) const { return !(s < *this); }
	bool operator> (const String& s) const { return s < *this; }
	bool operator>=(const String& s) const { return !(*this < s); }

	String operator+(const String&) const;
	//String operator+(const string&);
	//String operator+(const char);

	String& operator+=(const char* c) { return *this += String(c); }
	String& operator+=(const String& s) { return *this = *this + s; }
	String& operator+=(const string& s) { return *this += String(s.c_str()); }

};

ostream& operator<<(ostream&, const String&);

class String::BadString
{
private:
	const string _reason;

public:

	BadString(string reason = "") : _reason(reason) {}

	~BadString() {}

	void diagnose() const;
};

class String::BadIndex
{
private:
	const size_t _index;

public:
	BadIndex(const size_t index = 0) : _index(index) {}
	~BadIndex() {}

	void diagnose() const;
};

