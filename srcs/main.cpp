#include "Vector.hpp"
#include "Map.hpp"
#include "Stack.hpp"

#include <iostream>

int	main(void)
{
	std::cout << "------------ TEST VECTOR CONTAINER ------------"
	<< std::endl;

	ft::vector<int>		nbrs;

	std::cout << std::endl;
	std::cout << "------------ Test Capacity member function ------------"
	<< std::endl;
	std::cout << "Test size function" << std::endl;
	std::cout << std::endl;

	std::cout << "Size = " << nbrs.size() << std::endl;
	nbrs.push_back(1);
	nbrs.push_back(2);
	nbrs.push_back(3);
	nbrs.push_back(4);
	std::cout << "Size = " << nbrs.size() << std::endl;
	return (0);
}
