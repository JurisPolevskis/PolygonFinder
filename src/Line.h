#pragma once

#include <map>
#include <vector>
#include "Point.h"

typedef int line_id_t;

class Line
{
	public:
		Line();
		Line(const Point& start, const Point& end);
		bool isIntersecting(const Line& other, Point& intersect_point);
		std::pair<Point, Point> getEnds();
		static std::string to_string(Line line);
	private:
		bool areColinearLinesOverlapping(const Line& other);
		Point start;
		Point end;
};

typedef std::map<line_id_t, Line> lines_t;
lines_t makeLines( std::vector< std::vector<int> > table);
std::string linesToString(lines_t lines);