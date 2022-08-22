#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>

int	check_contact(std::string info)
{
	if (info.empty())
	{
		std::cout << "Error! You left an element empty, please try again";
		std::cout << std::endl; 
		exit (0);
	}
	else
		return (1);
}

Contact	set_contact()
{
	Contact	cnt;

	std::cout << "Please enter the first name of the contact: ";
	getline(std::cin, cnt.First_Name);
	check_contact(cnt.First_Name);
	std::cout << "Please enter the last name of the contact: ";
	getline(std::cin, cnt.Last_Name);
	check_contact(cnt.Last_Name);
	std::cout << "Please enter the nickname of the contact: ";
	getline(std::cin, cnt.Nickname);
	check_contact(cnt.Nickname);
	std::cout << "Please enter the phone number of the contact: ";
	getline(std::cin, cnt.Phone_Number);
	check_contact(cnt.Phone_Number);
	std::cout << "Please enter the contact's darkest secret: ";
	getline(std::cin, cnt.Darkest_Secret);
	check_contact(cnt.Darkest_Secret);
	return (cnt);
}

Contact	set_cont(Contact cnt)
{
	Contact	ct;

	ct.First_Name = cnt.First_Name;
	ct.Last_Name = cnt.Last_Name;
	ct.Nickname = cnt.Nickname;
	ct.Phone_Number = cnt.Phone_Number;
	ct.Darkest_Secret = cnt.Darkest_Secret;
	return (ct);
}

void printer(std::string str, int x)
{
	if (str.size() > 10 && x != 1)
		std::cout << std::setw(10) << std::right << str.substr(0, 9) << '.';
	else if (str.size() <= 10 && x != 1)
		std::cout << std::setw(10) << std::right << str << '|';
	if (x == 1)
		std::cout << str << '\n';
}

int	objleng(PhoneBook phn)
{
	int	i;

	i = 0;
	while (!phn.cont[i].First_Name.empty())
		i++;
	return (i);
}

void	ft_display(PhoneBook phn)
{
	std::string	src;
	int	i;
	
	i = 0;
	while (!phn.cont[i].First_Name.empty())
	{
		std::cout << std::setw(10) << std::right << i << '|';
		printer(phn.cont[i].First_Name, 0);
		printer(phn.cont[i].Last_Name, 0);
		printer(phn.cont[i].Nickname, 0);
		std::cout << std::endl;
		i++;
	}
	std::cout << "Please enter the index of the contact that you want: ";
	getline(std::cin, src);
	if (atoi(src.c_str()) > 8 || atoi(src.c_str()) > objleng(phn) - 1)
	{
		std::cout << "Error! index out of range.";
		std::cout << std::endl;
		return ;
	}
	printer(phn.cont[atoi(src.c_str())].First_Name, 1);
	printer(phn.cont[atoi(src.c_str())].Last_Name, 1);
	printer(phn.cont[atoi(src.c_str())].Nickname, 1);
	printer(phn.cont[atoi(src.c_str())].Phone_Number, 1);
	printer(phn.cont[atoi(src.c_str())].Darkest_Secret, 1);
}

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
		else if (opt == "SEARCH")
			ft_display(phn);
		std::cout << "You have a choice between ADD, SEARCH or EXIT, please choose one : ";
		getline(std::cin, opt);
	}
}