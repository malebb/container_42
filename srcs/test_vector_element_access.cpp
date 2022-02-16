#include "main.hpp"

void	test_subscript_operator(void)
{
	std::cout << std::endl;
	std::cout << ">> Test operator[]" << std::endl;
	std::cout << std::endl;

	ft::vector<std::string>				numbers;
	const ft::vector<std::string>		const_numbers(2, "zero");

	numbers.push_back("zero");
	numbers.push_back("one");
	numbers.push_back("two");
	numbers.push_back("three");
	numbers.push_back("four");

	std::cout << "numbers = ";
	display_tab(numbers);
	std::cout << "const_numbers = ";
	display_tab(const_numbers);
	std::cout << std::endl;

	for (ft::vector<std::string>::size_type i = 0; i < numbers.size(); i++)
	{
		std::cout << "numbers[" << i << "] = " << numbers[i];
		std::cout << std::endl;
	}

	std::cout << std::endl;
	for (ft::vector<std::string>::size_type i = 0; i < const_numbers.size(); i++)
	{
		std::cout << "const_numbers[" << i << "] = " << const_numbers[i];
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	test_at(void)
{
	std::cout << std::endl;
	std::cout << ">> Test at function" << std::endl;
	std::cout << std::endl;

	ft::vector<std::string>				animals;
	const ft::vector<std::string>		const_animals(2, "pigeon");

	animals.push_back("giraffe");
	animals.push_back("bear");
	animals.push_back("bird");
	animals.push_back("horse");
	animals.push_back("owl");

	std::cout << "animals = ";
	display_tab(animals);
	std::cout << "const_animals = ";
	display_tab(const_animals);
	std::cout << std::endl;

	try
	{
		for (ft::vector<int>::size_type i = 0; i < animals.size(); i++)
		{
			std::cout << "animals.at(" << i << ") = " << animals.at(i);
			std::cout << std::endl;
		}
	}
	catch(std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "animals.at(" << animals.size() << ") = ";
		animals.at(animals.size());
	}
	catch(std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		for (ft::vector<int>::size_type i = 0; i < const_animals.size(); i++)
		{
			std::cout << "const_animals.at(" << i << ") = " << const_animals.at(i);
			std::cout << std::endl;
		}
	}
	catch(std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "const_animals.at(" << const_animals.size() << ") = ";
		const_animals.at(animals.size());
	}
	catch(std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void	test_front(void)
{
	std::cout << std::endl;
	std::cout << ">> Test front function" << std::endl;
	std::cout << std::endl;

	ft::vector<std::string>				materials;
	const ft::vector<std::string> 		const_materials(2, "stone");

	materials.push_back("wood");
	materials.push_back("glass");
	materials.push_back("steel");

	std::cout << "materials = ";
	display_tab(materials);
	std::cout << "const_materials = ";
	display_tab(const_materials);
	std::cout << std::endl;

	std::cout << "materials.front() = " << materials.front() << std::endl;
	std::cout << "const_materials.front() = " << const_materials.front() << std::endl;

	std::cout << std::endl;
}

void	test_back(void)
{
	std::cout << std::endl;
	std::cout << ">> Test back function" << std::endl;
	std::cout << std::endl;

	ft::vector<std::string>				weathers;
	const ft::vector<std::string> 		const_weathers(2, "snowy");

	weathers.push_back("sunny");
	weathers.push_back("windy");
	weathers.push_back("rainy");

	std::cout << "weathers = ";
	display_tab(weathers);
	std::cout << "const_weathers = ";
	display_tab(const_weathers);
	std::cout << std::endl;

	std::cout << "weathers.back() = " << weathers.back() << std::endl;
	std::cout << "const_weathers.back() = " << const_weathers.back() << std::endl;

	std::cout << std::endl;
}

void	test_vector_element_access(void)
{
	ft::vector<std::string>				strs;
	ft::vector<char>					letters;
	const ft::vector<std::string>		const_strs(2, "blue");

	strs.push_back("yellow");
	strs.push_back("red");
	strs.push_back("green");
	strs.push_back("pink");
	strs.push_back("orange");

	std::cout << std::endl;
	std::cout << "<------------ Test vector element access------------>"
	<< std::endl;
	std::cout << std::endl;

	std::cout << "********************************************" << std::endl;
	test_subscript_operator();
	std::cout << "********************************************" << std::endl;
	test_at();
	std::cout << "********************************************" << std::endl;
	test_front();
	std::cout << "********************************************" << std::endl;
	test_back();
	std::cout << "********************************************" << std::endl;
}
