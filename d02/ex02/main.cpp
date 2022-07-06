/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:03:44 by dselmy            #+#    #+#             */
/*   Updated: 2022/04/27 21:41:44 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 12.4321f );
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << std::endl;
	std::cout << "---------testing comparison operators---------" << std::endl;
	std::cout << std::endl;
	std::cout << a << " < " << b << " is " << (a < b) << std::endl;
	std::cout << a << " > " << b << " is " << (a > b) << std::endl;
	std::cout << a << " <= " << b << " is " << (a <= b) << std::endl;
	std::cout << b << " >= " << d << " is " << (b >= d) << std::endl;
	std::cout << b << " == " << d << " is " << (b == d) << std::endl;
	std::cout << b << " != " << d << " is " << (b != d) << std::endl;
	std::cout << std::endl;
	std::cout << "-----------testing basic ariphmetic-----------" << std::endl;
	std::cout << std::endl;
	std::cout << a << " + " << b << " + " << b <<" is " << (a + b + b) << std::endl;
	std::cout << a << " - " << b << " - " << b <<" is " << (a - b - b) << std::endl;
	std::cout << c << " * " << b << " is " << (c * b) << std::endl;
	std::cout << c << " / " << b << " is " << (c / b) << std::endl;
	std::cout << std::endl;
	std::cout << "-------------testing preincrement-------------" << std::endl;
	std::cout << std::endl;
	{
		Fixed aa;
		std::cout << "aa = " << aa << std::endl;
		Fixed bb = ++aa;
		std::cout << "bb = ++aa" << std::endl;
		std::cout << "bb = " << bb << "     aa = " << aa << std::endl;
		std::cout << "++bb = " << ++bb << std::endl;
	}
	std::cout << std::endl;
	std::cout << "-------------testing predecrement-------------" << std::endl;
	std::cout << std::endl;
	{
		Fixed aa;
		std::cout << "aa = " << aa << std::endl;
		Fixed bb = --aa;
		std::cout << "bb = --aa" << std::endl;
		std::cout << "bb = " << bb << "     aa = " << aa << std::endl;
		std::cout << "--bb = " << --bb << std::endl;
	}
	std::cout << std::endl;
	std::cout << "-------------testing postincrement------------" << std::endl;
	std::cout << std::endl;
	{
		Fixed aa;
		std::cout << "aa = " << aa << std::endl;
		Fixed bb = aa++;
		std::cout << "bb = aa++" << std::endl;
		std::cout << "bb = " << bb << "     aa = " << aa << std::endl;
		std::cout << "before: aa++ = " << aa++ << " //// after: aa = " << aa << std::endl;
	}
	std::cout << std::endl;
	std::cout << "-------------testing postdecrement------------" << std::endl;
	std::cout << std::endl;
	{
		Fixed aa;
		std::cout << "aa = " << aa << std::endl;
		Fixed bb = aa--;
		std::cout << "bb = aa--" << std::endl;
		std::cout << "bb = " << bb << "     aa = " << aa << std::endl;
		std::cout << "before: aa-- = " << aa-- << " //// after: aa = " << aa << std::endl;
	}
	std::cout << std::endl;
	std::cout << "----------------testing max/min---------------" << std::endl;
	std::cout << std::endl;
	Fixed const g(100);
	std::cout << "Fixed a = " << a << std::endl;
	std::cout << "Fixed const g = " << g << std::endl;
	std::cout << "max(" << a << ", " << b << ") = " << Fixed::max(a, b) << std::endl;
	std::cout << "max(" << b << ", " << a << ") = " << Fixed::max(b, a) << std::endl;
	std::cout << "max(" << a << ", " << g << ") = " << Fixed::max(a, g) << std::endl;
	std::cout << "min(" << a << ", " << b << ") = " << Fixed::min(a, b) << std::endl;
	std::cout << "min(" << b << ", " << a << ") = " << Fixed::min(b, a) << std::endl;
	std::cout << "min(" << a << ", " << g << ") = " << Fixed::min(a, g) << std::endl;
}
