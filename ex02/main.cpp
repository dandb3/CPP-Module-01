#include <iostream>
#include <string>

int main(void)
{
	std::string msg("HI THIS IS BRAIN");
	std::string* stringPTR = &msg;
	std::string& stringREF = msg;

	std::cout << "Address of string object: " << &msg << '\n';
	std::cout << "Address of string pointer: " << &stringPTR << '\n';
	std::cout << "Address of string reference: " << &stringREF << std::endl;
	
	std::cout << "Value of string object: " << msg << '\n';
	std::cout << "Value of string pointer: " << *stringPTR << '\n';
	std::cout << "Value of string reference: " << stringREF << std::endl;

	return 0;
}