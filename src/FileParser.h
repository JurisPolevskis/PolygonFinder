#pragma once

#include <string>
#include <vector>
#include <fstream>

class FileParser
{
	public:
		FileParser(const std::string& filename);
		~FileParser();
		const std::vector<std::vector<int>>& getIntTable(const char& delimiter);
		static std::string intTableToString(const std::vector<std::vector<int>>& table);
	private:
		std::ifstream file;
};