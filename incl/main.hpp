#ifndef MAIN_HPP
#define MAIN_HPP


#include "Vector.hpp"
#include "Map.hpp"
#include "Stack.hpp"

#include <iostream>
#include <iterator>
#include <vector>
#include <map>


// test vector

void	test_vector(void);
void	test_vector_iterator(void);
void	test_vector_reverse_iterator(void);
void	test_const_vector_iterator(void);
void	test_vector_capacity(void);
void	test_vector_element_access(void);
void	test_vector_modifiers(void);
void	test_vector_allocator(void);
void	test_vector_relational_operators(void);

// test map

void	test_map(void);
void	test_map_iterator(void);
void	test_map_reverse_iterator(void);
void	test_map_modifiers(void);
void	test_map_capacity(void);
void	test_map_element_access(void);
void	test_map_observers(void);
void	test_map_operations(void);
void	test_map_allocator(void);

// utils

template<typename T>
void	display_vector(std::string name, const ft::vector<T> & cont);

class	Nb
{
	public :
		static const int first_value = 5;
		static const int second_value = 22;
};

template<typename T>
void	display_vector(std::string name, const ft::vector<T> & cont)
{
	std::cout << name << " = ";
	std::cout << "{";
	for (typename ft::vector<T>::const_iterator it = cont.begin(); it != cont.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != cont.end())
			std::cout << ", ";
	}
	std::cout << "}";
	std::cout << std::endl << std::endl;

}

template<typename Key, typename T>
void	display_map(std::string name, const ft::map<Key, T> & cont)
{
	typename ft::map<Key, T>::const_iterator next;

	std::cout << name << " = ";
	std::cout << "{";
	for (typename ft::map<Key, T>::const_iterator it = cont.begin(); it != cont.end(); ++it)
	{
		std::cout << "{";
		std::cout << it->first;
		std::cout << " => ";
		std::cout << it->second;
		std::cout << "}";
		next = it;
		next++;
		if (next != cont.end())
			std::cout << ", ";
	}
	std::cout << "}";
	std::cout << std::endl << std::endl;

}


void			check_comparison(bool n);

#endif
