#include "main.hpp"

static void		test_find(void)
{
	std::cout << std::endl;
	std::cout << ">> test find function" << std::endl;
	std::cout << std::endl;

	ft::map<std::string, std::string>				animal_size;
	ft::map<std::string, std::string>::iterator		it;

	animal_size["mouse"] = "2 inches";
	animal_size["cat"] = "1 foot";
	animal_size["elephant"] = "5 yards";

	const ft::map<std::string, std::string>					const_animal_size(animal_size.begin(), animal_size.end());
	ft::map<std::string, std::string>::const_iterator		c_it;

	display_map("animal_size", animal_size);
	display_map("const_animal_size", const_animal_size);

	it = animal_size.find("elephant");
	c_it = const_animal_size.find("elephant");

	std::cout << "it = animal_size.find(\"elephant\")" << std::endl;
	std::cout << "cit = animal_size.find(\"elephant\")" << std::endl << std::endl;

	std::cout << "it->first = " << it->first << std::endl;
	std::cout << "it->second = " << it->second << std::endl << std::endl;

	std::cout << "cit->first = " << c_it->first << std::endl;
	std::cout << "cit->second = " << c_it->second << std::endl;
}

void	test_map_operations(void)
{
	std::cout << std::endl;
	std::cout << "<------------ Test map operations ------------>"
	<< std::endl << std::endl;

	std::cout << "********************************************" << std::endl;
	test_find();
	std::cout << "********************************************" << std::endl;
}
