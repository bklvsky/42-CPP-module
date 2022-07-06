/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 08:59:13 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/25 10:14:23 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->_type = "WrongCat";
	std::cout << "Default Constructor called of WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy): WrongAnimal(copy)
{
	*this = copy;
	std::cout << "Copy Constructor called of WrongCat" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor called of WrongCat" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat &src)
{
	this->_type = src.getType();
	return *this;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
