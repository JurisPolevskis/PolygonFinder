#include "Intersector.h"

#include "Debug.h"

Intersector::Intersector(const lines_t& lines)
{
	calculateIntersections(lines);
}

const intersections_t& Intersector::getIntersections()
{
	return this->intersections;
}

void Intersector::calculateIntersections(const lines_t& lines)
{
	//Possible optimization: Calculate isIntersecting only if both line x or y coordinates overlap
	//Possible optimization: Split whole space including lines into chunks and calculate for Intersections for each chunck seperately
	for (auto it = lines.begin(); it != lines.end(); ++it) {
		for (auto it2 = it; it2 != lines.end(); ++it2) {
			if (it == it2) {
				continue;
			}
			line_id_t id1 = it->first;
			line_id_t id2 = it2->first;
			Line line1 = it->second;
			Line line2 = it2->second;
			Point point;
			if (line1.isIntersecting(line2, point)) {
				intersection_key_t coordinates = point.getCoordinates();
				this->intersections[ coordinates ].insert(id1);
				this->intersections[ coordinates ].insert(id2);
			}
		}
	}
	Debug::print(intersectionsToString());
}


std::string Intersector::intersectionsToString(){
	std::string message = "\nIntersections:";
	for (const auto& [key, value]:this->intersections) {
		message.append("\n(" + std::to_string(key.first) + ", " + std::to_string(key.second) + ") : ");
		bool first_value = true;
		for (const auto& it:value) {
			if (!first_value) {
				message.append(", ");
			}
			first_value = false;
			message.append(std::to_string(it));
		}
	}
	return message;
}