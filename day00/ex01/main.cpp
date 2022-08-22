#include "PhoneBook.hpp"
#include "Contact.hpp"
int main()
{
	Contact		cont;
	PhoneBook	phn;
	int			ind;
	ind = 0;
	std::string	opt;
	std::cout << "You have a choice between ADD, SEARCH or EXIT, please choose one : ";
	getline(std::cin, opt);
	while (opt != "EXIT")
	{
		if (opt == "ADD")
		{
			if (ind == 8)
				ind = 0;
			cont = set_contact();
			phn.cont[ind++] = set_cont(cont);
		}
	}
}