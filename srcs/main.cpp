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

	
	ft::map<int, std::string, ft_more>				mp;


	mp[42] = "fgzgxfn";
	mp[25] = "funny";
	mp[80] = "hey";
	mp[12] = "no";
	mp[27] = "bee";
	mp[90] = "8";
	for (ft::map<int, std::string, ft_more>::const_iterator it = mp.begin();
			it != mp.end(); ++it)
	std::cout << "mp" << it->first << " " << it->second << std::endl;
	std::cout << mp.size() << std::endl;
	return (0);
}

