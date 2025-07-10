#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
	*this = copy;
}

PmergeMe::~PmergeMe(void) {}

PmergeMe const	&PmergeMe::operator = (PmergeMe const &rhs)
{
	(void)rhs;
	return (*this);
}

void PmergeMe::validnumber(std::string number, std::vector<int> &Vholder, std::deque<int> &Qholder)
{
	long num;
	if (number.empty())
		throw std::invalid_argument("invalid number, reason: empty string");
	for (size_t i = 0; i < number.size(); i++)
	{
		if (i == 0 && number[i] == '+')
			continue;
		if (!std::isdigit(number[i]))
			throw std::invalid_argument("invlaid number");
	}
	num = std::strtol(number.c_str(), NULL, 10);
	if (num < 1 ||  num > INT_MAX)
		throw std::invalid_argument("invlaid number, reason: number is out of range");
	if (std::find(Vholder.begin(), Vholder.end(), num) == Vholder.end()){
		Vholder.push_back(static_cast<int>(num));
		Qholder.push_back(static_cast<int>(num));
	}
	else
		throw std::invalid_argument("duplicated numbers");
}

void PmergeMe::V_separateHolder(std::vector<int>& holder, std::vector<int> &B_List, std::vector<int> &S_List){
	size_t lenght = holder.size() % 2 == 0 ? holder.size() : holder.size() - 1;
	for (size_t i = 0; i < lenght; i += 2)
	{
		if (holder[i] > holder[i + 1])
		{
			B_List.push_back(holder[i]);
			S_List.push_back(holder[i + 1]);
		}
		else
		{
			B_List.push_back(holder[i + 1]);
			S_List.push_back(holder[i]);
		}
	}
	if (holder.size() % 2 == 1)
		S_List.push_back(holder[holder.size() - 1]);
}

void PmergeMe::Q_separateHolder(std::deque<int> &holder, std::deque<int> &B_List, std::deque<int> &S_List)
{
	size_t lenght = holder.size() % 2 == 0 ? holder.size() : holder.size() - 1;
	for (size_t i = 0; i < lenght; i += 2)
	{
		if (holder[i] > holder[i + 1])
		{
			B_List.push_back(holder[i]);
			S_List.push_back(holder[i + 1]);
		}
		else
		{
			B_List.push_back(holder[i + 1]);
			S_List.push_back(holder[i]);
		}
	}
	if (holder.size() % 2 == 1)
		S_List.push_back(holder[holder.size() - 1]);
}

std::vector<int> V_GenerateSequence(int x){
	std::vector<int> sequence;
	int i = 1, j = 1;
	while (j - 1 <= x)
	{
		sequence.push_back(j);
		int next = j + 2 * i;
		i = j;
		j = next;
	}
	return sequence;
}
std::deque<int> Q_GenerateSequence(int x)
{
	std::deque<int> sequence;
	int i = 1, j = 1;
	while (j - 1 <= x)
	{
		sequence.push_back(j);
		int next = j + 2 * i;
		i = j;
		j = next;
	}
	return sequence;
}

void PmergeMe::V_insertSmallerInBiggerHalf(std::vector<int> &BiggerHalf, std::vector<int> &SmallerHalf)
{
	std::vector<int> FilledIndex;
	std::vector<int> jackSequence = V_GenerateSequence(SmallerHalf.size());
	for (size_t i = 0; i < jackSequence.size(); i++)
	{
		size_t index = jackSequence[i] - 1;
		if (index >= SmallerHalf.size())
			break;
		std::vector<int>::iterator InsetPosition = std::upper_bound(BiggerHalf.begin(), BiggerHalf.end(), SmallerHalf[index]);
		BiggerHalf.insert(InsetPosition, SmallerHalf[index]);
		FilledIndex.push_back(index);
	}
	for (size_t i = 0; i < SmallerHalf.size(); i++)
	{
		if (std::find(FilledIndex.begin(), FilledIndex.end(), i) == FilledIndex.end())
		{
			std::vector<int>::iterator InsetPosition = std::upper_bound(BiggerHalf.begin(), BiggerHalf.end(), SmallerHalf[i]);
			BiggerHalf.insert(InsetPosition, SmallerHalf[i]);
		}
	}
}
void PmergeMe::Q_insertSmallerInBiggerHalf(std::deque<int> &BiggerHalf, std::deque<int> &SmallerHalf)
{
	std::deque<int> FilledIndex;
	std::deque<int> jackSequence = Q_GenerateSequence(SmallerHalf.size());
	for (size_t i = 0; i < jackSequence.size(); i++)
	{
		size_t index = jackSequence[i] - 1;
		if (index >= SmallerHalf.size())
			break;
		std::deque<int>::iterator InsetPosition = std::upper_bound(BiggerHalf.begin(), BiggerHalf.end(), SmallerHalf[index]);
		BiggerHalf.insert(InsetPosition, SmallerHalf[index]);
		FilledIndex.push_back(index);
	}
	for (size_t i = 0; i < SmallerHalf.size(); i++)
	{
		if (std::find(FilledIndex.begin(), FilledIndex.end(), i) == FilledIndex.end())
		{
			std::deque<int>::iterator InsetPosition = std::upper_bound(BiggerHalf.begin(), BiggerHalf.end(), SmallerHalf[i]);
			BiggerHalf.insert(InsetPosition, SmallerHalf[i]);
		}
	}
}

std::vector<int> PmergeMe::sortVector(std::vector<int>& list)
{
	if (list.size() < 2)
		return list;
	std::vector<int> BiggerHalf, SmallerHalf;
	V_separateHolder(list, BiggerHalf, SmallerHalf);
	BiggerHalf = sortVector(BiggerHalf);
	V_insertSmallerInBiggerHalf(BiggerHalf,SmallerHalf);
	return BiggerHalf;
}

std::deque<int> PmergeMe::sortDeque(std::deque<int>& list){
	if (list.size() < 2)
		return list;
	std::deque<int> BiggerHalf, SmallerHalf;
	Q_separateHolder(list, BiggerHalf, SmallerHalf);
	BiggerHalf = sortDeque(BiggerHalf);
	Q_insertSmallerInBiggerHalf(BiggerHalf, SmallerHalf);
	return BiggerHalf;
}


void PmergeMe::printVector(std::vector<int> sorted_list){
	for (size_t i = 0; i < sorted_list.size(); i++)
	{
		std::cout << sorted_list[i] << " ";
	}
	std::cout << "\n";
}

void PmergeMe::printDeque(std::deque<int> sorted_list)
{
	for (size_t i = 0; i < sorted_list.size(); i++)
	{
		std::cout << sorted_list[i] << " ";
	}
	std::cout << "\n";
}
