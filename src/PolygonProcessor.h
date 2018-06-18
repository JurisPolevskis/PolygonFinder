#pragma once

#include <set>
#include "Line.h"
#include "Graph.h"
#include "Polygon.h"

class PolygonProcessor
{
	public:
		PolygonProcessor(const cycles_t& cycles, const lines_t& lines);
		const std::string& writePolygons();
		void discardZeroLengthSides();
		void discardZeroAreaPolygons();
	private:
		polygons_t makePolygons(const cycles_t& cycles, const lines_t& lines);
		polygons_t polygons;
};