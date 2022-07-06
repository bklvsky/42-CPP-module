/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:35:59 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/19 16:58:25 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char const **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i += 1)
		{
			std::string arg(argv[i]);
			for (unsigned j = 0; j < arg.length(); j += 1)
			{
				std::cout << static_cast<char>(std::toupper(arg[j]));
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
