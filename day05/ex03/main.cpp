#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <exception>
int main()
{
	try{
	Bureaucrat a = Bureaucrat("Kella", 2);
	Intern i ;


	//std::cout << "HIII" << std::endl;
	Form *f = i.makeForm("shrubbery Creation", "clen");
	if (f == NULL)
		throw std::invalid_argument("Form type is non-existent");
	f->beSigned(a);
	a.executeForm(*f);
	std::cout << std::endl;
	//std::cout << a;
	//a.decrement();
	//std::cout << a;
	}catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}