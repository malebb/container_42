#include "main.hpp"

static void		test_subscript_operator(void)
{
	std::cout << std::endl;
	std::cout << ">> test operator[]" << std::endl;
	std::cout << std::endl;

	ft::map<int, std::string>		numbers;

	display_map("numbers", numbers);
	std::cout << "numbers[3] = \"three\"" << std::endl;
	std::cout << "numbers[10] = \"ten\"" << std::endl << std::endl;

	numbers[3] = "three";
	numbers[10] = "ten";

	display_map("numbers", numbers);
	std::cout << "numbers[10] = " << numbers[10] << std::endl;

	std::cout << "numbers[10] = \"dix\"" << std::endl << std::endl;
	numbers[10] = "dix";

	display_map("numbers", numbers);
}

void			test_map_element_access(void)
{
	std::cout << std::endl;
	std::cout << "<------------ Test map capacity ------------>"
	<< std::endl;
	std::cout << std::endl;

	std::cout << "********************************************" << std::endl;
	test_subscript_operator();
	std::cout << "********************************************" << std::endl;
}
