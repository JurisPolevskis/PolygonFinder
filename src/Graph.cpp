#include <Graph.h>

Graph::Graph(const intersections_t& intersections)
{
	c_cycles = calculateCycles(intersections);
}

const cycles_t& Graph::getCycles()
{
	return c_cycles;
}

cycles_t Graph::calculateCycles(const intersections_t& intersections)
{
	cycles_t cycles;
	return cycles;
}