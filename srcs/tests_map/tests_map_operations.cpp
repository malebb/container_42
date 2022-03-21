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

static void		test_count(void)
{
	std::cout << std::endl;
	std::cout << ">> test count function" << std::endl;
	std::cout << std::endl;

	ft::map<int, std::string>		numbers;

	numbers[1] = "one";
	numbers[2] = "two";
	numbers[3] = "three";
	numbers[4] = "four";
	numbers[5] = "five";

	display_map("numbers", numbers);

	std::cout << "numbers.count(4) = " << numbers.count(4) << std::endl;
	std::cout << "numbers.count(23) = " << numbers.count(23) << std::endl;
}

static void		test_lower_bound(void)
{
	std::cout << std::endl;
	std::cout << ">> test lower_bound function" << std::endl;
	std::cout << std::endl;

	ft::map<int, std::string>		numbers;

	numbers[15] = "fiveteen";
	numbers[20] = "twenty";
	numbers[25] = "twenty-five";
	numbers[30] = "thirty";
	numbers[35] = "thirty-five";
	const ft::map<int, std::string>		const_numbers(numbers);

//	display_map("numbers", numbers);
	std::cout << "numbers.lower_bound(7)->first) = " << numbers.lower_bound(7)->first << std::endl;
	std::cout << "numbers.lower_bound(25)->first) = " << numbers.lower_bound(25)->first << std::endl;
	std::cout << "numbers.lower_bound(32)->first) = " << numbers.lower_bound(32)->first << std::endl << std::endl;

	std::cout << "const_numbers.lower_bound(7)->first) = " << const_numbers.lower_bound(7)->first << std::endl;
	std::cout << "const_numbers.lower_bound(25)->first) = " << const_numbers.lower_bound(25)->first << std::endl;
	std::cout << "const_numbers.lower_bound(32)->first) = " << const_numbers.lower_bound(32)->first << std::endl;
}

static void		test_upper_bound(void)
{
	std::cout << std::endl;
	std::cout << ">> test upper_bound function" << std::endl;
	std::cout << std::endl;

	ft::map<int, std::string>		numbers;

	numbers[15] = "fiveteen";
	numbers[20] = "twenty";
	numbers[25] = "twenty-five";
	numbers[30] = "thirty";
	numbers[35] = "thirty-five";
	const ft::map<int, std::string>		const_numbers(numbers);

	//display_map("numbers", numbers);
	std::cout << "numbers.upper_bound(7)->first) = " << numbers.upper_bound(7)->first << std::endl;
	std::cout << "numbers.upper_bound(25)->first) = " << numbers.upper_bound(25)->first << std::endl;
	std::cout << "numbers.upper_bound(32)->first) = " << numbers.upper_bound(32)->first << std::endl << std::endl;

	std::cout << "const_numbers.upper_bound(7)->first) = " << const_numbers.upper_bound(7)->first << std::endl;
	std::cout << "const_numbers.upper_bound(25)->first) = " << const_numbers.upper_bound(25)->first << std::endl;
	std::cout << "const_numbers.upper_bound(32)->first) = " << const_numbers.upper_bound(32)->first << std::endl;
}

static void		test_equal_range(void)
{
	std::cout << std::endl;
	std::cout << ">> test equal_range function" << std::endl;
	std::cout << std::endl;

	ft::map<int, std::string>		numbers;

	numbers[15] = "fiveteen";
	numbers[20] = "twenty";
	numbers[25] = "twenty-five";
	numbers[30] = "thirty";
	numbers[35] = "thirty-five";
	const ft::map<int, std::string>		const_numbers(numbers);
	ft::pair<ft::map<int, std::string>::const_iterator, ft::map<int, std::string>::const_iterator>		ret;

	std::cout << "ret = numbers.equal_range(15)" << std::endl;
	ret = numbers.equal_range(15);
	std::cout << "(ret.first)->first = " << (ret.first)->first << std::endl;
	std::cout << "(ret.first)->first = " << (ret.second)->first << std::endl << std::endl;

	std::cout << "ret = numbers.equal_range(16)" << std::endl;

	ret = numbers.equal_range(16);
	std::cout << "(ret.first)->first = " << (ret.first)->first << std::endl;
	std::cout << "(ret.first)->first = " << (ret.second)->first << std::endl;
}

void	test_map_operations(void)
{
	std::cout << std::endl;
	std::cout << "<------------ Test map operations ------------>"
	<< std::endl << std::endl;

	std::cout << "********************************************" << std::endl;
	test_find();
	std::cout << "********************************************" << std::endl;
	test_count();
	std::cout << "********************************************" << std::endl;
	test_lower_bound();
	std::cout << "********************************************" << std::endl;
	test_upper_bound();
	std::cout << "********************************************" << std::endl;
	test_equal_range();
	std::cout << "********************************************" << std::endl;

}
