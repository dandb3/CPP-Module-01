#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon), _name(name)
{
	std::cout << "HumanA " << this->_name << " created" << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA " << this->_name << " destroyed" << std::endl;
}

void HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
