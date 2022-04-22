#include "main.hpp"
#include "compare.hpp"
#include <string.h>
#include <algorithm>
#include <stack>
#include <map>
#include <list>
/*
bool	check(std::string str1, std::string str2)
{
	std::cout << "str1 = " << str1 << " str2 = " << str2 << std::endl;
	if (str1 != str2)
	{
		return (true);
	}
	return (false);
}
*/
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
/*
template <typename t_it1, typename t_it2>
void		test (const t_it1 & it , const t_it2 & it2)
{
	if (it < it2)
		std::cout << "hello guys" << std::endl;
}
*/
/*
int	main(void)
{
	std::cout << std::endl;
	std::cout << "[------------ TEST FT CONTAINER ------------]" << std::endl;
	std::cout << std::endl;

//	test_stack();
//	test_vector();
//	test_map();
	ft::map<int, int>		nbrs;

	nbrs[1] = 3;
	nbrs[2] = 6;
	nbrs[3] = 9;
	nbrs[4] = 12;
	nbrs[5] = 15;
	nbrs[6] = 18;
	nbrs[7] = 21;
	nbrs[8] = 24;
	nbrs[9] = 27;

	nbrs.erase(++nbrs.begin());
	display_map("nbrs", nbrs);
	nbrs.erase(nbrs.begin());
	display_map("nbrs", nbrs);
	nbrs.erase(--nbrs.end());
	display_map("nbrs", nbrs);
	nbrs.erase(nbrs.begin(), ++(++(++nbrs.begin())));
	display_map("nbrs", nbrs);
	nbrs.erase(--(--(--nbrs.end())), --nbrs.end());
	display_map("nbrs", nbrs);

	nbrs[10] = 34;
	nbrs[11] = 35;
	display_map("nbrs", nbrs);
	nbrs.erase(--(--(--nbrs.end())), nbrs.end());
	display_map("nbrs", nbrs);
	nbrs[12] = 36;
	nbrs[13] = 37;
	nbrs[14] = 38;
	nbrs[15] = 39;
	nbrs.erase(nbrs.begin(), nbrs.end());
	display_map("nbrs", nbrs);
}
*/

#include <list>

#define T1 int
#define T2 std::string
typedef ft::pair<const T1, T2> T3;

static int iter = 0;

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}
template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param);
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param, param2);
	printSize(mp);
}

int		main(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
	ft::map<T1, T2> mp(lst.begin(), lst.end());
	printSize(mp);
	(void)iter;

//	ft_erase(mp, ++mp.begin());

//	ft_erase(mp, mp.begin());
//	ft_erase(mp, --mp.end());

//	ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
//	ft_erase(mp, --(--(--mp.end())), --mp.end());

	mp[10] = "Hello";
	mp[11] = "Hi there";
	printSize(mp);
	ft_erase(mp, --(--(--mp.end())), mp.end());
	//mp.print();


	std::cout << "ICI" << std::endl;
	printSize(mp);
	std::cout << "hey" << std::endl;
	mp[12] = "ONE";
//	printSize(mp);
/*	*/
	return (0);
}
