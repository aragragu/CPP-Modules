#include "PmergeMe.hpp"




int main(int argc, char* argv[]){
	try
	{
		if (argc < 3)
			throw std::invalid_argument("invalid arguments, minimal numbers to use are 2");
		else
		{
			std::vector<int> Vholder, V_toPrint;
			std::deque<int> Qholder;

			int i = 1;
			clock_t Vbegin = clock();
			while (argv[i]){
				std::string number(argv[i]);
				trim(number);
				PmergeMe::validnumber(number);
				i++;
			}
			clock_t Vend = clock();
			double parsing_time = (static_cast<double>(Vend - Vbegin) / CLOCKS_PER_SEC) * 1000000;
			i = 1;
			while (argv[i]){
				std::string number(argv[i]);
				PmergeMe::InsertToV(number, V_toPrint);
				i++;
			}
			std::cout << "Before:   ";
			PmergeMe::printVector(V_toPrint);
			i = 1;
			Vbegin = clock();
			while (argv[i])
			{
				std::string number(argv[i]);
				PmergeMe::InsertToV(number, Vholder);
				i++;
			}
			Vholder = PmergeMe::sortVector(Vholder);
			Vend = clock();
			double V_time = (static_cast<double>(Vend - Vbegin) / CLOCKS_PER_SEC) * 1000000;
			i = 1;
			Vbegin = clock();
			while (argv[i])
			{
				std::string number(argv[i]);
				PmergeMe::InsertToQ(number, Qholder);
				i++;
			}
			Qholder = PmergeMe::sortDeque(Qholder);
			Vend = clock();
			double Q_time = (static_cast<double>(Vend - Vbegin) / CLOCKS_PER_SEC) * 1000000;
			std::cout << "After:   ";
			PmergeMe::printVector(Vholder);
			std::cout << "Time to process a range of " << Vholder.size() << " elements with std::vector<int>  :  " << V_time + parsing_time  << " us" << std::endl;
			std::cout << "Time to process a range of " << Qholder.size() << " elements with std::deque<int>  :  " << Q_time + parsing_time << " us" << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}
