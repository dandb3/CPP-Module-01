#include "Zombie.hpp"

int main(void)
{
	Zombie* horde = zombieHorde(10, "zombie");
	for (int i = 0; i < 10; ++i)
		horde[i].announce();
	delete[] horde;
	return 0;
}
