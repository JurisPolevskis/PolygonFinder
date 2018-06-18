#include "Triangle.h"

#include "Debug.h"

Triangle::Triangle()
{
	//Nothing
}

Triangle::Triangle(std::pair<coordinate_t, coordinate_t> _a, 
					std::pair<coordinate_t, coordinate_t> _b, 
					std::pair<coordinate_t, coordinate_t> _c)
{
	this->a = Point(_a.first, _a.second);
	this->b = Point(_b.first, _b.second);
	this->c = Point(_c.first, _c.second);
}

Triangle::Triangle(Point _a, Point _b, Point _c)
{
	this->a = _a;
	this->b = _b;
	this->c = _c;
}

//Shoelace formula https://math.stackexchange.com/a/516223
area_t Triangle::getArea()
{
	Debug::print("a: " + Point::to_string(a));
	Debug::print("b: " + Point::to_string(b));
	Debug::print("c: " + Point::to_string(c));
	return abs( (a.getX() - c.getX()) * (b.getY() - a.getY())
			- (a.getX() - b.getX()) * (c.getY() - a.getY()) ) / 2.0;
}
