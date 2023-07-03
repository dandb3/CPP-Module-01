#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <fstream>
# include <sstream>

class Replace
{
private:
	std::ifstream _inputFile;
	std::ofstream _outputFile;
	std::ostringstream _oss;

public:
	void setInputFile(std::string inputFilename);
	void setOutputFile(std::string outputFilename);

	bool inputIsOpen(void);
	bool outputIsOpen(void);
	bool bad(void);
	void replace(std::string target, std::string change);
};

#endif
