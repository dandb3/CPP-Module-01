#include <iostream>
#include <sstream>
#include "Replace.hpp"

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

bool Replace::fail(void)
{
	if (this->inputFile_.fail() || this->outputFile_.fail() || this->oss_.fail())
		return true;
	return false;
}

void Replace::replace(std::string target, std::string change)
{
	std::string inputStr;
	std::size_t targetPos;

	this->oss_ << this->inputFile_.rdbuf();
	if (this->oss_.fail() || this->inputFile_.fail())
		return;
	inputStr = this->oss_.str();
	while ((targetPos = inputStr.find(target)) != std::string::npos) {
		this->outputFile_ << inputStr.substr(0, targetPos) << change;
		if (this->outputFile_.fail())
			return;
		inputStr = inputStr.substr(targetPos + target.size(), std::string::npos);
	}
	this->outputFile_ << inputStr;
}
