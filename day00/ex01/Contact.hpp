#ifndef	CONTACT_HPP
#define	CONTACT_HPP

#include <iostream>

class	Contact {
	public:
		std::string	First_Name;
		std::string	Last_Name;
		std::string	Nickname;
		std::string	Phone_Number;
		std::string	Darkest_Secret;
		Contact set_contact();
		Contact set_cont();
};
#endif
