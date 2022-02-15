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

void	test_push_back(void)
{
	std::cout << std::endl;
	std::cout << ">> Test push_back function" << std::endl;
	std::cout << std::endl;

	ft::vector<std::string>	seasons;

	std::cout << "seasons = ";
	display_tab(seasons);
	std::cout << std::endl;

	std::cout << "seasons.push_back(\"spring\")" << std::endl;
	std::cout << "seasons.push_back(\"summer\")" << std::endl;
	std::cout << "seasons.push_back(\"autumn\")" << std::endl;
	std::cout << "seasons.push_back(\"winter\")" << std::endl;
	std::cout << std::endl;

	seasons.push_back("spring");
	seasons.push_back("summer");
	seasons.push_back("autumn");
	seasons.push_back("winter");

	std::cout << "seasons = ";
	display_tab(seasons);
	std::cout << std::endl;
}

void	test_pop_back(void)
{
	std::cout << std::endl;
	std::cout << ">> Test pop_back function" << std::endl;
	std::cout << std::endl;

	ft::vector<std::string>	seasons;

	seasons.push_back("spring");
	seasons.push_back("summer");
	seasons.push_back("autumn");
	seasons.push_back("winter");

	std::cout << "seasons = ";
	display_tab(seasons);
	std::cout << std::endl;

	std::cout << "seasons.pop_back()" << std::endl;
	std::cout << std::endl;

	seasons.pop_back();

	std::cout << "seasons = ";
	display_tab(seasons);
	std::cout << std::endl;
}

void	test_assign(void)
{
	std::cout << std::endl;
	std::cout << ">> Test assign function" << std::endl;
	std::cout << std::endl;

	ft::vector<std::string>		colors(6, "empty");
	ft::vector<std::string>		green(6, "green");

	std::cout << "colors = ";
	display_tab(colors);
	std::cout << "green = ";
	display_tab(green);
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
}

void	test_insert(void)
{
	std::cout << std::endl;
	std::cout << ">> Test insert function" << std::endl;
	std::cout << std::endl;

	ft::vector<std::string>		white(6, "white");
	ft::vector<std::string>		black(6, "black");
	ft::vector<std::string>		red(6, "red");
	ft::vector<std::string>		yellow(6, "yellow");

	std::cout << "white = ";
	display_tab(white);
	std::cout << "red = ";
	display_tab(red);
	std::cout << "black = ";
	display_tab(black);
	std::cout << std::endl;

	std::cout << "while.insert(white.begin() + 1, \"orange\")" << std::endl;
	white.insert(white.begin() + 1, "orange");
	std::cout << "white = ";
	display_tab(white);
	std::cout << std::endl;

	std::cout << "black.insert(colors.begin() + 3, 2, \"blue\")" << std::endl;
	black.insert(black.begin() + 3, 2, "blue");
	std::cout << "black = ";
	display_tab(black);
	std::cout << std::endl;

	std::cout << "yellow.insert(colors.begin() + 1, red.begin(), red.begin() + 3 " << std::endl;
	yellow.insert(yellow.begin() + 1, red.begin(), red.begin() + 3);
	std::cout << "yellow = ";
	display_tab(yellow);
	std::cout << std::endl;

}

void	test_erase(void)
{
	std::cout << std::endl;
	std::cout << ">> Test erase function" << std::endl;
	std::cout << std::endl;

	ft::vector<std::string>		trees(6, "TREE");

	trees.insert(trees.begin() + 2, "flower");
	std::cout << "trees = ";
	display_tab(trees);
	std::cout << std::endl;


	std::cout << "trees.erase(trees.begin() + 2)" << std::endl;
	std::cout << std::endl;

	trees.erase(trees.begin() + 2);

	std::cout << "trees = ";
	display_tab(trees);
	std::cout << std::endl;

	std::cout << "trees.erase(trees.begin() + 2, trees.end())" << std::endl;

	trees.erase(trees.begin() + 2, trees.end());

	std::cout << std::endl;
	std::cout << "trees = ";
	display_tab(trees);
	std::cout << std::endl;
}

void	test_vector_modifiers(void)
{
	std::cout << std::endl;
	std::cout << "------------ Test modifiers ------------"
	<< std::endl;
	std::cout << std::endl;

	std::cout << "********************************************" << std::endl;
	test_push_back();
	std::cout << "********************************************" << std::endl;
	test_pop_back();
	std::cout << "********************************************" << std::endl;
	test_assign();
	std::cout << "********************************************" << std::endl;
	test_insert();
	std::cout << "********************************************" << std::endl;
	test_erase();
	std::cout << "********************************************" << std::endl;
}
