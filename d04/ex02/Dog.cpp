/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:09:40 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/04 18:47:55 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Default Constructor called of Dog" << std::endl;
	this->_type = "Dog";
	this->brain = new Brain("Dog thought");
}

Dog::Dog(const Dog& copy): Animal(copy)
{
	std::cout << "Copy Constructor called of Dog" << std::endl;
	this->brain = new Brain();
    *this = copy;
}

Dog::~Dog()
{
	std::cout << "Destructor called of Dog" << std::endl;
	delete this->brain;
}

Dog&	Dog::operator=(const Dog &src)
{
	std::cout << "Assignment operator called for Dog" << std::endl;
	this->_type = src.getType();
	*(this->brain) = *(src.getBrain());
	return *this;
}

Brain*	Dog::getBrain(void) const
{
	return this->brain;
}

void    Dog::makeSound(void) const
{
    std::cout << "Woof" << std::endl;
}
