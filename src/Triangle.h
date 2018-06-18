#pragma once

#include <set>
#include "Point.h"

typedef double area_t;

class Triangle
{
	public:
		Triangle();
		Triangle(std::pair<coordinate_t, coordinate_t> _a, 
				std::pair<coordinate_t, coordinate_t> _b, 
				std::pair<coordinate_t, coordinate_t> _c);
		Triangle(Point a, Point b, Point c);
		area_t getArea();
	private:
		Point a;
		Point b;
		Point c;
};