#ifndef SCALARCONVERTER_CLASS_HPP
# define SCALARCONVERTER_CLASS_HPP

#include <iostream>
#include <string>
#include <climits>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <cstdlib>


class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter& operator=(ScalarConverter const &other);

	public :
		~ScalarConverter(void);
		static void convert(const std::string& string);
};

#endif
