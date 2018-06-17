#pragma once

#include <vector>
#include <string>

class ArgParser
{
	public:
		ArgParser(const int& argc, char **argv);
		bool cmdOptionExists(const std::string& option);
		const std::string& getCmdOption(const std::string& option);
	private:
		std::vector <std::string> c_tokens;
};