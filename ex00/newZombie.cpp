#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie* babyZombie = new Zombie(name);
	return babyZombie;
}
