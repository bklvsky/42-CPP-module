/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:14:25 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/25 11:15:23 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("Just an WrongAnimal")
{
	std::cout << "Default Constructor called of WrongAnimal with a Type " \
	<< this->getType() << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	*this = copy;
	std::cout << "Copy Constructor called of WrongAnimal with a Type " \
	<< this->getType() << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor called of WrongAnimal with a Type " \
	<< this->getType() << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &src)
{
	this->_type = src.getType();
	return *this;
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "***WrongAnimal sounds***" << std::endl;
}