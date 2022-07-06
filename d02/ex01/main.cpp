/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:03:44 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/27 21:38:20 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
	std::cout << "a is " << 1234.4321f << std::endl;
	std::cout << "b is " << 10 << std::endl;
	std::cout << "c is " << 42.42f << std::endl;
	std::cout << "d is " << 10 << std::endl;

	std::cout << std::endl << "--------Constructors--------" << std::endl << std::endl;
	
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	
	std::cout << std::endl << "--------Fixed check--------" << std::endl << std::endl;
	std::cout << "fixed a is " << a << std::endl;
	std::cout << "fixed b is " << b << std::endl;
	std::cout << "fixed c is " << c << std::endl;
	std::cout << "fixed d is " << d << std::endl;

	std::cout << std::endl << "--------toInt() check--------" << std::endl << std::endl;
	std::cout << "fixed a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "fixed b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "fixed c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "fixed d is " << d.toInt() << " as integer" << std::endl;

	std::cout << std::endl << "--------toFloat() check--------" << std::endl << std::endl;
	std::cout << "fixed a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "fixed b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "fixed c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "fixed d is " << d.toFloat() << " as float" << std::endl;

	std::cout << std::endl << "--------Destructors--------" << std::endl << std::endl;
}