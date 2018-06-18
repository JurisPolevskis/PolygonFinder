#include <PolygonProcessor.h>

PolygonProcessor::PolygonProcessor(const cycles_t& cycles, const lines_t& lines)
{
	this->polygons = makePolygons(cycles, lines);
}

const std::string& PolygonProcessor::writePolygons()
{
	//TODO:Implement
	static std::string polygon_str = "";
	return polygon_str;
}

void PolygonProcessor::discardZeroLengthSides()
{
	//TODO:Implement
}

void PolygonProcessor::discardZeroAreaPolygons()
{
	//TODO:Implement
}

polygons_t PolygonProcessor::makePolygons(const cycles_t& cycles, const lines_t& lines)
{
	//TODO:Implement
	polygons_t polygons;
	return polygons;
}