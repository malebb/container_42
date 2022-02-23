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
		public :

			typedef Key										key_type;
			typedef T										mapped_type;
			typedef pair<const key_type, mapped_type>		value_type;
			typedef Compare									key_compare;

			class value_compare : public ft::binary_function<value_type, value_type, bool>
			{

				public:

					typedef typename ft::binary_function<value_type,
							value_type, bool>::result_type		result_type;
					typedef typename ft::binary_function<value_type,
							value_type, bool>::first_argument_type
								first_argument_type;
					typedef typename ft::binary_function<value_type,
							value_type, bool>::second_argument_type
								second_argument_type;

					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}

				protected:

					Compare comp;
					value_compare(Compare c) : comp(c) {}  // constructed with map's comparison object
		};
	};
}

#endif
