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
	this->inputFile_.open(inputFilename);
}

void Replace::setOutputFile(std::string outputFilename)
{
	this->outputFile_.open(outputFilename, std::ofstream::out | std::ofstream::trunc);
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

void Replace::readFile(void)
{
	this->inputFile_.get(this->buf_);
}

void Replace::replace(std::string target, std::string change)
{
	std::string inputStr;
	std::size_t targetPos;

	inputStr = this->buf_.str();
	while ((targetPos = inputStr.find(target)) != std::string::npos) {
		this->outputFile_ << inputStr.substr(0, targetPos) << change;
		if (this->outputFail())
			return ;
		inputStr = inputStr.substr(targetPos + target.size(), std::string::npos);
	}
	this->outputFile_ << inputStr;
}
