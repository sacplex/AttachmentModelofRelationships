#include "FileIO.h"

namespace AMR {

	FileIO::FileIO()
	{
	}


	FileIO::~FileIO()
	{
		writeToFile.close();
		readFromFile.close();
	}

	void FileIO::ReadFile(const char* fileName)
	{
		std::string line;
		readFromFile.open(fileName);

		while (getline(readFromFile, line))
		{
			lines.emplace_back(line);
		}

		readFromFile.close();
	}

	std::vector<std::string> FileIO::GetLines()
	{
		return lines;
	}

	void FileIO::WriteANewPlayerFile(const char* fileName)
	{
		writeToFile.open(fileName);
	}

	void FileIO::WriteHeaderDataToPlayerFile(const char* headerData, bool firstHeader)
	{
		if (firstHeader)
			writeToFile << headerData << "\n\n";
		else
			writeToFile << "\n" << headerData << "\n\n";
	}

	void FileIO::WriteDataToPlayerFile(const char* data)
	{
		writeToFile << data;
	}

	bool FileIO::CheckForExistingPlayerFile(const char* fileName)
	{
		std::ifstream checkingForFile(fileName);
		return (bool)checkingForFile;
	}
}