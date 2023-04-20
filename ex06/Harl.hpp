#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
private:
	std::string commands_[4];
	void (Harl::*msg_[4])(void);

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	Harl(void);

	void complain(std::string level);

};

#endif
