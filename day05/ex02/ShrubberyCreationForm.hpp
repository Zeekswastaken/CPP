#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form{
	private:
		std::string target;
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &obj);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
		virtual void execute(Bureaucrat const &executor) const;
		std::string getTarget() const;
		void shruub() const;
};
#endif