#include "Screen.h"

const int Screen::maxHeight = 50;
const int Screen::maxWidth = 50;
const char Screen::_filler = '.';

Screen::Screen(int width, int height, char* pc) : _cursor(0),
_width(width > maxWidth ? maxWidth : width),
_height(height > maxHeight ? maxHeight : height)
{
	int length = pc == 0 ? 0 : strlen(pc);
	int len = length > _width * _height ? _width * _height : length;

	_wContent = new char[_width * _height + 1];
	_wContent[_width * _height] = '\0';

	for (int i = 0; i < _width * _height; i++)
	{
		*(_wContent + i) = _filler;
	}

	if (pc != 0)
	{
		for (int i = 0; i < len; i++)
			*(_wContent + i) = *pc++;
	}
#ifndef NDEBUG
	cout << "!--Screen created--!\n";
#endif
};

Screen::~Screen()
{
	delete[] _wContent;
#ifndef NDEBUG
	cout << "!--Screen deleted--!\n";
#endif
}

const Screen& Screen::home() const
{
	_cursor = 0;
	return *this;
};

Screen& Screen::home()
{
	_cursor = 0;
	return *this;
};

const Screen& Screen::move() const     
{
	if ((++_cursor) >= _width * _height) _cursor = 0;
	return *this;
};

Screen& Screen::move()
{
	if ((++_cursor) >= _width * _height) _cursor = 0;
	return *this;
};


const Screen& Screen::back() const    
{
	if (--_cursor < 0) _cursor = 0;
	return *this;
};

Screen& Screen::back()
{
	if (--_cursor < 0) _cursor = 0;
	return *this;
};

const Screen& Screen::show() const
{
	int cursor = _cursor;
	cout << "cursor is now here " << _cursor << endl;
	home();
	for (int y = 0; y < _height; y++)
	{
		for (int x = 0; x < _width; x++)
		{
			cout << get();
			move();
		}
		cout << endl;
	}
	_cursor = cursor;
	return *this;
};

Screen& Screen::show()
{
	int cursor = _cursor;
	cout << "(( cursor is now here " << cursor << " ))\n";
	home();
	for (int y = 0; y < _height; y++)
	{
		for (int x = 0; x < _width; x++)
		{
			cout << get();
			move();
		}
		cout << '\n';
	}
	_cursor = cursor;
	return *this;
};

const Screen& Screen::move(int x, int y) const
{
	if ((x >= _width) || (y >= _height)) _cursor = 0;
	else _cursor = _width * y + x;
	return *this;
};

Screen& Screen::move(int x, int y)
{
	if ((x >= _width) || (y >= _height)) _cursor = 0;
	else _cursor = _width * y + x;
	return *this;
};

Screen& Screen::clear()
{
	for (int i = 0; i < _height * _width; i++)
		*(_wContent + i) = _filler;
	_cursor = 0;
	return *this;
#ifndef NDEBUG
	cout << "!--Screen cleared--!\n";
#endif
}


char Screen::get() const
{
	return *(_wContent + _cursor);
};

Screen& Screen::set(char ch)
{
	*(_wContent + _cursor) = ch;
	return *this;
}


void Screen::cursorPosition(const int s) const
{
	if (s >= _width * _height || s < 0) _cursor = 0;
	else _cursor = s;
}

const Screen& Screen::showCurrent() const
{
	cout << get() << '\n';
	return *this;
}


ostream& operator<<(ostream& os, const Screen& s)
{
	int cursor = s.cursorPosition();
	cout << "(( cursor is now here " << cursor << " ))\n";
	s.home();

	for (int y = 0; y < s.height(); y++)
	{
		for (int x = 0; x < s.width(); x++)
		{
			os << s.get();
			s.move();
		}
		os << '\n';
	}
	s.cursorPosition(cursor);
	return os;
}


void doActionConst(const Screen& s, ConstAction act, int n)
{
	for (int i = 0; i < n; i++)
		(s.*act)();
}

void doActionNonConst(Screen& s, NonConstAction act, int n)
{
	for (int i = 0; i < n; i++)
		(s.*act)();
}