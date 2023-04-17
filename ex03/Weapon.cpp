#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type_(type)
{
	std::cout << "Weapon " << this->type_ << "created" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon " << this->type_ << "destroyed" << std::endl;
}

const std::string& Weapon::getType(void)
{
	return this->type_;
}

void Weapon::setType(std::string newType)
{
	this->type_ = newType;
}
