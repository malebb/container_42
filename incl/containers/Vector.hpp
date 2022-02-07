#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iterator>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include "iterator.hpp"

namespace ft
{
	template <typename T>
	class vector_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{
		public :

			typedef T						value_type;
			typedef T*						pointer;
			typedef T&						reference;
			typedef std::ptrdiff_t			difference_type;

			// constructor destructor

			vector_iterator() {};

			vector_iterator(pointer ptr) : _it(ptr)
			{
			}

			// assignment operators

			vector_iterator		operator=(const vector_iterator& rhs)
			{
				this->_it = rhs._it;
				return (*this);
			}

			vector_iterator		operator+=(difference_type rhs)
			{
				this->_it = this->_it + rhs;
				return (*this);
			}

			vector_iterator		operator-=(difference_type rhs)
			{
				this->_it = this->_it - rhs;
				return (*this);
			}

			// increment decrement operators

			vector_iterator		operator++(int)
			{
				vector_iterator		tmp(*this);

				this->_it++;
				return (tmp);
			}

			vector_iterator&	operator++()
			{
				this->_it++;
				return (*this);
			}

			vector_iterator		operator--(int)
			{
				vector_iterator		tmp(*this);

				this->_it--;
				return (tmp);
			}

			vector_iterator&	operator--()
			{
				this->_it--;
				return (*this);
			}

			// arithmetic operators

			vector_iterator		operator+(difference_type rhs) const
			{
				return (vector_iterator(this->_it + rhs));
			}

			vector_iterator		operator-(difference_type rhs) const
			{
				return (vector_iterator(this->_it - rhs));
			}

			difference_type		operator-(vector_iterator const & rhs) const
			{
				return (this->_it - rhs._it);
			}

			// member access operators

			reference	operator*() const
			{
				return (*this->_it);
			}

			pointer		operator->()
			{
				return &(this->operator*());
			}

			reference			operator[](difference_type rhs)
			{
				return (this->_it[rhs]);
			}

			// comparison operators

			bool	operator==(vector_iterator const & rhs) const
			{
				return (this->_it == rhs._it);
			}

			bool	operator!=(vector_iterator const & rhs) const
			{
				return (!(*this == rhs));
			}

			bool	operator<(vector_iterator const & rhs)
			{
				return (this->_it < rhs._it);
			}

			bool	operator>(vector_iterator const & rhs)
			{
				return (this->_it > rhs._it);
			}

			bool	operator<=(vector_iterator const & rhs)
			{
				return (!(*this > rhs));
			}

			bool	operator>=(vector_iterator const & rhs)
			{
				return (!(*this < rhs));
			}

		private :

			pointer		_it;
	};

	//non-member function vector_iterator

	template<class T>
	vector_iterator<T>			operator+(
				typename vector_iterator<T>::difference_type n,
				const vector_iterator<T>& rhs)
	{
		return (rhs + n);
	}

	template<class Iterator>
	class reverse_vector_iterator
	{
		public :

			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;

			// constructor destructor

			reverse_vector_iterator()
			{

			}

			explicit reverse_vector_iterator(iterator_type it) : _it(it)
			{
			}

			template <class Iter>
			reverse_vector_iterator(const reverse_vector_iterator<Iter>& rev_it)
			{
				*this = rev_it;
			}


			// assignment operators

			template<typename T2>
			reverse_vector_iterator		operator+=(const T2& rhs)
			{
				this->_it = this->_it - rhs;
				return (*this);
			}

			template<typename T2>
			reverse_vector_iterator		operator-=(const T2& rhs)
			{
				this->_it = this->_it + rhs;
				return (*this);
			}

			// increment decrement operators

			reverse_vector_iterator		operator++(int)
			{
				reverse_vector_iterator		tmp(*this);

				this->_it--;
				return (tmp);
			}

			reverse_vector_iterator&	operator++()
			{
				this->_it--;
				return (*this);
			}

			reverse_vector_iterator		operator--(int)
			{
				reverse_vector_iterator		tmp(*this);

				this->_it++;
				return (tmp);
			}

			reverse_vector_iterator&	operator--()
			{
				this->_it++;
				return (*this);
			}

			// arithmetic operators

			reverse_vector_iterator		operator+(const int val) const
			{
				return (reverse_vector_iterator(this->_it - val));
			}

			reverse_vector_iterator		operator-(const int rhs) const
			{
				return (reverse_vector_iterator(this->_it + rhs));
			}
/*
			template<typename T2>
			difference_type		operator-(const T2& rhs) const
			{
				return (rhs._it - this->_it);
			}
*/
			reference					operator*() const
			{
				iterator_type		tmp(this->_it);

				tmp--;
				return (*tmp);
			}

			// member access operators

			pointer		operator->()
			{
				return &(operator*());
			}

			reference			operator[](int val)
			{
				return (this->_it[val * -1]);
			}


			iterator_type				base() const
			{
				return (this->_it);
			}

		private :

			iterator_type		_it;
	};

	// non-member function reverse iterator 

	// relational operators

	template <class Iterator>
	bool		operator==(const reverse_vector_iterator<Iterator>& lhs,
							const reverse_vector_iterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<class Iterator>
	bool		operator!=(const ft::reverse_vector_iterator<Iterator>& lhs,
					   	const ft::reverse_vector_iterator<Iterator>& rhs)
	{
		return  (lhs.base() != rhs.base());
	
	}

	template<class Iterator>
	bool		operator<(const ft::reverse_vector_iterator<Iterator>& lhs,
					   	const ft::reverse_vector_iterator<Iterator>& rhs)
	{
		return  (lhs.base() > rhs.base());
	
	}

	template<class Iterator>
	bool		operator>(const ft::reverse_vector_iterator<Iterator>& lhs,
					   	const ft::reverse_vector_iterator<Iterator>& rhs)
	{
		return  (lhs.base() < rhs.base());
	
	}

	template<class Iterator>
	bool		operator>=(const ft::reverse_vector_iterator<Iterator>& lhs,
					   	const ft::reverse_vector_iterator<Iterator>& rhs)
	{
		return  (lhs.base() <= rhs.base());
	
	}

	template<class Iterator>
	bool		operator<=(const ft::reverse_vector_iterator<Iterator>& lhs,
					   	const ft::reverse_vector_iterator<Iterator>& rhs)
	{
		return  (lhs.base() >= rhs.base());
	
	}


	template<class Iterator>
	reverse_vector_iterator<Iterator>		operator+(
				typename reverse_vector_iterator<Iterator>::difference_type n,
				const reverse_vector_iterator<Iterator>& rev_it)
	{
		return (rev_it + n);
	}

	template<class Iterator>
	typename reverse_vector_iterator<Iterator>::difference_type operator-(
		const reverse_vector_iterator<Iterator>& lhs ,
		const reverse_vector_iterator<Iterator>& rhs)
	{
		return (rhs.base() - lhs.base());
	}

	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		public :
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef size_t										size_type;

			typedef vector_iterator<value_type>				iterator;
			typedef reverse_vector_iterator<iterator>		reverse_iterator;
			
			vector() : _size(0), _capacity(0)
			{
			}

			explicit vector(size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type())
						: _alloc(alloc), _size(0), _capacity(0)
			{
				this->_alloc = alloc;
				this->resize(n, val);
			}

			~vector()
			{
				for (size_type i = 0; i < this->_size; i++)
				{
					this->_alloc.destroy(this->_array + i);
				}
				if (this->_size)
					this->_alloc.deallocate(this->_array, sizeof(T) * this->_size);
			}

			//iterators

			iterator		begin(void)
			{
					return (iterator(this->_array));
			}

			iterator		end(void)
			{
					return (iterator(this->_array + this->_size));
			}

			reverse_iterator		rbegin(void)
			{
					return (reverse_iterator(this->end()));
			}

			reverse_iterator		rend(void)
			{
					return (reverse_iterator(this->begin()));
			}

			//Capacity

			size_type		size() const
			{
				return (this->_size);
			}

			size_type		max_size() const
			{
				return (this->_alloc.max_size());
			}

			void			resize(size_type n, value_type val = value_type())
			{
				if (n < this->_size)
				{
					for (size_type i = n; i < this->_size; i++)
					{
						this->_alloc.destroy(this->_array + i);
					}
				}
				else
				{
					if (n > this->capacity())
					{
						if (n <= this->_size * 2)
							this->reserve(this->_size * 2);
						else
							this->reserve(n);
					}
					for (size_type i = this->_size; i < n; i++)
					{
						this->_alloc.construct(this->_array + i, val);
					}
				}	
				this->_size = n;
			}

			size_type		capacity() const
			{
				return (this->_capacity);
			}

			bool			empty() const
			{
					return (this->size() ? false : true);
			}

			void			reserve(size_type n)
			{
				pointer		new_array;

				if (n > this->_capacity)
				{
					new_array = this->_alloc.allocate(sizeof(T) * n);
					for (size_type i = 0; i < this->_size; i++)
					{
						_alloc.construct(new_array + i, this->_array[i]);
					}
					for (size_type i = 0; i < this->_size; i++)
					{
						_alloc.destroy(this->_array + i);
					}
					if (this->_size)
						_alloc.deallocate(this->_array, sizeof(T) * n);
					this->_array = new_array;
					this->_capacity = n;
				}
			}

			//Element access

			reference			operator[](size_type n)
			{
				return (this->_array[n]);
			}

			const_reference			operator[](size_type n) const
			{
				return (this->_array[n]);
			}

			reference				at(size_type n)
			{
				std::stringstream			ss;

				ss << "vector::_M_range_check: __n (which is ";
				ss << this->size();
				ss << ") >= this->size() (which is ";
				ss << this->size();
				ss <<")";
				if (n >= this->size())
					throw(std::out_of_range(ss.str()));
				return (this->_array[n]);
			}

			const_reference			at(size_type n) const
			{
				std::stringstream			ss;

				ss << "vector::_M_range_check: __n (which is ";
				ss << this->size();
				ss << ") >= this->size() (which is ";
				ss << this->size();
				ss <<")";
				if (n >= this->size())
					throw(std::out_of_range(ss.str()));
				return (this->_array[n]);
			}

			reference				front()
			{
				return (this->_array[0]);
			}

			const_reference			front() const
			{
				return (this->_array[0]);
			}

			reference				back()
			{
				return (this->_array[this->size() - 1]);
			}

			const_reference			back() const
			{
				return (this->_array[this->size() - 1]);
			}

			//Modifiers

			void			push_back(const value_type& val)
			{
				this->reserve(this->_size + 1);
				_alloc.construct(this->_array + this->_size, val);
				this->_size++;
			}
		private :
			allocator_type		_alloc;
			pointer				_array;
			size_type			_size;
			size_type			_capacity;
	};
}

#endif
