#pragma once

#include <map>
#include "Line.h"
#include "Point.h"

typedef std::map< std::pair<line_id_t, line_id_t>,  std::optional<Point> > intersections_t;

class Intersector
{
	public:
		Intersector(const lines_t& lines);
		const intersections_t& getIntersections();
		std::string intersectionsToString();
	private:
		void calculateIntersections(const lines_t& lines);
		intersections_t c_intersections;
};