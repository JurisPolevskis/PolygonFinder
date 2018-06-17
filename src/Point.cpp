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

std::pair<coordinate_t, coordinate_t> Point::getCoordinates()
{
	return std::make_pair(c_x, c_y);
}

std::string Point::to_string(Point point)
{
	auto coordinates = point.getCoordinates();
	std::string str = "(" + std::to_string(coordinates.first) + ", " + std::to_string(coordinates.second) +")";
	return str;
}