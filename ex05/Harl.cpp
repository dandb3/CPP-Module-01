#include <iostream>
#include "Harl.hpp"

Harl::Harl(void)
{
	msg_[0] = &Harl::debug;
	msg_[1] = &Harl::info;
	msg_[2] = &Harl::warning;
	msg_[3] = &Harl::error;
	commands_[0] = "DEBUG";
	commands_[1] = "INFO";
	commands_[2] = "WARNING";
	commands_[3] = "ERROR";
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout <<  "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; ++i) {
		if (level == this->commands_[i]) {
			(this->*msg_[i])();
			return;
		}
	}
	std::cout << "Invalid command." << std::endl;
}
