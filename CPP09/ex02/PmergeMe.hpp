#ifndef PMERGEME_HPP
# define PMERGEME_HPP
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stdexcept>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <ctime>

class PmergeMe
{
	private:
		PmergeMe(PmergeMe const &copy);
		PmergeMe(void);
		PmergeMe const &operator = (PmergeMe const &rhs);
	public :
		~PmergeMe(void);

		static void validnumber(std::string number, std::vector<int> &Vholder, std::deque<int> &Qholder);
		static std::vector<int> sortVector(std::vector<int>& list);
		static std::deque<int> sortDeque(std::deque<int>& list);
		static void V_separateHolder(std::vector<int> &holder, std::vector<int> &main, std::vector<int> &pend);
		static void Q_separateHolder(std::deque<int> &holder, std::deque<int> &main, std::deque<int> &pend);
		static void V_insertSmallerInBiggerHalf(std::vector<int> &BiggerHalf, std::vector<int> &SmallerHalf);
		static void Q_insertSmallerInBiggerHalf(std::deque<int> &BiggerHalf, std::deque<int> &SmallerHalf);
		static void printVector(std::vector<int> sorted_list);
		static void printDeque(std::deque<int> sorted_list);
};

#endif
