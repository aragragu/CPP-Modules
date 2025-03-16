#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; argv[i]; i++)
		{
			std::string str = argv[i];
			for (int g = 0; str[g]; g++)
			{
				if (std::isalpha(str[g]))
					str[g] = std::toupper(str[g]);
			}
			std::cout << str;
		}
		std::cout << std::endl;
	}
	return 0;
}
