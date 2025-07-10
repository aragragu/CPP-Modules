#ifndef RPN_HPP
# define RPN_HPP


#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <stack>
#include <climits>
#include <cstdlib>

class RPN
{
	private:
		RPN(void);
		RPN(RPN const &copy);
		RPN const &operator = (RPN const &rhs);

	public :
		~RPN(void);

		class INVALID_NUMBER : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class INVALID_OPERATION : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};


		static bool ValidNumber(long& holder, std::string& number);
		static void DoOperation(std::string &op, std::stack<long>& numbers);
		static long plus(long long a, long long b);
		static long minus(long long a, long long b);
		static long devide(long long a, long long b);
		static long mutiply(long long a, long long b);
};

#endif
