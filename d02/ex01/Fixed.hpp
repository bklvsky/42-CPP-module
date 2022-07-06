/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:45:31 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/19 01:25:30 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int rawBits;
	static const int    number_of_fractional_bits = 8;

public:
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &src);
	~Fixed(void);
	
	Fixed&	operator=(const Fixed& src);
	int		getRawBits(void) const;
	void	setRawBits(int const rawBits);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed);
int	ft_pow(const int src, const int pow);

#endif
