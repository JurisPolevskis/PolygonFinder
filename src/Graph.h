#pragma once

#include <set>
#include "Intersector.h"

typedef const intersection_key_t* node_key_t;
typedef std::pair<node_key_t, node_key_t> cycle_points_t;
typedef std::map <cycle_points_t, std::set<line_id_t> > cycle_t;
typedef std::set<cycle_t> cycles_t;

class Graph
{
	public:
		Graph(const intersections_t& intersections);
		const cycles_t& getCycles();
		std::string cycleToString(const cycle_t& cycle);
		std::string cyclesToString();
		std::string graphToString();
		std::string nodeIdToString(node_key_t key);
	private:
		void buildGraph(const intersections_t& intersections);
		void calculateCycles();
		void visitNode(const intersection_key_t* node);
		void saveCurrentPath();
		cycles_t cycles;
		std::vector< node_key_t > current_path;
		node_key_t current_start_node;
		
		typedef std::map< node_key_t, std::set<line_id_t>> connections_t;
		typedef std::map< node_key_t, connections_t > graph_t;
		graph_t graph;
};