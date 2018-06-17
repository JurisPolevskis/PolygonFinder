#pragma once

#include <set>
#include "Line.h"

typedef std::set<line_id_t> intersection_t;//Should contain 2 values only
typedef std::set<intersection_t> intersections_t;

class Intersector
{
	public:
		Intersector(const lines_t& lines);
		const intersections_t& getIntersections();
	private:
		intersections_t calculateIntersections(const lines_t& lines);
		intersections_t c_intersections;
};