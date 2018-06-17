#pragma once

#include <vector>
#include <string>

class Debug
{
	public:
		template<typename T> static void print2dObject(const T& object);
		static void print(const std::string& str);
};

template<typename T> void Debug::print2dObject(const T& object)
{
	for (const auto& it:object) {
		std::string line = "";
		bool first_value = true;
		for (const auto& value:it) {
			if (!first_value) {
				line.append("\t");
			}
			line.append(std::to_string(value));
		}
		Debug::print(line);
	}
}