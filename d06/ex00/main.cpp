/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:00:26 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/03 22:56:47 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Converter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert <value>" << std::endl;
		return (0);
	}

	Converter converter(argv[1]);
	if (!converter.checkLiteral())
		std::cout << "Error: " << converter.getError() << std::endl;
	else
	{
		converter.convert();
		converter.putConvertion();
	}
	return (0);
}
