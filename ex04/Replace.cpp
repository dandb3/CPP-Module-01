#include <iostream>
#include "Replace.hpp"

void Replace::setInputFile(std::string inputFilename)
{
	this->_inputFile.open(inputFilename.c_str());
}

void Replace::setOutputFile(std::string outputFilename)
{
	this->_outputFile.open(outputFilename.c_str(), std::ofstream::out | std::ofstream::trunc);
}

bool Replace::inputIsOpen(void)
{
	return this->_inputFile.is_open();
}

bool Replace::outputIsOpen(void)
{
	return this->_outputFile.is_open();
}

bool Replace::good(void)
{
	if (this->_inputFile.good() && this->_outputFile.good() && !this->_oss.bad())
		return true;
	return false;
}

void Replace::replace(std::string target, std::string change)
{
	std::string inputStr;
	std::size_t targetPos = 0;

	this->_oss << this->_inputFile.rdbuf();
	if (this->_oss.bad())
		return;
	inputStr = this->_oss.str();
	while ((targetPos = inputStr.find(target, targetPos)) != std::string::npos) {
		inputStr.replace(targetPos, target.size(), change);
		targetPos += change.size();
	}
	this->_outputFile << inputStr;
}
