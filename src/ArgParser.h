#pragma once

#include <vector>
#include <string>

class ArgParser
{
	public:
		ArgParser(const int& argc, char **argv);
		bool cmdOptionExists(const std::string& option);
		std::string getCmdOption(const std::string& option, const std::string& default_value);
		std::string getCmdOption(const std::string& option);
	private:
		std::vector <std::string> tokens;
};