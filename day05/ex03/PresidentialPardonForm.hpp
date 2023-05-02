#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include <fstream>
#include "Form.hpp"

class PresidentialPardonForm : public Form{
	private:
		std::string target;
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
		virtual void execute(Bureaucrat const &executor) const;
		std::string getTarget() const;
		void Pardon() const;
		void executeForm(Form const & form);

};
#endif