#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
private:
	std::string name_;
public:
	Zombie(std::string name);
	~Zombie(void);

	void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
