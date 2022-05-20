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
/*
	LIB::map<int, int>		nbrs;

//	nbrs[17] = 70;
//	nbrs[33] = 70;
//	nbrs[34] = 70; // la
  // 	nbrs[10] = 70;
	nbrs[86] = 70; // là
	nbrs[44] = 70;
//	nbrs[49] = 70;
//	nbrs[13] = 70; 
//	nbrs[30] = 70;
//	nbrs[32] = 70;
//	nbrs[3] = 70;
	nbrs[90] = 70;
	nbrs[50] = 70; // là
	nbrs[50] = 70; // là
	nbrs[12] = 70; // là
	nbrs[15] = 70; // là
//	nbrs[6] = 6;
//	nbrs[2] = 70; // là
	nbrs[40] = 70; // là
	nbrs[44] = 70; // là
	nbrs[83] = 70; // là
//	nbrs[57] = 70; // là
//	nbrs[50] = 70; // là
	
//	nbrs[6] = 6;
//	nbrs[2] = 6;
//	nbrs[3] = 6;
//	nbrs[5] = 6;

	// 3 5 6 10 12 13 15 17 30 32 33 34 40 44 49 50 57 83 86 90
	
	// 12 15 40 44 50 83 86 90
	ft::map<int, int>::iterator it = nbrs.upper_bound(70);

	std::cout << "nbrs.upper_bound(70) = " << nbrs.upper_bound(70)->first << std::endl;

	for (ft::map<int, int>::iterator it2 = it; it2 != nbrs.end(); ++it2)
	{
		std::cout << "it2->first = " << it2->first << "it->second = " << it2->second << std::endl;
	}
*/	
    //               |                 |

	// 3 10 13 17 30 32 33 34 44 49 77 90
	
	//2 6 40 12
	
	//			   |

	// 2 3 5 6 13 33 34 44 49 57 83 90 

//	nbrs.erase(++(++(++(++(++(++(nbrs.begin())))))), --(--(--(--nbrs.end()))));
//	nbrs.erase(++(++(++(++(++(nbrs.begin()))))), --(--(--(--nbrs.end()))));
//	std::cout << "it = " << (++(++(++(++(++(nbrs.begin()))))))->first << std::endl;
//	nbrs.erase(++(++(nbrs.begin())));
//	nbrs.erase(++(++(++(++(++(nbrs.begin()))))));
	



//	nbrs.erase(--nbrs.end());
//	std::cout << "--nbrs.end()->first" << (--nbrs.end())->first << std::endl;
//	nbrs.erase(--nbrs.end());
//	std::cout << "--nbrs.end() = " << (--nbrs.end())->first << std::endl;
//	nbrs.erase(--nbrs.end());

//	display_map("nbrs", nbrs);

	std::cout << "execution terminated after " << get_prog_time(first_time) << "ms" << std::endl;
//	exit(0);
	return (0);
}

