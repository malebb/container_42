#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iterator>
#include <iostream>
#include <stdexcept>
#include <sstream>

namespace ft
{
	template<
			class T, class pointer = T*,
			class reference = T&
			>
	class vector_iterator
	{
		public :
			typedef T									value_type;
			typedef std::random_access_iterator_tag		Categorie;

			vector_iterator(T * ptr) : _ptr(ptr)
			{
			}

			vector_iterator		operator++(int)
			{
				vector_iterator		tmp(*this);

				this->_ptr++;
				return (tmp);
			}

			T		operator*() const
			{
				return (*(this->_ptr));
			}

			bool	operator!=(vector_iterator const & rhs) const
			{
				if (this->_ptr == rhs._ptr)
					return (false);
				return (true);
			}

			vector_iterator		operator+(int val) const
			{
				return (vector_iterator(this->_ptr + val));
			}

		private :
			T		*_ptr;

	};

	template<class Iterator>
	class reverse_iterator
	{
		public :
			typedef Iterator													iterator_type;
			typedef typename std::iterator_traits<iterator_type>::iterator_category		iterator_category;
			typedef typename std::iterator_traits<iterator_type>::value_type				value_type;
			typedef typename std::iterator_traits<iterator_type>::difference_type		difference_type;
			typedef typename std::iterator_traits<iterator_type>::pointer				pointer;
			typedef typename std::iterator_traits<iterator_type>::reference				reference;

			reverse_iterator(iterator_type * ptr) : _ptr(ptr)
			{
			}

			reverse_iterator		operator++(int)
			{
				reverse_iterator		tmp(*this);

				this->_ptr--;
				return (tmp);
			}

			iterator_type			operator*() const
			{
				return (*(this->_ptr));
			}

			bool	operator!=(reverse_iterator const & rhs) const
			{
				if (this->_ptr == rhs._ptr)
					return (false);
				return (true);
			}

			reverse_iterator	operator+(int val) const
			{
				return (reverse_iterator(this->_ptr - val));
			}

		private :
			pointer		_ptr;
	};

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

			typedef vector_iterator<T>					iterator;
			typedef reverse_iterator<value_type>		reverse_iterator;
			
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
					return (reverse_iterator(this->_array));
			}

			reverse_iterator		rend(void)
			{
					return (reverse_iterator(this->_array + this->_size));
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
