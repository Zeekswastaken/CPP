#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a = Bureaucrat("Kella", 1);
		a.increment();
		std::cout << a;
		//std::cout << a;
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
}