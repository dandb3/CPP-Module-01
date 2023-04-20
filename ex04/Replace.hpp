#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <fstream>
# include <sstream>

class Replace
{
private:
	std::ifstream inputFile_;
	std::ofstream outputFile_;
	std::ostringstream oss_;

public:
	void setInputFile(std::string inputFilename);
	void setOutputFile(std::string outputFilename);

	bool inputIsOpen(void);
	bool outputIsOpen(void);
	bool fail(void);
	void replace(std::string target, std::string change);
};

#endif
