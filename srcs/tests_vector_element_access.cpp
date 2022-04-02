#include "main.hpp"

void	test_subscript_operator(void)
{
	std::cout << std::endl;
	std::cout << ">> Test operator[]" << std::endl;
	std::cout << std::endl;

	LIB::vector<std::string>				numbers;
	const LIB::vector<std::string>		const_numbers(2, "zero");

	numbers.push_back("zero");
	numbers.push_back("one");
	numbers.push_back("two");
	numbers.push_back("three");
	numbers.push_back("four");

	display_vector("numbers", numbers);
	display_vector("const_numbers", const_numbers);

	for (LIB::vector<std::string>::size_type i = 0; i < numbers.size(); i++)
	{
		std::cout << "numbers[" << i << "] = " << numbers[i];
		std::cout << std::endl;
	}

	std::cout << std::endl;
	for (LIB::vector<std::string>::size_type i = 0; i < const_numbers.size(); i++)
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

	LIB::vector<std::string>				animals;
	const LIB::vector<std::string>		const_animals(2, "pigeon");

	animals.push_back("giraffe");
	animals.push_back("bear");
	animals.push_back("bird");
	animals.push_back("horse");
	animals.push_back("owl");

	display_vector("animals", const_animals);
	display_vector("const_animals", const_animals);

	try
	{
		for (LIB::vector<int>::size_type i = 0; i < animals.size(); i++)
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
		for (LIB::vector<int>::size_type i = 0; i < const_animals.size(); i++)
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
		const_animals.at(const_animals.size());
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

	LIB::vector<std::string>				materials;
	const LIB::vector<std::string> 		const_materials(2, "stone");

	materials.push_back("wood");
	materials.push_back("glass");
	materials.push_back("steel");

	display_vector("materials", materials);
	display_vector("const_materials", const_materials);

	std::cout << "materials.front() = " << materials.front() << std::endl;
	std::cout << "const_materials.front() = " << const_materials.front() << std::endl;

	std::cout << std::endl;
}

void	test_back(void)
{
	std::cout << std::endl;
	std::cout << ">> Test back function" << std::endl;
	std::cout << std::endl;

	LIB::vector<std::string>				weathers;
	const LIB::vector<std::string> 		const_weathers(2, "snowy");

	weathers.push_back("sunny");
	weathers.push_back("windy");
	weathers.push_back("rainy");

	display_vector("weathers", weathers);
	display_vector("const_weathers", weathers);

	std::cout << "weathers.back() = " << weathers.back() << std::endl;
	std::cout << "const_weathers.back() = " << const_weathers.back() << std::endl;

	std::cout << std::endl;
}

void	test_vector_element_access(void)
{
	LIB::vector<std::string>				strs;
	LIB::vector<char>					letters;
	const LIB::vector<std::string>		const_strs(2, "blue");

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
