#include "main.hpp"
#include "compare.hpp"
#include <string.h>
#include <algorithm>
#include <stack>
#include <map>
#include <list>
/*
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
	return (0);
}
*/
struct ft_more {
	bool	operator()(const int &first, const int &second) const {
		return (first > second);
	}
};

typedef ft::map<int, int, ft_more> ft_mp;
typedef ft::map<int, int, ft_more>::iterator ft_mp_it;

int		main(void)
{
	ft_mp mp;

	mp[42] = 42;
	mp[25] = 25;
	mp[80] = 80;
	mp[12] = 12;
	mp[27] = 27;
	mp[90] = 90;

	std::cout << "ERROR" << std::endl;	
	ft_mp::iterator it = mp.begin();

//	std::cout << "first = " << it->first << " second = " << it->second << std::endl;



	for (ft_mp::iterator it = mp.begin(); it != mp.end(); it++)
	{
		std::cout << "first = " << it->first << " second = " << it->second << std::endl;
	}
	
	
//	display_map("mp", mp);

	return (0);
}
