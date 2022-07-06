/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 03:30:05 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/27 22:51:36 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main()
{
	ClapTrap biba("Biba");
	ScavTrap boba("Boba");

	std::cout << std::endl;
	std::cout << biba << " and " << boba << " get in a fight" << std::endl;
	std::cout << std::endl;
	boba.guardGate();
	biba.attack(boba.getName());
	boba.takeDamage(biba.getAttackDamage());
	boba.beRepaired(2);
	boba.attack(biba.getName());
	biba.takeDamage(boba.getAttackDamage());
	biba.attack(boba.getName());
	boba.beRepaired(2);
	std::cout << std::endl;
	std::cout << boba << " wins the fight!" << std::endl;
	boba.guardGate();
	std::cout << std::endl;
}