#include "myRect.h"
#include <iostream>

Rect::~Rect() { std::cout << "destructor\n"; }
Rect::Rect() :m_left(0), m_right(0), m_top(0), m_bottom(0) { std::cout << "default constructor\n"; }
Rect::Rect(int l, int r, int t, int b)
{
	if (t < b) 
	{
		int tmp = t;
		t = b;
		b = tmp;
	}
	if (r < l)
	{
		int tmp = r;
		r = l;
		l = tmp;
	}
	this->m_left = l;
	this->m_top = t;
	this->m_bottom = b;
	this->m_right = r;
	std::cout << "4 points constructor\n"; 
}

void Rect::Normalize()
{
	if (this->m_top < this->m_bottom)
	{
		int tmp = this->m_top;
		this->m_top = this->m_bottom;
		this->m_bottom = tmp;
	}
	if (this->m_right < this->m_left)
	{
		int tmp = this->m_right;
		this->m_right = this->m_left;
		this->m_left = tmp;
	}
}

Rect::Rect(const Rect& r)
{
	this->m_bottom = r.m_bottom;
	this->m_top = r.m_top;
	this->m_left= r.m_left;
	this->m_right= r.m_right;
	std::cout << "copy constructor\n";
}
void Rect::InflateRect(int a, int b, int c, int d)
{
	std::cout << "Inflate 4 params" << std::endl;
	m_left -= a;
	m_right += b;
	m_bottom -= c;
	m_top += d;
	Normalize();
}
void Rect::InflateRect(int add_hor, int add_vert)
{
	std::cout << "Inflate 2 params" << std::endl;
	m_left -= add_hor / 2;
	m_right += add_hor / 2;
	m_bottom -= add_vert / 2;
	m_top += add_vert / 2;
	Normalize();
}
/*
*void Rect::InflateRect(int a)
*{
*	m_left -= a / 2;
*	m_right += a / 2;
*	m_bottom -= a / 2;
*	m_top += a / 2;
*}
*
*void Rect::InflateRect()
*{
*	m_left -= 1;
*	m_right += 1;
*	m_bottom -= 1;
*	m_top += 1;
*}
*/
Rect& Rect::operator= (const Rect& r)
{
	this->m_bottom = r.m_bottom;
	this->m_top = r.m_top;
	this->m_left = r.m_left;
	this->m_right = r.m_right;
	return *this;
}

void Rect::SetAll(int a, int b, int c, int d)
{
	this->m_bottom = a;
	this->m_top = b;
	this->m_left = c;
	this->m_right = d;
	Normalize();
}

Coord Rect::GetAll() const
{
	Coord pp1;
	pp1.y1 = this->m_bottom;
	pp1.y2 = this->m_top;
	pp1.x1 = this->m_left;
	pp1.x2 = this->m_right;
	return pp1;
}
