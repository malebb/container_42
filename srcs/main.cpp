#include "main.hpp"
#include "compare.hpp"
#include <string.h>
#include <algorithm>
#include <stack>
#include <map>

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

//	test_vector_reverse_iterator();
	test_vector();
//	test_map();
//	ft::vector<int>		nbrs;

//	nbrs.push_back(10);
//	nbrs.push_back(20);
//	nbrs.push_back(30);
//	nbrs.push_back(40);
//	nbrs.erase(nbrs.begin(), nbrs.end());
	return (0);
}
