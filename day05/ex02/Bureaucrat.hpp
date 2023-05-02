#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "Form.hpp"
class Form;
class Bureaucrat {
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name,int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);
		std::string getName() const;
		int getGrade() const;
		class GradeTooHighException : public std::exception{
			const char* what() const throw()
			{
				return "The grade of the bureaucrat is too high \n";
			}
		};
		class GradeTooLowException : public std::exception{
			const char* what() const throw()
			{
				return "The grade of the bureaucrat is too low \n";
			}
		};
		int CheckGrade(int grade);
		void increment();
		void decrement();
		void executeForm(Form const &form);
		class FormSignedException : public std::exception {
    public:
		const char *what() const throw() {
    		return "The Form wasn't executed either because the bureaucrat's grade was too low or because the form wasn't signed";
   		}
		};
		};
		std::ostream& operator<<(std::ostream& os, const Bureaucrat& br);

#endif