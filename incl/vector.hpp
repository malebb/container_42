#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iterator>
#include <iostream>
#include <stdexcept>
#include <sstream>

#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "type_traits.hpp"
#include "compare.hpp"

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

			vector_iterator() : _it(NULL) {};

			vector_iterator(pointer ptr) : _it(ptr)
			{
			}

			vector_iterator(vector_iterator const & rhs)
			{
				*this = rhs;
			}

			// assignment operators

			vector_iterator&	operator=(vector_iterator const & rhs)
			{
				this->_it = rhs._it;
				return (*this);
			}

			vector_iterator&	operator+=(difference_type rhs)
			{
				this->_it = this->_it + rhs;
				return (*this);
			}

			vector_iterator&	operator-=(difference_type rhs)
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

			pointer		operator->() const
			{
				return &(this->operator*());
			}

			reference			operator[](difference_type rhs) const
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

	template <typename T>
	class const_vector_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{
		public :

			typedef const T					value_type;
			typedef const T*				pointer;
			typedef const T&				reference;
			typedef std::ptrdiff_t			difference_type;

			// constructor destructor

			const_vector_iterator() {};

			const_vector_iterator(pointer ptr) : _it(ptr)
			{
			}

			const_vector_iterator(vector_iterator<T> rhs)
			{
				*this = rhs;
			}

			const_vector_iterator(const_vector_iterator const & rhs)
			{
				*this = rhs;
			}

			// assignment operators

			const_vector_iterator&		operator=(const vector_iterator<T>& rhs)
			{
				this->_it = rhs._it;
				return (*this);
			}

			const_vector_iterator&		operator=(const const_vector_iterator& rhs)
			{
				this->_it = rhs._it;
				return (*this);
			}

			const_vector_iterator&		operator+=(difference_type rhs)
			{
				this->_it = this->_it + rhs;
				return (*this);
			}

			const_vector_iterator&		operator-=(difference_type rhs)
			{
				this->_it = this->_it - rhs;
				return (*this);
			}

			// increment decrement operators

			const_vector_iterator		operator++(int)
			{
				const_vector_iterator		tmp(*this);

				this->_it++;
				return (tmp);
			}

			const_vector_iterator&	operator++()
			{
				this->_it++;
				return (*this);
			}

			const_vector_iterator		operator--(int)
			{
				const_vector_iterator		tmp(*this);

				this->_it--;
				return (tmp);
			}

			const_vector_iterator&	operator--()
			{
				this->_it--;
				return (*this);
			}

			// arithmetic operators

			const_vector_iterator		operator+(difference_type rhs) const
			{
				return (const_vector_iterator(this->_it + rhs));
			}

			const_vector_iterator		operator-(difference_type rhs) const
			{
				return (const_vector_iterator(this->_it - rhs));
			}

			difference_type		operator-(const_vector_iterator const & rhs) const
			{
				return (this->_it - rhs._it);
			}

			// member access operators

			reference	operator*() const
			{
				return (*this->_it);
			}

			pointer		operator->() const
			{
				return &(this->operator*());
			}

			reference			operator[](difference_type rhs) const
			{
				return (this->_it[rhs]);
			}

			// comparison operators

			bool	operator==(const_vector_iterator const & rhs) const
			{
				return (this->_it == rhs._it);
			}

			bool	operator!=(const_vector_iterator const & rhs) const
			{
				return (!(*this == rhs));
			}

			bool	operator<(const_vector_iterator const & rhs)
			{
				return (this->_it < rhs._it);
			}

			bool	operator>(const_vector_iterator const & rhs)
			{
				return (this->_it > rhs._it);
			}

			bool	operator<=(const_vector_iterator const & rhs)
			{
				return (!(*this > rhs));
			}

			bool	operator>=(const_vector_iterator const & rhs)
			{
				return (!(*this < rhs));
			}

		protected :

			pointer		_it;
	};

	//non-member function const_vector_iterator

	template<class T>
	const_vector_iterator<T>			operator+(
				typename const_vector_iterator<T>::difference_type n,
				const const_vector_iterator<T>& rhs)
	{
		return (rhs + n);
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

			typedef ft::vector_iterator<value_type>				iterator;
			typedef ft::const_vector_iterator<value_type>		const_iterator;

			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

			typedef std::ptrdiff_t								difference_type;
			typedef size_t										size_type;

			explicit vector(const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _array(NULL), _size(0), _capacity(0)
			{
			}

			explicit vector(size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type())
						: _alloc(alloc), _array(NULL), _size(0), _capacity(0)
			{
				this->resize(n, val);
			}

			vector (const vector& x) : _alloc(x._alloc), _array(NULL), _size(0), _capacity(0)
			{
				this->assign(x.begin(), x.end());
			}

			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL)
				:  _alloc(alloc), _array(NULL), _size(0), _capacity(0)
			{
				size_type		range_size;

				range_size = 0;
				for (InputIterator it = first; it != last; it++)
				{
					range_size++;
				}
				reserve(range_size);
				this->_size = range_size;
				for (size_type i = 0; i < this->_size; i++)
				{
					this->_alloc.construct(this->_array + i, *first);
					++first;
				}
			}

			vector&		operator=(const vector & x)
			{
				this->_alloc = x._alloc;
				this->assign(x.begin(), x.end());
				return (*this);
			}

			~vector()
			{
				this->clear();
				if (this->capacity())
				{
					this->_alloc.deallocate(this->_array, this->capacity());
				}
			}

			//iterators

			iterator			begin(void)
			{
					return (iterator(this->_array));
			}

			const_iterator		begin(void) const
			{
					return (const_iterator(this->_array));
			}

			iterator			end(void)
			{
					return (iterator(this->_array + this->_size));
			}

			const_iterator		end(void) const
			{
					return (const_iterator(this->_array + this->_size));
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
					this->erase(this->begin() + n, this->begin() + this->size());
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
				this->_size = n;
				}	
			}

			size_type		capacity() const
			{
				return (this->_capacity);
			}

			bool			empty() const
			{
					return (!this->size());
			}

			void			reserve(size_type n)
			{
				pointer		new_array;

				if (n > this->max_size())
					throw(std::length_error("vector::reserve"));
				if (n > this->_capacity)
				{
					new_array = this->_alloc.allocate(n);
					for (size_type i = 0; i < this->_size; i++)
					{
						_alloc.construct(new_array + i, this->_array[i]);
						_alloc.destroy(this->_array + i);
					}
					if (this->capacity())
						_alloc.deallocate(this->_array, this->_capacity);
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
				ss << n;
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
				ss << n;
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

			template <class InputIterator>
			void			assign(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL)
			{
				difference_type		range_size;

				this->clear();
				range_size = 0;
				for (InputIterator it = first; it != last; it++)
				{
					range_size++;
				}
				if (this->capacity() < static_cast<size_type>(range_size))
					reserve(range_size);
				for (difference_type i = 0; i < range_size; i++)
				{
					this->_alloc.construct(this->_array + i, *first);
					first++;
				}
				this->_size = range_size;
			}

			void			assign(size_type n, const value_type& val)
			{
				if (this->capacity() < n)
					reserve(n);
				this->clear();
				for (size_type i = 0; i < n; i++)
				{
					this->_alloc.construct(this->_array + i, val);
				}
				this->_size = n;
			}

			void			push_back(const value_type& val)
			{
				this->insert(this->end(), val);
			}

			void			pop_back()
			{
				this->erase(this->end() - 1);
			}

			iterator		insert(iterator position, const value_type& val)
			{
				size_type	offset;

				offset = position - this->begin();
				if (this->size() + 1 > this->capacity())
				{
					if (!this->capacity())
						this->reserve(1);
					else
						this->reserve(this->capacity() * 2);
				}
				for (long long int i = this->size(); i >= static_cast<long long int>(offset); i--)
				{
					if (i == static_cast<long long int>(offset))
						this->_alloc.construct(this->_array + i, val);
					else
					{
						this->_alloc.construct(this->_array + i, *(this->_array + i - 1));
						this->_alloc.destroy(this->_array + i - 1);
					}
				}
				this->_size++;
				return (position);
			}

			iterator		insert(iterator position, size_type n,
					const value_type& val)
			{
				size_type		offset;

				offset = position - this->begin();
				if (this->size() + n > this->capacity())
				{
					if (this->size() + n <= this->capacity() * 2)
						reserve(this->capacity() * 2);
					else
						reserve(this->size() + n);
				}
				for (long long int i = this->size() - 1; i >= static_cast<long long int>(offset); i--)
				{
					this->_alloc.construct(this->_array + i + n, *(this->_array + i));
					this->_alloc.destroy(this->_array + i);
				}
				for (size_type i = offset; i < offset + n; i++)
				{
					this->_alloc.construct(this->_array + i, val);
				}
				this->_size += n;
				return (position);
			}

			template <class InputIterator>
			void		insert(iterator position, InputIterator first, InputIterator last)
			{
				size_type		offset;
				size_type		range_size;

				range_size = 0;
				for (InputIterator it = first; it != last; it++)
				{
					range_size++;
				}
				offset = 0;
				for (iterator it = this->begin(); it != position; it++)
				{
					offset++;
				}
				if (this->size() + range_size > this->capacity())
				{
					if (this->size() + range_size <= this->capacity() * 2)
						reserve(this->capacity() * 2);
					else
						reserve(this->size() + range_size);
				}
				for (size_type i = offset; i < size(); i++)
				{
					this->_alloc.construct(this->_array + i + range_size, *(this->_array + i));
					this->_alloc.destroy(this->_array + i);
				}
				for (size_type i = offset; i < offset + range_size; i++)
				{
					this->_alloc.construct(this->_array + i, *(first));
					first++;
				}
				this->_size += range_size;
			}

			iterator		erase(iterator position)
			{
				this->_alloc.destroy(&(*position));
				for (iterator it = position; it != this->end() - 1; it++)
				{
					*it = *(it + 1);
				}
				this->_size--;
				return (position);
			}

			iterator		erase(iterator first, iterator last)
			{
				size_type		range_size;
				size_type		offset;

				range_size = 0;
				for (iterator it = first; it != last; it++)
				{
					range_size++;
				}
				offset = 0;
				for (iterator it = this->begin(); it != first; it++)
				{
					offset++;
				}
				for (size_type i = offset; i != offset + range_size; i++)
				{
					this->_alloc.destroy(this->_array + i);
				}
				for (size_type i = offset; i != (this->size() - offset - range_size); i++)
				{
					this->_alloc.construct(this->_array + i, *(this->_array + i + range_size));
					this->_alloc.destroy(this->_array + i + range_size);
				}
				this->_size -= range_size;
				return (first);
			}

			void			swap(vector & x)
			{
				const allocator_type		alloc_tmp = this->_alloc;
				const pointer				array_tmp = this->_array;
				const size_type				size_tmp = this->_size;
				const size_type				capacity_tmp = this->_capacity;

				this->_alloc = x._alloc;
				this->_array = x._array;
				this->_size = x._size;
				this->_capacity = x._capacity;

				x._alloc = alloc_tmp;
				x._array = array_tmp;
				x._size = size_tmp;
				x._capacity = capacity_tmp;
			}

			void			clear()
			{
				erase(this->begin(), this->end());
			}

			//Allocator
			
			allocator_type		get_allocator() const
			{
				return (this->_alloc);
			}

		private :

			allocator_type		_alloc;
			pointer				_array;
			size_type			_size;
			size_type			_capacity;
	};

	//relational operator

	template <class T, class Alloc>
	bool	operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size()
			|| !ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
			return (false);
		return (true);
	}

	template <class T, class Alloc>
	bool	operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool	operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(),
					rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool	operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (!(lhs < rhs) && lhs != rhs);
	}

	template <class T, class Alloc>
	bool	operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (!(lhs > rhs));
	}

	template <class T, class Alloc>
	bool	operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	//swap overload
	
	template <class T, class Alloc>
	void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
	{
		x.swap(y);
	}
}

#endif
