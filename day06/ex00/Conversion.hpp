#ifndef CONVERSION_HPP
#define CONVERSION_HPP
#include <iostream>
#include <cstdlib>
#include <math.h>
class Conversion{
	private:
		int Conv_int;
		char Conv_char;
		float Conv_float;
		double Conv_doub;
		int	Type;
	public:
		Conversion();
		~Conversion();
		int Identify_Type(char *str);
		void ft_convert_int(char *str);
		void set_all(char *str);
		void ft_print_char(std::string str);
		void ft_print_double();
		void ft_print_int(char *str);
		void ft_print_float(char *str);
		void convert(char *str);
		void identify(char *str);
		int Identify_special_cases(char *str);
};
#endif