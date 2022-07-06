/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:10:41 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/21 16:15:41 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon(0)
{
}

HumanB::~HumanB(void)
{
	std::cout << this->name << " dropped their weapon " \
					<< this->weapon->getType() << " and died" << std::endl;
}

void	HumanB::attack(void) const
{
	if (this->weapon)
	{
		std::cout << this->name << " attacks with their " \
									<< this->weapon->getType() << std::endl;
	}
	else
	{
		std::cout << this->name << " has no weapon and can't attack" \
																<< std::endl;
	}
}

void	HumanB::setWeapon(Weapon* weapon)
{
	std::cout << this->name << " takes a weapon " << \
											weapon->getType() << std::endl;
	this->weapon = weapon;
}
