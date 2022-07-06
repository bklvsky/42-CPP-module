/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 03:30:05 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/25 00:04:19 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main()
{
	ClapTrap biba("Biba");
	ClapTrap boba("Boba");

	std::cout << std::endl << "****Biba tried to attack Boba but failed****" << std::endl;
	biba.attack(boba.getName());
	boba.takeDamage(biba.getAttackDamage());
	boba.beRepaired(2);

	std::cout << std::endl << "****Boba is attacked****" << std::endl;
	boba.takeDamage(5);
	boba.beRepaired(2);
	boba.takeDamage(10);
	boba.beRepaired(10);
	boba.attack("anyone");

	std::cout << std::endl << "****Biba turned crazy and attacks until it gets tired****" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Round " << i + 1 << ":";
		biba.attack("everyone around itself");
	}
	std::cout << std::endl;
}
