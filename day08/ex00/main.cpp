#include "easyfind.hpp"
#include <vector>
int main()
{
	std::vector<int> vec;
	vec.push_back(20);
	vec.push_back(250);
	vec.push_back(70);
	vec.push_back(2420);
	vec.push_back(2033);
	std::vector<int>::iterator it;
	it = easyfind(vec, 2420);
 	if (it != vec.end())
		std::cout << "The element found is in the index number: " << it - vec.begin() << std::endl;
	else
		std::cout << "Couldn't find the element" << std::endl;
	// 0xFFaa123
	// 0xFFaa124
	// 0xFFaa125
	// 0xFFaa126
}