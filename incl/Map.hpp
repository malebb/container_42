#ifndef MAP_HPP
#define MAP_HPP

#include "memory"

#include "functional.hpp"
#include "utility.hpp"

namespace ft
{
	template <class Key,
			 class T,
			 class Compare = ft::less<Key>,
			 class Alloc = std::allocator<ft::pair<const Key, T> >
			>
	class map
	{

	};
}

#endif
