#pragma once

#include <set>
#include "Intersector.h"

typedef std::set<line_id_t> cycle_t;
typedef std::set<cycle_t> cycles_t;

class Graph
{
	public:
		Graph(const intersections_t& intersections);
		const cycles_t& getCycles();
	private:
		cycles_t calculateCycles(const intersections_t& intersections);
		cycles_t cycles;
};