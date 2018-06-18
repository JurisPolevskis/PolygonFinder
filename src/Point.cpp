#include "Point.h"

Point::Point()
{
	//Nothing
}

Point::Point(const coordinate_t& x,const coordinate_t& y)
{
	this->x = x;
	this->y = y;
}

bool Point::operator== (const Point& other)
{
	return (this->x == other.x &&	this->y == other.y);
}

Point Point::operator+ (const Point& other) const
{
	Point ret;
	ret.x = this->x + other.x;
	ret.y = this->y + other.y;
	return ret;
}

Point Point::operator- (const Point& other) const
{
	Point ret;
	ret.x = this->x - other.x;
	ret.y = this->y - other.y;
	return ret;
}

coordinate_t Point::operator* (const Point& other)//cross product
{
	return (this->x * other.y - this->y * other.x);
}

Point Point::operator* (const coordinate_t& multiplier)
{
	return Point(this->x * multiplier,	this->y * multiplier);
}

std::pair<coordinate_t, coordinate_t> Point::getCoordinates()
{
	return std::make_pair(this->x, this->y);
}

coordinate_t Point::getX() const
{
	return this->x;
}

coordinate_t Point::getY() const
{
	return this->y;
}

std::string Point::to_string(Point point)
{
	std::string str = "(" + std::to_string(point.getX()) + ", " + std::to_string(point.getY()) +")";
	return str;
}