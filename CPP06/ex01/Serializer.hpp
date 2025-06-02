#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>

typedef unsigned long uintptr_t;

struct Data
{
	int i;
};


class Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const &copy);
		Serializer const &operator = (Serializer const &rhs);

	public :
		~Serializer(void);

		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif
