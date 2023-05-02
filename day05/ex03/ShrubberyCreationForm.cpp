#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", false, 145, 137), target("")
{
	std::cout << "Shrubbery default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery deconstructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", false, 145, 137)
{
	std::cout << "ShrubberyCreationForm parameterized constructor" << std::endl;
	this->target = target;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return(this->target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : Form("ShrubberyCreationForm", false, 145, 137)
{
	this->target = obj.getTarget();
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	target = obj.getTarget();
	return *this;
}

void ShrubberyCreationForm::shruub() const
{
	std::ofstream ofile(this->target + "_shruberry");
	ofile << "        &&& &&  & &&\n";
	ofile << "    && &\\/&\\|& ()|/ @, &&\n";
	ofile << "      &\\/(/&/&||/& /_/)_&/_&\n";
	ofile << "   &() &\\/&|()|/&\\/ '%\" & ()\n";
	ofile << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
	ofile << "&&   && & &| &| /& & % ()& /&&\n";
	ofile << " ()&_---()&\\&\\|&&-&&--%---()~\n";
	ofile << "     &&     \\|||\n";
	ofile << "             |||\n";
	ofile << "             |||\n";
	ofile << "             |||\n";
	ofile << "       , -=-~  .-^- _\n";
	ofile.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	//this->besigned(executor);
	if (executor.getGrade() > this->getSignedGrade() || executor.getGrade() > this->getExecutedGrade() || this->getSign() == false)
		throw ShrubberyCreationForm::GradeTooLowException();
	else
		shruub();
}