#pragma once

#include <map>
#include <set>
#include "Line.h"
#include "Point.h"

typedef std::pair<coordinate_t, coordinate_t> intersection_key_t;
typedef std::set <line_id_t> intersection_value_t;
typedef std::map< intersection_key_t,  intersection_value_t> intersections_t;

class Intersector
{
	public:
		Intersector(const lines_t& lines);
		const intersections_t& getIntersections();
		std::string intersectionsToString();
	private:
		void calculateIntersections(const lines_t& lines);
		intersections_t intersections;
};