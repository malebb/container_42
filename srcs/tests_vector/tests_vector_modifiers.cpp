#include "main.hpp"

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

	std::cout << "yellow.insert(yellow.begin() + 1, red.begin(), red.begin() + 3 " << std::endl;
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

void	test_swap(void)
{
	std::cout << std::endl;
	std::cout << ">> Test swap function" << std::endl;
	std::cout << std::endl;

	ft::vector<std::string>		tomato(6, "tomato");
	ft::vector<std::string>		cucumber(6, "cucumber");

	std::cout << "tomato = ";
	display_tab(tomato);

	std::cout << "cucumber = ";
	display_tab(cucumber);
	std::cout << std::endl;
	std::cout << "tomato.swap(cucumber)" << std::endl;

	tomato.swap(cucumber);
	std::cout << std::endl;

	std::cout << "tomato = ";
	display_tab(tomato);

	std::cout << "cucumber = ";
	display_tab(cucumber);
	std::cout << std::endl;
}

void	test_swap_overload(void)
{
	std::cout << std::endl;
	std::cout << ">> Test swap overload function" << std::endl;
	std::cout << std::endl;

	ft::vector<std::string>		pasta(6, "pasta");
	ft::vector<std::string>		rice(6, "rice");

	std::cout << "pasta = ";
	display_tab(pasta);
	std::cout << "rice = ";
	display_tab(rice);
	std::cout << std::endl;

	std::cout << "swap(pasta, rice)" << std::endl;
	swap(rice, pasta);
	std::cout << std::endl;

	std::cout << "pasta = ";
	display_tab(pasta);
	std::cout << "rice = ";
	display_tab(rice);
	std::cout << std::endl;
}

void	test_clear(void)
{
	std::cout << std::endl;
	std::cout << ">> Test clear function" << std::endl;
	std::cout << std::endl;
	
	ft::vector<std::string>		content(6, "content");

	std::cout << "content = ";
	display_tab(content);
	std::cout << std::endl;

	std::cout << "content.clear()" << std::endl;
	std::cout << std::endl;

	content.clear();

	std::cout << "content = ";
	display_tab(content);
	std::cout << std::endl;
}

void	test_vector_modifiers(void)
{
	std::cout << std::endl;
	std::cout << "<------------ Test modifiers ------------>"
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
	test_swap();
	std::cout << "********************************************" << std::endl;
	test_swap_overload();
	std::cout << "********************************************" << std::endl;
	test_clear();
	std::cout << "********************************************" << std::endl;
}
