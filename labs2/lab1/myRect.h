#pragma once
struct Coord
{
	int x1;
	int y1;
	int x2;
	int y2;
};

class Rect
{
	int m_left, m_right, m_top, m_bottom, tmp;
	void Normalize();
public:
	Rect();
	~Rect();
	
	Rect(int l, int r, int t, int b);
	void InflateRect(int a, int b, int c, int d);
	void InflateRect(int add_hor = 1, int add_vert = 1);
//	void InflateRect(int a);
//	void InflateRect();
	Rect(const Rect& r);
	Rect& operator= (const Rect& r);
	void SetAll(int a, int b, int c, int d);
	Coord GetAll() const;
};