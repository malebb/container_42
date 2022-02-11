#include "main.hpp"

void	test_vector_capacity(void)
{
	ft::vector<int>				nbrs;
	ft::vector<char>			letters;

	nbrs.push_back(19);
	nbrs.push_back(2);
	nbrs.push_back(3);
	nbrs.push_back(4);

	std::cout << std::endl;
	std::cout << "------------ Test vector capacity ------------"
	<< std::endl;

	std::cout << "nbrs = ";
	display_tab(nbrs);
	std::cout << "letters = ";
	display_tab(letters);
	std::cout << std::endl;

	std::cout << ">> Test size function" << std::endl;
	std::cout << std::endl;

	std::cout << "nbrs.size() = " << nbrs.size() << std::endl;
	std::cout << "letters.size() = " << letters.size() << std::endl;

	std::cout << std::endl;
	std::cout << ">> Test max size function" << std::endl;
	std::cout << std::endl;

	std::cout << "nbrs.max_size() = " << nbrs.max_size() << std::endl;
	std::cout << "letters.max_size() = " << letters.max_size() << std::endl;

	std::cout << std::endl;
	std::cout << ">> Test resize function" << std::endl;
	std::cout << std::endl;

	std::cout << "nbrs.size() = " << nbrs.size() << std::endl;
	std::cout << "nbrs.capacity() = " << nbrs.capacity() << std::endl;
	std::cout << "nbrs = ";
	display_tab(nbrs);

	nbrs.resize(6, 99);
	std::cout << std::endl;
	std::cout << "nbrs.resize(6, 99)" << std::endl;
	std::cout << std::endl;

	std::cout << "nbrs.size() = " << nbrs.size() << std::endl;
	std::cout << "nbrs.capacity() = " << nbrs.capacity() << std::endl;
	std::cout << "nbrs = ";
	display_tab(nbrs);

	nbrs.resize(4);
	std::cout << std::endl;
	std::cout << "nbrs.resize(4)" << std::endl;
	std::cout << std::endl;

	std::cout << "nbrs.size() = " << nbrs.size() << std::endl;
	std::cout << "nbrs.capacity() = " << nbrs.capacity() << std::endl;
	std::cout << "nbrs = ";
	display_tab(nbrs);

	std::cout << std::endl;
	std::cout << ">> Test reserve and capacity function" << std::endl;
	std::cout << std::endl;

	std::cout << "nbrs.capacity() = " << nbrs.capacity() << std::endl;
	std::cout << "nbrs.reserve(2)" << std::endl;
	nbrs.reserve(2);
	std::cout << "nbrs.capacity() = " << nbrs.capacity() << std::endl;
	std::cout << "nbrs.reserve(10)" << std::endl;
	nbrs.reserve(10);
	std::cout << "nbrs.capacity() = " << nbrs.capacity() << std::endl;
	std::cout << "nbrs.reserve(nbrs.max_size() + 1) ==> exception" << std::endl;
	try
	{
		nbrs.reserve(nbrs.max_size() + 1);
	}
	catch(std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << ">> Test empty function" << std::endl;
	std::cout << std::endl;

	display_tab(nbrs);
	std::cout << "nbrs.empty() = "<< nbrs.empty() << std::endl;
	std::cout << "letters.empty() = "<< letters.empty() << std::endl;
}

void	test_vector_access(void)
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
	std::cout << "------------ Test vector access element ------------"
	<< std::endl;

	std::cout << std::endl;
	std::cout << "strs = ";
	display_tab(strs);

	std::cout << std::endl;
	std::cout << "const_strs = ";
	display_tab(const_strs);

	std::cout << std::endl;
	std::cout << ">> Test operator[]" << std::endl;
	std::cout << std::endl;

	for (ft::vector<std::string>::size_type i = 0; i < strs.size(); i++)
	{
		std::cout << "strs[" << i << "] = " << strs[i];
		std::cout << std::endl;
	}

	std::cout << std::endl;
	for (ft::vector<std::string>::size_type i = 0; i < const_strs.size(); i++)
	{
		std::cout << "const_strs[" << i << "] = " << const_strs[i];
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << ">> Test at function" << std::endl;
	std::cout << std::endl;
	try
	{
		for (ft::vector<int>::size_type i = 0; i < strs.size(); i++)
		{
			std::cout << "strs.at(" << i << ") = " << strs.at(i);
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
		std::cout << "strs.at(" << strs.size() << ") = ";
		strs.at(strs.size());
	}
	catch(std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		for (ft::vector<int>::size_type i = 0; i < const_strs.size(); i++)
		{
			std::cout << "const_strs.at(" << i << ") = " << const_strs.at(i);
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
		std::cout << "const_strs.at(" << const_strs.size() << ") = ";
		const_strs.at(strs.size());
	}
	catch(std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << ">> Test front function" << std::endl;
	std::cout << std::endl;

	std::cout << "strs.front() = " << strs.front() << std::endl;

	std::cout << "const_strs.front() = " << const_strs.front() << std::endl;

	std::cout << std::endl;
	std::cout << ">> Test back function" << std::endl;
	std::cout << std::endl;

	std::cout << "strs.back() = " << strs.back() << std::endl;
	std::cout << "const_strs_back() = " << const_strs.back() << std::endl;

}

void	test_vector_modifiers(void)
{
	std::cout << std::endl;
	std::cout << "------------ Test vector modifiers ------------"
	<< std::endl;

	std::cout << std::endl;
	std::cout << ">> Test push_back function" << std::endl;

	ft::vector<std::string>	seasons;

	std::cout << "seasons = ";
	display_tab(seasons);
	std::cout << std::endl;

	std::cout << "seasons.push_back(\"spring\")" << std::endl;
	seasons.push_back("spring");
	std::cout << "seasons = ";
	display_tab(seasons);
	std::cout << std::endl;

	std::cout << "seasons.push_back(\"summer\")" << std::endl;
	seasons.push_back("summer");
	std::cout << "seasons.push_back(\"autumn\")" << std::endl;
	seasons.push_back("autumn");
	std::cout << "seasons.push_back(\"winter\")" << std::endl;
	seasons.push_back("winter");
	std::cout << "seasons = ";
	display_tab(seasons);

	std::cout << std::endl;
	std::cout << ">> Test pop_back function" << std::endl;

	std::cout << "seasons.pop_back()" << std::endl;
	seasons.pop_back();
	std::cout << "seasons = ";
	display_tab(seasons);

	std::cout << std::endl;
	std::cout << ">> Test assign function" << std::endl;

	ft::vector<std::string>		colors(6, "empty");
	ft::vector<std::string>		green(6, "green");
	ft::vector<std::string>		blue(6, "blue");

	std::cout << "colors = ";
	display_tab(colors);
	std::cout << "green = ";
	display_tab(green);
	std::cout << "blue = ";
	display_tab(blue);
	std::cout << std::endl;

	std::cout << "colors.assign(green.begin(), green.end() - 3)" << std::endl;
	colors.assign(green.begin(), green.end() - 3);
	std::cout << "colors = ";
	display_tab(colors);
	std::cout << std::endl;

	std::cout << "colors.assign(6, \"yellow\")" << std::endl;
	colors.assign(6, "yellow");
	std::cout << "colors = ";
	display_tab(colors);

	std::cout << std::endl;
	std::cout << ">> Test erase function" << std::endl;
}
