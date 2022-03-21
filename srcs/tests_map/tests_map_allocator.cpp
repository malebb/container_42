#include "main.hpp"

static void test_get_allocator(void)
{
	ft::map<int, std::string>						numbers;
	ft::pair<const int, std::string>				*p;

	std::cout << std::endl;
	std::cout << ">> test get_allocator function" << std::endl;
	std::cout << std::endl;

	display_map("numbers", numbers);
	std::cout << "p = numbers.get_allocator().allocate(2)" << std::endl;
	p = numbers.get_allocator().allocate(2);
	std::cout << "p->second = \"one\"" << std::endl;
	p->second = "one";
	std::cout << "p->second = " << p->second << std::endl;
}

void	test_map_allocator(void)
{
	std::cout << std::endl;
	std::cout << "<------------ Test map allocator ------------>"
	<< std::endl << std::endl;

	std::cout << "********************************************" << std::endl;
	test_get_allocator();
	std::cout << "********************************************" << std::endl;
}
