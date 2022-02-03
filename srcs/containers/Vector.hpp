#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iterator>

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

			iterator		begin(void)
			{
					return (iterator(&(_array[0])));
			}

			iterator		end(void)
			{
					return (iterator(&(_array[this->_size])));
			}

			vector() : _size(0)
			{
			}
			
			void			push_back(const value_type& val)
			{
				allocator_type		alloc;

				this->new_array = alloc.allocator(sizeof(T) * (this->_size));

				for (size_type i = 0; i < this->_size; i++)
				{
					alloc.construct(this->_new_array[i], this->_array[i]);
				}
				this->_size++;
				alloc.construct(this->_new_array[this->_size], val);

				//this->_size++;
			}

		private :
			pointer				_array;
			size_type			_size;
	};
}

#endif
