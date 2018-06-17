#pragma once

#include <map>
#include <vector>
#include <Point.h>

typedef int line_id_t;

class Line
{
	public:
		Line();
		Line(const Point& start, const Point& end);
		bool isIntersecting(const Line& line);
		bool isTouching(const Point& point);
		Point getIntersectionPoint(const Line& line);
		std::pair<Point, Point> getEnds();
		static std::string to_string(Point point);
	private:
		Point c_start;
		Point c_end;
};

typedef std::map<line_id_t, Line> lines_t;
lines_t makeLines( std::vector< std::vector<coordinate_t> > table);
std::string linesToString(lines_t lines);