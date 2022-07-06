/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 08:59:13 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/05 00:52:03 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Default Constructor called of Cat" << std::endl;
	this->_type = "Cat";
	this->brain = new Brain("Cat thought");
}

Cat::Cat(const Cat& copy): Animal(copy)
{
	std::cout << "Copy Constructor called of Cat" << std::endl;
	this->brain = new Brain();
	*this = copy;
}

Cat::~Cat()
{
	std::cout << "Destructor called of Cat" << std::endl;
	delete this->brain;
}

Cat&	Cat::operator=(const Cat &src)
{
	std::cout << "Assignment operator called for Cat" << std::endl;
	this->_type = src.getType();
	*(this->brain) = *(src.getBrain());
	return *this;
}

Brain*	Cat::getBrain(void) const
{
	return this->brain;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
