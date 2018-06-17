#include <ArgParser.h>

#include <iostream>
#include <algorithm>

void test() {
	std::cout << "test OK";
}

ArgParser::ArgParser(const int& argc, char **argv)
{
	for (int i = 1; i < argc; i++) {
		c_tokens.push_back( std::string(argv[i]) );
	}
}

bool ArgParser::cmdOptionExists(const std::string& option)
{
	return (std::find(c_tokens.begin(), c_tokens.end(), option) != c_tokens.end());
}

const std::string& ArgParser::getCmdOption(const std::string& option)
{
	auto it = std::find(c_tokens.begin(), c_tokens.end(), option);
	if (it != c_tokens.end() && (it + 1) != c_tokens.end()) {
		return *(it + 1);
	}
	static const std::string empty_string = "";
	return empty_string;
}