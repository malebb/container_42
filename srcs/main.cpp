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

void	print_the_pair(ft::map<int, int>::const_reverse_iterator it)
{
	std::cout << "first = " << it->first << " second = " << it->second << std::endl;
}

int	main(void)
{
	std::cout << std::endl;
	std::cout << "[------------ TEST FT CONTAINER ------------]" << std::endl;
	std::cout << std::endl;

//	test_stack();
//	test_vector();
//	test_map();

	ft::map<int, std::string>		mp;

	mp[42] = "lol";

	mp[50] = "mdr";
	mp[25] = "funny";

	mp[46] = "bunny";
	mp[21] = "fizz";
	mp[30] = "buzz";
	mp[55] = "fuzzy";

	mp[18] = "bee";
	mp[23] = "coconut";
	mp[28] = "diary";
	mp[35] = "fiesta";
	mp[44] = "hello";
	mp[48] = "world";
	mp[53] = "this is a test";
	mp[80] = "hey";

	mp[12] = "no";
	mp[20] = "idea";
	mp[22] = "123";
	mp[24] = "345";
	mp[27] = "27";
	mp[29] = "29";
	mp[33] = "33";
	mp[38] = "38";

	mp[43] = "1";
	mp[45] = "2";
	mp[47] = "3";
	mp[49] = "4";
	mp[51] = "5";
	mp[54] = "6";
	mp[60] = "7";
	mp[90] = "8";

//	display_map("mp", mp);

	mp.erase(25);
	std::cout <<"-----------------" << std::endl;
	mp.erase(55);

	/*
	std::cout <<"-----------------" << std::endl;
	mp.erase(24);
	std::cout <<"-----------------" << std::endl;
	mp.erase(54);
	std::cout <<"-----------------" << std::endl;
	mp.erase(22);
	std::cout <<"-----------------" << std::endl;
	mp.erase(51);
	std::cout <<"-----------------" << std::endl;
	mp.erase(21);
	std::cout <<"-----------------" << std::endl;
	mp.erase(53);
	std::cout <<"-----------------" << std::endl;
	mp.erase(20);
	std::cout <<"-----------------" << std::endl;
	mp.erase(23);
	std::cout <<"-----------------" << std::endl;
	mp.erase(42);
	std::cout <<"-----------------" << std::endl;
	mp.erase(38);
	std::cout <<"-----------------" << std::endl;
	mp.erase(35);
	std::cout <<"-----------------" << std::endl;
	mp.erase(33);
	std::cout <<"-----------------" << std::endl;
	*/

//	std::cout << "yuhouuuuu" << std::endl;
//	display_map("mp", mp);
	return (0);
}

