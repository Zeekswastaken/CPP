#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
template<typename T>
typename T::iterator easyfind(T &cont, int i)
{
	typename T::iterator it = find(cont.begin(), cont.end(), i);
	return (it);
}
#endif