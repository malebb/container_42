#include "main.hpp"

void	test_default_constructor(void)

{
	std::cout << std::endl;
	std::cout << ">> Test default constructor" << std::endl;
	std::cout << std::endl;

	LIB::vector<int>				nbrs;

	std::cout << "nbrs" << std::endl;
	display_vector("nbrs", nbrs);
	std::cout << "nbrs.size() = " << nbrs.size() << std::endl;
}

void	test_fill_constructor(void)

{
	std::cout << std::endl;
	std::cout << ">> Test fill constructor" << std::endl;
	std::cout << std::endl;
	LIB::vector<int>				nbrs(6, 5);

	std::cout << "nbrs(6, 5)" << std::endl;
	display_vector("nbrs", nbrs);
	std::cout << "nbrs.size() = " << nbrs.size() << std::endl;
}

void	test_range_constructor(void)
{
	std::cout << std::endl;
	std::cout << ">> Test range constructor" << std::endl;
	std::cout << std::endl;
	LIB::vector<int>		nbrs;

	for (int i = 0; i < 5; i++)
		nbrs.push_back(i);
	display_vector("nbrs", nbrs);

	LIB::vector<int>		nbrs2(nbrs.begin(), nbrs.end());

	std::cout << "nbrs2(nbrs.begin(), nbrs.end() - 1)" << std::endl << std::endl;
	display_vector("nbrs2", nbrs2);
	nbrs[0] = 99;
	std::cout << "nbrs[0] = 99" << std::endl << std::endl;
	display_vector("nbrs", nbrs);
	display_vector("nbrs2", nbrs2);
}

void	test_copy_constructor(void)
{
	std::cout << std::endl;
	std::cout << ">> Test copy constructor" << std::endl;
	std::cout << std::endl;
	LIB::vector<int>		nbrs; 
	for (int i = 0; i < 5; i++)
		nbrs.push_back(i);
	display_vector("nbrs", nbrs);

	LIB::vector<int>		nbrs2(nbrs);

	std::cout << "nbrs2(nbrs)" << std::endl << std::endl;
	display_vector("nbrs2", nbrs2);
	nbrs[0] = 99;
	std::cout << "nbrs[0] = 99" << std::endl << std::endl;
	display_vector("nbrs", nbrs);
	display_vector("nbrs2", nbrs2);
}

void	test_assign_operator(void)

{
	std::cout << std::endl;
	std::cout << ">> Test assign constructor" << std::endl;
	std::cout << std::endl;
	LIB::vector<int>		nbrs; 
	for (int i = 0; i < 5; i++)
		nbrs.push_back(i);
	display_vector("nbrs", nbrs);

	LIB::vector<int>		nbrs2 = nbrs;

	std::cout << "nbrs2 = nbrs" << std::endl << std::endl;
	display_vector("nbrs2", nbrs2);
	nbrs[0] = 99;
	std::cout << "nbrs[0] = 99" << std::endl << std::endl;
	display_vector("nbrs", nbrs);
	display_vector("nbrs2", nbrs2);
}

void	test_vector_init(void)
{
	std::cout << std::endl;
	std::cout << "[------------ Test vector init ------------]" << std::endl;
	std::cout << std::endl;

	std::cout << "********************************************" << std::endl;
	test_default_constructor();
	std::cout << "********************************************" << std::endl;
	test_fill_constructor();
	std::cout << "********************************************" << std::endl;
	test_range_constructor();
	std::cout << "********************************************" << std::endl;
	test_copy_constructor();
	std::cout << "********************************************" << std::endl;
	test_assign_operator();
	std::cout << "********************************************" << std::endl;
}
