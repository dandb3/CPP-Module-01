#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void) : name_("default")
{
	std::cout << this->name_ << ": created" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->name_ << ": destroyed" << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name_ = name;
}

void Zombie::announce(void)
{
	std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
