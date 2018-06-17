#include <ArgParser.h>

#include <iostream>

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
	//TODO:Implement
	return false;
}

const std::string& ArgParser::getCmdOption(const std::string& option)
{
	//TODO:Implement
	static const std::string empty_string = "";
	return empty_string;
}