#pragma once

#include <string>
#include <vector>
#include <fstream>

class FileParser
{
	public:
		FileParser(const std::string& filename);
		~FileParser();
		const std::vector<std::vector<int>>& getIntTable(const std::string& delimiters);
	private:
		std::ifstream c_file;
};