/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:53:29 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/27 21:41:35 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): rawBits(0)
{
}

Fixed::Fixed(const int value): rawBits(value << this->number_of_fractional_bits)
{
}

Fixed::Fixed(const float value)
{
	int	power = ft_pow(2, this->number_of_fractional_bits);
	this->rawBits = roundf(value * power);
}

Fixed::Fixed(const Fixed& src)
{
	*this = src;
}

Fixed::~Fixed(void)
{
}

Fixed&	Fixed::operator=(const Fixed& src)
{
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

bool	Fixed::operator>(const Fixed& rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed& rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed& rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed& rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed& rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	Fixed newFixed;

	newFixed.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (newFixed);
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	Fixed newFixed;

	newFixed.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (newFixed);
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	Fixed newFixed(this->toFloat() * rhs.toFloat());
	return (newFixed);
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	Fixed newFixed(this->toFloat() / rhs.toFloat());
	return (newFixed);
}

Fixed	Fixed::operator++(void)
{
	this->rawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	this->rawBits++;
	return temp;
}

Fixed	Fixed::operator--(void)
{
	this->rawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	this->rawBits--;
	return temp;
}

int		Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->number_of_fractional_bits);
}

Fixed& Fixed::min(Fixed& lhs, Fixed& rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs)
{
	if (lhs > rhs)
		return (lhs);
	return (rhs);
}

const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
	if (lhs > rhs)
		return (lhs);
	return (rhs);
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
