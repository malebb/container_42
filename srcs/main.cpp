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

void	test_reverse_iterator(void)
{
	ft::vector<std::string>::reverse_iterator		rit;
	ft::vector<std::string>::reverse_iterator		rit2;
	ft::vector<Nb>::reverse_iterator				rit3;
	ft::vector<std::string>							strs;
	ft::vector<Nb>									nbs;
	Nb												nb;

	strs.push_back("one");
	strs.push_back("two");
	strs.push_back("three");
	strs.push_back("four");
	strs.push_back("five");

	nbs.push_back(nb);

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

	std::cout << "nbs is a vector of class Nb" << std::endl;
	rit3 = nbs.rbegin();
	rit3 = nbs.rbegin();
	std::cout << "rit3->nb = " << rit3->nb << std::endl;
	std::cout << "rit3->nb2 = " << rit3->nb2 << std::endl;
}

void	test_vector_iterator()
{
	ft::vector<std::string>::iterator		it;
	ft::vector<std::string>::iterator		it2;
	ft::vector<Nb>::iterator				it3;
	ft::vector<Nb>							nbs;
	Nb										nb;
	ft::vector<std::string>					strs;

	strs.push_back("one");
	strs.push_back("two");
	strs.push_back("three");
	strs.push_back("four");
	strs.push_back("five");

	nbs.push_back(nb);

	std::cout << std::endl;
	std::cout << "------------ Test Iterator ------------"
	<< std::endl;

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
	it3 = nbs.begin();
	std::cout << "it3->nb = " << it3->nb << std::endl;
	std::cout << "it3->nb2 = " << it3->nb2 << std::endl;

}

void	test_vector_capacity(void)
{
	ft::vector<int>				nbrs;
	ft::vector<char>			letters;

	nbrs.push_back(19);
	nbrs.push_back(2);
	nbrs.push_back(3);
	nbrs.push_back(4);

//	letters.push_back('h');
//	letters.push_back('e');
//	letters.push_back('l');
//	letters.push_back('l');
//	letters.push_back('o');

	std::cout << std::endl;
	std::cout << "------------ Test vector capacity ------------"
	<< std::endl;

	std::cout << "nbrs = ";
	display_tab(nbrs);
	std::cout << "letters = ";
	display_tab(letters);
	std::cout << std::endl;

	std::cout << ">> Test size function" << std::endl;
	std::cout << std::endl;

	std::cout << "nbrs.size() = " << nbrs.size() << std::endl;
	std::cout << "letters.size() = " << letters.size() << std::endl;

	std::cout << std::endl;
	std::cout << ">> Test max size function" << std::endl;
	std::cout << std::endl;

	std::cout << "nbrs.max_size() = " << nbrs.max_size() << std::endl;
	std::cout << "letters.max_size() = " << letters.max_size() << std::endl;

	std::cout << std::endl;
	std::cout << ">> Test resize function" << std::endl;
	std::cout << std::endl;

	std::cout << "nbrs.size() = " << nbrs.size() << std::endl;
	std::cout << "nbrs.capacity() = " << nbrs.capacity() << std::endl;
	std::cout << "nbrs = ";
	display_tab(nbrs);

	nbrs.resize(6, 99);
	std::cout << std::endl;
	std::cout << "nbrs.resize(6, 99)" << std::endl;
	std::cout << std::endl;

	std::cout << "nbrs.size() = " << nbrs.size() << std::endl;
	std::cout << "nbrs.capacity() = " << nbrs.capacity() << std::endl;
	std::cout << "nbrs = ";
	display_tab(nbrs);

	std::cout << std::endl;
	std::cout << ">> Test reserve and capacity function" << std::endl;
	std::cout << std::endl;

	std::cout << "nbrs.capacity() = " << nbrs.capacity() << std::endl;
	std::cout << "nbrs.reserve(2)" << std::endl;
	nbrs.reserve(2);
	std::cout << "nbrs.capacity() = " << nbrs.capacity() << std::endl;
	std::cout << "nbrs.reserve(10)" << std::endl;
	nbrs.reserve(10);
	std::cout << "nbrs.capacity() = " << nbrs.capacity() << std::endl;

	std::cout << std::endl;
	std::cout << ">> Test empty function" << std::endl;
	std::cout << std::endl;

	display_tab(nbrs);
	std::cout << "nbrs.empty() = "<< nbrs.empty() << std::endl;
	std::cout << "letters.empty() = "<< letters.empty() << std::endl;
}

void	test_vector_access(void)
{
	ft::vector<std::string>				strs;
	ft::vector<char>					letters;
	const ft::vector<std::string>		const_strs(2, "blue");


	strs.push_back("yellow");
	strs.push_back("red");
	strs.push_back("green");
	strs.push_back("pink");
	strs.push_back("orange");

	std::cout << std::endl;
	std::cout << "------------ Test Access element ------------"
	<< std::endl;

	std::cout << std::endl;
	std::cout << "strs = ";
	display_tab(strs);

	std::cout << std::endl;
	std::cout << "const_strs = ";
//	display_tab(const_strs);

	std::cout << std::endl;
	std::cout << ">> Test operator[]" << std::endl;
	std::cout << std::endl;

	for (ft::vector<std::string>::size_type i = 0; i < strs.size(); i++)
	{
		std::cout << "strs[" << i << "] = " << strs[i];
		std::cout << std::endl;
	}

	std::cout << std::endl;
	for (ft::vector<std::string>::size_type i = 0; i < const_strs.size(); i++)
	{
		std::cout << "const_strs[" << i << "] = " << const_strs[i];
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << ">> Test at function" << std::endl;
	std::cout << std::endl;
	try
	{
		for (ft::vector<int>::size_type i = 0; i < strs.size(); i++)
		{
			std::cout << "strs.at(" << i << ") = " << strs.at(i);
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
		std::cout << "strs.at(" << strs.size() << ") = ";
		strs.at(strs.size());
	}
	catch(std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		for (ft::vector<int>::size_type i = 0; i < const_strs.size(); i++)
		{
			std::cout << "const_strs[" << i << "] = " << const_strs.at(i);
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
		std::cout << "const_strs.at(" << const_strs.size() << ") = ";
		const_strs.at(strs.size());
	}
	catch(std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << ">> Test front function" << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "strs.front() = " << strs.front() << std::endl;

	std::cout << "const_strs.front() = " << const_strs.front() << std::endl;

	std::cout << std::endl;
	std::cout << ">> Test back function" << std::endl;
	std::cout << std::endl;

	std::cout << "strs.back() = " << strs.back() << std::endl;
	std::cout << "const_strs_back() = " << const_strs.back() << std::endl;

}

int	main(void)
{
	std::cout << std::endl;
	std::cout << "[------------ TEST FT CONTAINER ------------]" << std::endl;
	std::cout << std::endl;

	test_reverse_iterator();

	std::cout << "------------ TEST VECTOR CONTAINER ------------"
	<< std::endl;

//	test_vector_capacity();
	test_vector_access();
	const ft::vector<int>		twenty(5, 20);
	ft::vector<int>::const_iterator	cit;

	cit = twenty.begin();
	std::cout << "cit = " << *cit << std::endl;
	return (0);
}
