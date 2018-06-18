#include <Graph.h>

Graph::Graph(const intersections_t& intersections)
{
	this->cycles = calculateCycles(intersections);
}

const cycles_t& Graph::getCycles()
{
	return this->cycles;
}

cycles_t Graph::calculateCycles(const intersections_t& intersections)
{
	cycles_t cycles;
	return cycles;
}