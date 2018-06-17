#include <Line.h>

Line::Line(const Point& start, const Point& end)
{
	c_start = start;
	c_end = end;
}

bool isIntersecting(const Line& line)
{
	//TODO:Implement
	return false;
}

bool isTouching(const Point& point)
{
	//TODO:Implement
	return false;
}

Point getIntersectoion(const Line& line)
{
	//TODO:Implement
	return Point(0, 0);
}

lines_t makeLines( std::vector< std::vector<coordinate_t> > )
{
	//TODO:Implement
	lines_t lines;
	return lines;
}