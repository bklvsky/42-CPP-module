/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 03:51:40 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/02 16:12:22 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap("FragTrap")
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	this->setInitHit(100);
	std::cout << *this << " default constructor was called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	this->setInitHit(100);
	std::cout << *this << " constructor was called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << *this << " destructor was called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src): ClapTrap()
{
	std::cout << *this << " copy constructor was called" << std::endl;
	*this = src;
}

FragTrap&   FragTrap::operator=(const FragTrap& src)
{
	this->setName(src.getName());
	this->setHitPoints(src.getHitPoints());
	this->setEnergyPoints(src.getEnergyPoints());
	this->setAttackDamage(src.getAttackDamage());
	this->setInitHit(src.getInitHit());
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	std::cout << "FragTrap ";
	this->ClapTrap::attack(target);
}

void    FragTrap::highFivesGuys(void)
{
	std::cout << this->getName() << " throws a high five!" << std::endl;
}

std::ostream&	operator<<(std::ostream& stream, const FragTrap& fragtrap)
{
	stream << "FragTrap " << fragtrap.getName();
	return (stream);
}
