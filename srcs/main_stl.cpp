#include <vector>
#include <map>
#include <stack>

#include <iostream>

template<typename T> void	display_tab(std::vector<T> & cont)
{
	std::cout << "{";
	for (typename std::vector<T>::iterator it = cont.begin(); it != cont.end(); it++)
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
	std::cout << "[------------ TEST STL CONTAINER ------------]" << std::endl;
	std::cout << std::endl;

	std::cout << "------------ TEST VECTOR CONTAINER ------------"
	<< std::endl;

	std::vector<int>		nbrs;
	std::vector<char>	letters;

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
	std::cout << "Test capacity function" << std::endl;
	std::cout << std::endl;

	std::cout << "Capacity = " << nbrs.capacity() << std::endl;
	nbrs.reserve(2);
	std::cout << "Capacity = " << nbrs.capacity() << std::endl;
	nbrs.reserve(5);
	std::cout << "Capacity = " << nbrs.capacity() << std::endl;

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
	return (0);
}
