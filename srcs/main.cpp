#include "main.hpp"
#include "compare.hpp"
#include <string.h>
#include <algorithm>
#include <stack>
#include <map>
#include <list>
#include <sys/time.h>

class A
{
	public :
		A(int nb): _nb(nb) {}

	friend bool	operator<(const A& lhs, const A & rhs)
	{
		return (lhs._nb < rhs._nb);
	}

	int		_nb;
};

long long int	get_time_ms()
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

long long int get_prog_time(long long int first_time)
{
	return (get_time_ms() - first_time);
}

int	main(void)
{
	long long int		first_time;

	std::cout << std::endl;
	std::cout << "[------------ TEST FT CONTAINER ------------]" << std::endl;
	std::cout << std::endl;

	first_time = get_time_ms();
	test_stack();
	test_vector();
	test_map();

	ft::map<int, int>			mp;

	for (int i = 0; i < 100000; i++)
	{
		mp[i] = i;
	}
//	mp.clear();
	std::cout << "execution terminated after " << get_prog_time(first_time) << "ms" << std::endl;

//	std::cout << "mp.end() - 1 " << (--it)->first << std::endl;
//	std::cout << "mp.end() - 1 " << (--it)->first << std::endl;
	return (0);
}

