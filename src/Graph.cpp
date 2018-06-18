#include "Graph.h"

#include "Debug.h"

Graph::Graph(const intersections_t& intersections)
{
	buildGraph(intersections);
	calculateCycles();
}

const cycles_t& Graph::getCycles()
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
						graph[node_key1].insert(node_key2);
						graph[node_key2].insert(node_key1);
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
	for (const auto& it:graph) {
		auto key = it.first;
		this->current_start_node = key;
		//Debug::print("Start Node (" + std::to_string(key->first) + ", " + std::to_string(key->second) + ")");
		visitNode(current_start_node);
	}
	Debug::print(cyclesToString());
}

void Graph::visitNode( node_key_t node) {
	//Debug::print("Depth:" + std::to_string(current_path.size()));
	//Debug::print("Visiting Node (" + std::to_string(node->first) + ", " + std::to_string(node->second) + ")");
	current_path.insert(node);
	for (const auto& next_node:graph[node]) {
		//Debug::print("Next Node (" + std::to_string(next_node->first) + ", " + std::to_string(next_node->second) + ")");
		
		//If return to start add to cycle
		if (next_node == current_start_node && current_path.size() > 2) {
			//Debug::print("Start found");
			cycles.insert(current_path);
		}
		
		//If new node visit it
		else if (current_path.find(next_node) == current_path.end()) {
			visitNode(next_node);
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
		first_value = false;
		message.append( "(" + std::to_string(it->first) + ", " + std::to_string(it->second) + ")");
	}
	message.append(")");
	return message;
}


std::string Graph::cyclesToString(){
	std::string message = "Cycles:";
	for (const auto& cycle:cycles) {
		message.append("\n" + cycleToString(cycle));
	}
	return message;
}

std::string Graph::graphToString()
{
	std::string message = "Graph:";
	for (const auto& [key, value]:graph) {
		message.append("\n(" + std::to_string(key->first) + ", " + std::to_string(key->second) +")->");
		bool first_value = true;
		for (const auto& entry:value) {
			if (!first_value) {
				message.append(", ");
			}
			first_value = false;
			message.append( "(" + std::to_string(entry->first) + ", " + std::to_string(entry->second) + ")");
		}
	}
	return message;
}
