#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << "Weapon " << this->_type << " created" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon " << this->_type << " destroyed" << std::endl;
}

const std::string& Weapon::getType(void)
{
	return this->_type;
}

void Weapon::setType(std::string newType)
{
	this->_type = newType;
}
