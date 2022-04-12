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

//	test_stack();
//	test_vector();
//	test_map();

	ft::vector<std::string>		red(10, "red");
	ft::vector<std::string>		yellow;

	yellow.push_back("un");
	yellow.push_back("deux");
	yellow.push_back("trois");
	yellow.push_back("quatre");
	yellow.push_back("cinq");
	yellow.push_back("six");
	yellow.push_back("sept");
	yellow.push_back("huit");
	yellow.push_back("neuf");
	yellow.push_back("dix");
	/*
	for (std::vector<std::string>::iterator it = yellow.begin(); it != yellow.end(); it++)
	{
		std::cout << "it = " << *it << std::endl;
	}
	*/
	std::cout << std::endl;
	display_vector("yellow", yellow);
	yellow.erase(yellow.begin() + 4, yellow.end() - 3);
	display_vector("yellow", yellow);

}
