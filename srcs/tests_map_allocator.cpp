#include "main.hpp"

static void test_get_allocator(void)
{
	LIB::map<int, std::string>						numbers;
	LIB::pair<const int, std::string>				*pair_ptr;
	LIB::pair<const int, std::string>				pair;

	std::cout << std::endl;
	std::cout << ">> test get_allocator function" << std::endl;
	std::cout << std::endl;

	display_map("numbers", numbers);

	std::cout << "pair_ptr = numbers.get_allocator().allocate(1)" << std::endl << std::endl;
	pair_ptr = numbers.get_allocator().allocate(1);

	std::cout << "pair.second = \"one\"" << std::endl;
	pair.second = "one";

	std::cout << "numbers.get_allocator().construct(pair_ptr, pair)" << std::endl << std::endl;
	numbers.get_allocator().construct(pair_ptr, pair);

	std::cout << "pair_ptr->second = " << pair_ptr->second << std::endl << std::endl;

	std::cout << "numbers.get_allocator().destroy(pair_ptr)" << std::endl << std::endl;
	numbers.get_allocator().destroy(pair_ptr);

	std::cout << "numbers.get_allocator().deallocate(pair_ptr, 1)" << std::endl << std::endl;
	numbers.get_allocator().deallocate(pair_ptr, 1);

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
