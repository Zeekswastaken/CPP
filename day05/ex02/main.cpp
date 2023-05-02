#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
int main()
{
	try
	{
		Bureaucrat a = Bureaucrat("Kella", 2);

		//std::cout << "HIII" << std::endl;
		Form *f = new RobotomyRequestForm("clen");
		f->beSigned(a);
		//int i = 0;
		//while (i < 50)
		//{
			a.executeForm(*f);
		//	std::cout << std::endl;
		//	i++;
		//}
	//std::cout << a;
	//a.decrement();
	//std::cout << a;
	}catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}