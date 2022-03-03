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

			rbt() : right(NULL), left(NULL), end(false) {}
			rbt(T* value) : value(value), right(NULL), left(NULL), end(false)
			{
			}
			rbt(const rbt& src)
			{
				*this = src;
			}

			rbt&		operator=(const rbt& rhs)
			{
				this->value = rhs.value;
				this->right = rhs.right;
				this->left = rhs.left;
				this->parent = rhs.parent;
				return (*this);
			}

			T			*value;
			rbt			*right;
			rbt			*left;
			rbt			*parent;
			bool		end;
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

			// Constructors / destructor

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

			map_iterator(tree_type *node) : _node(node)
			{
			}

			virtual ~map_iterator() {}

			// comparison operators

			template <class T2>
			bool			operator==(const T2& rhs)
			{
				return (this->_node == rhs._node);
			}

			template <class T2>
			bool			operator!=(const T2& rhs)
			{
				return (!(*this == rhs));
			}

			// member access operators

			value_type			*operator->()
			{
				return (this->_node->value);
			}

			value_type			&operator*()
			{
				return (*(this->_node->value));
			}

			// Increment / decrement operators

			map_iterator&		operator++()
			{
				const Key		origin_value = this->_node->value->first;

				if (this->_node->end)
					this->operator--();
				else
				{
					while (this->_node->value->first <= origin_value && !this->_node->end)
					{
						if (this->_node->right &&
							(this->_node->right->value->first > origin_value
							 || this->_node->right->end))
							this->_node = this->_node->right;
						else
							this->_node = this->_node->parent;
					}
					while (this->_node->left && (this->_node->left->value->first > origin_value))
					{
						this->_node = this->_node->left;
					}
				}
				return (*this);
			}

			map_iterator		operator++(int)
			{
				map_iterator		tmp(*this);

				this->operator++();
				return (tmp);
			}

			map_iterator&		operator--()
			{
				tree_type		origin_node(*(this->_node));

				if (get_first_value()->first == origin_node.value->first)
				{
					this->_node = get_last();
				}
				else if (this->_node->end)
					this->_node = this->_node->parent;
				else
				{
					while (this->_node->value->first >= origin_node.value->first)
					{
						if (this->_node->left &&
							(this->_node->left->value->first < origin_node.value->first))
							this->_node = this->_node->left;
						else
							this->_node = this->_node->parent;
					}
					while (this->_node->right && (this->_node->right->value->first < origin_node.value->first))
					{
						this->_node = this->_node->right;
					}
				}
				return (*this);
			}

			map_iterator		operator--(int)
			{
				map_iterator		tmp(*this);

				this->operator--();
				return (tmp);
			}


			tree_type		*_node;

		private :

			value_type		*get_first_value()
			{
				tree_type		*origin_node;

				origin_node = this->_node;
				while (origin_node->parent)
				{
					origin_node = origin_node->parent;
				}
				while (origin_node->left != NULL)
				{
					origin_node = origin_node->left;
				}
				return (origin_node->value);
			}

			tree_type		*get_last()
			{
				tree_type		*origin_node;

				origin_node = this->_node;
				while (origin_node->parent)
				{
					origin_node = origin_node->parent;
				}
				while (origin_node->right != NULL)
				{
					origin_node = origin_node->right;
				}
				return (origin_node);
			}
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
			value_type		end_node_value;

			this->add_node(&this->_tree, end_node_value, NULL);
			this->_end_node = this->_tree;
			this->_tree->end = 1;
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

		iterator		end()
		{
			return (iterator(this->_end_node));
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
			this->_size++;
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
		rbt<value_type>									*_end_node;
		alloc_rbt										_alloc_rbt;

		// binary tree function

		void		add_node(rbt<value_type> **tree, value_type new_node, rbt<value_type> *parent)
		{
			if (!(*tree) || (*tree && *tree == this->_end_node))
			{
				ft::pair<const int, int>		*node_ptr;
				bool							end_node;

				if (*tree == this->_end_node)
					end_node = true;
				else
					end_node = false;
				node_ptr = this->_alloc.allocate(1);
				this->_alloc.construct(node_ptr, new_node);
				(*tree) = this->_alloc_rbt.allocate(1);
				this->_alloc_rbt.construct(*tree, node_ptr);
				(*tree)->parent = parent;
				if (end_node)
				{
					(*tree)->right = this->_end_node;
					this->_end_node->parent = *tree;
				}
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
