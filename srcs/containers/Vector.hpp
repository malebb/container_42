#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iterator>
#include <iostream>
#include <stdexcept>

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
			
			vector() : _size(0), _capacity(0)
			{
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
				if (n >= this->size())
					throw(std::out_of_range("out of range"));
				return (this->_array[n]);
			}
			const_reference			operator[](size_type n) const
			{
				if (n >= this->size())
					throw(std::out_of_range("out of range"));
				return (this->_array[n]);
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
