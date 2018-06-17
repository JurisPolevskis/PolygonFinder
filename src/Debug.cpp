#include "Debug.h"

#include <iostream>

void Debug::printIntTable(const std::vector< std::vector<int> >& table )
{
	print("printIntTable");
	for (const auto& int_line:table) {
		std::string line = "";
		bool first_value = true;
		for (const int& value:int_line) {
			if (!first_value) {
				line.append("\t");
			}
			line.append(std::to_string(value));
		}
		print(line);
	}
}

void Debug::print(const std::string& str) 
{
	#ifdef DEBUG
		std::cout << str << std::endl;
	#endif
}