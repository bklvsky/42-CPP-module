/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:30:34 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/26 18:54:02 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void): type("weapon")
{
	std::cout << "Default constructor for weapon is called" << std::endl;
}

Weapon::Weapon(std::string type): type(type)
{
	std::cout << "Constructor for " << type << \
											" weapon is called" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon " << this->getType() << " destroyed" << std::endl;
}

void	Weapon::setType(std::string type)
{
	std::cout << this->type << " morphes into " << type << std::endl;
	this->type = type;
}

const	std::string& Weapon::getType(void)
{
	return (this->type);
}
