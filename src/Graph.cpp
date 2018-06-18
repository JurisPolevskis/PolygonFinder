#include "Graph.h"

#include <algorithm>

#include "Debug.h"

Graph::Graph(const intersections_t& intersections)
{
	buildGraph(intersections);
	calculateCycles();
}

cycles_t& Graph::getCycles()
{
	return this->cycles;
}

void Graph::buildGraph(const intersections_t& intersections)
{
	for (auto it = intersections.begin(); it != intersections.end(); ++it) {
		node_key_t node_key1 = &it->first;
		const auto& line_ids1 = it->second;
		for (auto it2 = it; it2 != intersections.end(); ++it2) {
			node_key_t node_key2 = &it2->first;
			const auto& line_ids2 = it2->second;
			for (const auto& line_id:line_ids1) {
				if (line_ids2.find(line_id) != line_ids2.end()){
					if (node_key1 != node_key2) {
						this->graph[node_key1][node_key2].insert(line_id);
						this->graph[node_key2][node_key1].insert(line_id);
					}
				}
			}
		}
	}
	Debug::print(graphToString());
}


//Depth first search with backtracking while storing visited nodes
//One pass starting for every line that has an intersection
void Graph::calculateCycles()
{
	for (const auto& it:this->graph) {
		auto key = it.first;
		this->current_start_node = key;
		//Debug::print("Start Node (" + std::to_string(key->first) + ", " + std::to_string(key->second) + ")");
		visitNode(current_start_node);
	}
	Debug::print(cyclesToString());
}

void Graph::visitNode( node_key_t node) {
	Debug::print("Depth:" + std::to_string(current_path.size()));
	Debug::print("Visiting Node (" + std::to_string(node->first) + ", " + std::to_string(node->second) + ")");
	current_path.emplace_back(node);
	for (const auto& it:this->graph[node]) {
		const auto& next_node = it.first;
		Debug::print("Next Node (" + std::to_string(next_node->first) + ", " + std::to_string(next_node->second) + ")");
		
		//If return to start add to cycle
		if (next_node == current_start_node && current_path.size() > 2) {
			//Debug::print("Start found");
			current_path.emplace_back(next_node);
			saveCurrentPath();
			current_path.pop_back();
		}
		//If new node visit it
		else if ( std::find(current_path.begin(), current_path.end(), next_node) == current_path.end() ) {
			visitNode(next_node);
		}
	}
	current_path.pop_back();
}

void Graph::saveCurrentPath()
{
	cycle_t cycle;
	node_key_t prev_value;
	for (auto it = current_path.begin(); it != current_path.end(); ++it) {
		if (it == current_path.begin()) {
			prev_value = *it;
			continue;
		}
		cycle_points_t segment = std::make_pair(prev_value, *it);
		const auto& connecting_lines = graph[prev_value][*it];
		cycle.insert(std::make_pair(segment, connecting_lines) );
		prev_value = *it;
	}
	Debug::print(cycleToString(cycle));
	cycles.insert(cycle);
}


std::string Graph::cycleToString(const cycle_t& cycle){
	std::string message = "(";
	bool first_value = true;
	for (const auto& it:cycle) {
		if (!first_value) {
			message.append("\t");
		}
		first_value = false;
		message.append( nodeIdToString(it.first.first) + "->" + nodeIdToString(it.first.second)  + ":") ;
		bool first_line = true;
		for(const auto& line_id:it.second) {
			if (!first_line) {
				message.append(", ");
			}
			message.append( std::to_string(line_id));
		}
	}
	message.append(")");
	return message;
}


std::string Graph::cyclesToString(){
	std::string message = "\nCycles:";
	for (const auto& cycle:cycles) {
		message.append("\n" + cycleToString(cycle));
	}
	return message;
}

std::string Graph::graphToString()
{
	std::string message = "\nGraph:";
	for (const auto& [key, value]:graph) {
		message.append("\n(" + std::to_string(key->first) + ", " + std::to_string(key->second) +")->");
		bool first_value = true;
		for (const auto& entry:value) {
			if (!first_value) {
				message.append(", ");
			}
			first_value = false;
			message.append( nodeIdToString(entry.first) );
		}
	}
	return message;
}

std::string Graph::nodeIdToString(node_key_t key) 
{
	return ("(" + std::to_string(key->first) + ", " + std::to_string(key->second) + ")");
}
