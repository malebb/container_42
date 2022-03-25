#include "main.hpp"

static void		test_increment_decrement(void)
{
	ft::vector<std::string>::iterator		it;
	ft::vector<std::string>					nbrs;

	nbrs.push_back("one");
	nbrs.push_back("two");
	nbrs.push_back("three");
	nbrs.push_back("four");

	std::cout << std::endl;
	std::cout << ">> Test increment and decrement" << std::endl;
	std::cout << std::endl;

	display_vector("nbrs", nbrs);
	it = nbrs.begin();
	std::cout << "*it = " << *it << std::endl << std::endl;

	std::cout << "it++" << std::endl;
	it++;
	std::cout << "*it = " << *it << std::endl << std::endl;

	std::cout << "it--" << std::endl;
	it--;
	std::cout << "*it = " << *it << std::endl << std::endl;

	std::cout << "*++it = " << *++it << std::endl;
	std::cout << "*--it = " << *--it << std::endl << std::endl;

	std::cout << "*it++ = " << *it++ << std::endl;

	std::cout << "*it = " << *it << std::endl << std::endl;

	std::cout << "*it-- = " << *it-- << std::endl;

	std::cout << "*it = " << *it << std::endl;
}

static void		test_assignment(void)
{
	ft::vector<std::string>::iterator		it;
	ft::vector<std::string>					nbrs;

	nbrs.push_back("one");
	nbrs.push_back("two");
	nbrs.push_back("three");
	nbrs.push_back("four");

	std::cout << std::endl;
	std::cout << ">> Test assignment" << std::endl;
	std::cout << std::endl;
	
	display_vector("nbrs", nbrs);

	it = nbrs.begin();

	std::cout << "*it = " << *it << std::endl << std::endl;

	std::cout << "it += 2" << std::endl;
	it += 2;
	std::cout << "*it = " << *it << std::endl;

	std::cout << "it -= 2" << std::endl;
	it -= 2;
	std::cout << "*it = " << *it << std::endl << std::endl;
}

static void		test_arithmetic(void)
{
	ft::vector<std::string>::iterator		it;
	ft::vector<std::string>::iterator		it2;
	ft::vector<std::string>					nbrs;

	nbrs.push_back("one");
	nbrs.push_back("two");
	nbrs.push_back("three");
	nbrs.push_back("four");

	std::cout << std::endl;
	std::cout << ">> Test arithmetic" << std::endl;
	std::cout << std::endl;
	
	display_vector("nbrs", nbrs);

	it = nbrs.begin();

	std::cout << "*it = " << *it << std::endl  << std::endl;

	std::cout << "it2 = it + 2 " << std::endl;
	it2 = it + 2;
	std::cout << "*it2 = " << *it2 << std::endl;

	std::cout << "it2 = 3 + it " << std::endl;
	it2 = 3 + it;
	std::cout << "*it2 = " << *it2 << std::endl;

	std::cout << "*++it = " << *++it << std::endl;
	std::cout << "it2 = it - 1 " << std::endl;
	it2 = it - 1;
	std::cout << "*it2 = " << *it2 << std::endl << std::endl;
}

static void		test_comparison(void)
{
	ft::vector<std::string>::iterator		it;
	ft::vector<std::string>::iterator		it2;
	ft::vector<std::string>					nbrs;

	nbrs.push_back("one");
	nbrs.push_back("two");
	nbrs.push_back("three");
	nbrs.push_back("four");

	std::cout << std::endl;
	std::cout << ">> Test comparison" << std::endl;
	std::cout << std::endl;
	
	display_vector("nbrs", nbrs);

	it = nbrs.begin();
	it2 = nbrs.begin() + 1;

	std::cout << "*it = " << *it << std::endl;
	std::cout << "*it2 = " << *it2 << std::endl << std::endl;

	std::cout << "it == it2 : ";
	check_comparison(it == it2);

	std::cout << "it != it2 : ";
	check_comparison(it != it2);

	std::cout << "it < it2 : ";
	check_comparison(it < it2);

	std::cout << "it > it2 : ";
	check_comparison(it > it2);

	std::cout << "it <= it2 : ";
	check_comparison(it <= it2);

	std::cout << "it >= it2 : ";
	check_comparison(it >= it2);
	std::cout << std::endl;
}

static void		test_member_access(void)
{
	ft::vector<std::string>::iterator		it;
	ft::vector<Nb>::iterator				it2;
	ft::vector<std::string>					nbrs;
	ft::vector<Nb>							nbs;
	Nb										nb;

	nbrs.push_back("one");
	nbrs.push_back("two");
	nbrs.push_back("three");
	nbrs.push_back("four");

	nbs.push_back(nb);

	std::cout << std::endl;
	std::cout << ">> Test member access" << std::endl;
	std::cout << std::endl;
	
	display_vector("nbrs", nbrs);
	std::cout << "nb->first_value = " << nb.first_value << std::endl;
	std::cout << "nb->second_value = " << nb.second_value << std::endl << std::endl;

	it = nbrs.begin();
	it2 = nbs.begin();

	std::cout << "it[3] = " << it[3] << std::endl << std::endl;
	std::cout << "it2->first_value = " << it2->first_value << std::endl;
	std::cout << "it2->second_value = " << it2->second_value << std::endl << std::endl;
}

static void		test_substract(void)
{
	ft::vector<std::string>::iterator		it;
	ft::vector<std::string>::iterator		it2;
	ft::vector<std::string>					nbrs;

	nbrs.push_back("one");
	nbrs.push_back("two");
	nbrs.push_back("three");
	nbrs.push_back("four");

	std::cout << std::endl;
	std::cout << ">> Test substract" << std::endl;
	std::cout << std::endl;
	
	display_vector("nbrs", nbrs);

	it = nbrs.begin();
	it2 = nbrs.begin() + 1;

	std::cout << "*it = " << *it << std::endl;
	std::cout << "*it2 = " << *it2 << std::endl << std::endl;

	std::cout << "it - it2 = " << it - it2 << std::endl << std::endl;
}

static void		test_const_iterator(void)
{
	std::cout << std::endl;
	std::cout << ">> Test const" << std::endl;
	std::cout << std::endl;

	ft::vector<std::string>::const_iterator		const_it;
	ft::vector<std::string>						nbrs;

	nbrs.push_back("one");
	nbrs.push_back("two");
	nbrs.push_back("three");
	nbrs.push_back("four");

	display_vector("nbrs", nbrs);
	const_it = nbrs.begin();
	std::cout << "*const_it = " << *const_it << std::endl << std::endl;
	std::cout << "*const_it = \"first\" => impossible" << std::endl;
//	*const_it = "first"; // impossible
	std::cout << "*const_it[0] = \"first\" => impossible" << std::endl << std::endl;
//	const_it[0] = "first"; // impossible
	std::cout << "*const_it = " << *const_it << std::endl;
}

void	test_vector_iterator(void)
{
	std::cout << std::endl;
	std::cout << "<------------ Test vector iterator ------------>"
	<< std::endl;
	std::cout << std::endl;

	std::cout << "********************************************" << std::endl;
	test_increment_decrement();
	std::cout << "********************************************" << std::endl;
	test_assignment();
	std::cout << "********************************************" << std::endl;
	test_arithmetic();
	std::cout << "********************************************" << std::endl;
	test_comparison();
	std::cout << "********************************************" << std::endl;
	test_member_access();
	std::cout << "********************************************" << std::endl;
	test_substract();
	std::cout << "********************************************" << std::endl;
	test_const_iterator();
	std::cout << "********************************************" << std::endl;
}
