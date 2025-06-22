#include "BitcoinExchange.hpp"




int main(int argc, char* argv[]){
	try
	{
		if (argc != 2)
			throw std::invalid_argument("invlaid argument. (syntax ./btc <filename.txt>)");
		else
		{
			std::string filename = argv[1];
			Data_and_Prices allo(filename);
			allo.ParseData();

		}

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
