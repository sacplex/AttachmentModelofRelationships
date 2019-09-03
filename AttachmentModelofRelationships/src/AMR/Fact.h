#pragma once

#include <iostream>

#include "Core/Core.h"

namespace AMR {

	class Fact
	{
	private:
		String name;
		String data;
		String question;
		bool known;
	public:
		Fact();
		Fact(String name, String data);
		~Fact();
		void SetFactData(String name, String data);
		void setFactQuestion(String question);
		String GetFactName();
		String GetFactData();
		String GetFactQuestion();
	};
}