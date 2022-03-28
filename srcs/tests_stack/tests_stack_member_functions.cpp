#include "main.hpp"

void	test_empty(void)
{
	std::cout << std::endl;
	std::cout << ">> test empty function" << std::endl;
	std::cout << std::endl;
}

void	test_size(void)
{
	std::cout << std::endl;
	std::cout << ">> test size function" << std::endl;
	std::cout << std::endl;
}

void	test_top(void)
{
	std::cout << std::endl;
	std::cout << ">> test top" << std::endl;
	std::cout << std::endl;
}

void	test_push(void)
{
	std::cout << std::endl;
	std::cout << ">> test push function" << std::endl;
	std::cout << std::endl;
}

void	test_pop(void)
{
	std::cout << std::endl;
	std::cout << ">> test pop function" << std::endl;
	std::cout << std::endl;
}

void	test_stack_member_functions(void)
{
	std::cout << std::endl;
	std::cout << "<------------ Test member functions ------------>"
	<< std::endl << std::endl;

	std::cout << "********************************************" << std::endl;
	test_empty();
	std::cout << "********************************************" << std::endl;
	test_size();
	std::cout << "********************************************" << std::endl;
	test_top();
	std::cout << "********************************************" << std::endl;
	test_push();
	std::cout << "********************************************" << std::endl;
	test_pop();
	std::cout << "********************************************" << std::endl;
}
