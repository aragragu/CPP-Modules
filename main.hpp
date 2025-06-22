#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <vector>

template <typename T>
class MyLimitedVector
{
	private:
	std::vector<T> data;

	public:
	MyLimitedVector();
	~MyLimitedVector();
	typedef typename std::vector<T>::iterator My_Iterator;
	typedef typename std::vector<T>::const_iterator My_Const_Iterator;
	void push_back(const T &val);
	void pop_back();
		size_t size();
		My_Iterator begin() { return data.begin(); }
		My_Const_Iterator begin() const { return data.begin(); }
		My_Iterator end() {return data.end();}
		My_Const_Iterator end() const {return data.end();}
	};



	class SecretKeeper
	{
		protected:
		std::vector<int> mySecretData;
		public:
		SecretKeeper(/* args */);
		~SecretKeeper();
	};

	SecretKeeper::SecretKeeper(){
		mySecretData.push_back(1);
	}

	SecretKeeper::~SecretKeeper()
	{
	}

	class DataAccessor : public SecretKeeper
	{
		private:
		/* data */
		public:
		DataAccessor(/* args */);
		~DataAccessor();
		std::vector<int>& getInternalDataReference();
	};

	DataAccessor::DataAccessor(/* args */)
	{
	}

	DataAccessor::~DataAccessor()
	{
	}

	std::vector<int>& DataAccessor::getInternalDataReference(){
		return mySecretData;
	}



	template <typename ContainerType>
	class Processor
	{
		private:
		/* data */
		public:
		Processor(/* args */);
		~Processor();
		typedef typename ContainerType::iterator my_iterator;
		void DoSomething(my_iterator it){(void)it;std::cout << "iterator function\n";}


	};

	template <typename ContainerType>
	Processor<ContainerType>::Processor(/* args */)
	{
	}
	template <typename ContainerType>
	Processor<ContainerType>::~Processor()
	{
	}


	template <typename iterator>
	void print_all_elements(iterator begin, iterator end){
		for ( ;begin != end; ++begin){
			std::cout << *begin << " ";
		}
		std::cout << "\n";
	}

#include "main.tpp"

#endif

