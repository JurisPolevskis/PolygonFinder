#include "Debug.h"

#include <iostream>

void Debug::print(const std::string& str) 
{
	#ifdef DEBUG
		std::cout << str << std::endl;
	#endif
}