#include "Zombie.hpp"

int main(void)
{
	Zombie zombie1("one");
	Zombie zombie2 = Zombie("two");
	zombie1.announce();
	zombie2.announce();
	{
		Zombie zombie3 = Zombie("three");
		zombie3.announce();
	}
	Zombie* zombie4 = newZombie("four");
	zombie4->announce();
	delete zombie4;
	randomChump("five");
	return 0;
}
