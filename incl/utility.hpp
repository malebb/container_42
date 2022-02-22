#ifndef UTILITY_HPP
#define UTILITY_HPP

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

		pair	&operator=(const pair& pr)
		{
			this->first = pr.first;
			this->second = pr.second;
		}

		template <class U1, class U2>
  		friend bool operator==(const pair<U1,U2>& lhs, const pair<U1,U2>& rhs)
		{ 
			return (lhs.first == rhs.first && lhs.second == rhs.second);
		}

		template <class U1, class U2>
  		friend bool operator!=(const pair<U1,U2>& lhs, const pair<U1,U2>& rhs)
		{ 
			return (!(lhs == rhs));
		}

		template <class U1, class U2>
  		friend bool operator<(const pair<U1,U2>& lhs, const pair<U1,U2>& rhs)
		{
			return (lhs.first < rhs.first
					|| (!(rhs.first < lhs.first) && lhs.second < rhs.second));
		}

		template <class U1, class U2>
  		friend bool operator<=(const pair<U1,U2>& lhs, const pair<U1,U2>& rhs)
		{
			return (!(rhs < lhs));
		}

		template <class U1, class U2>
  		friend bool operator>(const pair<U1,U2>& lhs, const pair<U1,U2>& rhs)
		{
			return (rhs < lhs);
		}

		template <class U1, class U2>
  		friend bool operator>=(const pair<U1,U2>& lhs, const pair<U1,U2>& rhs)
		{
			return (!(rhs < lhs));
		}
	};
}

#endif
