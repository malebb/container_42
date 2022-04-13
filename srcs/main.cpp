#include "main.hpp"
#include "compare.hpp"
#include <string.h>
#include <algorithm>
#include <stack>
#include <map>
#include <list>
/*
bool	check(std::string str1, std::string str2)
{
	std::cout << "str1 = " << str1 << " str2 = " << str2 << std::endl;
	if (str1 != str2)
	{
		return (true);
	}
	return (false);
}
*/
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
/*
template <typename t_it1, typename t_it2>
void		test (const t_it1 & it , const t_it2 & it2)
{
	if (it < it2)
		std::cout << "hello guys" << std::endl;
}
*/

int	main(void)
{
	std::cout << std::endl;
	std::cout << "[------------ TEST FT CONTAINER ------------]" << std::endl;
	std::cout << std::endl;

//	test_stack();
//	test_vector();
//	test_map();
	
	ft::vector<int>							nbrs(4, 4);
	ft::vector<int>							nbrs2(6, 6);
	ft::vector<int>::const_reverse_iterator	crit;
	ft::vector<int>::reverse_iterator	rit;

	rit = nbrs.rbegin();
	crit = nbrs2.rbegin();
//	test(it, it2);
	if (crit - rit)
	{
		std::cout << "rit == it" << std::endl;
		std::cout << "rit = " << *rit << "crit = " << *crit << std::endl;
	}
	else
	{
		std::cout << "rit != it" << std::endl;
	}
	/*
	for (std::vector<int>::iterator it = nbrs.begin(); it != nbrs.end(); it++)
	{
		std::cout << "it = " << *it << std::endl;
	}
	*/
}
