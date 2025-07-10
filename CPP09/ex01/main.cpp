#include "RPN.hpp"



int main(int argc, char* argv[]){
	try
	{
		if (argc != 2)
			std::invalid_argument("invalid arguments, synthax (./RPN <number.......>");
		else
		{
			long holder;
			std::stack<long> numbers;
			std::string num(argv[1]);
			std::istringstream input(num);
			while (input >> num)
			{
				if (RPN::ValidNumber(holder, num))
					numbers.push(holder);
				else
					RPN::DoOperation(num, numbers);
			}
			if (numbers.size() != 1)
				throw std::invalid_argument("allo");
			std::cout << numbers.top();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
