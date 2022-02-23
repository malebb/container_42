#ifndef FUNCTIONAL_HPP
#define FUNCTIONAL_HPP

namespace ft
{
	template <class Arg1, class Arg2, class Result>
	struct binary_function
	{
		typedef Arg1 		first_argument_type;
		typedef Arg2		second_argument_type;
		typedef Result		result_type;
	};

	template <class T>
	struct less : public ft::binary_function <T, T, bool>
	{
		typedef typename	ft::binary_function<T, T, bool>::
								first_argument_type first_argument_type;
		typedef typename	ft::binary_function<T, T, bool>::
								second_argument_type second_argument_type;
		typedef typename	ft::binary_function<T, T, bool>::
								result_type result_type;

		result_type			operator()(const T& x, const T& y) const
		{
			return (x < y);
		}
	};

}

#endif
