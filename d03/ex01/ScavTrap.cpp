/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 03:51:40 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/02 16:12:46 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap("ScavTrap")
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	this->setInitHit(100);
	std::cout << *this << " default constructor was called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	this->setInitHit(100);
	std::cout << *this << " constructor was called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src): ClapTrap()
{
	std::cout << *this << " copy constructor was called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << *this << " destructor was called" << std::endl;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& src)
{
	this->setName(src.getName());
	this->setHitPoints(src.getHitPoints());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setAttackDamage(src.getAttackDamage());
	this->setInitHit(src.getInitHit());
	return (*this);
}

void    ScavTrap::guardGate(void)
{
	std::cout << this->getName() << " guards the gate now." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap ";
	this->ClapTrap::attack(target);
}

std::ostream&	operator<<(std::ostream& stream, const ScavTrap& scavtrap)
{
	stream << "ScavTrap " << scavtrap.getName();
	return (stream);
}
