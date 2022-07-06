/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dselmy <dselmy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 04:09:28 by dselmy            #+#    #+#             */
/*   Updated: 2022/05/24 20:01:18 by dselmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

class Awesome
{
	public:
		Awesome(void): _n(42) {}
		int get() const {return this->_n;}
	private:
		int _n;
};

std::ostream & operator<<(std::ostream & o, const Awesome & a) { o << a.get(); return o;}

template<typename T>
void print(T const & x)
{
	std::cout << x << std::endl;
	return ;
}

void	putchar(char const & c)
{
	std::cout << c << std::endl;
}

void	plusOne(int const & i)
{
	std::cout << i + 1;
}

int main(void)
{
	std::cout << std::endl;
	std::cout << "********Basic test********" << std::endl;
	{
		char str[12] = "Hello world";
		::iter(str, 11, putchar);
		std::cout << std::endl;

		int	intarr[] = {0, 1, 2, 3, 4};
		for (int i = 0; i < 5; i++)
			std::cout << intarr[i];
		std::cout << std::endl;
		iter(intarr, 5, plusOne);
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "********Test from checklist********" << std::endl;
	{
		int tab[] = {0, 1, 2, 3, 4};
		Awesome tab2[5];
		iter(tab, 5, print);
		iter(tab2, 5, print);
	}
	return 0;
}
