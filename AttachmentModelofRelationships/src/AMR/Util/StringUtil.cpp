#include "StringUtil.h"

namespace AMR {

	StringUtil::StringUtil()
	{
	}


	StringUtil::~StringUtil()
	{
	}

	std::vector<std::string> StringUtil::Split(const std::string& input, const std::string& _regex)
	{
		std::regex re(_regex);
		std::sregex_token_iterator
			first{ input.begin(), input.end(), re, -1 },
			last;
		return { first, last };
	}
}
