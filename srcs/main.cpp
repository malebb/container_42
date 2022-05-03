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

struct ft_more {
	bool	operator()(const int &first, const int &second) const {
		return (first > second);
	}
};

int	main(void)
{
	std::cout << std::endl;
	std::cout << "[------------ TEST FT CONTAINER ------------]" << std::endl;
	std::cout << std::endl;

//	test_stack();
//	test_vector();
//	test_mapĸk

	
	std::map<int, int>				mp1;
	std::map<int, int>				mp2;

	mp1[0] = 0;
	mp2[1] = 0;

	if (mp1 == mp2)
		std::cout << "ok" << std::endl;
	else
		std::cout << "ko" << std::endl;
	
	return (0);
}

