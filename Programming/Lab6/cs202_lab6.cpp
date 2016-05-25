#include "shape.h"

Point Point::operator + (const Point& p) const
{
	Point * p = new Point();
	p->x = this->x + p.x;
	p->y = this->y + p.y;
	return (*p);
}

Point& Point::operator += (const Point& p)
{
	this->x += p.x;
	this->y += p.y;
	return (*this);
}

bool Point::operator == (const Point& p) const
{
	if(this->x == p.x && this->y == p.y)
	{
		return true;
	} 
	else
	{
		return false;
	}    
}

ostream& operator << (ostream& out, const Point& p)
{
	out << '[' << p.x << ", " << p.y << ']';
	return out;
}

Shape& Shape::operator = (const Shape& s)
{
	if (this != &s) 
	{
		center = s.center;
		color = s.color;
	}
	return *this;
}

Shape& Shape::operator += (const Point& p)
{
    return *this;    
}

Shape operator + (const Point& p, const Shape& s)
{
	 return Shape (p.x, p.y, s.color);
}

Shape operator + (const Shape& s, const Point& p)
{
	return Shape (p.x, p.y, s.color);
}

Circle operator + (const Point& p, const Circle& c)
{
	return Circle (p.x, p.y, c.radius, )
}

Circle operator + (const Circle& c, const Point& p)
{
}

Circle& Circle::operator = (const Circle& c)
{
	radius = c.radius;
	return *this;
}

ostream& operator << (ostream& out, const Shape& s)
{
		output << "Center: " << "(" << s.color << "," << circle.y << ")" << " , radius: " << circle.radius;
	output << " , area: " << circle.area() << endl;
	return output;
}

