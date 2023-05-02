#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>
template <typename T>
void iter(T *arr, int length,void (*ft_func)(T &y))
{
	for (int i = 0; i < length ; i++)
		ft_func(arr[i]);
}
#endif