#include "Replace.hpp"
int main()
{
	std::string	str1;
	std::string	str2;
	std::string	str3;
	std::string replace;

	std::cout << "Please enter the file name: ";
	getline(std::cin, str1);
	isempty(str1);
	std::cout << "Please enter the string to be replaced: ";
	getline(std::cin, str2);
	isempty(str2);
	std::cout << "Please enter the string to replace: ";
	getline(std::cin, str3);
	isempty(str3);
	std::string mainstr;
	std::ifstream filein;
	filein.open(str1);
	if (filein)
	{
		replace = str1.substr(0, str1.find('.') + 1);
		replace += "replace";
		int i = 1;
		while (filein.good())
		{
			getline(filein, str1);
			str1+='\n';
			mainstr += str1;
		}
		filein.close();
		mainstr = Replacement(mainstr, str2, str3);
		std::ofstream ofile(replace);
		ofile << mainstr;
		ofile.close();
	}
	else
		std::cout << "Error! File doesn't exist" << std::endl; 
}