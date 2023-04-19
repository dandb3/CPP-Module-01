#include <iostream>
#include "Replace.hpp"

Replace::Replace(void) {}

Replace::~Replace(void)
{
	if (this->inputFile_.is_open())
		this->inputFile_.close();
	if (this->outputFile_.is_open())
		this->outputFile_.close();
}

void Replace::setInputFile(std::string inputFilename)
{
	this->inputFile_.open(inputFilename.c_str());
}

void Replace::setOutputFile(std::string outputFilename)
{
	this->outputFile_.open(outputFilename.c_str(), std::ofstream::out | std::ofstream::trunc);
}

bool Replace::inputIsOpen(void)
{
	return this->inputFile_.is_open();
}

bool Replace::outputIsOpen(void)
{
	return this->outputFile_.is_open();
}

bool Replace::inputFail(void)
{
	return this->inputFile_.fail();
}

bool Replace::outputFail(void)
{
	return this->outputFile_.fail();
}

void Replace::replace(std::string target, std::string change)
{
	std::string inputStr;
	std::size_t fileSize;
	std::size_t targetPos;
	char* buffer;

	this->inputFile_.seekg(0, std::ios_base::end);
	fileSize = this->inputFile_.tellg();
	this->inputFile_.seekg(0, std::ios_base::beg);
	buffer = new char[fileSize + 1];
	this->inputFile_.read(buffer, fileSize);
	if (this->inputFile_.bad()) {
		delete[] buffer;
		return;
	}
	buffer[fileSize] = '\0';
	inputStr = std::string(buffer);
	delete[] buffer;
	while ((targetPos = inputStr.find(target)) != std::string::npos) {
		this->outputFile_ << inputStr.substr(0, targetPos) << change;
		if (this->outputFile_.fail())
			return;
		inputStr = inputStr.substr(targetPos + target.size(), std::string::npos);
	}
	this->outputFile_ << inputStr;
}
