#include "Replace.hpp"

std::string ft_replace(std::string str, int found, std::string rp1, std::string rp2)
{
	int i = 0;
	std::string mainsub;
	if (found == 0)
	{
		std::string last;
		last = str.substr(rp2.length(), str.length() - rp2.length());
		mainsub = rp1;
		mainsub += last;
		return (mainsub);
	}
	mainsub = str.substr(0, found);
	std::string lastsub = str.substr(((mainsub.length()) + (rp2.length())), str.length() - (mainsub.length() + rp2.length()));
	mainsub += rp1;
	mainsub += lastsub;
	return (mainsub);
}

void	isempty(std::string str)
{
	if (str.empty())
	{
		std::cout << "Error! Empty string";
		exit(1);
	}
}

std::string Replacement(std::string str, std::string rp1, std::string rp2)
{
	std::string main;
	std::size_t	found = str.find(rp1);
	main = str;
	while (found != std::string::npos)
	{
		main = ft_replace(main, found, rp2, rp1);
		found = main.find(rp1, found + 1);
	}
	return (main);
}