#include "Vector.hpp"
#include "Map.hpp"
#include "Stack.hpp"

#include <iostream>

int	main(void)
{
	std::cout << "ft container main" << std::endl;
	ft::vector<int>					test;

	test.push_back(12);
//	test.push_back(33);
//	test.push_back(90);
	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); it++)
	{
		std::cout << "it = " << *it << std::endl;
	}
	return (0);
}
