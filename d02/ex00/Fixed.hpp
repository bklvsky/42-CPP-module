/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:45:31 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/18 22:03:30 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
class Fixed
{
private:
    int rawBits;
    static const int    number_of_fractional_bits = 8;

public:
    Fixed(void);
    Fixed(const Fixed &src);
    ~Fixed(void);
    
    Fixed&  operator=(const Fixed& src);
    int     getRawBits(void) const;
    void    setRawBits(int const rawBits);
};

std::ostream&   operator<<(std::ostream& stream, const Fixed& fixed);

#endif
