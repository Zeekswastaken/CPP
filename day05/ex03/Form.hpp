#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
class Bureaucrat;
class Form{
	private:
		const std::string name;
		bool sign;
		const int s_grade;
		const int e_grade;
	public:
		Form();
		Form(const std::string name, bool sign, const int s_grade, const int e_grade);
		virtual ~Form();
		Form(const Form &obj);
		std::string getName() const;
		class GradeTooHighException : public std::exception{
			const char* what() const throw()
			{
				return "The grade of the Form is too high \n";
			}
		};
		class GradeTooLowException : public std::exception{
			const char* what() const throw()
			{
				return "The grade of the Form is too low \n";
			}
		};
		bool getSign() const;
		int getSignedGrade() const;
		int getExecutedGrade() const;
		Form &operator=(const Form &obj);
		void beSigned(Bureaucrat &br);
		virtual void execute(Bureaucrat const &executor) const = 0;
};
std::ostream& operator<<(std::ostream& os, const Form &fr);
#endif