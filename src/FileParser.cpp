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
	Debug::print("getIntTable returns:");
	Debug::print(intTableToString(table));
	return table;
}

std::string FileParser::intTableToString(const std::vector<std::vector<int>>& table)
{
	std::string message = "Int table:";
	for (const auto& table_line:table) {
		std::string str_line = "";
		bool first_value = true;
		for (const auto& value:table_line) {
			if (!first_value) {
				str_line.append("\t");
			}
			first_value = false;
			str_line.append(std::to_string(value));
		}
		message.append("\n" + str_line);
	}
	return message;
}
