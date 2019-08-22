#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include <vector>

namespace AMR {

	class FileIO
	{
	private:
		std::ofstream writeToFile;
		std::ifstream readFromFile;

		std::vector<std::string> lines;
	public:
		FileIO();
		~FileIO();
		void ReadFile(const char*);
		std::vector<std::string> GetLines();
		void WriteANewPlayerFile(const char*);
		void WriteHeaderDataToPlayerFile(const char*, bool = false);
		void WriteDataToPlayerFile(const char*);
		bool CheckForExistingPlayerFile(const char*);
	};

}