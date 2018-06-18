#include "PolygonProcessor.h"

#include <algorithm>
#include <queue>

#include "Triangle.h"
#include "Debug.h"

PolygonProcessor::PolygonProcessor(cycles_t& _cycles)
: cycles(_cycles)
{
	//Nothing
}

void PolygonProcessor::discardMirroredCycles()
{
	std::queue<cycles_t::iterator> erased_iterators;
	for (auto cycles_it1 = this->cycles.begin(); cycles_it1 != this->cycles.end(); ++cycles_it1) {
		if (cycles_it1 == erased_iterators.front()) {
			erased_iterators.pop();
			continue;
		}
		std::set<cycle_points_t> initial_segments;
		for (const auto& cycle_it:*cycles_it1) {
			initial_segments.insert(cycle_it.first);
		}
		for (auto cycles_it2 = cycles_it1; cycles_it2 != this->cycles.end(); ++cycles_it2) {
			if (cycles_it1 == cycles_it2) {
				continue;
			}
			std::set<cycle_points_t> combined_segments = initial_segments;
			for (const auto& cycle_it:*cycles_it2) {
				cycle_points_t new_segment = make_pair(cycle_it.first.second, cycle_it.first.first);
				combined_segments.insert(new_segment);
			}
			if (initial_segments.size() == combined_segments.size()) {
				erased_iterators.emplace(cycles_it2);
				cycles_it2 = cycles.erase(cycles_it2);
			}
		}
	}
}

void PolygonProcessor::discardZeroAreaSegmentCycles()
{
	std::queue<cycles_t::iterator> erased_iterators;
	Debug::print("a");
	for (auto cycles_it = this->cycles.begin(); cycles_it != this->cycles.end(); ++cycles_it) {
		Debug::print("1");
		bool erase_cycle = false;
		cycle_points_t  prev_segment;
		for (auto cycle_it = cycles_it->begin(); cycle_it != cycles_it->end(); ++cycle_it) {
			if (cycle_it == cycles_it->begin()) {
				prev_segment = cycle_it->first;
				continue;
			}
			cycle_points_t segment = cycle_it->first;
			if (prev_segment.second != segment.first) {
				Debug::print("cycle neighboring segments discontinuous");
				Debug::print("(" + std::to_string(prev_segment.first->first) + ", " + std::to_string(prev_segment.first->second) + "), " + 
							"(" + std::to_string(prev_segment.second->first) + ", " + std::to_string(prev_segment.second->second) + ")!= " +
							"(" + std::to_string(segment.first->first) + ", " + std::to_string(segment.first->second) + "), " +
							"(" + std::to_string(segment.second->first) + ", " + std::to_string(segment.second->second) );
				throw std::logic_error("cycle neighboring segments discontinuous");
			}
			Triangle triangle(*prev_segment.first, *prev_segment.second, *segment.second);
			Debug::print(std::to_string(triangle.getArea()));
			if ( triangle.getArea() == 0) {
				erase_cycle = true;
				break;
			}
			prev_segment = segment;
		}
		if (erase_cycle) {
			Debug::print("xxx");
			cycles_it = cycles.erase(cycles_it);
		}
		Debug::print("y3");
	}
	Debug::print("b");
}