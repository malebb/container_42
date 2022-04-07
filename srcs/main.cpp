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

int	main(void)
{
	std::cout << std::endl;
	std::cout << "[------------ TEST FT CONTAINER ------------]" << std::endl;
	std::cout << std::endl;

	test_stack();
	test_vector();
	test_map();
//	LIB::vector<std::string>		red(6, "red");
//	LIB::vector<std::string>		yellow(6, "yellow");
//	display_vector("yellow", yellow);
//	std::cout << "yellow.insert(yellow.begin() + 1, red.begin(), red.begin() + 3 " << std::endl;
//	yellow.insert(yellow.begin() + 1, red.begin(), red.begin() + 3);
//	display_vector("yellow", yellow);
	return (0);
}
