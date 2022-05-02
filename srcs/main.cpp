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

//	test_stack();
//	test_vector();
//	test_map();
	
	ft::map<int, int>				nbrs;
	ft::map<int, int>::iterator		it;


	for (int i = 0; i < 10; i++)
		nbrs[i] = i;
	display_map("nbrs", nbrs);
	it = --nbrs.end();
	std::cout << "error " << std::endl;
	std::cout << "END = " << (--it)->first << std::endl;
	std::cout << "error " << std::endl;
//	nbrs.erase(++nbrs.begin());
	/*
	display_map("nbrs", nbrs);
	nbrs.erase(nbrs.begin());
	display_map("nbrs", nbrs);
	nbrs.erase(--nbrs.end());
	display_map("nbrs", nbrs);
	nbrs.erase(++(++(++nbrs.begin())));
	display_map("nbrs", nbrs);
	std::cout << "Error" << std::endl;
	std::cout << "END = " << (--(--nbrs.end()))->first << std::endl;
	std::cout << "VALUE = " << (--(--(--nbrs.end())))->first << std::endl;
	nbrs.erase(--(--(--nbrs.end())), --nbrs.end());
	std::cout << "Error" << std::endl;
	display_map("nbrs", nbrs);
	*/
	return (0);
}

