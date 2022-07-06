/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 02:55:51 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/02 16:31:51 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): name("ClapTrap"), hitPoints(10), \
						initialHitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << *this << " default constructor was called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), hitPoints(10), \
						initialHitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << *this << " constructor was called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << *this << " copy constructor was called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << *this << " destructor was called" << std::endl;
}

std::string	ClapTrap::getName(void) const
{
	return (this->name);
}

int	ClapTrap::getHitPoints(void) const
{
	return (this->hitPoints);
}

int	ClapTrap::getInitHit(void) const
{
	return (this->initialHitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->attackDamage);
}

void	ClapTrap::setName(std::string name)
{
	this->name = name;
}

void	ClapTrap::setHitPoints(int amount)
{
	this->hitPoints = amount;
}

void	ClapTrap::setInitHit(int amount)
{
	this->initialHitPoints = amount;
}

void	ClapTrap::setEnergyPoints(unsigned int amount)
{
	this->energyPoints = amount;
}

void	ClapTrap::setAttackDamage(unsigned int amount)
{
	this->attackDamage = amount;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& src)
{
	this->setName(src.getName());
	this->setHitPoints(src.getHitPoints());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setAttackDamage(src.getAttackDamage());
	this->setInitHit(src.getInitHit());
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() == 0)
	{
		std::cout << this->getName() << \
				" has no energy left and can't attack anymore." << std::endl;
		return;
	}
	else if (this->getHitPoints() <= 0)
	{
		std::cout << this->getName() << \
				" is too injured and can't attack anymore." << std::endl;
		return;
	}
	std::cout << this->getName() << " attacks " << target << \
	", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->energyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->getName() << " gets attacked and loses " \
	<< amount << " points of damage!" << std::endl;
	this->hitPoints -= amount;
	if (this->getHitPoints() > 0)
	{
		std::cout << "(" << this->getName() << " has " << \
		this->getHitPoints() << " points of damage left)" << std::endl;
		return;
	}
	std::cout << "(" << this->getName() << " has no more points" << \
											" of damage left)" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergyPoints() == 0)
	{
		std::cout << this->getName() << \
				" has no energy left and can't repair itself." << std::endl;
		return;
	}
	else if (this->getHitPoints() <= 0)
	{
		std::cout << this->getName() << " has fallen to " << \
		"the death of the brave and can't be repaired." << std::endl;
		return;
	}
	else if (this->getHitPoints() >= this->getInitHit())
	{
		std::cout << this->getName() << " has full hit " << \
								"points and can't be repaired." << std::endl;
		return;
	}
	std::cout << this->getName() << " get repaired and" << \
				" restores " << amount << " points of damage!" << std::endl;
	this->hitPoints += amount;
	std::cout << "(" << this->getName() << " has " << \
			this->getHitPoints() << " points of damage left)" << std::endl;
	this->energyPoints -= 1;
}

std::ostream&	operator<<(std::ostream& stream, const ClapTrap& claptrap)
{
	stream << "ClapTrap " << claptrap.getName();
	return (stream);
}
