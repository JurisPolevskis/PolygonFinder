#include <Intersector.h>

Intersector::Intersector(const lines_t& lines)
{
	c_intersections = calculateIntersections(lines);
}

const intersections_t& Intersector::getIntersections()
{
	return c_intersections;
}

intersections_t Intersector::calculateIntersections(const lines_t& lines)
{
	intersections_t intersections;
	return intersections;
}