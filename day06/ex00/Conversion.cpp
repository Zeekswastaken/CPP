/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazahr <zouazahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:37:15 by zouazahr          #+#    #+#             */
/*   Updated: 2022/09/21 15:47:41 by zouazahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"
#include <stdlib.h>
#include <string>


/*0 FOR IMPOSSIBLE 
1 FOR INT
2 FOR DOUBLE
3 FOR FLOAT
4 FOR CHAR*/


Conversion::Conversion()
{
	
}

Conversion::~Conversion()
{
	
}

int ft_handle_nums(char *str)
{
	int i = 0;
	int point = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1])
		i++;
	while (str[i] == '.' || isdigit(str[i]))
	{
		if (str[i] == '.')
			point++;
		if (point > 1)
			return (0);
		i++;
	}
	if (!str[i])
	{
		if (point == 1)
			return (2);
		return (1);
	}
	if (str[i] == 'f' && !str[i + 1] && point == 1)
		return (3);
	return (0);
}

int Conversion::Identify_special_cases(char *str)
{
	std::string double_cases[] = {"inf","+inf", "-inf", "nan"};
	std::string float_cases[] = {"inff", "+inff", "-inff", "nanf"};

	for (int i = 0; i < 4; i++)
	{
		if (str == double_cases[i])
			return (2);
		if (str == float_cases[i])
			return (1);
	}
	return (0);
}

int Conversion::Identify_Type(char *str)
{
	this->Type = this->Identify_special_cases(str);
	if (this->Type != 0)
		return (1);
	if ((str[0] >= '0' && str[0] <= '9') || str[0] == '+' || str[0] == '-' || str[0] == '.')
	{
		this->Type = ft_handle_nums(str);
		if (this->Type != 0)
			return (1);
	}
	if (str[1])
		return (0);
	this->Type = 4;
	return (1);
}

void Conversion::identify(char *str)
{
	if (this->Identify_Type(str))
	{
		set_all(str);
		this->convert(str);
	}
	else
		std::cout << "Unidentified type" << std::endl; 
}


void Conversion::set_all(char *str)
{
	try
	{
		switch(this->Type)
	{
	case 1:
		this->Conv_int = std::stoi(str);
		break;
	case 2:
		this->Conv_doub = std::stof(str);
		break;
	case 3:
		this->Conv_float = std::stof(str);
		break;
	case 4:
		this->Conv_char = str[0];
		break;
	}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		exit (0);
	}
}

int ft_check_char(double i, std::string str)
{
	if ( str == "nan" || str == "nanf" || str == "inf" || str == "-inf" || str == "inff" || str == "-inff"  ||i > 127 || i < 0)
	{
		std::cout << "Impossible";
		return (0);
	}
	else if (i <= 31 || i == 127)
	{
		std::cout << "Non displayable";
		return (0);
	}
	return (1);
}

void Conversion::ft_print_char(std::string str)
{
	std::cout << "char: '";
	if (this->Type == 1)
	{
		if (ft_check_char(static_cast<double>(this->Conv_int), str))
			std::cout << static_cast<char>(this->Conv_int);
	}
	else if (this->Type == 2)
	{
		if (ft_check_char(static_cast<double>(this->Conv_doub), str))
			std::cout << static_cast<char>(this->Conv_doub);
	}
	else if (this->Type == 3)
	{
		if (ft_check_char(static_cast<double>(this->Conv_float), str))
			std::cout << static_cast<char>(this->Conv_float);
	}
	else
		std::cout << this->Conv_char;
	std::cout << "'" << std::endl;
}


void ft_check_doub_zer(double i)
{
	if (i - static_cast<int> (i) == 0)
		std::cout << ".0";
}

void Conversion::ft_print_double()
{
	std::cout << "double: ";
	if (this->Type == 1)
			std::cout << this->Conv_int << ".0"<<std::endl;
	else if (this->Type == 4)
		std::cout << (static_cast<int>(this->Conv_char)) << ".0" << std::endl;
	else if (this->Type == 3)
	{
		std::cout << this->Conv_float;
		ft_check_doub_zer(this->Conv_float);
	}
	else
	{
		std::cout << this->Conv_doub;
		ft_check_doub_zer(this->Conv_doub);
		std::cout << std::endl;
	}
}

int ft_check_int(char *str)
{
	try{
		std::stoi(str);
	}
	catch(...)
	{
		std::cout << "Impossible";
		return (0);
	}
	return (1);
}

void Conversion::ft_print_int(char *str)
{
	std::cout << "int: ";
	if (this->Type == 4)
		std::cout << static_cast<int>(this->Conv_char);
	else if (this->Type == 2)
	{
		if (ft_check_int(str))
			std::cout << static_cast<int>(this->Conv_doub);
	}
	else if (this->Type == 3)
	{
		if(ft_check_int(str))
			std::cout << static_cast<int>(this->Conv_float);
	}
	else
	{
		if (ft_check_int(str))
			std::cout << this->Conv_int;
	}
	std::cout << std::endl;
}

int ft_check_float(char *str)
{
	
	if (atof(str) == 0.0)
	{
		std::cout << "impossible" << std::endl;
		return (0);
	}
	return (1);
}

void Conversion::ft_print_float(char *str)
{
	std::cout << "float: ";
	if (this->Type == 1)
	{
		std::cout << this->Conv_int << ".0f"<<std::endl;
	}
	else if (this->Type == 4)
		std::cout << (static_cast<double>(this->Conv_char)) << ".0f" << std::endl;
	else if (this->Type == 2)
	{
		if (ft_check_float(str))
		{
			std::cout << static_cast<float>(this->Conv_doub);
			ft_check_doub_zer(this->Conv_doub);
			std::cout << "f" << std::endl;
		}
	}
	else
	{
		std::cout << this->Conv_float;
		ft_check_doub_zer(this->Conv_float);
		std::cout << "f" << std::endl;
	}
}

void Conversion::convert(char *str)
{
	this->set_all(str);
	this->ft_print_char(str);
	this->ft_print_int(str);
	this->ft_print_float(str);
	this->ft_print_double();
}
