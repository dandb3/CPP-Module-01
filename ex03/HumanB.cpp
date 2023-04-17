#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : weapon_(NULL), name_(name)
{
	std::cout << "HumanB " << this->name_ << " created" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB " << this->name_ << " destroyed" << std::endl;
}

void HumanB::setWeapon(Weapon& newWeapon)
{
	weapon_ = &newWeapon;
}

void HumanB::attack(void)
{
	if (this->weapon_ == NULL) {
		std::cout << this->name_ << " doesn't have any weapon" << std::endl;
		return ;
	}
	std::cout << this->name_ << " attacks with their " << this->weapon_->getType() << std::endl;
}
