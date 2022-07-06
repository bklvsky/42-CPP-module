/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:09:40 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/05 00:56:17 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Default Constructor called of Dog" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog& copy): Animal(copy)
{
	std::cout << "Copy Constructor called of Dog" << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "Destructor called of Dog" << std::endl;
}

Dog&	Dog::operator=(const Dog &src)
{
	std::cout << "Assignment operator called for Dog" << std::endl;
	this->_type = src.getType();
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}
