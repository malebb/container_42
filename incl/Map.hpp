#ifndef MAP_HPP
#define MAP_HPP

#include "memory"

#include "functional.hpp"
#include "utility.hpp"
#include "iterator.hpp"

#include <iostream>

namespace ft
{

	template <class Key, class T>
	struct rbt
	{
		rbt() : _root(NULL)
		{

		}
		typedef ft::pair<const Key, T>		value_type;

		value_type		_root;
	};

	struct bidirectional_iterator_tag {};

	template <class Key, class T>
	class map_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef T*											pointer;
		typedef T&											reference;
		typedef std::ptrdiff_t								difference_type;
		typedef ft::pair<const key_type, mapped_type>		value_type;

		public :

			value_type			_it;

			map_iterator() : _it(NULL) {}

	};

	template <class Key,
			 class T,
			 class Compare = ft::less<Key>,
			 class Alloc = std::allocator<ft::pair<const Key, T> >
			>
	class map
	{
		public :

			typedef Key											key_type;
			typedef T											mapped_type;
			typedef pair<const key_type, mapped_type>			value_type;
			typedef Compare										key_compare;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef map_iterator<Key, T>						iterator;

			// ...

			typedef std::ptrdiff_t								difference_type;
			typedef size_t										size_type;

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
					value_compare(Compare c) : comp(c) {}
		};

		explicit map(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
				: _compare(comp), _alloc(alloc), _size(0)
		{
		}

		map(const map& x)
		{
			*this = x;
		}

		~map()
		{

		}

		map&	operator=(const map& x)
		{
			this->_compare = x._compare;
			this->_alloc = x._alloc;
			this->_size = x._size;
			return (*this);
		}

		// capacity

		bool			empty() const
		{
			return (!(this->_size));
		}

		size_type		size() const
		{
			return (this->_size);
		}
/*
		size_type		max_size() const
		{

		}
*/
		// modifiers
		


	private :

		key_compare			_compare;
		allocator_type		_alloc;
		size_type			_size;

	};

		
}

#endif
