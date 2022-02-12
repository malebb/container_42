#include "main.hpp"

class	A
{
	public :

		A(int nb) : _nb(nb)
		{
			std::cout << "A constructor called" << std::endl;
		}
		~A()
		{
			std::cout << "A destructor called nb = " << this->_nb << std::endl;
		};
	
	private :
		int		_nb;

};

void	test_reverse_iterator(void)
{
	ft::vector<std::string>::reverse_iterator		rit;
	ft::vector<std::string>::reverse_iterator		rit2;
	ft::vector<Nb>::reverse_iterator				rit3;
	ft::vector<std::string>							strs;
	ft::vector<Nb>									nbs;
	Nb												nb;

	strs.push_back("one");
	strs.push_back("two");
	strs.push_back("three");
	strs.push_back("four");
	strs.push_back("five");

	nbs.push_back(nb);

	std::cout << std::endl;
	std::cout << "------------ Test reverse Iterator ------------"
	<< std::endl;

	std::cout << std::endl;
	std::cout << ">> Test iterate" << std::endl;
	std::cout << std::endl;

	for (ft::vector<std::string>::reverse_iterator rit = strs.rbegin();
			rit != strs.rend(); rit++)
	{
		std::cout << "strs = " << *rit << std::endl;
	}

	std::cout << std::endl;
	std::cout << ">> Test iterator operator" << std::endl;
	std::cout << std::endl;

	
	std::cout << "strs is a vector of string" << std::endl;
	std::cout << std::endl;
	std::cout << "rit = strs.rbegin()" << std::endl;
	std::cout << std::endl;

	rit = strs.rbegin();

	std::cout << "*rit = " << *rit << std::endl;

	std::cout << "rit++" << std::endl;
	rit++;
	std::cout << "*rit = " << *rit << std::endl;

	std::cout << "rit--" << std::endl;
	rit--;
	std::cout << "*rit = " << *rit << std::endl;

	std::cout << "*++rit = " << *++rit << std::endl;

	std::cout << "*--rit = " << *--rit << std::endl;

	std::cout << "*rit++" << std::endl;
	*rit++;
	std::cout << "*rit = " << *rit << std::endl;

	std::cout << "*rit--" << std::endl;
	*rit--;
	std::cout << "*rit = " << *rit << std::endl;

	std::cout << "rit += 2" << std::endl;
	rit += 2;
	std::cout << "*rit = " << *rit << std::endl;

	std::cout << "rit -= 2" << std::endl;
	rit -= 2;
	std::cout << "*rit = " << *rit << std::endl;
	
	std::cout << "rit[3] = " << rit[3] << std::endl;

	std::cout << "rit2 = rit + 2 " << std::endl;
	rit2 = rit + 2;
	std::cout << "*rit2 = " << *rit2 << std::endl;

	std::cout << "rit2 = 3 + rit " << std::endl;
	rit2 = 3 + rit;
	std::cout << "*rit2 = " << *rit2 << std::endl;
	std::cout << "*++rit = " << *++rit << std::endl;
	std::cout << "rit2 = rit - 1 " << std::endl;
	rit2 = rit - 1;
	std::cout << "*rit2 = " << *rit2 << std::endl;

	
	std::cout << "rit - rit2 = " << rit - rit2 << std::endl;
	rit = strs.rbegin();
	std::cout << "*rit = \"hello\"" << std::endl;
	*rit = "hello";
	std::cout << "*rit = " << *rit << std::endl;
	std::cout << "*++rit = " << *++rit << std::endl;
	std::cout << "*rit2 = " << *rit2 << std::endl;
	std::cout << "rit2 = rit" << std::endl;
	rit2 = rit;
	std::cout << "*rit2 = " << *rit2 << std::endl;

	std::cout << "rit = strs.begin() and rit2 = strs.begin() + 1" << std::endl;
	rit =  strs.rbegin();
	rit2 = strs.rbegin() + 1;
	std::cout << "rit == rit2 : ";
	check_comparison(rit == rit2);
	std::cout << "rit != rit2 : ";
	check_comparison(rit != rit2);

	std::cout << "rit < rit2 : ";
	check_comparison(rit < rit2);
	std::cout << "rit > rit2 : ";
	check_comparison(rit > rit2);

	std::cout << "rit <= rit2 : ";
	check_comparison(rit <= rit2);
	std::cout << "rit >= rit2 : ";
	check_comparison(rit >= rit2);

	std::cout << "nbs is a vector of class Nb" << std::endl;
	rit3 = nbs.rbegin();
	rit3 = nbs.rbegin();
	std::cout << "rit3->nb = " << rit3->nb << std::endl;
	std::cout << "rit3->nb2 = " << rit3->nb2 << std::endl;
}

int	main(void)
{
	std::cout << std::endl;
	std::cout << "[------------ TEST FT CONTAINER ------------]" << std::endl;
	std::cout << std::endl;

//	test_reverse_iterator();

	std::cout << std::endl;
	std::cout << "------------ TEST VECTOR CONTAINER ------------"
	<< std::endl;

//	test_const_vector_iterator();
//	test_vector_iterator();
//	test_vector_capacity();
//	test_vector_access();
	test_vector_modifiers();
/*
	ft::vector<int>	nbrs2;

	nbrs2.push_back(11);
	nbrs2.push_back(22);
	nbrs2.push_back(33);
	nbrs2.push_back(44);
	nbrs2.push_back(55);
*/

	ft::vector<int>	nbrs;

	nbrs.push_back(1);
	nbrs.push_back(2);
	nbrs.push_back(3);
	nbrs.push_back(4);

	std::cout << std::endl;
	std::cout << "SIZE = " << nbrs.size() << "CAPACITY = " << nbrs.capacity() << std::endl;
	std::cout << "iterator = " << *(nbrs.erase(nbrs.begin() + 3)) << std::endl;
	std::cout << "SIZE = " << nbrs.size() << "CAPACITY = " << nbrs.capacity() << std::endl;
	for (ft::vector<int>::iterator it = nbrs.begin(); it != nbrs.end(); it++)
	{
		std::cout << "*it = " << *it << std::endl;
	}
/*
	std::cout << "capacity = " << nbrs.capacity() << std::endl;
	for (ft::vector<int>::iterator it = nbrs.begin(); it != nbrs.end(); it++)
	{
		std::cout << "*it = " << *it << std::endl;
	}
*/
	return (0);
}
