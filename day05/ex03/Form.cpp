#include "Form.hpp"

Form::Form():name(NULL), sign(false), s_grade(150), e_grade(150) 
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, bool sign ,const int s_grade, const int e_grade): name(name), s_grade(s_grade), e_grade(e_grade)
{
	sign = false;
	if (s_grade > 150 || e_grade > 150)
		throw Form::GradeTooLowException();
	else if (s_grade < 1 || e_grade < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &obj): name(obj.getName()), s_grade(obj.getSignedGrade()), e_grade(obj.getExecutedGrade())
{
	this->sign = obj.getSign();
	std::cout << "Form Copy Constructor called" << std::endl;
}

Form& Form::operator=(const Form &obj)
{
	this->sign = obj.getSign();
	std::cout << "Form Copy constructor called" << std::endl;
	return (*this);
}

std::string Form::getName() const
{
	return (this->name);
}

bool Form::getSign() const
{
	return (this->sign);
}

int Form::getSignedGrade() const
{
	return (this->s_grade);
}

int Form::getExecutedGrade() const
{
	return (this->e_grade);
}

void Form::beSigned(Bureaucrat &br)
{
	if (br.getGrade() <= this->s_grade)
		this->sign = true;
	else
		throw GradeTooLowException();
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}