#include <Line.h>

#include <Debug.h>

Line::Line()
{
	//Nothing
}

Line::Line(const Point& start, const Point& end)
{
	c_start = start;
	c_end = end;
}

//https://stackoverflow.com/a/565282
//Given lines p->(p+r) and q->(q+s)
//We calculate coefficients t and u
//Where Intersection at p+tr = q+us
bool Line::isIntersecting(const Line& other, std::optional<Point>& intersect_point)
{
	Point p = this->c_start;
	Point q = other.c_start;
	Point r = this->c_end - this->c_start;
	Point s = other.c_end - other.c_start;
	
	if (r*s == 0) { //parralel lines
		if ((q-p)*r == 0) { //colinear lines
			if (areColinearLinesOverlapping(other)) {
				//Don't set intersection point
				return true;
			}
			return false;
		}
		else { //parallel non-intersecting;
			return false;
		}
	}
	else { 
		coordinate_t t = (q-p)*s/(r*s);
		coordinate_t u = (q-p)*r/(r*s);
		if ( 0 <= t && t <= 1 && 0 <= u && u <= 1) {
			intersect_point = p+r*t;
			return true;
		}
		return false;
	}
}


bool Line::areColinearLinesOverlapping(const Line& line) {
	//TODO:Implement
	return false;
}

std::pair<Point, Point> Line::getEnds()
{
	return std::make_pair(c_start, c_end);
}

std::string Line::to_string(Line line)
{
	auto ends = line.getEnds();
	std::string str = Point::to_string(ends.first) + ", " + Point::to_string(ends.second);
	return str;
}

lines_t makeLines( std::vector< std::vector<coordinate_t> > table)
{
	lines_t lines;
	for (const auto& table_line:table) {
		if (table_line.size() != 5) {
			throw std::invalid_argument( "makeLines invalid value caount in line" );
		}
		Point start(table_line[1], table_line[2]);
		Point end(table_line[3], table_line[4]);
		line_id_t line_id = table_line[0];
		Line line(start, end);
		lines[line_id] = line;
	}
	Debug::print("makeLines returns:");
	Debug::print(linesToString(lines));
	return lines;
}

std::string linesToString(lines_t lines)
{
	std::string message = "Lines:";
	for (const auto& entry:lines) {
		message.append("\n " + std::to_string(entry.first) +
				+ ":\t" + Line::to_string(entry.second) );
		
	}
	return message;
}