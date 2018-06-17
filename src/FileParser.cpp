#include <FileParser.h>

#include <sstream>
#include <Debug.h>

FileParser::FileParser(const std::string& filename)
{
	c_file.open(filename);
}

FileParser::~FileParser()
{
	c_file.close();
}

const std::vector<std::vector<int>>& FileParser::getIntTable(const char& delimiter)
{
	static std::vector<std::vector<int>> table;
	std::string line;
	while ( std::getline(c_file, line) ) {
		std::stringstream linestream(line);
		std::string data;
		std::vector<int> int_line;
		while (getline(linestream, data, delimiter)) {
			int_line.push_back(stoi(data));
		}
		table.push_back(int_line);
	}
	Debug::printIntTable(table);
	return table;
}
