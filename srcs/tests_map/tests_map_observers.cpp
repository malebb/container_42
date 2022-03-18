#include "main.hpp"

static void		test_key_comp(void)
{
	std::cout << std::endl;
	std::cout << ">> test key_comp function" << std::endl;
	std::cout << std::endl;
	ft::map<int, int>::key_compare			compare;
	ft::map<int, int>						numbers;

	compare = numbers.key_comp();
	std::cout << "compare = numbers.key_comp()" << std::endl << std::endl;

	std::cout << "compare(1, 5) = " << compare(1, 5) << std::endl;
	std::cout << "compare(6, 5) = " << compare(6, 5) << std::endl;
}

static void		test_value_comp(void)
{
	std::cout << std::endl;
	std::cout << ">> test value_comp function" << std::endl;
	std::cout << std::endl;
	ft::map<int, int>						numbers;
	ft::map<int, int>::iterator				it;
	ft::map<int, int>::iterator				it_2;
	

	numbers[1] = 1;
	numbers[2] = 2;
	numbers[3] = 3;
	numbers[4] = 4;

	display_map("numbers", numbers);
	std::cout << "it = numbers.find(2)" << std::endl;
	it = numbers.find(2);
	std::cout << "it_2 = numbers.find(4)" << std::endl << std::endl;
	it_2 = numbers.find(4);

	std::cout << "numbers.value_comp()(*it, *it_2) = "
		<< numbers.value_comp()(*it, *it_2) << std::endl;
	std::cout << "numbers.value_comp()(*it_2, *it) = "
		<< numbers.value_comp()(*it_2, *it) << std::endl;
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
