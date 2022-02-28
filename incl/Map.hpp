#ifndef MAP_HPP
#define MAP_HPP

#include <memory>

#include "functional.hpp"
#include "utility.hpp"
#include "iterator.hpp"

#include <iostream>

namespace ft
{
	template <class T>
	class rbt
	{
		public :

			rbt() : right(NULL), left(NULL) {}
			rbt(T* value) : value(value), right(NULL), left(NULL)
			{
			}

			rbt&		operator=(const rbt& rhs)
			{
				this->value = rhs.value;
				this->right = rhs.right;
				this->left = rhs.left;
				return (*this);
			}


			T			*value;
			rbt			*right;
			rbt			*left;
			rbt			*parent;
	};

	struct bidirectional_iterator_tag {};

	template <class Key, class T>
	class map_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		typedef Key												key_type;
		typedef T												mapped_type;
		typedef T*												pointer;
		typedef T&												reference;
		typedef std::ptrdiff_t									difference_type;
		typedef rbt<ft::pair<const key_type, mapped_type> >		tree_type;
		typedef ft::pair<const key_type, mapped_type>			value_type;


		public :

			map_iterator() {}

			map_iterator(const map_iterator& src)
			{
				*this = src;
			}

			map_iterator&		operator=(const map_iterator& rhs)
			{
				this->_node = rhs._node;
				return (*this);
			}

			value_type			*operator->()
			{
				return (this->_node->value);
			}

			map_iterator&		operator++()
			{
				if (this->_node->right)
					this->_node = this->_node->right;
				else
					this->_node = this->_node->parent;
				return (*this);
			}

			map_iterator(tree_type *node) : _node(node)
			{
			}

			tree_type		*_node;

		private :


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
//			typedef std::allocator<rbt<value_type> >			alloc_rbt;
			typedef typename allocator_type::template 
									rebind<rbt<value_type> >::other			alloc_rbt;

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
				: _compare(comp), _alloc(alloc), _size(0), _tree(NULL)
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

		// iterator
		iterator		begin()
		{
			rbt<value_type>			*first_node;

			first_node = this->_tree;
			while (first_node->left != NULL)
			{
				first_node = first_node->left;
			}
			return (iterator(first_node));
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
		void		insert(value_type value)
		{
			this->add_node(&this->_tree, value, NULL);
		}

		// modifiers
		rbt<value_type>		*get_tree(void) const
		{
			return (this->_tree);
		}

		void		print_sorted(rbt<value_type> *tree)
		{
			if (!tree)
				return ;
		
			print_sorted(tree->left);
			std::cout << "value = " << tree->value->first << std::endl;
			print_sorted(tree->right);
		}

	private :

		key_compare										_compare;
		allocator_type									_alloc;
		size_type										_size;
		rbt<value_type>									*_tree;
		alloc_rbt										_alloc_rbt;

		// binary tree function

		void		add_node(rbt<value_type> **tree, value_type new_node, rbt<value_type> *parent)
		{
			if (!(*tree))
			{
				ft::pair<const int, int>		value(new_node);
				ft::pair<const int, int>		*node_ptr;

				node_ptr = this->_alloc.allocate(1);
				this->_alloc.construct(node_ptr, value);
				(*tree) = this->_alloc_rbt.allocate(1);
				this->_alloc_rbt.construct(*tree, node_ptr);
				(*tree)->parent = parent;
			}
			else if (!this->_compare((*tree)->value->first, new_node.first))
			{
				this->add_node(&(*tree)->left, new_node, *tree);
			}
			else
			{
				this->add_node(&(*tree)->right, new_node, *tree);
			}
		}
	};
}

#endif
