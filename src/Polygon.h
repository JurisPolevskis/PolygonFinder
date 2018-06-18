#pragma once

#include <set>
#include "Line.h"

typedef int area_t;

class Polygon
{
	public:
		Polygon();
		Polygon(const lines_t& sides);
		area_t getArea();
	private:
		lines_t sides;
};

inline bool operator== (const Polygon& p1, const Polygon& p2)
{
	//TODO:Implement
	return false;
}

inline bool operator< (const Polygon& p1, const Polygon& p2)//for set
{
	//TODO:Implement
	return true;
}

typedef std::set<Polygon> polygons_t;