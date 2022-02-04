#include "Vector.hpp"
#include "Map.hpp"
#include "Stack.hpp"

#include <iostream>

template<typename T> void	display_tab(ft::vector<T> & cont)
{
	std::cout << "{";
	for (typename ft::vector<T>::iterator it = cont.begin(); it != cont.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != cont.end())
			std::cout << ", ";
	}
	std::cout << "}";
	std::cout << std::endl;

}

int	main(void)
{
	std::cout << std::endl;
	std::cout << "[------------ TEST FT CONTAINER ------------]" << std::endl;
	std::cout << std::endl;

	std::cout << "------------ TEST VECTOR CONTAINER ------------"
	<< std::endl;

	ft::vector<int>		nbrs;
	ft::vector<char>	letters;

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

	std::cout << std::endl;
	std::cout << "Test size function" << std::endl;
	std::cout << std::endl;

	std::cout << "Max size (int) = " << nbrs.max_size() << std::endl;
	std::cout << "Max size (char) = " << letters.max_size() << std::endl;

	std::cout << std::endl;
	std::cout << "Test resize function" << std::endl;
	std::cout << std::endl;

	std::cout << "Size = " << nbrs.size() << " Capacity = " <<
		nbrs.capacity() << " | ";
	display_tab(nbrs);
	nbrs.resize(6, 99);
	std::cout << "Size = " << nbrs.size() << " Capacity = " <<
		nbrs.capacity() << " | ";
	display_tab(nbrs);

	std::cout << std::endl;
	std::cout << "Test capacity function" << std::endl;
	std::cout << std::endl;

	std::cout << "Capacity = " << nbrs.capacity() << std::endl;
	nbrs.reserve(2);
	std::cout << "Capacity = " << nbrs.capacity() << std::endl;
	nbrs.reserve(9);
	std::cout << "Capacity = " << nbrs.capacity() << std::endl;

	std::cout << std::endl;
	std::cout << "Test empty function" << std::endl;
	std::cout << std::endl;

	display_tab(nbrs);
	if (nbrs.empty())
		std::cout << "vector is empty" << std::endl;
	else
		std::cout << "vector is not empty" << std::endl;
	return (0);
}
