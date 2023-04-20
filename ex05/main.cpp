#include <iostream>
#include "Harl.hpp"

int main(void)
{
	Harl harl;
	std::string cmd;

	while (std::cin >> cmd) {
		harl.complain(cmd);
	}
	return 0;
}