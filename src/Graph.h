#pragma once

#include <set>
#include "Intersector.h"

typedef std::set<const intersection_key_t*> cycle_t;
typedef std::set<cycle_t> cycles_t;

class Graph
{
	public:
		Graph(const intersections_t& intersections);
		const cycles_t& getCycles();
		std::string cycleToString(const cycle_t& cycle);
		std::string cyclesToString(const cycles_t& cycle);
	private:
		void calculateCycles(const intersections_t& intersections);
		void visitNode(const intersection_key_t* node, const intersections_t& intersections);
		cycles_t cycles;
		std::set< const intersection_key_t* > visited_nodes;
		std::set< const intersection_key_t* > current_path;
		const intersection_key_t* current_start_node;
};