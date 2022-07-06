/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:54:38 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/21 16:03:43 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::~Zombie(void)
{
	std::cout << this->name \
			<< ": **incomprehensible sounds of a dying zombie**" << std::endl;
}

Zombie::Zombie(void)
{
	std::cout << "Default constructor is called" << std::endl;
	this->name = "Nameless zombie";
}

Zombie::Zombie(std::string name)
{
	std::cout << "Named constuctor is called" << std::endl;
	this->name = name;
}

void	Zombie::announce(void) const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
