/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:33:42 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/26 19:01:14 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	HumanB jim("Jim");
	
	bob.attack();
	jim.attack();
	jim.setWeapon(&club);
	jim.attack();
	
	club.setType("some other type of club");
	bob.attack();
	jim.attack();
	return 0;
}
