#pragma once

#include <iostream>
using namespace std;

class Screen
{
public:
	//Екран заповнюється рядком pc,
    //якщо він заданий, інакше він наповнюється
    //наповнювачем _filler
	Screen(int, int, char* pc = 0);
	~Screen();

	//Сталі та їx однойменні методи

    //Перевести курсор на початок екрану
	const Screen& home() const;
	Screen& home();

	//Посунути курсор на один символ вправо
	const Screen& move() const;
	Screen& move();
	
	//Посунути курсор на один символ вліво
	const Screen& back() const;
	Screen& back();

	//Показати вміст екрану
	const Screen& show() const;
	Screen& show();

	//Перенести курсор на задану позицію
	const Screen& move(int, int) const;
	Screen& move(int, int);

	//Очистити екран
	Screen& clear();
	
	//Показати символ, на якому знаходиться курсор
	const Screen& showCurrent() const; 

	//Селектори
	const int height() const { return _height; }
	const int width() const { return _width; }
	const int cursorPosition() const { return _cursor; }
	char get() const; 

	//Модифікатор
	Screen& set(char); 

	void cursorPosition(const int s) const;

private:
	static const int maxHeight; 

	static const int maxWidth; 

	static const char _filler; 

	int _height; 

	int _width;

	char* _wContent; 

	mutable int _cursor; 

	Screen(const Screen&);

	Screen& operator= (const Screen&);
};

ostream& operator<<(ostream&, const Screen&);

typedef const Screen& (Screen::* const ConstAction) () const;
typedef Screen& (Screen::* const NonConstAction) ();

void doActionConst(const Screen& s, ConstAction act, int n);
void doActionNonConst(Screen& s, NonConstAction act, int n);
