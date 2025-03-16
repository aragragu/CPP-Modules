#include "Harl.hpp"


int		get_level(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (size_t i = 0; i < 4; i++)
	{
		if (level == levels[i])
			return (i);
	}
	return -1;

}

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		Harl harold;
		std::string level = argv[1];
		int level_num = get_level(level);
		switch (level_num)
		{
			case 0:
				harold.complain("DEBUG");
				// fall through
			case 1:
				harold.complain("INFO");
				// fall through
			case 2:
				harold.complain("WARNING");
				// fall through
			case 3:
				harold.complain("ERROR");
				// fall through
				break;
			default:
				std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
		}
		return 0;
	}
	else
	{
		std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
		return 1;
	}
}
