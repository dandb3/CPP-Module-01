#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : weapon_(weapon), name_(name)
{
	std::cout << "HumanA " << this->name_ << " created" << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA " << this->name_ << " destroyed" << std::endl;
}

void HumanA::attack(void)
{
	std::cout << this->name_ << " attacks with their " << this->weapon_.getType() << std::endl;
}
