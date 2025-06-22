#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cstdlib>

class BitcoinExchange
{
public:
	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const &copy);
	~BitcoinExchange(void);
	BitcoinExchange const &operator=(BitcoinExchange const &rhs);
};

class Data_and_Prices
{
private:
	// std::map<std::string, float> input;
	std::string filename;
	std::map<std::string, float> data;
	// std::ifstream InStream();
public:
	Data_and_Prices(std::string filename);
	~Data_and_Prices(); // close file
	void ParseData();
	bool ValidLine(std::string &line, std::string to_look, int i);
	bool validNumbers(int year, int month, int day, float quantity);
	void print_price(std::string &line);
};

#endif
