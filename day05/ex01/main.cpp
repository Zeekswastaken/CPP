#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
	try{
	Bureaucrat a = Bureaucrat("Kella", 125);
	Form f = Form("Djaj", false, 120, 100);
	f.beSigned(a);
	a.signForm(f);
	//a.decrement();
	//std::cout << a;
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
}