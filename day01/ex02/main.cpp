#include <iostream>
int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "The address of the string is: " << &str << std::endl;
	std::cout << "The address held by the string pointer is: " << &stringPTR << std::endl;
	std::cout << "The address help by the string reference is: " << &stringREF << std::endl;

	std::cout << "The value of the string variable is: " << str << std::endl;
	std::cout << "The value pointed to by stringPTR is: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF is: " << stringREF << std::endl;
}