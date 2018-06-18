#pragma once

#include <string>
#include <fstream>

class Output
{
	public:
		Output(const std::string& filename);
		~Output();
		void print(const std::string&  str);
	private:
		std::ofstream file;
};