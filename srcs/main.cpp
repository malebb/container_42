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
	ft::map<int, int>		nbrs;

	nbrs[1] = 3;
	nbrs[2] = 6;
	nbrs[3] = 9;
	nbrs[4] = 12;
	nbrs[5] = 15;
	nbrs[6] = 18;
//	nbrs[7] = 21;
//	nbrs[8] = 24;
//	nbrs[9] = 27;
//	nbrs[10] = 30;
	std::cout << (nbrs.lower_bound(7))->first << " | " << (nbrs.lower_bound(7))->second << std::endl;
}
