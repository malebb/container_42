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

void	check_comparison(bool n)
{
	if (n)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
}

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
	ft::vector<std::string>::iterator		it2;
	ft::vector<Nb>							nbs;
	ft::vector<Nb>::iterator				it3;
	
	std::cout << "strs is a vector of string" << std::endl;
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

	std::cout << "it2 = it + 2 " << std::endl;
	it2 = it + 2;
	std::cout << "*it2 = " << *it2 << std::endl;

	std::cout << "it2 = 3 + it " << std::endl;
	it2 = 3 + it;
	std::cout << "*it2 = " << *it2 << std::endl;

	std::cout << "*++it = " << *++it << std::endl;
	std::cout << "it2 = it - 1 " << std::endl;
	it2 = it - 1;
	std::cout << "*it2 = " << *it2 << std::endl;

	std::cout << "it - it2 = " << it - it2 << std::endl;
	it = strs.begin();
	std::cout << "*it = \"hello\"" << std::endl;
	*it = "hello";
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*++it = " << *++it << std::endl;
	std::cout << "*it2 = " << *it2 << std::endl;
	std::cout << "it2 = it" << std::endl;
	it2 = it;
	std::cout << "*it2 = " << *it2 << std::endl;
	std::cout << "it = strs.begin() and it2 = strs.begin() + 1" << std::endl;
	it =  strs.begin();
	it2 = strs.begin() + 1;
	std::cout << "it == it2 : ";
	check_comparison(it == it2);
	std::cout << "it != it2 : ";
	check_comparison(it != it2);
	std::cout << "it < it2 : ";
	check_comparison(it < it2);
	std::cout << "it > it2 : ";
	check_comparison(it > it2);
	std::cout << "it <= it2 : ";
	check_comparison(it <= it2);
	std::cout << "it >= it2 : ";
	check_comparison(it >= it2);

	std::cout << "nbs is a vector of class Nb" << std::endl;
	it3 = nbs.begin();
	Nb				nb;
	nbs.push_back(nb);
	it3 = nbs.begin();
	std::cout << "it3->nb = " << it3->nb << std::endl;
	std::cout << "it3->nb2 = " << it3->nb2 << std::endl;

	it[0] = "one";

	
	std::cout << std::endl;
	std::cout << "------------ Test reverse Iterator ------------"
	<< std::endl;

	std::cout << std::endl;
	std::cout << ">> Test iterate" << std::endl;
	std::cout << std::endl;

	for (ft::vector<std::string>::reverse_iterator rit = strs.rbegin();
			rit != strs.rend(); rit++)
	{
		std::cout << "strs = " << *rit << std::endl;
	}

	std::cout << std::endl;
	std::cout << ">> Test iterator operator" << std::endl;
	std::cout << std::endl;

	ft::vector<std::string>::reverse_iterator		rit;
	ft::vector<std::string>::reverse_iterator		rit2;
	ft::vector<Nb>::reverse_iterator				rit3;
	
	std::cout << "strs is a vector of string" << std::endl;
	std::cout << std::endl;
	std::cout << "rit = strs.rbegin()" << std::endl;
	std::cout << std::endl;

	rit = strs.rbegin();

	std::cout << "*rit = " << *rit << std::endl;

	std::cout << "rit++" << std::endl;
	rit++;
	std::cout << "*rit = " << *rit << std::endl;

	std::cout << "rit--" << std::endl;
	rit--;
	std::cout << "*rit = " << *rit << std::endl;

	std::cout << "*++rit = " << *++rit << std::endl;

	std::cout << "*--rit = " << *--rit << std::endl;

	std::cout << "*rit++" << std::endl;
	*rit++;
	std::cout << "*rit = " << *rit << std::endl;

	std::cout << "*rit--" << std::endl;
	*rit--;
	std::cout << "*rit = " << *rit << std::endl;

	std::cout << "rit += 2" << std::endl;
	rit += 2;
	std::cout << "*rit = " << *rit << std::endl;

	std::cout << "rit -= 2" << std::endl;
	rit -= 2;
	std::cout << "*rit = " << *rit << std::endl;
	
	std::cout << "rit[3] = " << rit[3] << std::endl;

	std::cout << "rit2 = rit + 2 " << std::endl;
	rit2 = rit + 2;
	std::cout << "*rit2 = " << *rit2 << std::endl;

	std::cout << "rit2 = 3 + rit " << std::endl;
	rit2 = 3 + rit;
	std::cout << "*rit2 = " << *rit2 << std::endl;
	std::cout << "*++rit = " << *++rit << std::endl;
	std::cout << "rit2 = rit - 1 " << std::endl;
	rit2 = rit - 1;
	std::cout << "*rit2 = " << *rit2 << std::endl;

	
	std::cout << "rit - rit2 = " << rit - rit2 << std::endl;
	rit = strs.rbegin();
	std::cout << "*rit = \"hello\"" << std::endl;
	*rit = "hello";
	std::cout << "*rit = " << *rit << std::endl;
	std::cout << "*++rit = " << *++rit << std::endl;
	std::cout << "*rit2 = " << *rit2 << std::endl;
	std::cout << "rit2 = rit" << std::endl;
	rit2 = rit;
	std::cout << "*rit2 = " << *rit2 << std::endl;

	std::cout << "rit = strs.begin() and rit2 = strs.begin() + 1" << std::endl;
	rit =  strs.rbegin();
	rit2 = strs.rbegin() + 1;
	std::cout << "rit == rit2 : ";
	check_comparison(rit == rit2);
	std::cout << "rit != rit2 : ";
	check_comparison(rit != rit2);

	std::cout << "rit < rit2 : ";
	check_comparison(rit < rit2);
	std::cout << "rit > rit2 : ";
	check_comparison(rit > rit2);

	std::cout << "rit <= rit2 : ";
	check_comparison(rit <= rit2);
	std::cout << "rit >= rit2 : ";
	check_comparison(rit >= rit2);
/*
	std::cout << "nbs is a vector of class Nb" << std::endl;
	rit3 = nbs.rbegin();
	rit3 = nbs.rbegin();
	std::cout << "rit3->nb = " << rit3->nb << std::endl;
	std::cout << "rit3->nb2 = " << rit3->nb2 << std::endl;
	*/
	



	std::cout << "TEST ZONE " << std::endl;

	ft::vector<int>						numbers;
	ft::vector<int>::reverse_iterator		rit5;
	ft::vector<int>::reverse_iterator		rit6;

	numbers.push_back(20);
	numbers.push_back(21);
	numbers.push_back(22);
	rit5 = numbers.rbegin();
	rit6 = numbers.rbegin();

	if (rit5 > rit6)
		std::cout << "rit5 > rit6" << std::endl;
	return (0);
}
