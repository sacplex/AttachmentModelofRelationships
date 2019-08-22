#include "Fact.h"

namespace AMR {

	Fact::Fact()
	{
		name = "unknown";
		data = "unknown";
	}

	Fact::Fact(String name, String data)
	{
		Fact::name = name;
		Fact::data = data;

		if (data.compare("unknown"))
			known = false;
		else
			known = true;
	}


	Fact::~Fact()
	{
	}

	void Fact::SetFactData(String name, String data)
	{
		Fact::name = name;
		Fact::data = data;
	}

	String Fact::GetFactName()
	{
		return name;
	}

	String Fact::GetFactData()
	{
		return data;
	}
}