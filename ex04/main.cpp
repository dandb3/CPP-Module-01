#include <iostream>
#include "Replace.hpp"

static bool replaceWords(char *argv[])
{
	Replace replaceTool;

	replaceTool.setInputFile(argv[1]);
	if (!replaceTool.inputIsOpen()) {
		std::cerr << "File open error" << std::endl;
		return (false);
	}
	replaceTool.setOutputFile(std::string(argv[1]) + ".replace");
	if (!replaceTool.outputIsOpen()) {
		std::cerr << "File open error" << std::endl;
		return (false);
	}
	replaceTool.replace(argv[2], argv[3]);
	if (replaceTool.fail()) {
		std::cerr << "Replace error" << std::endl;
		return (false);
	}
	return (true);
}

int main(int argc, char *argv[])
{
	Replace replaceTool;

	if (argc != 4) {
		std::cerr << "Invalid input: [filename] [target] [change]" << std::endl;
		return 1;
	}
	if (replaceWords(argv) == false)
		return 1;
	return 0;
}