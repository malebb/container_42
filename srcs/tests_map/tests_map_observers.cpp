#include "main.hpp"

static void		test_key_comp(void)
{
	std::cout << std::endl;
	std::cout << ">> test key_comp function" << std::endl;
	std::cout << std::endl;
	ft::map<int, int>::key_compare			comp;
	ft::map<int, int>						numbers;

	comp = numbers.key_comp();
	std::cout << "comp = numbers.key_comp()" << std::endl << std::endl;

	std::cout << "comp(1, 5) = " << comp(1, 5) << std::endl;
	std::cout << "comp(6, 5) = " << comp(6, 5) << std::endl;
}

static void		test_value_comp(void)
{
	std::cout << std::endl;
	std::cout << ">> test value_comp function" << std::endl;
	std::cout << std::endl;
}

void			test_map_observers(void)
{
	std::cout << std::endl;
	std::cout << "<------------ Test map observers ------------>"
	<< std::endl;
	std::cout << std::endl;

	std::cout << "********************************************" << std::endl;
	test_key_comp();
	std::cout << "********************************************" << std::endl;
	test_value_comp();
	std::cout << "********************************************" << std::endl;
}
