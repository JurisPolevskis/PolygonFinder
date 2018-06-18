#include "ArgParser.h"

#include <iostream>
#include <algorithm>

void test() {
	std::cout << "test OK";
}

ArgParser::ArgParser(const int& argc, char **argv)
{
	for (int i = 1; i < argc; i++) {
		this->tokens.push_back( std::string(argv[i]) );
	}
}

bool ArgParser::cmdOptionExists(const std::string& option)
{
	return (std::find(this->tokens.begin(), this->tokens.end(), option) != this->tokens.end());
}

std::string ArgParser::getCmdOption(const std::string& option, const std::string& default_value)
{
	auto it = std::find(this->tokens.begin(), this->tokens.end(), option);
	if (it != this->tokens.end() && (it + 1) != this->tokens.end()) {
		return *(it + 1);
	}
	return default_value;
}

std::string ArgParser::getCmdOption(const std::string& option)
{
	return getCmdOption(option, "");
}