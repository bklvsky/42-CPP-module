/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:53:29 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/19 01:32:44 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value): rawBits(value << this->number_of_fractional_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;

	int	power = ft_pow(2, this->number_of_fractional_bits);
	this->rawBits = roundf(value * power);
}

Fixed::Fixed(const Fixed& src)
{
	*this = src;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->rawBits = src.rawBits;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->rawBits);
}

void	Fixed::setRawBits(int const rawBits)
{
	this->rawBits = rawBits;
}

float	Fixed::toFloat(void) const
{
	int	power = ft_pow(2, this->number_of_fractional_bits);
	float fixedValue = (float)this->getRawBits() / power;

	return (fixedValue);
}

int		Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->number_of_fractional_bits);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed)
{
	stream << fixed.toFloat();
	return (stream);
}

int	ft_pow(const int src, const int pow)
{
	int	newVal = src;
	for (int i = 1; i < pow; i++)
		newVal *= src;
	return (newVal);
}
