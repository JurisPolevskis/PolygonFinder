#include "Output.h"

#include <iostream>
#include <stdio.h>

#include "Debug.h"

Output::Output(const std::string& filename)
{
	Debug::print("Output: " + filename);
	if (!filename.empty()) {
		this->file.open(filename, std::ios::out);
	}
}

Output::~Output()
{
	this->file.close();
}

void Output::print(const std::string&  str)
{
	std::cout << str;
	if (this->file.is_open()) {
		this->file << str;
	}
}

