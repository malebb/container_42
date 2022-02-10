#include "main.hpp"

void	test_vector_iterator(void)
{
	ft::vector<std::string>::iterator		it;
	ft::vector<std::string>::iterator		it2;
	ft::vector<Nb>::iterator				it3;
	ft::vector<Nb>							nbs;
	Nb										nb;
	ft::vector<std::string>					strs;

	strs.push_back("one");
	strs.push_back("two");
	strs.push_back("three");
	strs.push_back("four");
	strs.push_back("five");

	nbs.push_back(nb);

	std::cout << std::endl;
	std::cout << "------------ Test vector iterator ------------"
	<< std::endl;

	std::cout << std::endl;
	std::cout << ">> Test iterate" << std::endl;
	std::cout << std::endl;

	for (ft::vector<std::string>::iterator it = strs.begin();
			it != strs.end(); it++)
	{
		std::cout << "strs = " << *it << std::endl;
	}

	std::cout << std::endl;
	std::cout << ">> Test iterator operator" << std::endl;
	std::cout << std::endl;

	
	std::cout << "strs is a vector of string" << std::endl;
	std::cout << std::endl;
	std::cout << "it = strs.begin()" << std::endl;
	std::cout << std::endl;

	it = strs.begin();

	std::cout << "*it = " << *it << std::endl;

	std::cout << "it++" << std::endl;
	it++;
	std::cout << "*it = " << *it << std::endl;

	std::cout << "it--" << std::endl;
	it--;
	std::cout << "*it = " << *it << std::endl;

	std::cout << "*++it = " << *++it << std::endl;

	std::cout << "*--it = " << *--it << std::endl;

	std::cout << "*it++" << std::endl;
	*it++;
	std::cout << "*it = " << *it << std::endl;

	std::cout << "*it--" << std::endl;
	*it--;
	std::cout << "*it = " << *it << std::endl;

	std::cout << "it += 2" << std::endl;
	it += 2;
	std::cout << "*it = " << *it << std::endl;

	std::cout << "it -= 2" << std::endl;
	it -= 2;
	std::cout << "*it = " << *it << std::endl;
	
	std::cout << "it[3] = " << it[3] << std::endl;

	std::cout << "it2 = it + 2 " << std::endl;
	it2 = it + 2;
	std::cout << "*it2 = " << *it2 << std::endl;

	std::cout << "it2 = 3 + it " << std::endl;
	it2 = 3 + it;
	std::cout << "*it2 = " << *it2 << std::endl;

	std::cout << "*++it = " << *++it << std::endl;
	std::cout << "it2 = it - 1 " << std::endl;
	it2 = it - 1;
	std::cout << "*it2 = " << *it2 << std::endl;

	std::cout << "it - it2 = " << it - it2 << std::endl;
	it = strs.begin();
	std::cout << "*it = \"hello\"" << std::endl;
	*it = "hello";

	std::cout << "*it = " << *it << std::endl;
	std::cout << "*++it = " << *++it << std::endl;
	std::cout << "*it2 = " << *it2 << std::endl;
	std::cout << "it2 = it" << std::endl;
	it2 = it;

	std::cout << "*it2 = " << *it2 << std::endl;
	std::cout << "it = strs.begin() and it2 = strs.begin() + 1" << std::endl;
	it =  strs.begin();
	it2 = strs.begin() + 1;

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

	std::cout << "nbs is a vector of class Nb" << std::endl;
	it3 = nbs.begin();
	it3 = nbs.begin();
	std::cout << "it3->nb = " << it3->nb << std::endl;
	std::cout << "it3->nb2 = " << it3->nb2 << std::endl;

}

void	test_const_vector_iterator(void)
{
	ft::vector<std::string>::const_iterator		it;
	ft::vector<std::string>::const_iterator		it2;
	ft::vector<Nb>::const_iterator				it3;
	ft::vector<Nb>							nbs;
	Nb										nb;
	ft::vector<std::string>					strs;

	strs.push_back("one");
	strs.push_back("two");
	strs.push_back("three");
	strs.push_back("four");
	strs.push_back("five");

	nbs.push_back(nb);

	std::cout << std::endl;
	std::cout << "------------ Test const vector iterator ------------"
	<< std::endl;

	std::cout << std::endl;
	std::cout << ">> Test iterate" << std::endl;
	std::cout << std::endl;

	for (ft::vector<std::string>::iterator it = strs.begin();
			it != strs.end(); it++)
	{
		std::cout << "strs = " << *it << std::endl;
	}

	std::cout << std::endl;
	std::cout << ">> Test iterator operator" << std::endl;
	std::cout << std::endl;

	
	std::cout << "strs is a vector of string" << std::endl;
	std::cout << std::endl;
	std::cout << "it = strs.begin()" << std::endl;
	std::cout << std::endl;

	it = strs.begin();

	std::cout << "*it = " << *it << std::endl;

	std::cout << "it++" << std::endl;
	it++;
	std::cout << "*it = " << *it << std::endl;

	std::cout << "it--" << std::endl;
	it--;
	std::cout << "*it = " << *it << std::endl;

	std::cout << "*++it = " << *++it << std::endl;

	std::cout << "*--it = " << *--it << std::endl;

	std::cout << "*it++" << std::endl;
	*it++;
	std::cout << "*it = " << *it << std::endl;

	std::cout << "*it--" << std::endl;
	*it--;
	std::cout << "*it = " << *it << std::endl;

	std::cout << "it += 2" << std::endl;
	it += 2;
	std::cout << "*it = " << *it << std::endl;

	std::cout << "it -= 2" << std::endl;
	it -= 2;
	std::cout << "*it = " << *it << std::endl;
	
	std::cout << "it[3] = " << it[3] << std::endl;

	std::cout << "it[3] = \"hello\" ==> impossible because const" << std::endl;
//	it[3] = "hello";

	std::cout << "it2 = it + 2 " << std::endl;
	it2 = it + 2;
	std::cout << "*it2 = " << *it2 << std::endl;

	std::cout << "it2 = 3 + it " << std::endl;
	it2 = 3 + it;
	std::cout << "*it2 = " << *it2 << std::endl;

	std::cout << "*++it = " << *++it << std::endl;
	std::cout << "it2 = it - 1 " << std::endl;
	it2 = it - 1;
	std::cout << "*it2 = " << *it2 << std::endl;

	std::cout << "it - it2 = " << it - it2 << std::endl;
	it = strs.begin();
	std::cout << "*it = \"hello\" ==> impossible because const" << std::endl;
//	*it = "hello"; // impossible

	std::cout << "*it = " << *it << std::endl;
	std::cout << "*++it = " << *++it << std::endl;
	std::cout << "*it2 = " << *it2 << std::endl;
	std::cout << "it2 = it" << std::endl;
	it2 = it;

	std::cout << "*it2 = " << *it2 << std::endl;
	std::cout << "it = strs.begin() and it2 = strs.begin() + 1" << std::endl;
	it =  strs.begin();
	it2 = strs.begin() + 1;

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

	std::cout << "nbs is a vector of class Nb" << std::endl;
	it3 = nbs.begin();
	it3 = nbs.begin();
	std::cout << "it3->nb = " << it3->nb << std::endl;
	std::cout << "it3->nb2 = " << it3->nb2 << std::endl;
}
