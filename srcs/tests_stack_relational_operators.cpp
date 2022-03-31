#include "main.hpp"

static void		test_equal_to(void)
{
	std::cout << std::endl;
	std::cout << ">> Test == operator" << std::endl;
	std::cout << std::endl;

	LIB::stack<int>		nbrs;
	LIB::stack<int>		nbrs2;

	nbrs.push(0);
	nbrs.push(0);

	nbrs2 = nbrs;

	display_stack("nbrs", nbrs);
	display_stack("nbrs2", nbrs2);

	std::cout << "(nbrs == nbrs2) = " << (nbrs == nbrs2) << std::endl;
	std::cout << std::endl;

	nbrs.pop();
	nbrs.push(1);

	display_stack("nbrs", nbrs);
	display_stack("nbrs2", nbrs2);

	std::cout << "(nbrs == nbrs2) = " << (nbrs == nbrs2) << std::endl;
	std::cout << std::endl;
}

static void		test_not_equal_to(void)
{
	std::cout << std::endl;
	std::cout << ">> Test != operator" << std::endl;
	std::cout << std::endl;

	LIB::stack<int>		nbrs;
	LIB::stack<int>		nbrs2;

	nbrs.push(0);
	nbrs.push(0);

	nbrs2 = nbrs;
	
	display_stack("nbrs", nbrs);
	display_stack("nbrs2", nbrs2);

	std::cout << "(nbrs != nbrs2) = " << (nbrs != nbrs2) << std::endl;
	std::cout << std::endl;

	nbrs.pop();
	nbrs.push(1);

	display_stack("nbrs", nbrs);
	display_stack("nbrs2", nbrs2);

	std::cout << "(nbrs != nbrs2) = " << (nbrs != nbrs2) << std::endl;
	std::cout << std::endl;
}

static void		test_less_than(void)
{
	std::cout << std::endl;
	std::cout << ">> Test < operator" << std::endl;
	std::cout << std::endl;

	LIB::stack<int>		nbrs;
	LIB::stack<int>		nbrs2;

	nbrs.push(1);
	nbrs.push(1);

	nbrs2 = nbrs;
	
	display_stack("nbrs", nbrs);
	display_stack("nbrs2", nbrs2);

	std::cout << "(nbrs < nbrs2) = " << (nbrs < nbrs2) << std::endl;
	std::cout << std::endl;

	nbrs.pop();
	nbrs.push(0);

	display_stack("nbrs", nbrs);
	display_stack("nbrs2", nbrs2);

	std::cout << "(nbrs < nbrs2) = " << (nbrs < nbrs2) << std::endl;
	std::cout << std::endl;
}

static void		test_greater_than(void)
{
	std::cout << std::endl;
	std::cout << ">> Test > operator" << std::endl;
	std::cout << std::endl;

	LIB::stack<int>		nbrs;
	LIB::stack<int>		nbrs2;

	nbrs.push(0);
	nbrs.push(0);

	nbrs2 = nbrs;
	
	display_stack("nbrs", nbrs);
	display_stack("nbrs2", nbrs2);

	std::cout << "(nbrs > nbrs2) = " << (nbrs > nbrs2) << std::endl;
	std::cout << std::endl;

	nbrs.pop();
	nbrs.push(1);

	display_stack("nbrs", nbrs);
	display_stack("nbrs2", nbrs2);

	std::cout << "(nbrs > nbrs2) = " << (nbrs > nbrs2) << std::endl;
	std::cout << std::endl;
}

static void		test_less_than_or_equal_to(void)
{
	std::cout << std::endl;
	std::cout << ">> Test <= operator" << std::endl;
	std::cout << std::endl;

	LIB::stack<int>		nbrs;
	LIB::stack<int>		nbrs2;

	nbrs.push(1);
	nbrs.push(1);

	nbrs2 = nbrs;
	
	display_stack("nbrs", nbrs);
	display_stack("nbrs2", nbrs2);

	std::cout << "(nbrs <= nbrs2) = " << (nbrs <= nbrs2) << std::endl;
	std::cout << std::endl;

	nbrs.pop();
	nbrs.push(0);

	display_stack("nbrs", nbrs);
	display_stack("nbrs2", nbrs2);

	std::cout << "(nbrs <= nbrs2) = " << (nbrs <= nbrs2) << std::endl;
	std::cout << std::endl;

	nbrs.pop();
	nbrs.push(1);
	nbrs2.pop();
	nbrs2.push(0);

	display_stack("nbrs", nbrs);
	display_stack("nbrs2", nbrs2);

	std::cout << "(nbrs <= nbrs2) = " << (nbrs <= nbrs2) << std::endl;
	std::cout << std::endl;
}

static void		test_greater_than_or_equal_to()
{
	std::cout << std::endl;
	std::cout << ">> Test >= operator" << std::endl;
	std::cout << std::endl;

	LIB::stack<int>		nbrs;
	LIB::stack<int>		nbrs2;

	nbrs.push(1);
	nbrs.push(1);

	nbrs2 = nbrs;
	
	display_stack("nbrs", nbrs);
	display_stack("nbrs2", nbrs2);

	std::cout << "(nbrs >= nbrs2) = " << (nbrs >= nbrs2) << std::endl;
	std::cout << std::endl;

	nbrs.pop();
	nbrs.push(0);

	display_stack("nbrs", nbrs);
	display_stack("nbrs2", nbrs2);

	std::cout << "(nbrs >= nbrs2) = " << (nbrs >= nbrs2) << std::endl;
	std::cout << std::endl;

	nbrs.pop();
	nbrs.push(1);
	nbrs2.pop();
	nbrs2.push(0);

	display_stack("nbrs", nbrs);
	display_stack("nbrs2", nbrs2);

	std::cout << "(nbrs >= nbrs2) = " << (nbrs >= nbrs2) << std::endl;
	std::cout << std::endl;
}

void	test_stack_relational_operators(void)
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
