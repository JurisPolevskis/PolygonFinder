#include <Line.h>

#include <Debug.h>

Line::Line()
{
	//Nothing
}

Line::Line(const Point& start, const Point& end)
{
	this->start = start;
	this->end = end;
}

//https://stackoverflow.com/a/565282
//Given lines p->(p+r) and q->(q+s)
//We calculate coefficients t and u
//Where Intersection at p+tr = q+us
bool Line::isIntersecting(const Line& other, std::optional<Point>& intersect_point)
{
	Point p = this->start;
	Point q = other.start;
	Point r = this->end - this->start;
	Point s = other.end - other.start;
	
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
		double t = (q-p)*s/(r*s);
		double u = (q-p)*r/(r*s);
		if ( 0 <= t && t <= 1 && 0 <= u && u <= 1) {
			intersect_point = p+r*t;
			Debug::print("p: " + Point::to_string(p));
			Debug::print("q: " + Point::to_string(q));
			Debug::print("r: " + Point::to_string(r));
			Debug::print("s: " + Point::to_string(s));
			Debug::print("t: " + std::to_string(t));
			Debug::print("u: " + std::to_string(u));
			Debug::print("");
			return true;
		}
		return false;
	}
}


bool Line::areColinearLinesOverlapping(const Line& other) {
	//TODO:Implement
	return false;
}

std::pair<Point, Point> Line::getEnds()
{
	return std::make_pair(this->start, this->end);
}

std::string Line::to_string(Line line)
{
	auto ends = line.getEnds();
	std::string str = Point::to_string(ends.first) + ", " + Point::to_string(ends.second);
	return str;
}

lines_t makeLines( std::vector< std::vector<int> > table)
{
	lines_t lines;
	for (const auto& table_line:table) {
		if (table_line.size() != 5) {
			throw std::invalid_argument( "makeLines invalid value caount in line" );
		}
		Point start((coordinate_t)table_line[1], (coordinate_t)table_line[2]);
		Point end((coordinate_t)table_line[3], (coordinate_t)table_line[4]);
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