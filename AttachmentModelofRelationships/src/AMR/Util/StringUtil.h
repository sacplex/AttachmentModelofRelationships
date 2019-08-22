#pragma once

#include <iostream>
#include <regex>
#include <vector>

namespace AMR
{
	class StringUtil
	{
	public:
		StringUtil();
		~StringUtil();
		std::vector<std::string> Split(const std::string&, const std::string&);
	};
}

