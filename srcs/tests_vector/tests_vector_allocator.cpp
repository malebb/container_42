#include "main.hpp"

void	test_get_allocator(void)
{
	std::cout << std::endl;
	std::cout << ">> Test get_allocator" << std::endl;
	std::cout << std::endl;

	ft::vector<int>		vector_container(3, 0);
	int						*ptr;

	std::cout << "vector_container = ";
	display_vector("vector_container", vector_container);
	std::cout << std::endl;

	ptr = vector_container.get_allocator().allocate(3);
	std::cout << "ptr = vector_container.get_allocator().allocate(3)"
		<< std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
	{
		vector_container.get_allocator().construct(ptr + i, i + 1);
		std::cout << "vector_container.get_allocator().construct(ptr + "
			<< i << ", " << i + 1 << ")" << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
	{
		std::cout << "ptr[" << i << "] = " << ptr[i] << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
	{
		vector_container.get_allocator().destroy(ptr + i);
		std::cout << "vector_container.get_allocator().destroy(ptr + "
			<< i << ")" << std::endl;
	}
	std::cout << std::endl;

	vector_container.get_allocator().deallocate(ptr, 3);
	std::cout << "vector_container.get_allocator().deallocate(ptr, 3)"
		<< std::endl;

	std::cout << std::endl;
}

void	test_vector_allocator(void)
{
	std::cout << std::endl;
	std::cout << "[------------ Test vector allocator ------------]" << std::endl;
	std::cout << std::endl;

	std::cout << "********************************************" << std::endl;
	test_get_allocator();
	std::cout << "********************************************" << std::endl;
}
