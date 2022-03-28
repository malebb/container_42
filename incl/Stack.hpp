#include "Vector.hpp"

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
				: _array(ctnr)
			{
			}

			bool					empty() const
			{
				return (this->_array.empty());
			}

			size_type				size() const
			{
				return (this->_array.size());
			}

			value_type&				top()
			{
				return (this->_array.back());
			}

			const value_type&		top() const
			{
				return (this->_array.back());
			}

			void					push(const value_type & val)
			{
				this->_array.push_back(val);
			}

			void					pop()
			{
				this->_array.pop_back();
			}

			// relational operators

			template <class T1, class Cont>
			friend bool	operator==(const stack<T1, Cont>& lhs,
					const stack<T1, Cont>& rhs)
			{
				return (lhs._array == rhs._array);
			}

			template <class T1, class Cont>
			friend bool	operator!=(const stack<T1, Cont>& lhs,
					const stack<T1, Cont>& rhs)
			{
				return (lhs._array != rhs._array);
			}

			template <class T1, class Cont>
			friend bool	operator<(const stack<T1, Cont>& lhs,
					const stack<T1, Cont>& rhs)
			{
				return (lhs._array < rhs._array);
			}

			template <class T1, class Cont>
			friend bool	operator>(const stack<T1, Cont>& lhs,
					const stack<T1, Cont>& rhs)
			{
				return (lhs._array > rhs._array);
			}

			template <class T1, class Cont>
			friend bool	operator<=(const stack<T1, Cont>& lhs,
					const stack<T1, Cont>& rhs)
			{
				return (lhs._array <= rhs._array);
			}

			template <class T1, class Cont>
			friend bool	operator>=(const stack<T1, Cont>& lhs,
					const stack<T1, Cont>& rhs)
			{
				return (lhs._array >= rhs._array);
			}

		private :

			container_type		_array;
	};


}

#endif
