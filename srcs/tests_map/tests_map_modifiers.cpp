#include "main.hpp"

static void		test_insert(void)
{
	std::cout << std::endl;
	std::cout << ">> Test insert function" << std::endl;
	std::cout << std::endl;

	ft::map<std::string, std::string>		countries;

	std::cout << "countries = ";
	display_map(countries);
	std::cout << std::endl;

	std::cout << "countries.insert(ft::make_pair<std::string, std::string>(\"Italie\", \"Italy\"))" << std::endl;
	std::cout << "countries.insert(ft::make_pair<std::string, std::string>(\"Espagne\", \"Spain\"))" << std::endl;
	std::cout << "countries.insert(ft::make_pair<std::string, std::string>(\"Maroc\", \"Marocco\"))" << std::endl;

	countries.insert(ft::make_pair<std::string, std::string>("Italie", "Italy"));
	countries.insert(ft::make_pair<std::string, std::string>("Espagne", "Spain"));
	countries.insert(ft::make_pair<std::string, std::string>("Maroc", "Marocco"));

	std::cout << std::endl;
	std::cout << "countries = ";
	display_map(countries);
	std::cout << std::endl << std::endl;

	ft::map<int, std::string>		numbers;

	numbers.insert(ft::make_pair<int, std::string>(1, "un"));
	std::cout << "numbers = ";
	display_map(numbers);
	std::cout << std::endl;

	std::cout << "numbers.insert(numbers.begin(), ft::make_pair<int, std::string>(6, \"six\"))" << std::endl;
	numbers.insert(numbers.begin(), ft::make_pair<int, std::string>(6, "six"));
	std::cout << "numbers = ";
	display_map(numbers);
	std::cout << std::endl << std::endl;

	ft::map<char, char>		letters;
	ft::map<char, char>		end_alphabet;

	end_alphabet.insert(ft::make_pair<char, char>('x', 'X'));
	end_alphabet.insert(ft::make_pair<char, char>('y', 'Y'));
	end_alphabet.insert(ft::make_pair<char, char>('z', 'Z'));

	std::cout << "letters = ";
	display_map(letters);
	std::cout << "end_alphabet = ";
	display_map(end_alphabet);
	std::cout << std::endl;

	std::cout << "letters.insert(end_alphabet.begin(), end_alphabet.end())" << std::endl;
	letters.insert(end_alphabet.begin(), end_alphabet.end());
	std::cout << std::endl;

	std::cout << "letters = ";
	display_map(letters);
	std::cout << std::endl;
	std::cout << std::endl;
}

void			test_erase(void)
{

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
}
