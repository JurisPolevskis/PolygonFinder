#pragma once

#include <set>
#include "Line.h"
#include "Graph.h"
#include "Polygon.h"

class PolygonProcessor
{
	public:
		PolygonProcessor(cycles_t& cycles);
		void discardMirroredCycles();
		void discardZeroAreaSegmentCycles();
	private:
		cycles_t& cycles;
};