#include "Graph.h"

#include "Debug.h"

Graph::Graph(const intersections_t& intersections)
{
	calculateCycles(intersections);
}

const cycles_t& Graph::getCycles()
{
	return this->cycles;
}


//Depth first search with backtracking while storing visited nodes
//One pass starting for every line that has an intersection
void Graph::calculateCycles(const intersections_t& intersections)
{
	for (const auto& it:intersections) {
		Debug::print("x");
		auto key = &it.first;
		visited_nodes.clear();
		this->current_start_node = key;
		Debug::print("Start Node (" + std::to_string(key->first) + ", " + std::to_string(key->second) + ")");
		visitNode(current_start_node, intersections);
	}
	Debug::print(cyclesToString(this->cycles));
}

void Graph::visitNode(const intersection_key_t *node, const intersections_t& intersections) {
	Debug::print("Depth:" + std::to_string(current_path.size()));
	Debug::print("Visiting Node (" + std::to_string(node->first) + ", " + std::to_string(node->second) + ")");
	visited_nodes.insert(node);
	current_path.insert(node);
	//const auto& next_nodes = ;
	for (const auto& it:intersections) {
		auto next_node = &it.first;
		Debug::print("Next Node (" + std::to_string(next_node->first) + ", " + std::to_string(next_node->second) + ")");
		//If return to start add to cycle
		if (next_node == current_start_node && current_path.size() > 2) {
			Debug::print("Start found");
			cycles.insert(current_path);
		}
		//If new node visit it
		else if (current_path.find(next_node) == current_path.end()) {
			visitNode(next_node, intersections);
		}
	}
	current_path.erase(node);
}

std::string Graph::cycleToString(const cycle_t& cycle){
	std::string message = "(";
	bool first_value = true;
	for (const auto& it:cycle) {
		if (!first_value) {
			message.append("->");
		}
		first_value = true;
		message.append( "(" + std::to_string(it->first) + ", " + std::to_string(it->second) + ")");
	}
	message.append(")");
	return message;
}


std::string Graph::cyclesToString(const cycles_t& cycle){
	std::string message = "Cycles:";
	for (const auto& cycle:cycles) {
		message.append("\n" + cycleToString(cycle));
	}
	return message;
}
