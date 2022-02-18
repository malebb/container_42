#include "main.hpp"

static void		test_equal_to(void)
{
	std::cout << std::endl;
	std::cout << ">> Test == operator" << std::endl;
	std::cout << std::endl;

	ft::vector<std::string>		strs;
	ft::vector<std::string>		strs2;

	strs.push_back("aaa");
	strs.push_back("aaa");
	strs2.assign(strs.begin(), strs.end());
	
	std::cout << "strs = ";
	display_tab(strs);
	std::cout << "strs2 = ";
	display_tab(strs2);
	std::cout << std::endl;

	std::cout << "(strs == strs2) = " << (strs == strs2) << std::endl;
	std::cout << std::endl;

	strs.pop_back();
	strs.push_back("bbb");

	std::cout << "strs = ";
	display_tab(strs);
	std::cout << "strs2 = ";
	display_tab(strs2);
	std::cout << std::endl;

	std::cout << "(strs == strs2) = " << (strs == strs2) << std::endl;
	std::cout << std::endl;
}

static void		test_not_equal_to(void)
{
	std::cout << std::endl;
	std::cout << ">> Test != operator" << std::endl;
	std::cout << std::endl;

	ft::vector<std::string>		strs;
	ft::vector<std::string>		strs2;

	strs.push_back("desert");
	strs.push_back("desert");
	strs2.assign(strs.begin(), strs.end());
	
	std::cout << "strs = ";
	display_tab(strs);
	std::cout << "strs2 = ";
	display_tab(strs2);
	std::cout << std::endl;

	std::cout << "(strs != strs2) = " << (strs != strs2) << std::endl;
	std::cout << std::endl;

	strs.pop_back();
	strs.push_back("dessert");

	std::cout << "strs = ";
	display_tab(strs);
	std::cout << "strs2 = ";
	display_tab(strs2);
	std::cout << std::endl;

	std::cout << "(strs != strs2) = " << (strs != strs2) << std::endl;
	std::cout << std::endl;
}
void	test_vector_relational_operators(void)
{
	std::cout << std::endl;
	std::cout << "<------------ Test relational operators ------------>"
	<< std::endl;
	std::cout << std::endl;

	std::cout << "********************************************" << std::endl;
	test_equal_to();
	std::cout << "********************************************" << std::endl;
	test_not_equal_to();
	std::cout << "********************************************" << std::endl;
	std::cout << "********************************************" << std::endl;
	std::cout << "********************************************" << std::endl;
	std::cout << "********************************************" << std::endl;
	std::cout << "********************************************" << std::endl;
	std::cout << "********************************************" << std::endl;
}
