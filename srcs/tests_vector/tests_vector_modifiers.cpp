#include "main.hpp"

static void		test_push_back(void)
{
	std::cout << std::endl;
	std::cout << ">> Test push_back function" << std::endl;
	std::cout << std::endl;

	LIB::vector<std::string>	seasons;

	display_vector("seasons", seasons);

	std::cout << "seasons.push_back(\"spring\")" << std::endl;
	std::cout << "seasons.push_back(\"summer\")" << std::endl;
	std::cout << "seasons.push_back(\"autumn\")" << std::endl;
	std::cout << "seasons.push_back(\"winter\")" << std::endl;
	std::cout << std::endl;

	seasons.push_back("spring");
	seasons.push_back("summer");
	seasons.push_back("autumn");
	seasons.push_back("winter");

	display_vector("seasons", seasons);
}

static void		test_pop_back(void)
{
	std::cout << std::endl;
	std::cout << ">> Test pop_back function" << std::endl;
	std::cout << std::endl;

	LIB::vector<std::string>	seasons;

	seasons.push_back("spring");
	seasons.push_back("summer");
	seasons.push_back("autumn");
	seasons.push_back("winter");

	display_vector("seasons", seasons);

	std::cout << "seasons.pop_back()" << std::endl;
	std::cout << std::endl;

	seasons.pop_back();

	display_vector("seasons", seasons);
}

static void		test_assign(void)
{
	std::cout << std::endl;
	std::cout << ">> Test assign function" << std::endl;
	std::cout << std::endl;

	LIB::vector<std::string>		colors(6, "empty");
	LIB::vector<std::string>		green(6, "green");

	display_vector("colors", colors);
	display_vector("green", green);

	std::cout << "colors.assign(green.begin(), green.end() - 3)" << std::endl;
	colors.assign(green.begin(), green.end() - 3);
	display_vector("colors", colors);

	std::cout << "colors.assign(6, \"yellow\")" << std::endl;
	colors.assign(6, "yellow");
	display_vector("colors", colors);
}

static void		test_insert(void)
{
	std::cout << std::endl;
	std::cout << ">> Test insert function" << std::endl;
	std::cout << std::endl;

	LIB::vector<std::string>		white(6, "white");
	LIB::vector<std::string>		black(6, "black");
	LIB::vector<std::string>		red(6, "red");
	LIB::vector<std::string>		yellow(6, "yellow");

	display_vector("white", white);
	display_vector("red", red);
	display_vector("black", black);

	std::cout << "while.insert(white.begin() + 1, \"orange\")" << std::endl;
	white.insert(white.begin() + 1, "orange");
	display_vector("white", white);

	std::cout << "black.insert(colors.begin() + 3, 2, \"blue\")" << std::endl;
	black.insert(black.begin() + 3, 2, "blue");
	display_vector("black", black);

	std::cout << "yellow.insert(yellow.begin() + 1, red.begin(), red.begin() + 3 " << std::endl;
	yellow.insert(yellow.begin() + 1, red.begin(), red.begin() + 3);
	display_vector("yellow", yellow);

}

static void		test_erase(void)
{
	std::cout << std::endl;
	std::cout << ">> Test erase function" << std::endl;
	std::cout << std::endl;

	LIB::vector<std::string>		trees(6, "TREE");

	trees.insert(trees.begin() + 2, "flower");
	display_vector("trees", trees);

	std::cout << "trees.erase(trees.begin() + 2)" << std::endl;
	std::cout << std::endl;

	trees.erase(trees.begin() + 2);

	display_vector("trees", trees);

	std::cout << "trees.erase(trees.begin() + 2, trees.end())" << std::endl;

	trees.erase(trees.begin() + 2, trees.end());

	std::cout << std::endl;
	display_vector("trees", trees);
}

static void		test_swap(void)
{
	std::cout << std::endl;
	std::cout << ">> Test swap function" << std::endl;
	std::cout << std::endl;

	LIB::vector<std::string>		tomato(6, "tomato");
	LIB::vector<std::string>		cucumber(6, "cucumber");

	display_vector("tomato", tomato);

	display_vector("cucumber", cucumber);
	std::cout << "tomato.swap(cucumber)" << std::endl;

	tomato.swap(cucumber);
	std::cout << std::endl;

	display_vector("tomato", tomato);
	display_vector("cucumber", cucumber);
}

static void		test_swap_overload(void)
{
	std::cout << std::endl;
	std::cout << ">> Test swap overload function" << std::endl;
	std::cout << std::endl;

	LIB::vector<std::string>		pasta(6, "pasta");
	LIB::vector<std::string>		rice(6, "rice");

	display_vector("pasta", pasta);
	display_vector("rice", rice);

	std::cout << "swap(pasta, rice)" << std::endl;
	swap(rice, pasta);
	std::cout << std::endl;

	display_vector("pasta", pasta);
	display_vector("rice", rice);
}

static void		test_clear(void)
{
	std::cout << std::endl;
	std::cout << ">> Test clear function" << std::endl;
	std::cout << std::endl;
	
	LIB::vector<std::string>		content(6, "content");

	display_vector("content", content);

	std::cout << "content.clear()" << std::endl;
	std::cout << std::endl;

	content.clear();

	display_vector("content", content);
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
