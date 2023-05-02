#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", false, 72, 45), target("")
{
	std::cout << "Roboto default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Roboto deconstructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", false, 72, 45)
{
	std::cout << "RobotomyRequestForm parameterized constructor" << std::endl;
	this->target = target;
}

std::string RobotomyRequestForm::getTarget() const
{
	return(this->target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : Form("RobotomyRequestForm", false, 72, 45)
{
	this->target = obj.getTarget();
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	target = obj.getTarget();
	return *this;
}

void RobotomyRequestForm::Roboto() const
{
	srand(time(NULL));
	if ((rand() % 2) == 0)
		std::cout << this->getTarget() << " Has been robotomized successfully" << std::endl;
	else
		std::cout << this->getTarget() << " couldn't be robotomized" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
		if (executor.getGrade() > this->getSignedGrade() || executor.getGrade() > this->getExecutedGrade() || this->getSign() == false)
			throw RobotomyRequestForm::GradeTooLowException();
		else
			Roboto();
}