#include "Container.hpp"

int main(int argc, char *argv[])
{
	if (argc == 4)
	{
		std::string filename = argv[1];
		std::string file_replace = filename + ".replace";
		std::string file;
		std::string line;
		std::ifstream in_file(argv[1]);
		if (!in_file)
		{
			std::cerr << "Error: Cannot open input file!" << std::endl;
			return 1;
		}
		while (std::getline(in_file, line))
			file += line + "\n";
		if (file.empty())
		{
			std::cerr << "error: file is empty" << std::endl;
			return 1;
		}
		if (!std::strlen(argv[2]) || !std::strlen(argv[3]))
		{
			std::cerr << "Error: Both the string to be replaced and the replacement string must be non-empty!" << std::endl;
			return 1;
		}
		in_file.close();
		Container data(file);
		data.set_string(argv[2], argv[3]);
		std::ofstream ou_file(file_replace.c_str());
		if (!ou_file)
		{
			std::cerr << "Error: Cannot create output file!" << std::endl;
			return 1;
		}
		ou_file << data.S2_getter();
		ou_file.close();
		return 0;
	}
	else
	{
		std::cerr << "Usage: ./program filename s1 s2" << std::endl;
		return 1;
	}
}
