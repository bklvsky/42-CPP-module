/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 03:30:05 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/02 16:14:47 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main()
{
	FragTrap biba("Biba");
	ScavTrap boba("Boba");

	std::cout << std::endl;
	std::cout << biba << " is friendly but " << boba << " is not." << std::endl;
	std::cout << std::endl;
	boba.guardGate();
	biba.highFivesGuys();
	boba.attack(biba.getName());
	biba.takeDamage(boba.getAttackDamage());
	biba.beRepaired(10);

	std::cout << std::endl;
	std::cout << biba << " and " << boba << " got in a fight" << std::endl;
	std::cout << std::endl;

	while (boba.getHitPoints() > 0 && biba.getHitPoints() > 0)
	{
		biba.attack(boba.getName());
		boba.takeDamage(biba.getAttackDamage());
		boba.attack(biba.getName());
		if (boba.getHitPoints() > 0)
			biba.takeDamage(boba.getAttackDamage());
	}
	if (boba.getHitPoints() > 0)
		std::cout << boba;
	else
		std::cout << biba;
	std::cout << " wins the fight!" << std::endl;
	std::cout << std::endl;
}
