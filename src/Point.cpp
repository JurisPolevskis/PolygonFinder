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

bool Point::operator==(const Point& point)
{
	return (c_x == point.c_x &&	c_y == point.c_y);
}