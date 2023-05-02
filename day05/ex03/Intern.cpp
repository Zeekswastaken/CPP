#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &obj)
{
	std::cout << "Intern copy constructor called" << std::endl;
	(void)obj;
}

Intern& Intern::operator=(const Intern &obj)
{
	(void)obj;
	return(*this);
}

Intern::~Intern()
{
	std::cout << "Intern default deconstructor" << std::endl;
}

Form* Intern::makeForm(std::string FormName, std::string FormTarget)
{
	Form *f = NULL;
	Form *forms[] = {new PresidentialPardonForm(FormTarget), new RobotomyRequestForm(FormTarget), new ShrubberyCreationForm(FormTarget)};
	std::string Forms[] = {"presidential Pardon", "roboto myrequest", "shrubbery Creation"};
	for (int i = 0; i < 3; i++)
	{
		if (FormName == Forms[i])
			f = forms[i];
	}
	for (int i = 0; i < 3; i++)
	{
		if (FormName != Forms[i])
			delete forms[i];
	}
	return (f);
	
}
