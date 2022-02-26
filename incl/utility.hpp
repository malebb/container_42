#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <iostream>

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		typedef T1				first_type;
		typedef	T2				second_type;
	
		first_type			first;
		second_type			second;

		pair() : first(), second() {}

		template <class U, class V>
		pair(const pair<U, V>& pr)
		{
			*this = pr;
		}

		pair(const first_type& a, const second_type& b) : first(a), second(b)
		{
		}

		pair	&operator=(const pair& pr)
		{
			this->first = pr.first;
			this->second = pr.second;
			return (*this);
		}

	};

	template <class U1, class U2>
	bool operator==(const pair<U1,U2>& lhs, const pair<U1,U2>& rhs)
	{ 
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class U1, class U2>
	bool operator!=(const pair<U1,U2>& lhs, const pair<U1,U2>& rhs)
	{ 
		return (!(lhs == rhs));
	}

	template <class U1, class U2>
	bool operator<(const pair<U1,U2>& lhs, const pair<U1,U2>& rhs)
	{
		return (lhs.first < rhs.first
			|| (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <class U1, class U2>
	bool operator<=(const pair<U1,U2>& lhs, const pair<U1,U2>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class U1, class U2>
	bool operator>(const pair<U1,U2>& lhs, const pair<U1,U2>& rhs)
	{
		return (rhs < lhs);
	}

	template <class U1, class U2>
	bool operator>=(const pair<U1,U2>& lhs, const pair<U1,U2>& rhs)
	{
		return (!(rhs < lhs));
	}



	template <class T1, class T2>
	ft::pair<T1, T2>	make_pair(T1 x, T2 y)
	{
		return (ft::pair<T1, T2>(x, y));
	}
}

#endif
