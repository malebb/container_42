#include "main.hpp"

void	test_default_constructor(void)

{
	std::cout << std::endl;
	std::cout << ">> Test default constructor" << std::endl;
	std::cout << std::endl;
}

void	test_fill_constructor(void)

{
	std::cout << std::endl;
	std::cout << ">> Test fill constructor" << std::endl;
	std::cout << std::endl;
}

void	test_range_constructor(void)

{
	std::cout << std::endl;
	std::cout << ">> Test range constructor" << std::endl;
	std::cout << std::endl;
}

void	test_assign_operator(void)

{
	std::cout << std::endl;
	std::cout << ">> Test assign constructor" << std::endl;
	std::cout << std::endl;
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
	test_assign_operator();
	std::cout << "********************************************" << std::endl;
}
