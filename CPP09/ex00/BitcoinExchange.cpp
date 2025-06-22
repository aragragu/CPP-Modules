#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange const &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	(void)rhs;
	return (*this);
}

Data_and_Prices::Data_and_Prices(std::string filename) : filename(filename)
{
}

Data_and_Prices::~Data_and_Prices()
{
}

void Data_and_Prices::ParseData()
{
	if (filename.substr(filename.length() - 4) != ".txt")
		throw std::invalid_argument("invalid file extention (valid file extention -> .txt)");
	std::ifstream data_base_file("data.csv");
	if (!data_base_file.is_open())
		throw std::runtime_error("Error opening file : data.csv");
	std::string holder;
	while (std::getline(data_base_file, holder)){
		ValidLine(holder, ",", 1);
	}
	std::ifstream in_file(filename.c_str());
	if (!in_file.is_open())
		throw std::runtime_error("Error opening file: " + filename);
	std::string line;
	while (std::getline(in_file, line))
	{
		if (line == "date | value")
			continue;
		if (ValidLine(line, "|", 0))
			print_price(line);
		else
			std::cout << "Error: line is not valid\n";
	}
}

void trim(std::string &line)
{
	size_t start, end;
	start = line.find_first_not_of(" \t");
	if (std::string::npos == start)
	{
		line = "";
		return;
	}
	end = line.find_last_not_of(" \t");
	line = line.substr(start, end - start + 1);
}

bool is_num(std::string &line)
{
	for (size_t i = 0; i < line.length(); i++)
	{
		if (!std::isdigit(line[i]))
		{
			if (line[i] != '.')
				return false;
		}
	}
	return true;
}

bool Data_and_Prices::ValidLine(std::string &line, std::string to_look, int i)
{
	std::string date, amount;
	int year, month, day;
	float quantity;
	if (line.find(to_look) == std::string::npos)
		return false;
	date = line.substr(0, line.find(to_look));
	amount = line.substr(line.find(to_look) + 1);
	trim(date);
	trim(amount);
	if (date.empty() || date.size() < 10 || amount.empty())
		return false;
	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());
	if (!is_num(amount))
		return false;
	quantity = std::strtof(amount.c_str(), NULL);
	if (!validNumbers(year, month, day, quantity))
		return false;
	if (i)
		data[date] = quantity;
	return true;
}

bool Data_and_Prices::validNumbers(int year, int month, int day, float quantity)
{
	int maxDays = 0;
	if ((year < 2009 || year > 2026) || (month < 1 || month > 12) || (day < 1 || day > 31))
		return false;
	if (quantity < 0 || quantity > 1000.0)
		return false;
	switch (month)
	{
	case 2:
		maxDays = 28;
		if (year % 4 == 0)
			maxDays = 29;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		maxDays = 30;
		break;
	default:
		maxDays = 31;
		break;
	}
	return (day <= maxDays);
}

void Data_and_Prices::print_price(std::string &line)
{
	std::string date, amount;
	float quantity, price;
	date = line.substr(0, line.find("|"));
	amount = line.substr(line.find("|") + 1);
	trim(date);
	trim(amount);
	quantity = std::strtof(amount.c_str(), NULL);
	std::map<std::string, float>::iterator it;
	it = data.find(date);
	if (it != data.end())
		price = quantity * it->second;
	else
	{
		it = data.upper_bound(date);
		if (it == data.begin())
		{
			std::cerr << "Error: no data available before this date\n";
			return;
		}
		it--;
		price = quantity * it->second;
	}
	std::cout << date << " => " << amount << " = " << price << std::endl;
}

