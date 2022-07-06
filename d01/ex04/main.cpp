/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 00:09:11 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/21 16:39:54 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sed.hpp"

int	argsAreValid(int argc, char **argv)
{
	if (argc != 4)
		std::cout << "Usage: ./sed filename str_to_replace replacement_str" \
																<< std::endl;
	else
	{
		if (!argv[1][0])
			std::cout << "<filename> can't be an empty string" << std::endl;
		if (!argv[2][0])
			std::cout << "<str_to_replace> can't be an empty string" << std::endl;
		else
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (!argsAreValid(argc, argv))
		return (0);
	
	Sed sed(argv[1], argv[2], argv[3]);
	if (sed.setFile())
		sed.replace();
	return (0);
}
