#include "vector.hpp"

#ifndef STACK_HPP
#define STACK_HPP

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public :

			typedef T							value_type;
			typedef Container					container_type;
			typedef size_t						size_type;

			explicit stack(const container_type& ctnr = container_type())
				: c(ctnr)
			{
			}

			stack (const stack& x)
			{
				*this = x;
			}
			
			stack&		operator=(const stack & x)
			{
				this->c = x.c;
				return (*this);
			}

			bool					empty() const
			{
				return (this->c.empty());
			}

			size_type				size() const
			{
				return (this->c.size());
			}

			value_type&				top()
			{
				return (this->c.back());
			}

			const value_type&		top() const
			{
				return (this->c.back());
			}

			void					push(const value_type & val)
			{
				this->c.push_back(val);
			}

			void					pop()
			{
				this->c.pop_back();
			}

			// non-member overloads

			friend bool operator==(const stack& lhs,
					const stack& rhs)
			{
				return (lhs.c == rhs.c);
			}

			friend bool	operator!=(const stack& lhs,
					const stack& rhs)
			{
				return (lhs.c != rhs.c);
			}

			friend bool	operator<(const stack& lhs,
					const stack& rhs)
			{
				return (lhs.c < rhs.c);
			}

			friend bool	operator>(const stack& lhs,
					const stack& rhs)
			{
				return (lhs.c > rhs.c);
			}

			friend bool	operator<=(const stack& lhs,
					const stack& rhs)
			{
				return (lhs.c <= rhs.c);
			}

			friend bool	operator>=(const stack& lhs,
					const stack& rhs)
			{
				return (lhs.c >= rhs.c);
			}


			friend void	swap(const stack& x, const stack& y)
			{
				x.swap(y);
			}

		protected :

			container_type		c;
	};
}

#endif
