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

void Data_and_Prices::ParseData()
{
	if (filename.substr(filename.length() - 4) != ".txt")
		throw std::invalid_argument("invalid file extention (valid file extention -> .txt)");
	std::ifstream data_base_file("data.csv");
	if (!data_base_file.is_open())
		throw std::runtime_error("Error opening file : data.csv");
	std::string holder;
	int i = 1;
	while (std::getline(data_base_file, holder)){
		try{
			if (i == 1){
				i++;
				continue;
			}
			std::istringstream input(holder);
			ValidLine(holder, ",", 1);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
		i++;
	}
	data_base_file.close();
	std::ifstream in_file(filename.c_str());
	if (!in_file.is_open())
		throw std::runtime_error("Error opening file: " + filename);
	std::string line;
	i = 1;
	while (std::getline(in_file, line)){
		try{
			if (i == 1){
				i++;
				continue;
			}
			if (line.empty())
				continue;
			ValidLine(line, "|", 0);
			print_price(line);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
		i++;
	}
	in_file.close();
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

bool parse_date(std::string &date)
{
	if (date.size() != 10)
		return false;
	for (int i = 0; i < 10; ++i){
		if (i == 4 || i == 7){
			if (date[i] != '-')
				return false;
		}
		else{
			if (!std::isdigit(date[i]))
				return false;
		}
	}
	return true;
}

void Data_and_Prices::ValidLine(std::string &line, std::string to_look, int i)
{
	std::string date, amount;
	int year, month, day;
	float quantity;
	if (line.find(to_look) == std::string::npos)
		throw std::invalid_argument("Error: invalid line format");
	date = line.substr(0, line.find(to_look));
	amount = line.substr(line.find(to_look) + 1);
	trim(date);
	trim(amount);
	if (date.empty() || date.size() < 10 || amount.empty())
		throw std::invalid_argument("Error: invalid line format");
	if (!parse_date(date))
		throw std::invalid_argument("Eror: invalid date format");
	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());
	if (!is_num(amount))
		throw std::invalid_argument("Error: quantity is not a number");
	quantity = std::strtof(amount.c_str(), NULL);
	if (!i)
		validNumbers(year, month, day, quantity, i);
	if (i)
		data[date] = quantity;
	return;
}

void Data_and_Prices::validNumbers(int year, int month, int day, float quantity, int i)
{
	int maxDays = 0;
	if ((year < 2009 || year > 2025) || (month < 1 || month > 12) || (day < 1 || day > 31))
		throw std::invalid_argument("Error: invalid date");
	if (i == 0 && (quantity < 0.0f || quantity > 1000.0f))
		throw std::invalid_argument("Error: invalid quantity (must be between 0 and 1000)");
	if (i == 1 && (quantity <= 0.0f || quantity > 150000.0f))
		throw std::invalid_argument("Error: invalid price (must be between 0 and 150000)");
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
	if (!(day <= maxDays))
		throw std::invalid_argument("Error: invalid day");
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
			throw std::invalid_argument("Error: no data available before this date");
		it--;
		price = quantity * it->second;
	}
	std::cout << date << " => " << amount << " = " << price << std::endl;
}

