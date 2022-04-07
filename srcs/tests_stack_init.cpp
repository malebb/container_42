#include "main.hpp"

static void		test_default_constructor(void)

{
	std::cout << std::endl;
	std::cout << ">> Test default constructor" << std::endl;
	std::cout << std::endl;

	LIB::stack<int>				nbrs;

	std::cout << "nbrs" << std::endl;
	display_stack("nbrs", nbrs);
	std::cout << "nbrs.size() = " << nbrs.size() << std::endl << std::endl;
}

static void		test_copy_constructor(void)
{
	std::cout << std::endl;
	std::cout << ">> Test copy constructor" << std::endl;
	std::cout << std::endl;
	LIB::stack<int>		nbrs; 
	for (int i = 0; i < 5; i++)
		nbrs.push(i);
	display_stack("nbrs", nbrs);

	LIB::stack<int>		nbrs2(nbrs);

	std::cout << "nbrs2(nbrs)" << std::endl << std::endl;
	display_stack("nbrs2", nbrs2);

	nbrs.pop();
	nbrs.push(99);
	std::cout << "nbrs.pop()" << std::endl;
	std::cout << "nbrs.push(99)" << std::endl << std::endl;

	display_stack("nbrs", nbrs);
	display_stack("nbrs2", nbrs2);
}

static void		test_assign_operator(void)
{
	std::cout << std::endl;
	std::cout << ">> Test assign operator" << std::endl;
	std::cout << std::endl;
	LIB::stack<int>		nbrs; 
	for (int i = 0; i < 5; i++)
		nbrs.push(i);
	display_stack("nbrs", nbrs);

	LIB::stack<int>		nbrs2 = nbrs;

	std::cout << "nbrs2 = nbrs" << std::endl << std::endl;
	display_stack("nbrs2", nbrs2);

	nbrs.pop();
	nbrs.push(99);
	std::cout << "nbrs.pop()" << std::endl;
	std::cout << "nbrs.push(99)" << std::endl << std::endl;

	display_stack("nbrs", nbrs);
	display_stack("nbrs2", nbrs2);
}

void			test_stack_init(void)
{
	std::cout << std::endl;
	std::cout << "[------------ Test stack init ------------]" << std::endl;
	std::cout << std::endl;

	std::cout << "********************************************" << std::endl;
	test_default_constructor();
	std::cout << "********************************************" << std::endl;
	test_copy_constructor();
	std::cout << "********************************************" << std::endl;
	test_assign_operator();
	std::cout << "********************************************" << std::endl;
}
