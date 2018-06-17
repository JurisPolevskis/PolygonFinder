#include <FileParser.h>

FileParser::FileParser(const std::string& filename)
{
	c_file.open(filename);
}

FileParser::~FileParser()
{
	c_file.close();
}

const std::vector<std::vector<int>>& FileParser::getIntTable(const std::string& delimiters)
{
	//TODO:Implement
	static std::vector<std::vector<int>> table;
	return table;
}
