#pragma once

#include <set>
#include "Intersector.h"


typedef const intersection_key_t* node_key_t;
typedef std::set<node_key_t> cycle_t;
typedef std::set<cycle_t> cycles_t;

class Graph
{
	public:
		Graph(const intersections_t& intersections);
		const cycles_t& getCycles();
		std::string cycleToString(const cycle_t& cycle);
		std::string cyclesToString();
		std::string graphToString();
	private:
		void buildGraph(const intersections_t& intersections);
		void calculateCycles();
		void visitNode(const intersection_key_t* node);
		cycles_t cycles;
		std::set< node_key_t > current_path;
		node_key_t current_start_node;
		
		typedef std::set< node_key_t> connections_t;
		typedef std::map< node_key_t, connections_t > graph_t;
		graph_t graph;
};