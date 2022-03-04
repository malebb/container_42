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
				this->node = rhs.node;
				return (*this);
			}

			map_iterator(tree_type *node) : node(node)
			{
			}

			virtual ~map_iterator() {}

			// comparison operators

			template <class T2>
			bool			operator==(const T2& rhs)
			{
				return (this->node == rhs.node);
			}

			template <class T2>
			bool			operator!=(const T2& rhs)
			{
				return (!(*this == rhs));
			}

			// member access operators

			value_type			*operator->()
			{
				return (this->node->value);
			}

			value_type			&operator*()
			{
				return (*(this->node->value));
			}

			// Increment / decrement operators

			map_iterator&		operator++()
			{
				const Key		origin_value = this->node->value->first;

				if (this->node->end)
					this->operator--();
				else
				{
					while (this->node->value->first <= origin_value && !this->node->end)
					{
						if (this->node->right &&
							(this->node->right->value->first > origin_value
							 || this->node->right->end))
							this->node = this->node->right;
						else
							this->node = this->node->parent;
					}
					while (this->node->left && (this->node->left->value->first > origin_value))
					{
						this->node = this->node->left;
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
				tree_type		origin_node(*(this->node));

				if (get_first_value()->first == origin_node.value->first)
				{
					this->node = get_last();
				}
				else if (this->node->end)
					this->node = this->node->parent;
				else
				{
					while (this->node->value->first >= origin_node.value->first)
					{
						if (this->node->left &&
							(this->node->left->value->first < origin_node.value->first))
							this->node = this->node->left;
						else
							this->node = this->node->parent;
					}
					while (this->node->right && (this->node->right->value->first < origin_node.value->first))
					{
						this->node = this->node->right;
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


			tree_type		*node;

		private :

			value_type		*get_first_value()
			{
				tree_type		*origin_node;

				origin_node = this->node;
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

				origin_node = this->node;
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
			rbt<value_type>			*node;

			node = this->_tree;
			while (node->left != NULL)
			{
				node = node->left;
			}
			return (iterator(node));
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

		// modifiers

		ft::pair<iterator, bool>		insert(const value_type& val)
		{
			ft::pair<iterator, bool>	ret;

			ret = this->add_node(&this->_tree, val, NULL);
			if (ret.second)
				this->_size++;
			return (ret);
		}
		
		iterator	insert(iterator position, const value_type& val)
		{
			iterator			next_to_position;
			rbt<value_type>		*new_node;
			rbt<value_type>		*old_node;

			next_to_position = position;
			next_to_position++;
			if (!position.node->end && position->first < val.first && (next_to_position.node->end
						|| next_to_position->first > val.first))
			{
				new_node = this->create_node(val);
				old_node = position.node->right;
				if (old_node)
					position.node->right->parent = new_node;
				position.node->right = new_node;
				new_node->parent = position.node;
				new_node->right = old_node;
				this->_size++;
				return (new_node);
			}
			else
				return (insert(val).first);
		}

	private :

		key_compare										_compare;
		allocator_type									_alloc;
		size_type										_size;
		rbt<value_type>									*_tree;
		rbt<value_type>									*_end_node;
		alloc_rbt										_alloc_rbt;

		// binary tree function

		rbt<value_type>				*create_node(value_type node_value)
		{
			rbt<value_type>			*new_node;
			value_type				*node_value_ptr;


			node_value_ptr = this->_alloc.allocate(1);
			this->_alloc.construct(node_value_ptr, node_value);

			new_node = this->_alloc_rbt.allocate(1);
			this->_alloc_rbt.construct(new_node, node_value_ptr);
			return (new_node);
		}

		ft::pair<iterator, bool>		add_node(rbt<value_type> **tree, value_type node_value, rbt<value_type> *parent)
		{
			bool							end_node;
			ft::pair<iterator, bool>		ret;

			if (!(*tree) || (*tree && *tree == this->_end_node))
			{
				if ((*tree) == this->_end_node)
					end_node = true;
				else
					end_node = false;
				(*tree) = this->create_node(node_value);
				(*tree)->parent = parent;
				if (end_node)
				{
					(*tree)->right = this->_end_node;
					this->_end_node->parent = *tree;
				}
				ret.first = iterator(*tree);
				ret.second = true;
				return (ret);
			}
			else if ((*tree)->value->first == node_value.first)
			{
				ret.first = iterator(*tree);
				ret.second = false;
				return (ret);
			}
			else if (!this->_compare((*tree)->value->first, node_value.first))
				return (this->add_node(&(*tree)->left, node_value, *tree));
			else
				return (this->add_node(&(*tree)->right, node_value, *tree));
		}
	};
}

#endif
