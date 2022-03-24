#ifndef REVERSE_ITERATOR
#define REVERSE_ITERATOR

#include "iterator.hpp"

namespace ft
{

	template<class Iterator>
	class reverse_iterator
	{
		public :

			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;

			// constructor destructor

			reverse_iterator()
			{

			}

			explicit reverse_iterator(iterator_type it) : _it(it)
			{
			}

			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter>& rev_it)
			{
				*this = rev_it;
			}

			// assignment operators
			
			reverse_iterator&	operator=(reverse_iterator const & rhs)
			{
				this->_it = rhs._it;
				return (*this);
			}

			reverse_iterator&	operator+=(difference_type rhs)
			{
				this->_it.operator-=(rhs);
				return (*this);
			}

			reverse_iterator&	operator-=(difference_type rhs)
			{
				this->_it.operator+=(rhs);
				return (*this);
			}

			// increment decrement operators

			reverse_iterator		operator++(int)
			{
				reverse_iterator		tmp(*this);

				this->_it.operator--();
				return (tmp);
			}

			reverse_iterator&	operator++()
			{
				this->_it.operator--();
				return (*this);
			}

			reverse_iterator		operator--(int)
			{
				reverse_iterator		tmp(*this);

				this->_it.operator++();
				return (tmp);
			}

			reverse_iterator&	operator--()
			{
				this->_it.operator++();
				return (*this);
			}

			// arithmetic operators

			reverse_iterator		operator+(difference_type rhs) const
			{
				return (reverse_iterator(this->_it.operator-(rhs)));
			}

			reverse_iterator		operator-(difference_type rhs) const
			{
				return (reverse_iterator(this->_it.operator+(rhs)));
			}

			reference					operator*() const
			{
				iterator_type		tmp(this->_it);

				tmp.operator--();
				return (*tmp);
			}

			// member access operators

			pointer		operator->()
			{
				return (this->_it.operator->());
			}

			reference			operator[](difference_type rhs) const
			{
				return (this->_it[rhs * -1]);
			}


			iterator_type				base() const
			{
				return (this->_it);
			}

		private :

			iterator_type		_it;
	};
	// non-member functions

	// relational operators

	template <class Iterator>
	bool		operator==(const reverse_iterator<Iterator>& lhs,
							const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<class Iterator>
	bool		operator!=(const ft::reverse_iterator<Iterator>& lhs,
					   	const ft::reverse_iterator<Iterator>& rhs)
	{
		return  (lhs.base() != rhs.base());
	
	}

	template<class Iterator>
	bool		operator<(const ft::reverse_iterator<Iterator>& lhs,
					   	const ft::reverse_iterator<Iterator>& rhs)
	{
		return  (lhs.base() > rhs.base());
	
	}

	template<class Iterator>
	bool		operator>(const ft::reverse_iterator<Iterator>& lhs,
					   	const ft::reverse_iterator<Iterator>& rhs)
	{
		return  (lhs.base() < rhs.base());
	
	}

	template<class Iterator>
	bool		operator>=(const ft::reverse_iterator<Iterator>& lhs,
					   	const ft::reverse_iterator<Iterator>& rhs)
	{
		return  (lhs.base() <= rhs.base());
	
	}

	template<class Iterator>
	bool		operator<=(const ft::reverse_iterator<Iterator>& lhs,
					   	const ft::reverse_iterator<Iterator>& rhs)
	{
		return  (lhs.base() >= rhs.base());
	
	}


	template<class Iterator>
	reverse_iterator<Iterator>		operator+(
				typename reverse_iterator<Iterator>::difference_type n,
				const reverse_iterator<Iterator>& rev_it)
	{
		return (rev_it + n);
	}

	template<class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator>& lhs ,
		const reverse_iterator<Iterator>& rhs)
	{
		return (rhs.base() - lhs.base());
	}
};
#endif
