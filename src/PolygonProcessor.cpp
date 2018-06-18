#include "PolygonProcessor.h"

#include <algorithm>
#include <queue>

PolygonProcessor::PolygonProcessor(cycles_t& _cycles)
: cycles(_cycles)
{
	//Nothing
}

void PolygonProcessor::discardMirroredCycles()
{
	std::queue<cycles_t::iterator> erased_iterators;
	for (auto cycle_it1 = this->cycles.begin(); cycle_it1 != this->cycles.end(); ++cycle_it1) {
		if (cycle_it1 == erased_iterators.front()) {
			erased_iterators.pop();
			continue;
		}
		std::set<cycle_points_t> initial_segments;
		for (const auto& segment_it:*cycle_it1) {
			initial_segments.insert(segment_it.first);
		}
		for (auto cycle_it2 = cycle_it1; cycle_it2 != this->cycles.end(); ++cycle_it2) {
			if (cycle_it1 == cycle_it2) {
				continue;
			}
			std::set<cycle_points_t> combined_segments = initial_segments;
			for (const auto& segment_it:*cycle_it2) {
				cycle_points_t new_segment = make_pair(segment_it.first.second, segment_it.first.first);
				combined_segments.insert(new_segment);
			}
			if (initial_segments.size() == combined_segments.size()) {
				erased_iterators.emplace(cycle_it2);
				cycle_it2 = cycles.erase(cycle_it2);
			}
		}
	}
}

void PolygonProcessor::discardZeroAreaSegmentCycles()
{
}