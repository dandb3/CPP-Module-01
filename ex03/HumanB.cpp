#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _weapon(NULL), _name(name)
{
	std::cout << "HumanB " << this->_name << " created" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB " << this->_name << " destroyed" << std::endl;
}

void HumanB::setWeapon(Weapon& newWeapon)
{
	_weapon = &newWeapon;
}

void HumanB::attack(void)
{
	if (this->_weapon == NULL) {
		std::cout << this->_name << " doesn't have any weapon" << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
