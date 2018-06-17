#include <Output.h>

#include <iostream>
#include <stdio.h>

Output::Output(const std::string& filename)
{
	if (!filename.empty()) {
		c_file.open(filename, std::ios::out);
	}
}

Output::~Output()
{
	c_file.close();
}

void Output::print(const std::string&  str)
{
	std::cout << str;
	if (c_file.is_open()) {
		c_file << str;
	}
}

