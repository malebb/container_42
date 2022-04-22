#include "main.hpp"

static void test_empty(void)
{
	std::cout << std::endl;
	std::cout << ">> Test empty function" << std::endl;
	std::cout << std::endl;
	
	LIB::map<int, std::string>		numbers;

	display_map("numbers", numbers);
	std::cout << "numbers.empty() = " << numbers.empty()
		<< std::endl << std::endl;

	numbers[1] = "one";
	display_map("numbers", numbers);

	std::cout << "numbers.empty() = " << numbers.empty() << std::endl << std::endl;
}

static void test_size(void)
{
	std::cout << std::endl;
	std::cout << ">> test size function" << std::endl;
	std::cout << std::endl;
	LIB::map<int, std::string>		numbers;

	display_map("numbers", numbers);
	std::cout << "numbers.size() = " << numbers.size()
		<< std::endl << std::endl;

	numbers[1] = "one";
	numbers[2] = "two";
	numbers[3] = "three";

	display_map("numbers", numbers);
	std::cout << "numbers.size() = " << numbers.size()
		<< std::endl << std::endl;
}

static void test_max_size(void)
{
	std::cout << std::endl;
	std::cout << ">> test max_size function" << std::endl;
	std::cout << std::endl;

	LIB::map<int, std::string>		numbers;
	LIB::map<char, char>		letters;

	display_map("numbers", numbers);
	display_map("letters", letters);

	std::cout << "numbers.max_size() = " << numbers.max_size() << std::endl;
	std::cout << "letters.max_size() = " << letters.max_size() << std::endl;
	std::cout << std::endl;
}

void			test_map_capacity(void)
{
	std::cout << std::endl;
	std::cout << "<------------ Test map capacity ------------>"
	<< std::endl;
	std::cout << std::endl;

	std::cout << "********************************************" << std::endl;
	test_empty();
	std::cout << "********************************************" << std::endl;
	test_size();
	std::cout << "********************************************" << std::endl;
	test_max_size();
	std::cout << "********************************************" << std::endl;
}
