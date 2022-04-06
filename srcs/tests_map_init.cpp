#include "main.hpp"

static void		test_default_constructor(void)

{
	std::cout << std::endl;
	std::cout << ">> Test default constructor" << std::endl;
	std::cout << std::endl;

	LIB::map<int, int>				nbrs;

	std::cout << "nbrs" << std::endl;
	display_map("nbrs", nbrs);
	std::cout << "nbrs.size() = " << nbrs.size() << std::endl;
}

static void		test_range_constructor(void)
{
	std::cout << std::endl;
	std::cout << ">> Test range constructor" << std::endl;
	std::cout << std::endl;
	LIB::map<int, int>		nbrs;
	LIB::map<int, int>::iterator		it;

	for (int i = 0; i < 5; i++)
		nbrs[i] = i;
	display_map("nbrs", nbrs);
	it = nbrs.end();
	it++;
	std::cout << "it->first = " << it->first << std::endl;
	LIB::map<int, int>		nbrs2(nbrs.begin(), it);

	std::cout << "nbrs2(nbrs.begin(), --nbrs.end())" << std::endl << std::endl;
	display_map("nbrs2", nbrs2);
	nbrs[0] = 99;
	std::cout << "nbrs[0] = 99" << std::endl << std::endl;
	display_map("nbrs", nbrs);
	display_map("nbrs2", nbrs2);
}

static void		test_copy_constructor(void)
{
	std::cout << std::endl;
	std::cout << ">> Test copy constructor" << std::endl;
	std::cout << std::endl;
	LIB::map<int, int>		nbrs; 
	for (int i = 0; i < 5; i++)
		nbrs[i] = i;
	display_map("nbrs", nbrs);

	LIB::map<int, int>		nbrs2(nbrs);

	std::cout << "nbrs2(nbrs)" << std::endl << std::endl;
	display_map("nbrs2", nbrs2);
	nbrs[0] = 99;
	std::cout << "nbrs[0] = 99" << std::endl << std::endl;
	display_map("nbrs", nbrs);
	display_map("nbrs2", nbrs2);
}

static void		test_assign_operator(void)
{
	std::cout << std::endl;
	std::cout << ">> Test assign constructor" << std::endl;
	std::cout << std::endl;
	LIB::map<int, int>		nbrs; 
	for (int i = 0; i < 5; i++)
		nbrs[i] = i;
	display_map("nbrs", nbrs);

	LIB::map<int, int>		nbrs2 = nbrs;

	std::cout << "nbrs2 = nbrs" << std::endl << std::endl;
	display_map("nbrs2", nbrs2);
	nbrs[0] = 99;
	std::cout << "nbrs[0] = 99" << std::endl << std::endl;
	display_map("nbrs", nbrs);
	display_map("nbrs2", nbrs2);
}

void	test_map_init(void)
{
	std::cout << std::endl;
	std::cout << "[------------ Test map init ------------]" << std::endl;
	std::cout << std::endl;

	std::cout << "********************************************" << std::endl;
	test_default_constructor();
	std::cout << "********************************************" << std::endl;
	test_range_constructor();
	std::cout << "********************************************" << std::endl;
	test_copy_constructor();
	std::cout << "********************************************" << std::endl;
	test_assign_operator();
	std::cout << "********************************************" << std::endl;
}
