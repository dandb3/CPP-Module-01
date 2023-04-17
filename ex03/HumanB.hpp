#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
private:
	Weapon* weapon_;
	std::string name_;
public:
	HumanB(std::string name);
	~HumanB(void);

	void setWeapon(Weapon& newWeapon);

	void attack(void);
};

#endif
