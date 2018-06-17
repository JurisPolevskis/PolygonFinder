#pragma once

typedef int coordinate_t;

class Point
{
	public:
		Point();
		Point(const coordinate_t& x, const coordinate_t& y);
		bool operator==(const Point& point);
	private:
		coordinate_t c_x;
		coordinate_t c_y;
};