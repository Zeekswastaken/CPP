#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("PresidentialPardonForm", false, 25, 5), target("")
{
	std::cout << "Presidential pardon default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Roboto deconstructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", false, 25, 5)
{
	std::cout << "PresidentialPardonForm parameterized constructor" << std::endl;
	this->target = target;
}

std::string PresidentialPardonForm::getTarget() const
{
	return(this->target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : Form("PresidentialPardonForm", false, 25, 5)
{
	this->target = obj.getTarget();
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	target = obj.getTarget();
	return *this;
}

void PresidentialPardonForm::Pardon() const
{
	std::cout << this->getTarget() << " Has been pardoned by Zaphod Beeblebrox" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getSignedGrade() || executor.getGrade() > this->getExecutedGrade() || this->getSign() == false)
		throw PresidentialPardonForm::GradeTooLowException();
	else
		Pardon();
}