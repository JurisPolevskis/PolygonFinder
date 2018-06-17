#pragma once

#include <vector>
#include <string>

class Debug
{
	public:
		static void printIntTable( const std::vector< std::vector<int> >& table );
		static void print(const std::string& str);
};