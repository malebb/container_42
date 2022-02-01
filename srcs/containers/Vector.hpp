#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		public :
			T			value_type;
			Alloc		allocator_type;
			allocator_type
	};
}

#endif
