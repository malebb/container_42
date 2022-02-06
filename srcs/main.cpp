#include "Vector.hpp"
#include "Map.hpp"
#include "Stack.hpp"

#include <iostream>
#include <iterator>
#include <vector>

void	iterate(ft::vector<int>::iterator ite)
{
	std::iterator_traits<ft::vector<int>::iterator>::reference  ref = *ite;
	std::cout << ref << std::endl;
}

template<typename T> void	display_tab(ft::vector<T> & cont)
{
	std::cout << "{";
	for (typename ft::vector<T>::iterator it = cont.begin(); it != cont.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != cont.end())
			std::cout << ", ";
	}
	std::cout << "}";
	std::cout << std::endl;

}

class	Nb
{
	public :
		static const int nb = 5;
		static const int nb2 = 22;
};

int	main(void)
{
	std::cout << std::endl;
	std::cout << "[------------ TEST FT CONTAINER ------------]" << std::endl;
	std::cout << std::endl;

	std::cout << "------------ TEST VECTOR CONTAINER ------------"
	<< std::endl;

	ft::vector<int>				nbrs;
	ft::vector<char>			letters;
	const ft::vector<int>		const_nbrs(2, 88);

	std::cout << std::endl;
	std::cout << "------------ Test Capacity ------------"
	<< std::endl;
	 
	std::cout << ">> Test size function" << std::endl;
	std::cout << std::endl;

	std::cout << "Size = " << nbrs.size() << std::endl;
	nbrs.push_back(19);
	nbrs.push_back(2);
	nbrs.push_back(3);
	nbrs.push_back(4);
	std::cout << "Size = " << nbrs.size() << std::endl;

	std::cout << std::endl;
	std::cout << ">> Test size function" << std::endl;
	std::cout << std::endl;

	std::cout << "Max size (int) = " << nbrs.max_size() << std::endl;
	std::cout << "Max size (char) = " << letters.max_size() << std::endl;

	std::cout << std::endl;
	std::cout << ">> Test resize function" << std::endl;
	std::cout << std::endl;

	std::cout << "Size = " << nbrs.size() << " Capacity = " <<
		nbrs.capacity() << " | ";
	display_tab(nbrs);
	nbrs.resize(6, 99);
	std::cout << "Size = " << nbrs.size() << " Capacity = " <<
		nbrs.capacity() << " | ";
	display_tab(nbrs);

	std::cout << std::endl;
	std::cout << ">> Test capacity function" << std::endl;
	std::cout << std::endl;

	std::cout << "Capacity = " << nbrs.capacity() << std::endl;
	nbrs.reserve(2);
	std::cout << "Capacity = " << nbrs.capacity() << std::endl;
	nbrs.reserve(9);
	std::cout << "Capacity = " << nbrs.capacity() << std::endl;

	std::cout << std::endl;
	std::cout << ">> Test empty function" << std::endl;
	std::cout << std::endl;

	display_tab(nbrs);
	if (nbrs.empty())
		std::cout << "vector is empty" << std::endl;
	else
		std::cout << "vector is not empty" << std::endl;

	std::cout << std::endl;
	std::cout << "------------ Test Access element ------------"
	<< std::endl;

	std::cout << std::endl;
	std::cout << ">> Test operator[]" << std::endl;
	std::cout << std::endl;

	for (ft::vector<int>::size_type i = 0; i < nbrs.size(); i++)
	{
		std::cout << "[" << i << "] = " << nbrs[i];
		if (i + 1 != nbrs.size())
			std::cout << " ";
		else
			std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "const version : " << std::endl;
	for (ft::vector<int>::size_type i = 0; i < const_nbrs.size(); i++)
	{
		std::cout << "[" << i << "] = " << const_nbrs[i];
		if (i + 1 != const_nbrs.size())
			std::cout << " ";
		else
			std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << ">> Test at function" << std::endl;
	std::cout << std::endl;
	try
	{
		for (ft::vector<int>::size_type i = 0; i < nbrs.size(); i++)
		{
			std::cout << "[" << i << "] = " << nbrs.at(i);
			if (i + 1 != nbrs.size())
				std::cout << " ";
			else
				std::cout << std::endl;
		}
	}
	catch(std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		nbrs.at(nbrs.size());
	}
	catch(std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "const version : " << std::endl;
	try
	{
		for (ft::vector<int>::size_type i = 0; i < const_nbrs.size(); i++)
		{
			std::cout << "[" << i << "] = " << const_nbrs.at(i);
			if (i + 1 != const_nbrs.size())
				std::cout << " ";
			else
				std::cout << std::endl;
		}
	}
	catch(std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		const_nbrs.at(nbrs.size());
	}
	catch(std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << ">> Test front function" << std::endl;
	std::cout << std::endl;

	display_tab(nbrs);
	std::cout << std::endl;
	std::cout << "first elem = " << nbrs.front() << std::endl;

	std::cout << "const version : " << std::endl;
	std::cout << "first elem = " << const_nbrs.front() << std::endl;

	std::cout << std::endl;
	std::cout << ">> Test back function" << std::endl;
	std::cout << std::endl;

	std::cout << "last elem = " << nbrs.back() << std::endl;

	std::cout << "const version : " << std::endl;
	std::cout << "last elem = " << const_nbrs.back() << std::endl;

	std::cout << std::endl;
	std::cout << "------------ Test Iterator ------------"
	<< std::endl;

	ft::vector<std::string>				strs;

	strs.push_back("one");
	strs.push_back("two");
	strs.push_back("three");
	strs.push_back("four");
	strs.push_back("five");

	std::cout << std::endl;
	std::cout << ">> Test iterate" << std::endl;
	std::cout << std::endl;

	for (ft::vector<std::string>::iterator it = strs.begin();
			it != strs.end(); it++)
	{
		std::cout << "strs = " << *it << std::endl;
	}

	std::cout << std::endl;
	std::cout << ">> Test iterator operator" << std::endl;
	std::cout << std::endl;

	ft::vector<std::string>::iterator		it;
	ft::vector<std::string>::iterator		ite;

	std::cout << std::endl;
	std::cout << "it = strs.begin()" << std::endl;
	std::cout << std::endl;

	it = strs.begin();

	std::cout << "*it = " << *it << std::endl;

	std::cout << "it++" << std::endl;
	it++;
	std::cout << "*it = " << *it << std::endl;

	std::cout << "it--" << std::endl;
	it--;
	std::cout << "*it = " << *it << std::endl;

	std::cout << "*++it = " << *++it << std::endl;

	std::cout << "*--it = " << *--it << std::endl;

	std::cout << "*it++" << std::endl;
	*it++;
	std::cout << "*it = " << *it << std::endl;

	std::cout << "*it--" << std::endl;
	*it--;
	std::cout << "*it = " << *it << std::endl;

	std::cout << "it += 2" << std::endl;
	it += 2;
	std::cout << "*it = " << *it << std::endl;

	std::cout << "it -= 2" << std::endl;
	it -= 2;
	std::cout << "*it = " << *it << std::endl;
	
	std::cout << "it[3] = " << it[3] << std::endl;

	std::cout << "ite = it + 2 " << std::endl;
	ite = it + 2;
	std::cout << "*ite = " << *ite << std::endl;

	std::cout << "ite = 3 + it " << std::endl;
	ite = 3 + it;
	std::cout << "*ite = " << *ite << std::endl;

	std::cout << "*++it = " << *++it << std::endl;
	std::cout << "ite = it - 1 " << std::endl;
	ite = it - 1;
	std::cout << "*ite = " << *ite << std::endl;

	std::cout << "it - ite = " << it - ite << std::endl;



	std::cout << "TEST ZONE " << std::endl;
	ft::vector<Nb>					nbr;
	ft::vector<Nb>::iterator		it2;
	Nb				class_test;

	nbr.push_back(class_test);
	it2 = nbr.begin();
	std::cout << it2->nb << std::endl;
	return (0);
}
