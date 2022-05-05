#include "main.hpp"
#include "compare.hpp"
#include <string.h>
#include <algorithm>
#include <stack>
#include <map>
#include <list>

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

	test_stack();
	test_vector();
	test_map();

//	ft::map<int, int>		nbrs;

//	nbrs[15] = 15;
//	nbrs[20] = 20;
//	nbrs[25] = 25;
//	nbrs[30] = 30;
//	nbrs[35] = 35;

//	std::cout << "value = " << nbrs.lower_bound(16)->first << std::endl;
	return (0);
}

