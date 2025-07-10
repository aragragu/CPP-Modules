#include "PmergeMe.hpp"




int main(int argc, char* argv[]){
	try
	{
		if (argc < 3)
			throw std::invalid_argument("invalid arguments, minimal numbers to use are 2");
		else
		{
			std::vector<int> Vholder;
			std::deque<int> Qholder;

			int i = 1;
			while (argv[i]){
				std::string number(argv[i]);
				PmergeMe::validnumber(number , Vholder, Qholder);
				i++;
			}
			std::cout << "Before:   ";
			PmergeMe::printVector(Vholder);
			clock_t Vbegin = clock();
			Vholder = PmergeMe::sortVector(Vholder);
			clock_t Vend = clock();
			std::cout << "After:   ";
			PmergeMe::printVector(Vholder);
			std::cout << "Time to process a range of " << Vholder.size() <<  " elements with std::vector<int>  :  " << (static_cast<double>(Vend - Vbegin) / CLOCKS_PER_SEC) << " us" << std::endl;
			Vbegin = clock();
			Qholder = PmergeMe::sortDeque(Qholder);
			Vend = clock();
			std::cout << "Time to process a range of " << Qholder.size() << " elements with std::deque<int>  :  " << (static_cast<double>(Vend - Vbegin) / CLOCKS_PER_SEC)<< " us" << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}
