#ifndef MAIN_HPP
#define MAIN_HPP


#include "Vector.hpp"
#include "Map.hpp"
#include "Stack.hpp"

#include <iostream>
#include <iterator>
#include <vector>


//test functions

void	test_vector(void);
void	test_vector_iterator(void);
void	test_const_vector_iterator(void);
void	test_vector_capacity(void);
void	test_vector_element_access(void);
void	test_vector_modifiers(void);


//utils

template<typename T>
void	display_tab(const ft::vector<T> & cont);

class	Nb
{
	public :
		static const int nb = 5;
		static const int nb2 = 22;
};

template<typename T>
void	display_tab(const ft::vector<T> & cont)
{
	std::cout << "{";
	for (typename ft::vector<T>::const_iterator it = cont.begin(); it != cont.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != cont.end())
			std::cout << ", ";
	}
	std::cout << "}";
	std::cout << std::endl;

}

void			check_comparison(bool n);

#endif
