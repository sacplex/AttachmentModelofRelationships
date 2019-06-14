#pragma once

#include <fstream>

class FileIO
{
private:
	std::ofstream writeToFile;
	std::ifstream readFromFile;
public:
	FileIO();
	~FileIO();
	void WriteANewPlayerFile(const char*);
	void WriteHeaderDataToPlayerFile(const char*);
	void WriteDataToPlayerFile(const char*);
	bool CheckForExistingPlayerFile(const char*);
};

