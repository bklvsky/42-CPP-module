/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:08:22 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/26 18:45:24 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int		main(void)
{
	std::cout << "making a randomChump() zombie" << std::endl;
	randomChump("Bill");
	std::cout << std::endl << "making a newZombie() zombie" << std::endl;
	Zombie	*bob = newZombie("Bob");
	bob->announce();
	delete bob;
	std::cout << std::endl << "making a zombie in main()" << std::endl;
	Zombie clark = Zombie("Clark");
	clark.announce();
}
