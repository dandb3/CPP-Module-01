#include <iostream>
#include "Replace.hpp"

int main(int argc, char *argv[])
{
	Replace replaceTool;

	if (argc != 4) {
		std::cerr << "Usage: [filename] [target] [change]" << std::endl;
		return 1;
	}
	replaceTool.setInputFile(argv[1]);
	if (!replaceTool.inputIsOpen()) {
		std::cerr << "Error: file open failed" << std::endl;
		return 1;
	}
	replaceTool.setOutputFile(std::string(argv[1]) + ".replace");
	if (!replaceTool.outputIsOpen()) {
		std::cerr << "Error: file open failed" << std::endl;
		return 1;
	}
	replaceTool.replace(argv[2], argv[3]);
	if (!replaceTool.good()) {
		std::cerr << "Error: replacement failed" << std::endl;
		return 1;
	}
	return 0;
}