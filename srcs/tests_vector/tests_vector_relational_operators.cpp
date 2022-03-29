#include "main.hpp"

static void		test_equal_to(void)
{
	std::cout << std::endl;
	std::cout << ">> Test == operator" << std::endl;
	std::cout << std::endl;

	ft::vector<int>		nbrs;
	ft::vector<int>		nbrs2;

	nbrs.push_back(0);
	nbrs.push_back(0);
	nbrs2.assign(nbrs.begin(), nbrs.end());
	
	display_vector("nbrs", nbrs);
	display_vector("nbrs2", nbrs2);

	std::cout << "(nbrs == nbrs2) = " << (nbrs == nbrs2) << std::endl;
	std::cout << std::endl;

	nbrs.pop_back();
	nbrs.push_back(1);

	display_vector("nbrs", nbrs);
	display_vector("nbrs2", nbrs2);

	std::cout << "(nbrs == nbrs2) = " << (nbrs == nbrs2) << std::endl;
	std::cout << std::endl;
}

static void		test_not_equal_to(void)
{
	std::cout << std::endl;
	std::cout << ">> Test != operator" << std::endl;
	std::cout << std::endl;

	ft::vector<int>		nbrs;
	ft::vector<int>		nbrs2;

	nbrs.push_back(0);
	nbrs.push_back(0);
	nbrs2.assign(nbrs.begin(), nbrs.end());
	
	display_vector("nbrs", nbrs);
	display_vector("nbrs2", nbrs2);

	std::cout << "(nbrs != nbrs2) = " << (nbrs != nbrs2) << std::endl;
	std::cout << std::endl;

	nbrs.pop_back();
	nbrs.push_back(1);

	display_vector("nbrs", nbrs);
	display_vector("nbrs2", nbrs2);

	std::cout << "(nbrs != nbrs2) = " << (nbrs != nbrs2) << std::endl;
	std::cout << std::endl;
}

static void		test_less_than(void)
{
	std::cout << std::endl;
	std::cout << ">> Test < operator" << std::endl;
	std::cout << std::endl;

	ft::vector<int>		nbrs;
	ft::vector<int>		nbrs2;

	nbrs.push_back(1);
	nbrs.push_back(1);
	nbrs2.assign(nbrs.begin(), nbrs.end());
	
	display_vector("nbrs", nbrs);
	display_vector("nbrs2", nbrs2);

	std::cout << "(nbrs < nbrs2) = " << (nbrs < nbrs2) << std::endl;
	std::cout << std::endl;

	nbrs.pop_back();
	nbrs.push_back(0);

	display_vector("nbrs", nbrs);
	display_vector("nbrs2", nbrs2);

	std::cout << "(nbrs < nbrs2) = " << (nbrs < nbrs2) << std::endl;
	std::cout << std::endl;
}

static void		test_greater_than(void)
{
	std::cout << std::endl;
	std::cout << ">> Test > operator" << std::endl;
	std::cout << std::endl;

	ft::vector<int>		nbrs;
	ft::vector<int>		nbrs2;

	nbrs.push_back(0);
	nbrs.push_back(0);
	nbrs2.assign(nbrs.begin(), nbrs.end());
	
	display_vector("nbrs", nbrs);
	display_vector("nbrs2", nbrs2);

	std::cout << "(nbrs > nbrs2) = " << (nbrs > nbrs2) << std::endl;
	std::cout << std::endl;

	nbrs.pop_back();
	nbrs.push_back(1);

	display_vector("nbrs", nbrs);
	display_vector("nbrs2", nbrs2);

	std::cout << "(nbrs > nbrs2) = " << (nbrs > nbrs2) << std::endl;
	std::cout << std::endl;
}

static void		test_less_than_or_equal_to(void)
{
	std::cout << std::endl;
	std::cout << ">> Test <= operator" << std::endl;
	std::cout << std::endl;

	ft::vector<int>		nbrs;
	ft::vector<int>		nbrs2;

	nbrs.push_back(1);
	nbrs.push_back(1);
	nbrs2.assign(nbrs.begin(), nbrs.end());
	
	display_vector("nbrs", nbrs);
	display_vector("nbrs2", nbrs2);

	std::cout << "(nbrs <= nbrs2) = " << (nbrs <= nbrs2) << std::endl;
	std::cout << std::endl;

	nbrs.pop_back();
	nbrs.push_back(0);

	display_vector("nbrs", nbrs);
	display_vector("nbrs2", nbrs2);

	std::cout << "(nbrs <= nbrs2) = " << (nbrs <= nbrs2) << std::endl;
	std::cout << std::endl;

	nbrs.pop_back();
	nbrs.push_back(1);
	nbrs2.pop_back();
	nbrs2.push_back(0);

	display_vector("nbrs", nbrs);
	display_vector("nbrs2", nbrs2);

	std::cout << "(nbrs <= nbrs2) = " << (nbrs <= nbrs2) << std::endl;
	std::cout << std::endl;
}

static void		test_greater_than_or_equal_to()
{
	std::cout << std::endl;
	std::cout << ">> Test >= operator" << std::endl;
	std::cout << std::endl;

	ft::vector<int>		nbrs;
	ft::vector<int>		nbrs2;

	nbrs.push_back(1);
	nbrs.push_back(1);
	nbrs2.assign(nbrs.begin(), nbrs.end());
	
	display_vector("nbrs", nbrs);
	display_vector("nbrs2", nbrs2);

	std::cout << "(nbrs >= nbrs2) = " << (nbrs >= nbrs2) << std::endl;
	std::cout << std::endl;

	nbrs.pop_back();
	nbrs.push_back(0);

	display_vector("nbrs", nbrs);
	display_vector("nbrs2", nbrs2);

	std::cout << "(nbrs >= nbrs2) = " << (nbrs >= nbrs2) << std::endl;
	std::cout << std::endl;

	nbrs.pop_back();
	nbrs.push_back(1);
	nbrs2.pop_back();
	nbrs2.push_back(0);

	display_vector("nbrs", nbrs);
	display_vector("nbrs2", nbrs2);

	std::cout << "(nbrs >= nbrs2) = " << (nbrs >= nbrs2) << std::endl;
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
	test_less_than();
	std::cout << "********************************************" << std::endl;
	test_greater_than();
	std::cout << "********************************************" << std::endl;
	test_less_than_or_equal_to();
	std::cout << "********************************************" << std::endl;
	test_greater_than_or_equal_to();
	std::cout << "********************************************" << std::endl;
}
