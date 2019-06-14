#include "FileIO.h"

FileIO::FileIO()
{
}


FileIO::~FileIO()
{
	writeToFile.close();
	readFromFile.close();
}

void FileIO::WriteANewPlayerFile(const char* fileName)
{
	writeToFile.open(fileName);
}

void FileIO::WriteHeaderDataToPlayerFile(const char* headerData)
{
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
