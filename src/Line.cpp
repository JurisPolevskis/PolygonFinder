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

Point getIntersectionPoint(const Line& line)
{
	//TODO:Implement
	return Point(0, 0);
}

std::pair<Point, Point> Line::getEnds()
{
	return std::make_pair(c_start, c_end);
}

std::string to_string(Line line)
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
		Point end(table_line[1], table_line[2]);
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
				+ ":\t" + to_string(entry.second) );
		
	}
	return message;
}