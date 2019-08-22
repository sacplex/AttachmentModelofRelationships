#pragma once

#include <iostream>

#include "Core/Core.h"

namespace AMR {

	class Fact
	{
	private:
		String name;
		String data;
		bool known;
	public:
		Fact();
		Fact(String name, String data);
		~Fact();
		void SetFactData(String name, String data);
		String GetFactName();
		String GetFactData();
	};
}