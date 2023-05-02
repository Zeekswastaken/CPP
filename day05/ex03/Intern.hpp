#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &obj);
		Intern &operator=(const Intern &obj);
		Form *makeForm(std::string FormName, std::string FormTarget);
};
#endif