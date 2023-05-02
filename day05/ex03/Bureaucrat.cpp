#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	//try{
		if (CheckGrade(grade) == 0)
			throw Bureaucrat::GradeTooLowException();
		else if (CheckGrade(grade) == 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->grade = grade;
	//}
	//catch (std::exception &msg)
	//{
	//	std::cout << msg.what();
	//	this->grade = 150;
	//}
}

int Bureaucrat::CheckGrade(int grade)
{
	if (grade > 150)
		return (0);
	else if (grade  < 1)
		return (1);
	else
		return (5);
}

void Bureaucrat::increment()
{
	if (CheckGrade(grade - 1) == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade -= 1;
}

void Bureaucrat::decrement()
{
	if (CheckGrade(grade + 1) == 0)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade += 1;
}

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.name)
{
	std::cout << "Copy constructor called" << std::endl;
	this->grade = obj.grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl; 
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& obj)
{
	this->grade = obj.grade;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

void Bureaucrat::executeForm(Form const &form)
{
	if (form.getSign() == true && this->grade <= form.getSignedGrade() && this->grade <= form.getExecutedGrade())
	{
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
		form.execute(*this);
	}
	else
		throw Bureaucrat::FormSignedException();
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& br){
	os << br.getName() << ", bureaucrat grade " << br.getGrade() << std::endl;
	return (os);
}