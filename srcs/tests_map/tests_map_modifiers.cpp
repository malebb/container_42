#include "main.hpp"

static void		test_insert(void)
{
	std::cout << std::endl;
	std::cout << ">> Test insert function" << std::endl;
	std::cout << std::endl;

	ft::map<std::string, std::string>		countries;

	display_map("countries", countries);

	std::cout << "countries.insert(ft::make_pair<std::string, std::string>(\"Italie\", \"Italy\"))" << std::endl;
	std::cout << "countries.insert(ft::make_pair<std::string, std::string>(\"Espagne\", \"Spain\"))" << std::endl;
	std::cout << "countries.insert(ft::make_pair<std::string, std::string>(\"Maroc\", \"Marocco\"))" << std::endl;

	countries.insert(ft::make_pair<std::string, std::string>("Italie", "Italy"));
	countries.insert(ft::make_pair<std::string, std::string>("Espagne", "Spain"));
	countries.insert(ft::make_pair<std::string, std::string>("Maroc", "Marocco"));

	std::cout << std::endl;

	display_map("countries", countries);

	ft::map<int, std::string>		numbers;

	numbers.insert(ft::make_pair<int, std::string>(1, "un"));
	display_map("numbers", numbers);

	std::cout << "numbers.insert(numbers.begin(), ft::make_pair<int, std::string>(6, \"six\"))" << std::endl;
	numbers.insert(numbers.begin(), ft::make_pair<int, std::string>(6, "six"));
	display_map("numbers", numbers);

	ft::map<char, char>		letters;
	ft::map<char, char>		end_alphabet;

	end_alphabet.insert(ft::make_pair<char, char>('x', 'X'));
	end_alphabet.insert(ft::make_pair<char, char>('y', 'Y'));
	end_alphabet.insert(ft::make_pair<char, char>('z', 'Z'));

	display_map("letters", letters);
	display_map("end_alphabet", end_alphabet);

	std::cout << "letters.insert(end_alphabet.begin(), end_alphabet.end())" << std::endl;
	letters.insert(end_alphabet.begin(), end_alphabet.end());
	std::cout << std::endl;

	display_map("letters", letters);
}

static void		test_erase(void)
{
	std::cout << std::endl;
	std::cout << ">> Test erase function" << std::endl;
	std::cout << std::endl;

	ft::map<int, std::string>		numbers;

	numbers[0] = "zero";
	numbers[1] = "one";
	numbers[2] = "two";
	numbers[3] = "three";
	numbers[4] = "four";

	display_map("numbers", numbers);
	std::cout << "erase(numbers.begin())" << std::endl << std::endl;
	numbers.erase(numbers.begin());
	display_map("numbers", numbers);

	std::cout << "erase(4)" << std::endl << std::endl;
	numbers.erase(4);
	display_map("numbers", numbers);

	ft::map<int, std::string>::iterator		it;

	std::cout << "it = numbers.end()" << std::endl;
	std::cout << "it--" << std::endl;
	it = numbers.end();
	--it;

	std::cout << "erase(first.begin(), it)" << std::endl << std::endl;
	numbers.erase(numbers.begin(), it);
	display_map("numbers", numbers);
}

static void		test_clear(void)
{
	std::cout << std::endl;
	std::cout << ">> Test clear function" << std::endl;
	std::cout << std::endl;

	ft::map<std::string, std::string>		fruits_colors;

	fruits_colors["banana"] = "yellow";
	fruits_colors["strawberry"] = "red";
	fruits_colors["kiwi"] = "green";
	display_map("fruits_colors", fruits_colors);

	std::cout << "fruits_colors.clear()" << std::endl << std::endl;
	fruits_colors.clear();
	display_map("fruits_colors", fruits_colors);
}

static void		test_swap(void)
{
	std::cout << std::endl;
	std::cout << ">> Test clear function" << std::endl;
	std::cout << std::endl;

	ft::map<std::string, std::string>	ying;
	ft::map<std::string, std::string>	yang;

	ying["YING"] = "YING";
	ying["ying"] = "ying";
	ying["YIIIING"] = "YIIIING";
	ying["yiiiing"] = "yiiiing";

	yang["YANG"] = "YANG";
	yang["yang"] = "yang";
	yang["YAAAANG"] = "YAAAANG";
	yang["yaaaang"] = "yaaaang";

	display_map("ying", ying);
	display_map("yang", yang);

	std::cout << "ying.swap(yang)" << std::endl << std::endl;

	ying.swap(yang);

	display_map("ying", ying);
	display_map("yang", yang);
}

void			test_map_modifiers(void)
{
	std::cout << std::endl;
	std::cout << "<------------ Test modifiers ------------>"
	<< std::endl;
	std::cout << std::endl;

	std::cout << "********************************************" << std::endl;
	test_insert();
	std::cout << "********************************************" << std::endl;
	test_erase();
	std::cout << "********************************************" << std::endl;
	test_clear();
	std::cout << "********************************************" << std::endl;
	test_swap();
	std::cout << "********************************************" << std::endl;
}
