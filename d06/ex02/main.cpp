/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 00:48:14 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/06 02:34:34 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <stdexcept>

Base* generate(void)
{
	int	number = rand() % 30;
	
	if (number < 10)
		return (new A());
	else if (number < 20)
		return (new B());
	else
		return (new C());
}

void	identify(Base* p)
{
	A *a = dynamic_cast<A *>(p);
	B *b = dynamic_cast<B *>(p);
	C *c = dynamic_cast<C *>(p);


	if (a)
		std::cout << "A";
	else if (b)
		std::cout << "B";
	else if (c)
		std::cout << "C";
	else
		std::cout << "Bad cast";
}

void	identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A";
	}
	catch (std::exception& e)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "B";
		}
		catch(std::exception& e)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "C";
			}
			catch(std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}
}

int	main(void)
{
	std::cout << std::endl;
	std::cout << "****testing identify with generate****" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		Base	*base = generate();

		std::cout << "identify(ptr): ";
		identify(base);
		std::cout << std::endl << "identify(ref): ";
		identify(*base);
		std::cout << std::endl;
	
		std::cout << std::endl;
		delete base;
	}

	std::cout << std::endl;
	std::cout << "****testing identify manually****" << std::endl;
	std::cout << std::endl;

	{
		std::cout << "Base *base = new A()" << std::endl;
		std::cout << std::endl;
		Base *base = new A();
		std::cout << "identify(ptr): ";
		identify(base);
		std::cout << std::endl << "identify(ref): ";
		identify(*base);
		std::cout << std::endl;
		delete base;
	}

	{
		std::cout << std::endl;
		std::cout << "Base *base = new B()" << std::endl;
		std::cout << std::endl;
		Base *base = new B();
		std::cout << "identify(ptr): ";
		identify(base);
		std::cout << std::endl << "identify(ref): ";
		identify(*base);
		std::cout << std::endl;
		delete base;
	}

	{
		std::cout << std::endl;
		std::cout << "Base *base = new C()" << std::endl;
		std::cout << std::endl;
		Base *base = new C();
		std::cout << "identify(ptr): ";
		identify(base);
		std::cout << std::endl << "identify(ref): ";
		identify(*base);
		std::cout << std::endl;
		delete base;
	}
}
