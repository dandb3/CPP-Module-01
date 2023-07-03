#include <iostream>
#include "Harl.hpp"

Harl::Harl(void)
{
	_msg[0] = &Harl::debug;
	_msg[1] = &Harl::info;
	_msg[2] = &Harl::warning;
	_msg[3] = &Harl::error;
	_commands[0] = "DEBUG";
	_commands[1] = "INFO";
	_commands[2] = "WARNING";
	_commands[3] = "ERROR";
}

Harl::~Harl(void) {}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]\n";
	std::cout <<  "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; ++i) {
		if (level == this->_commands[i]) {
			(this->*_msg[i])();
			return;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]\n" << std::endl;
}
