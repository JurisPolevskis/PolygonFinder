#pragma once

#include <string>

typedef double coordinate_t;

class Point
{
	public:
		Point();
		Point(const coordinate_t& x, const coordinate_t& y);
		bool operator== (const Point& point);
		Point operator+ (const Point& point) const;
		Point operator- (const Point& point) const;
		coordinate_t operator* (const Point& point);//cross product
		Point operator* (const coordinate_t& multiplier);
		coordinate_t getX() const;
		coordinate_t getY() const;
		static std::string to_string(Point point);
	private:
		coordinate_t x;
		coordinate_t y;
};