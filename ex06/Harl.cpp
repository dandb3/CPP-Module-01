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
	int idx = 0;

	for (; idx < 4; ++idx)
		if (level == this->_commands[idx])
			break;
	switch (idx) {
	case 0:
		(this->*_msg[0])();
		__attribute__((fallthrough));
	case 1:
		(this->*_msg[1])();
		__attribute__((fallthrough));
	case 2:
		(this->*_msg[2])();
		__attribute__((fallthrough));
	case 3:
		(this->*_msg[3])();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n" << std::endl;
	}
}
