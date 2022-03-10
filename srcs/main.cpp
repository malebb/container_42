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
//	test_map();
	/*
	std::map<int, std::string>		numbers;

	std::cout << std::endl;
	numbers.insert(numbers.end(), std::make_pair<int, std::string>(1, "un"));
	for (std::map<int, std::string>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		std::cout << "first = " << it->first << std::endl;
	}
	*/
	ft::map<int, int>		nbrs;

//	nbrs.insert(ft::make_pair(18, 5));
//	nbrs.insert(ft::make_pair(17, 5));
//	nbrs.insert(ft::make_pair(16, 5));
//	nbrs.insert(ft::make_pair(8, 5));
//	nbrs.insert(ft::make_pair(10, 5));
//	nbrs.insert(ft::make_pair(11, 5));
//	nbrs.insert(ft::make_pair(15, 5));
//	nbrs.insert(ft::make_pair(14, 5));
	/*
	nbrs.insert(ft::make_pair<int, int>(13, 5));
	nbrs.insert(ft::make_pair<int, int>(10, 5));
	nbrs.insert(ft::make_pair<int, int>(21, 5));
	nbrs.insert(ft::make_pair<int, int>(20, 5));
	nbrs.insert(ft::make_pair<int, int>(22, 5));
	nbrs.insert(ft::make_pair<int, int>(23, 5));
	*/

/*
 */
	nbrs.insert(ft::make_pair<int, int>(42, 5));
	nbrs.insert(ft::make_pair<int, int>(43, 5));
	nbrs.insert(ft::make_pair<int, int>(44, 5));
	nbrs.insert(ft::make_pair<int, int>(45, 5));
	nbrs.insert(ft::make_pair<int, int>(46, 5));
	nbrs.insert(ft::make_pair<int, int>(47, 5));
//	nbrs.insert(ft::make_pair<int, int>(48, 5));
//	nbrs.insert(ft::make_pair<int, int>(49, 5));
	ft::rbt<ft::pair<const int, int> >		*tree;

	tree = nbrs.get_tree();
	std::cout << "root = " << tree->left->left->value->first << std::endl;
	display_map(nbrs);
	return (0);
}
