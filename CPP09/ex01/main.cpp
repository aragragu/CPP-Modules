#include "RPN.hpp"



int main(int argc, char* argv[]){
	try
	{
		if (argc != 2)
			throw std::invalid_argument("invalid arguments, synthax (./RPN <number.......>");
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
				throw std::invalid_argument("Error: stack does not have one number");
			std::cout << numbers.top() << "\n";
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
