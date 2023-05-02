/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazahr <zouazahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:06:13 by zouazahr          #+#    #+#             */
/*   Updated: 2022/09/08 12:20:13 by zouazahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int main(int argc, char **argv)
{
	Conversion conv;
	if (argc == 1)
		std::cout << "Error" << std::endl;
	else
	{
		conv.identify(argv[1]);
	}
}