#include "main.hpp"

void	test_get_allocator(void)
{
	std::vector<int>		vector_container(3, 0);
	int						*ptr;

	std::cout << "vector_container = ";
	display_tab(vector_container);
	std::cout << std::endl;

	ptr = vector_container.get_allocator().allocate(3);
	for (int i = 0; i < 3; i++)
	{
		vector_container.construct(ptr + i, i);
	}
	for (int i = 0; i < 3; i++)
	{
		std::cout << "ptr[i] = " << ptr[i] << std::endl;
	}
	
}

void	test_allocator()
{
	std::cout << std::endl;
	std::cout << "[------------ Test vector allocator ------------" << std::endl;
	std::cout << std::endl;

	std::cout << "********************************************" << std::endl;
	test_get_allocator();
	std::cout << "********************************************" << std::endl;
}
