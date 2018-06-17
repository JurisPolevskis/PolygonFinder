#include <Point.h>

Point::Point()
{
	//Nothing
}

Point::Point(const coordinate_t& x,const coordinate_t& y)
{
	c_x = x;
	c_y = y;
}

bool Point::operator== (const Point& point)
{
	return (c_x == point.c_x &&	c_y == point.c_y);
}

Point Point::operator+ (const Point& point) const
{
	Point ret;
	ret.c_x = c_x + point.c_x;
	ret.c_y = c_y + point.c_y;
	return ret;
}

Point Point::operator- (const Point& point) const
{
	Point ret;
	ret.c_x = c_x - point.c_x;
	ret.c_y = c_y - point.c_y;
	return ret;
}

coordinate_t Point::operator* (const Point& point)//cross product
{
	return (c_x * point.c_y - c_y * point.c_x);
}

Point Point::operator* (const coordinate_t& multiplier)
{
	return Point(c_x * multiplier,	c_y * multiplier);
}

coordinate_t Point::getX()
{
	return c_x;
}

coordinate_t Point::getY()
{
	return c_y;
}

std::string Point::to_string(Point point)
{
	std::string str = "(" + std::to_string(point.getX()) + ", " + std::to_string(point.getY()) +")";
	return str;
}