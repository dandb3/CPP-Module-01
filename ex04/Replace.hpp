#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <fstream>
# include <sstream>

class Replace
{
private:
	std::ifstream inputFile_;
	std::ofstream outputFile_;
	std::stringbuf buf_;

public:
	Replace(void);
	~Replace(void);

	void setInputFile(std::string inputFilename);
	void setOutputFile(std::string outputFilename);

	bool inputIsOpen(void);
	bool outputIsOpen(void);
	bool inputFail(void);
	bool outputFail(void);
	void readFile(void);
	void replace(std::string target, std::string change);
};

#endif
