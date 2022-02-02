#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iterator>

namespace ft
{
	template<
			class Categorie, class T, class pointer = T*,
			class reference = T&
			>
	class vector_iterator
	{
		public :
			typedef T				value_type;
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

			typedef typename allocator_type::pointer			iterator;

	};
}

#endif
