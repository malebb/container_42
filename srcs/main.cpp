#include "main.hpp"
#include "compare.hpp"
#include <string.h>
#include <algorithm>
#include <stack>
#include <map>

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

bool	check(std::string str1, std::string str2)
{
	std::cout << "str1 = " << str1 << " str2 = " << str2 << std::endl;
	if (str1 != str2)
	{
		return (true);
	}
	return (false);
}

class A
{
	public :
		A(int nb): _nb(nb) {}

	friend bool	operator<(const A& lhs, const A & rhs)
	{
		return (lhs._nb < rhs._nb);
	}

	int		_nb;
};

int	main(void)
{
	std::cout << std::endl;
	std::cout << "[------------ TEST FT CONTAINER ------------]" << std::endl;
	std::cout << std::endl;

//	test_reverse_iterator();
//	test_vector();
//	int nb = 4;	
//	std::vector<int>::iterator		it(&nb);

//	std::cout << *it << std::endl;
/*
	std::vector<int>				nbs;
	std::vector<int>::iterator		it_v;

	it_v = nbs.begin();

	for (std::vector<int>::size_type i = 0; i < nbs.size(); i++)
	{
		std::cout << "*it = " << *it_v << std::endl;
		++it_v;
	}
	std::cout << "---------------------------" << std::endl;
	*/


//	ft::rbt<ft::pair<const int, int> >		*rbt;

	ft::map<int, int>						nbrs;
//	nbrs["a"] = 4;
//	nbrs["b"] = 4;
//	nbrs["c"] = 6;
//	nbrs["d"] = 4;
	
//	nbrs[10] = 4;
//	nbrs[-5] = 4;
//	nbrs[13] = 4;
//	nbrs[-8] = 4;
//	nbrs[25] = 4;
//	nbrs[4] = 6;
//	nbrs[5] = 4;

	nbrs.insert(ft::pair<int, int>(10, 4));
	nbrs.insert(ft::pair<int, int>(-5, 4));
	nbrs.insert(ft::pair<int, int>(13, 4));
	nbrs.insert(ft::pair<int, int>(-8, 4));
	nbrs.insert(ft::pair<int, int>(8, 4));
	nbrs.insert(ft::pair<int, int>(6, 4));
	nbrs.insert(ft::pair<int, int>(7, 4));


	// -8, -5, 4, 5, 10, 13, 25 

//	rbt = nbrs.get_tree();
//	nbrs.print_sorted(nbrs.get_tree());
	
//			std::cout << "END: first = " << it->first << " second = " << it->second<< std::endl;
	ft::map<int, int>::iterator it = nbrs.begin();
/*
	std::cout << "first = " << it->first << " second = " << it->second << std::endl;
	++it;
	std::cout << "first = " << it->first << " second = " << it->second << std::endl;
	--it;
	std::cout << "first = " << it->first << " second = " << it->second << std::endl;
	++it;
	std::cout << "first = " << it->first << " second = " << it->second << std::endl;
	++it;
	std::cout << "first = " << it->first << " second = " << it->second << std::endl;
	++it;
	std::cout << "first = " << it->first << " second = " << it->second << std::endl;
	++it;
	std::cout << "first = " << it->first << " second = " << it->second << std::endl;
	++it;
	std::cout << "first = " << it->first << " second = " << it->second << std::endl;
	++it;
	std::cout << "first = " << it->first << " second = " << it->second << std::endl;
	++it;
	std::cout << "first = " << it->first << " second = " << it->second << std::endl;
	++it;
	std::cout << "first = " << it->first << " second = " << it->second << std::endl;
	*/
	for (int i = 0; i < 10 ; i++)
	{
		std::cout << "first = " << it->first << " second = " << it->second << std::endl;
		++it;
	}
	
/*
	for (ft::map<int, int>::iterator it = nbrs.begin(); it != nbrs.end(); ++it)
	{
		std::cout << "first = " << it->first << " second = " << it->second  << " size = " << nbrs.size() << std::endl;
	}

	std::map<int, int>					nbrs2;
	std::map<int, int>::iterator		it2;

	nbrs2[4] = 6;
	nbrs2[8] = 6;
	it2 = nbrs2.end();

	std::cout << "first = " << it2->first << std::endl;
	--it2;
	std::cout << "first = " << it2->first << std::endl;
	--it2;
	std::cout << "first = " << it2->first << std::endl;
//	std::cout << "nbrs2.end() = " << &it2 << std::endl;
	
*/
	/*
	for (std::map<int, int>::iterator it = nbrs2.begin(); it != it2; it++)
	{
		std::cout << "first = " << it->first << std::endl;
	}
	std::cout << "======================================" << std::endl;
	nbrs2[5] = 6;
	nbrs2[6] = 6;
	nbrs2[7] = 6;
	nbrs2[8] = 6;
	for (std::map<int, int>::iterator it = nbrs2.begin(); it != it2; it++)
	{
		std::cout << "first = " << it->first << std::endl;
	}
	*/


	
/*
	while (rbt)
	{
		std::cout << "value = " << rbt->value->first << std::endl;
		rbt = rbt->left;
	}
	*/

//	make_
//	ft::rbt<ft::pair<int, int> > tree(ft::make_pair(6, 5));

//	std::cout << "first = " << tree._value.first << "second = "
//		<< tree._value.second << std::endl;
	return (0);
}
