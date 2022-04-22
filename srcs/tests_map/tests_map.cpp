#include "main.hpp"

void	test_map(void)
{
	std::cout << std::endl;
	std::cout << "[------------ Tests map ------------]"
	<< std::endl;

	test_map_iterator();
	test_map_reverse_iterator();
	test_map_capacity();
	test_map_element_access();
	test_map_modifiers();
	test_map_observers();
	test_map_operations();
	test_map_allocator();
}
